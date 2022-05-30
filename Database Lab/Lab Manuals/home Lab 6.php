<?php
$host = "localhost";
$user = "root";
$pass = "";
$dbName = "university";
$con = mysqli_connect($host,$user,$pass,$dbName);
if(mysqli_connect_error($con))
{
    echo "Connection Failed";
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
    html{
        /* background: linear-gradient(to right top, #0c008c, #002a8d, #003c82, #134971, #45535e) ; */

        max-height:768px;
        height:100%;
        color:black;
        /* background-image: linear-gradient(to bottom, #00132e, #27485a, #648085, #acbbb7, #f7f8f7); */
    }
     form{
         margin:10px auto;
         max-width:350px;
         width:100%;
         border:2px solid lightgrey;
         background: white;
        
       
         
         /* box-shadow: 1px 2px  1px 3px  lightgrey; */
         height:300px;
         border-radius: 10px;
         text-align:center;
         margin-bottom:0px;
     }
     form div{
         height:50px;
         color: #002a8d;
         text-align:center;
         padding:10px ;
        
         margin-top:-10px !important;
         border-bottom: 2px solid transparent;
         border-bottom: 2px solid #002a8d;
         margin-bottom:10px;
          

     }
     form div h3{
         margin-top:50px;
         margin-bottom:0px;
        
     }
      form label{
         padding-left:5px;
         float:left;
         margin:13px auto ;
     }
     form input{
         padding:5px;
         border-radius: 5px;
         border:2.5px solid grey;
         border-radius: 5px;
         max-width:160px;
         margin:10px auto;
        margin-right:10px;
         
         float:right;
     
        
     }
     .submit{
         height:40px;
         font-size:16px;
         border: 2px solid transparent;
         border-radius: 5px;
         background: #002a8d;
         font-weight:bold; 
         color: white;
         margin-top:20px;
         margin-right:100px !important;
         width:120px;
     

     }
     table{
         max-width:600px;
         width:80%;
         
         border: 2px solid black;
         margin-top:30px;
         text-align: center;
         padding:5px;
         background: white;
         color:black;
         border-collapse: collapse;
         margin:30px auto 0px;
         
        
     }
    table thead{

        font-size: 20px;
        font-weight: bold;
        border: 1px solid black;
        width:200px;
        color:black;
    }
    table  tr {
     border: 1px solid black;
     color:black;
    }
    table tr td{
color: black;
font-weight: bold;
border: 1px solid black;
    }
    h2{
        margin:30px auto 10px;
        width:200px;

    }
    h1{
        width:800px;
        margin:30px auto 0px;
        text-align:center;
    }

     


    </style>
</head>
<body>

   
    <h1 >CRUD APPLICATION</h1>
    <form action="" method="POST">
        <div><h2>Records Table</h2></div>
        <label for="Full Name">Enter your Full Name:</label>
        <input type="text" name="name">
        <br>
        <label for="Email ID">Enter your Email ID:</label>
        <input type="email" name="email">
        <input type="submit" name="submit" class="submit" value="Delete Record">
    </form>
   <h2 margin="0px auto" color="Black" >Students Table</h2>
    <table   cellpadding="1" cellspacing="1">
       <tr> <thead><td>ID</td><td>Name</td><td>Email ID</td></thead></tr>
        
        <tr>
<?php
$sql= "select * from student";
$result= mysqli_query($con, $sql);
//if ($result->num_rows>0){
while ($rows=$result->fetch_assoc())
{
?>
            <td><?php echo $rows['id'] ?></td>
            <td><?php echo $rows['name'] ?></td>
            <td><?php echo $rows['email'] ?></td>
        </tr>
        <?php
        } ?>

    </table>
<!--    --><?php
//    }else{
//     echo "No Result is founded!!!";
//    }
//    ?>
</body>
</html>
<?php
if(isset($_POST['submit']))
{

//        $name =$_POST['name'];
//        $email=$_POST['email'];
//        $sql= "INSERT INTO student(NAME,EMAIL)VALUES('$name','$email')";
//
//        if(mysqli_query($con, $sql))
//        {
//            echo "record inserted successfully!";
//
//        }
//        else {
//            echo "Error inserting records!".mysqli_connect_error();
//        }



    /// Updating the record
//        $name =$_POST['name'];
//        $email=$_POST['email'];
//        $sql= "select id from student where email = '$email'";
//        $result= mysqli_query($con, $sql);
//        $rows=$result->fetch_assoc();
//        $id = $rows['id'];
//        $query = "UPDATE student SET email = '$email', name = '$name' WHERE id = '$id'";
//            if($con->query($query)){
//                echo "Recorded Updated!!";
//            }
//            else
//            {
//                echo "Error Updating records!".mysqli_connect_error();;
//            }

//Delete Records from Table

        //$name =$_POST['name'];
        $email=$_POST['email'];
        $sql = "DELETE From student where email = '$email'";
        if ($con->query($sql)==TRUE){
            echo "Record deleted successfully";
        }else{
            echo "Error". $conn->error;
        }

}
?>
