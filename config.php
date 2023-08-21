<?php

$server = "localhost";
$user = "root";
$password = "";
$nama_database ="dht_11";

$db = mysqli_connect($server, $user, $password, $nama_database);//untuk menghubungkan PHP dengan MySQL, kita menggunakan fuungsi mysqli_connect()

if( !$db ){//jika koneksi gagal, variabel $db akan bernilai false
    die("Gagal terhubung dengan database: " . mysqli_connect_error());
}

?>