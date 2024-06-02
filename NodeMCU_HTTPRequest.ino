// Library koneksi
#include <WiFi.h>
#include "DHT.h"//library dht 
#define DHTPIN 0     // DHT PIN 2
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

// Konfigurasi WiFi
const char *ssid = "Redmi Note 10 Pro";
const char *password = "1sampai9";

// IP Address Server yang terpasang XAMPP
const char *host = "192.168.169.76";

float t;
float h;

void setup() {
  Serial.begin(9600);

  // Koneksi ESP dengan WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Menunggu koneksi
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  // Jika koneksi berhasil, maka akan muncul address di serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // Membaca data sensor 
  h = dht.readHumidity();
  t = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");
  
  Serial.println("===================================================");
  Serial.print("Mencoba Pengiriman Data ke : ");
  Serial.println(host);

  // Memanggil fungsi kirim() untuk kirim data ke host XAMPP (local host)
  kirim();
  
  delay(1000);
}

void kirim(){
  // Mengirimkan ke alamat host dengan port 80
  WiFiClient client;
  const int httpPort = 80;

  // Mencoba koneksi, jika gagal
  if (!client.connect(host, httpPort)) {
    Serial.println("Koneksi Gagal");
    return;
  }

  // Isi konten yang dikirim adalah alamat ip si esp
  String url = "/dht/save.php?temperature="; 
  url += t;
  url += "&humidity=";
  url += h;

  //Sekarang URL = "/folder_tujuan/file_tujuan.php?id=value"

  Serial.print("Requesting URL: ");
  Serial.println(url);

  // Mengirimkan Request ke Server
  client.print("GET " + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
               /*
               \r\n = fungsi enter
               */
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 1000) {
      Serial.println("Client Timeout !");
      client.stop();
      return;
    }
  }

  // Membaca balasan dari server dan tampilkan di serial monitor
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println("Selesai");
}
