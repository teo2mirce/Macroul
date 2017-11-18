<?php
if ( ! session_id() ) @ session_start();


	$con = mysqli_connect("93.188.160.43","u751888225_teo2m","G0jmQXkOoKcG","u751888225_macro");
	$sql = "SELECT `T` FROM `TV2` WHERE UserID_Nume='".$_SESSION["UID"].'_'.$_SESSION['NumeCalculator']."'";
	$result = mysqli_query($con,$sql);
		if($result && $result->num_rows>0)//logat
			$da=$result->fetch_assoc()['T'];
	echo $da;
?>

