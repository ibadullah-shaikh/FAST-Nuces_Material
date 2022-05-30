<?php
$servername = "localhost";
$username="root";
$password ="";
$dbname="university";
//create connection
$conn =mysqli_connect($servername, $username, $password,$dbname);
if ($conn -> connect_error) {
die("connection failed:".$conn->connect_error);

}
//sql to insert data in table
//$sql =  "INSERT INTO student_info(fname,email) VALUES('Hamza Ahmed','hamza.ahmed@nu.edu.pk')";
//if (mysqli_query($conn, $sql)) {
//  echo "New record created successfully";
//}


//Sql to show the data
//$sql = "SELECT id, fname, email from student_info";
//$result = $conn->query($sql);
//if ($result->num_rows>0)
//{
////output data of each row in Student table
//while ($row=$result->fetch_assoc()){
//    echo "id:  ". $row["id"]."  -Name:  " .$row["fname"]. "  email:  ". $row["email"]. "<br>";
//}
//}else{
//    echo "0 results";
//}


// Delete Records from Table
//$sql = "DELETE From student_info where id = 5";
//if ($conn->query($sql)==TRUE){
//    echo "Record deleted successfully";
//}else{
//    echo "Error". $conn->error;
//}


// Updating Records
//$sql = "UPDATE student_info set email = 'asim.iqbal@nu.edu.pk',fname = 'Asim Iqbal' where id = 1";
//if ($conn->query($sql)==TRUE){
//    echo "Record updated successfully";
//}else
//{
//    echo "Error". $conn->error;
//}

$conn->close();
?>