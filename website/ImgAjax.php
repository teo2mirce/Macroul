<?php
if ( ! session_id() ) @ session_start();

//$con = mysqli_connect("64.62.211.131","teo2m_mruser","google","teo2m_macroul");
$con = mysqli_connect("93.188.160.43","u751888225_teo2m","G0jmQXkOoKcG","u751888225_macro");
	$sql = "SELECT `Poza` FROM `teamviewer` WHERE UserID_Nume='".$_SESSION["UID"].'_'.$_SESSION['NumeCalculator']."'";
	//echo $sql;
	$result = mysqli_query($con,$sql);
		if($result && $result->num_rows>0)//logat
			$da=$result->fetch_assoc()['Poza'];
	echo 'data:image/jpeg;base64,'.base64_encode( $da);
			
			
?>

