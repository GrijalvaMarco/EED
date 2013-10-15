<html>
  <head>
  
  
  </head>
  <body>
    
<?php
   
    $Usuario = $_POST['usuario'];
    $Contra = $_POST['contra'];
if( ($Usuario == "joel" && $Contra == "joel")){
	session_start();
	$_SESSION["codigo"] = $Codigo;
	header("Location: inicio.php");
      }else{
	header("Location: principal.php");
	}
?>
 
   	
</body>

</html>
