<?php
// include database connection file
include_once("config.php");
 
// Get id from URL to delete that user
$id = $_GET['suhu'];
 
// Delete user row from table based on given id
$result = mysqli_query($db, "DELETE FROM suhu");
 
// After delete redirect to Home, so that latest user list will be displayed.
header("Location:index.php");
// ini menghapus data semua berdasarkan 
?>