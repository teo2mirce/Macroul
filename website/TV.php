<?php
if ( ! session_id() ) @ session_start();
//macroul e al lui si grupu/calculatorul e al lui


//$con = mysqli_connect("64.62.211.131","teo2m_mruser","google","teo2m_macroul");
$con = mysqli_connect("93.188.160.43","u751888225_teo2m","G0jmQXkOoKcG","u751888225_macro");

echo 'da';

if(isset($_SESSION["NumeCalculator"]))
{
	$q=7+$_POST['t'];
	if($_POST['t']<3)
	{
		mysqli_query($con, "INSERT INTO `activator`(`MacrouID`, `Type`, `Data`, `NrTimes`,Additional1,Additional2,Additional3) values(0,".$q.",'".addslashes($_SESSION["NumeCalculator"])."',1,".$_SESSION["UID"].",'".$_POST['x']."','".$_POST['y']."' )");
	}
	if($_POST['t']==3 || $_POST['t']==4)
	{
		//9/10  UID    x=code      y=press/release
		mysqli_query($con, "INSERT INTO `activator`(`MacrouID`, `Type`, `Data`, `NrTimes`,Additional1,Additional2,Additional3) values(0,".$q.",'".addslashes($_SESSION["NumeCalculator"])."',1,".$_SESSION["UID"].",'".$_POST['x']."','' )");
	}
	if($_POST['t']==5)
	{
		mysqli_query($con, "INSERT INTO `activator`(`MacrouID`, `Type`, `Data`, `NrTimes`,Additional1,Additional2,Additional3) values(0,".$q.",'".addslashes($_SESSION["NumeCalculator"])."',1,".$_SESSION["UID"].",'".$_POST['x']."','' )");
	}
}
//pt data: MID|C   (macrouID si calculator)
?>

