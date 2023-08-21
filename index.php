<?php include("config.php"); ?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Kirim data DHT</title>
</head>
<body>
    <table border="1">
    <tr>
        <th bgcolor="green">Tanggal</th>
        <th bgcolor="yellow">Temperature</th>
        <th bgcolor="red">Humidity</th>
        <th bgcolor="pink"><a href='del.php?id=$value[suhu]'>Delete All Data</a></th>
    </tr>
        <?php
        $sql = "SELECT * FROM suhu ORDER BY tanggal DESC";
        $query = mysqli_query($db, $sql);
        $no = 1;
        while($value = mysqli_fetch_array($query)){
            echo "<tr>";
            echo "<td>".$value['tanggal']."</td>";
            echo "<td>".$value['temperature']."</td>";
            echo "<td>".$value['humidity']."</td>";
            echo "<td><a href='delete.php?id=$value[tanggal]'>Delete</a></td></tr>";
            // <a href='edit.php?id=$value[id]'>Edit</a> |
            echo "</tr>";
            echo "<tr>";
            

            echo "</tr>";
            $no++;
        }
        ?>
    
    </table>
</body>
</html>