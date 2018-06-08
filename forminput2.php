<!DOCTYPE html>
<html>
  <head>
    <title>Super Secret Encryper</title>
    <link rel="stylesheet" type="text/css" href="style.css">
  </head>


  <body>
	<nav>
		<ul>
			<li><a href="index.html">Home</a> </li>
		</ul>
	</nav>
    <h1>Vigenere Cipher</h1>
    <p>This is the bin to write your message...(no spaces please)</p>
    <p>Your key should only contain letters!</p>

    <?php
       // define variables and set to empty values
       $arg1 = $arg2 = $result = $Choose = "";
       if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $arg1 = test_input($_POST["arg1"]);
            $arg2 = test_input($_POST["arg2"]);
            $Choose = test_input($_POST["Choose"]);
            $result = system( "/usr/lib/cgi-bin/student3/project " . $arg1 . " " . $arg2 . " " . $Choose ); 
       }

       function test_input($data) {
         $data = trim($data);
         $data = stripslashes($data);
         $data = htmlspecialchars($data);
         return $data;
       }
    ?>
<br>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      Message: <input type="text" name="arg1"><br>
      Key: <input type="text" name="arg2"><br>
	
	<input type = "radio" name = "Choose" value = "Encrypt">Encrypt
	<input type = "radio" name = "Choose" value = "Decrypt">DeCrypt
      <br><input type="submit">
    </form>

    <?php
       echo "<h2>Your Input:</h2>";
       echo $arg1;
       echo "<br>";
       echo $arg2;
       echo "<br>";
       echo $Choose;
       echo "<br>";

  //     echo "<h2>Your Message Sir :^)</h2>";
//       echo $result;
       
     ?>
    
  </body>
</html>
