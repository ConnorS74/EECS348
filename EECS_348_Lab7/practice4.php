<html>
 <body>
  <table border=3>
   <?php
    for ($i = 0; $i <= $_GET["size"]; $i++) {
     echo "<tr>";
     for ($j = 0; $j <= $_GET["size"]; $j++) {
      if ($i == 0 and $j == 0) {
       echo "<th></th>";
      } else if ($i == 0) {
       echo "<th>{$j}</th>";
      } else if ($j == 0) {
       echo "<th>{$i}</th>";
      } else {
       $product = $i*$j;
       echo "<td>{$product}</td>";
      }
     }
     echo "</tr>";
    }
   ?>
  </table>
 </body>
</html>