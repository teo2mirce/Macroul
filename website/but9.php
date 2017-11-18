<?php
if ( ! session_id() ) @ session_start();
//macroul e al lui si grupu/calculatorul e al lui

//$con = mysqli_connect("64.62.211.131","teo2m_mruser","google","teo2m_macroul");
$con = mysqli_connect("93.188.160.43","u751888225_teo2m","G0jmQXkOoKcG","u751888225_macro");
$macrou=-1;
if($_POST["MX"]==0)
{
	if(strlen($_POST["CodMacrou"]))
		$macrou=-2;
	else
		$macrou=$_POST["Macrou"];
}
else
	$macrou=$_SESSION["M".$_POST["MX"]];
if($macrou!=-1)
{

	
	
	  $RMP = mysqli_query($con,"select * from macrou where ID=".$macrou." and UserID=".$_SESSION["UID"]);
	  if(($RMP && $RMP->num_rows) || $macrou==-2)//daca e macroul lui
	  {
		  {$file = 'people.txt';$current = file_get_contents($file);$current .= "John Smith1\n";file_put_contents($file, $current);}
		  if($_SESSION["Activator"]=='Calculatoare')//daca e calculatoarele lui
		  {
			  {$file = 'people.txt';$current = file_get_contents($file);$current .= "John Smith2\n";file_put_contents($file, $current);}
			  $vec="('".addslashes($_POST['Vector'][0]);
			  for($i=1; $i<count($_POST['Vector']); $i++)
				  $vec.="','".addslashes($_POST['Vector'][$i]);
			  $vec.="')";
			  if($macrou!=-2)
				mysqli_query($con, "INSERT INTO `activator`(`MacrouID`, `Type`, `Data`, `NrTimes`) Select ".$macrou.",6, Nume ,1 from calculatoare where Nume in ".$vec);
			  else
			  {
				  {$file = 'people.txt';$current = file_get_contents($file);$current .= "John Smith3\n";file_put_contents($file, $current);}
				  mysqli_query($con, "INSERT INTO `activator`(Additional1,`MacrouID`, `Type`, `Data`, `NrTimes`) Select '".addslashes($_POST["CodMacrou"])."',".$macrou.",0, Nume ,1 from calculatoare where Nume in ".$vec);
			  }
		  }
		  if($_SESSION["Activator"]=='Grupuri')//daca e calculatoarele lui
		  {
			  $vec="('".addslashes($_POST['Vector'][0]);
			  for($i=1; $i<count($_POST['Vector']); $i++)
				  $vec.="','".addslashes($_POST['Vector'][$i]);
			  $vec.="')";
				if($macrou!=-2)
					mysqli_query($con, "INSERT INTO `activator`(`MacrouID`, `Type`, `Data`, `NrTimes`) Select ".$macrou.",6, NumeCalculator ,1 from asocieregrup where UserID=".$_SESSION["UID"]." and NumeGrup in ".$vec);
				else
				    mysqli_query($con, "INSERT INTO `activator`(Additional1,`MacrouID`, `Type`, `Data`, `NrTimes`) Select '".addslashes($_POST["CodMacrou"])."',".$macrou.",0, NumeCalculator ,1 from asocieregrup where UserID=".$_SESSION["UID"]." and NumeGrup in ".$vec);
		  }
		  if($_SESSION["Activator"]=='Toate')//daca e calculatoarele lui
		  {
				if($macrou!=-2)
					mysqli_query($con, "INSERT INTO `activator`(`MacrouID`, `Type`, `Data`, `NrTimes`) Select ".$macrou.",6, Nume ,1 from calculatoare where UserID=".$_SESSION["UID"]);
				else
				  mysqli_query($con, "INSERT INTO `activator`(Additional1,`MacrouID`, `Type`, `Data`, `NrTimes`) Select '".addslashes($_POST["CodMacrou"])."',".$macrou.",0, Nume ,1 from calculatoare where UserID=".$_SESSION["UID"]);
		  }
	  }
	
}

//pt data: MID|C   (macrouID si calculator)       addslashes($_POST["CodMacrou"])
?>

