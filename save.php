<?php

include("config.php");

// cek apakah tombol daftar sudah diklik atau blum?
if(isset($_GET['temperature'])){

    // ambil data dari formulir
    $t = $_GET['temperature'];
    $h = $_GET['humidity'];
    // echo $nama;

    // buat query
    $sql = "INSERT INTO suhu VALUES (now(),$t,$h)";
    $query = mysqli_query($db, $sql);

}

?>