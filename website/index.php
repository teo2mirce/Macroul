<?php

if (!isset($_SESSION)){
	header('Cache-Control: no cache'); //no cache
	session_cache_limiter('private_no_expire'); // works
  session_start();
}
?>

<html>
<head>
<script src='http://cdnjs.cloudflare.com/ajax/libs/jquery/2.1.3/jquery.min.js'></script>
<script src="js/index.js"></script>
<title>Macroul</title>
<meta charset="utf-8">
<link rel="stylesheet" href="css/style.css">
<link rel="icon" href="res/macrou.ico">


<meta name="viewport" content="user-scalable=no;user-scalable=0;"/>

</head>


<script>

function Click9(da)
{
	//alert("astia vrea sa fac ceva...");
	if(da>=0 && da<=9)
	{
		var toate = []; // initialize empty array 
		$("input[type='checkbox']").each(function(){
			toate.push($(this).val());
		});
		
		var selected_value = []; // initialize empty array 
		$("input[type='checkbox']:checked").each(function(){
			selected_value.push($(this).val());
		});
		
		if(toate.length!=0 && selected_value.length==0)
		{
			alert("Trebuie sa alegi ceva");
			return;
		}
		var cod=document.getElementById("codMacrou").value;
		document.getElementById("codMacrou").value="";
		
		$.ajax(
		{
			url: "but9.php",
			type:'POST',
			data:
			{
				MX: da,
				Vector: selected_value,
				Macrou: document.getElementById('ListaMacrou').value,
				CodMacrou: cod
				//email: email_address,
				//message: message
			},
			success: function(msg)
			{
				
			}               
		}
		///todo
		///document.getElementById("codMacrou").value="";
		);
		//console.log(selected_value); //Press F12 to see all selected values
		//console.log(document.getElementById('ListaMacrou').value);
	}
}

function LogOut()
{
	window.location = "LogOut.php";
}
</script>

<style  type="text/css">
		a:link, a:visited {
			background-color: #4060AA;
			color: white;
			padding: 14px 25px;
			text-align: center;
			text-decoration: none;
			display: inline-block;
		}


		a:hover, a:active {
			background-color: #5090BB;
		}
</style>
<body >





	<?php 
	if (!isset($_SESSION)){
	  session_start();
	}
	$useragent=$_SERVER['HTTP_USER_AGENT'];
	if(preg_match('/(android|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i',$useragent)||preg_match('/1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i',substr($useragent,0,4)))
	{
		
		echo '<style type="text/css">
		
        .inner-container{
			position:relative;
			top:0px;
			left:0px;
			width:100%;
			height:100%;
        }
		.box h1
		{
			font-size:3em;
		}
        .box input[type="submit"]{
			width: 3em;
			height: 2em;
			font-size:2em;
        }
        .box input[type="text"]{
			width: 75%;
			height: 3em;
			font-size:2em;
			margin:20px auto;
        }
        .box input[type="password"]{
			width: 75%;
			height: 3em;
			font-size:2em;
			margin:20px auto;
        }
        .box input[type="checkbox"]{
			width: 2em;
			height: 3em;
			font-size:2em;
        }
        .box label{
			font-size:3em;
        }
        .styled-select{
			width: 75%;
			height: 3em;
			font-size:2em;
			margin:20px auto;
        }
        .styled-select select{
			width: 75%;
			height: 100%;
			font-size:2em;
			margin:20px auto;
        }
		.box button
		{
			margin:30px auto;
			width: 75%;
			height: 3em;
			font-size:3em;
			padding: 0px;
		}
		#codMacrou
		{
			margin:30px auto;
			width: 75%;
			height: 5em;
			font-size:3em;
			padding: 0px;
		}
		
		
        </style>';
	}

		//session_destroy();

		//daca trebuie sa se logheze
		if (!isset($_SESSION["UID"])  && empty($_POST)){
		?>
		  <div class="vid-container">
		  <img class="bgvid back" src="res/background.jpg">
		  <div class="inner-container">
			<div class="box">
			<form action="" method="post">
			  <h1>Macroul</h1>
			  
				<input name="Email" placeholder="Email@something.com" type="text">
				<input name="password" placeholder="**********" type="password">
				
				  <button>Logare</button>
					<div style="text-align:center"><a href="/exe/Macroul.zip">Descarca</a></div>​
					<div style="text-align:center"><a href="/exe">Surse</a></div>​

				</form>
			</div>
		  </div>
		</div>
		<?php
		}
		else
		{
			//phpinfo();
			// echo var_dump($_POST); 
			// echo var_dump($_SESSION); 
			
			//$con = mysqli_connect("64.62.211.131","teo2m_mruser","google","teo2m_macroul");
			$con = mysqli_connect("93.188.160.43","u751888225_teo2m","G0jmQXkOoKcG","u751888225_macro");
			if (isset($_SESSION['Macrou'])) //daca trebuie executat un macrou + anunt
			{
				//mysqli_query($con, "INSERT INTO activator (MacrouID,Type,Data,NrTimes) VALUES (". $_POST['Macrou'] . ",5,'',1)" );
				mysqli_query($con, $_SESSION['Macrou']);//EVENTUAL SA VERIFIC DACA MACROUL DE TRE SA IL PUN E A LU UID
			    echo '<p>Macroul'.$_SESSION['MacrouNume'].' o sa fie executat acum</p><br>';
				
				unset($_SESSION['Macrou']);
				unset($_SESSION['MacrouNume']);
			}
			if(!isset($_SESSION["UID"]))
			{
				$pass="";
				for($a=0;$a<strlen($_POST['password']);$a++)
					$pass.= ord($_POST['password'][$a]);
				$q = "select ID from users where Email= '" . addslashes($_POST['Email']) . "' and Password='" . addslashes($pass) . "'";
				// echo '\n';
				// echo $q;
				// echo '\n';
				$result = mysqli_query($con,$q);
				if($result && $result->num_rows>0)//logat
					$_SESSION["UID"]=$result->fetch_assoc()['ID'];
					
				//echo $result->num_rows;
				//$_SESSION["GrupuriCalculatoare"]="Toate calculatoarele";
			}
			
			//echo var_dump($_SESSION); 
			if(isset($_SESSION["UID"]))
			{
				echo '<script>
				function func(nume)
				{
					$.ajax(
					{
						url: "printscreen.php",
						type:\'POST\',
						data:
						{
							NumeCalculator: nume
						},
						success: function(msg)
						{
							window.location = "printscreen.php";
						}               
					}
					);
				}
				
				
				
				
				</script>';
				echo '<div class="vid-container">';
				  echo '<img class="bgvid back" src="res/background.jpg">';
				  echo '<div class="inner-container">';
					echo '<div class="box">';
					
					  //aici ne uitam dupa meniuri
					  ///Meniu preferat
					  if(!isset($_SESSION["MP"]))///daca nu exista deja meniu principal selectat
					  {
						  $MP="select Nume from meniupreferat where UserID=".$_SESSION["UID"];
						  $RMP = mysqli_query($con,$MP);
						  if($RMP && $RMP->num_rows==1)
							  $_SESSION["MP"]=$RMP->fetch_assoc()["Nume"];
					  }
					  if(isset($_POST["Meniuri"]))
					  {
						  $_SESSION["MP"]=$_POST["Meniuri"];
					  }
					  if(isset($_SESSION["MP"]))//daca e setat, il afisam
					  {
						  $Que = "SELECT Nume,COALESCE((SELECT Nume from macrou WHERE ID=M1),'-') M1,COALESCE((SELECT Nume from macrou WHERE ID=M2),'-') M2,COALESCE((SELECT Nume from macrou WHERE ID=M3),'-') M3,COALESCE((SELECT Nume from macrou WHERE ID=M4),'-') M4,COALESCE((SELECT Nume from macrou WHERE ID=M5),'-') M5,COALESCE((SELECT Nume from macrou WHERE ID=M6),'-') M6,COALESCE((SELECT Nume from macrou WHERE ID=M7),'-') M7,COALESCE((SELECT Nume from macrou WHERE ID=M8),'-') M8,COALESCE((SELECT Nume from macrou WHERE ID=M9),'-') M9 from meniuri where UserID=".$_SESSION["UID"]." and Nume='".addslashes($_SESSION["MP"])."'";
						  $Meniu = mysqli_query($con,$Que)->fetch_assoc();
						  if($Meniu)
						  {
							  //echo $Que;
							  $_SESSION["N1"]=$Meniu["M1"];
							  $_SESSION["N2"]=$Meniu["M2"];
							  $_SESSION["N3"]=$Meniu["M3"];
							  $_SESSION["N4"]=$Meniu["M4"];
							  $_SESSION["N5"]=$Meniu["M5"];
							  $_SESSION["N6"]=$Meniu["M6"];
							  $_SESSION["N7"]=$Meniu["M7"];
							  $_SESSION["N8"]=$Meniu["M8"];
							  $_SESSION["N9"]=$Meniu["M9"];
							  
							  echo '<h1>'.$Meniu["Nume"].'</h1>';
							  echo '<button onclick="Click9(1)" style="float:left;width:30%;margin:1.5%;">'.$_SESSION["N1"].'</button>';
							  echo '<button onclick="Click9(2)" style="float:left;width:30%;margin:1.5%;">'.$_SESSION["N2"].'</button>';
							  echo '<button onclick="Click9(3)" style="float:left;width:30%;margin:1.5%;">'.$_SESSION["N3"].'</button>';
							  echo '<button onclick="Click9(4)" style="float:left;width:30%;margin:1.5%;">'.$_SESSION["N4"].'</button>';
							  echo '<button onclick="Click9(5)" style="float:left;width:30%;margin:1.5%;">'.$_SESSION["N5"].'</button>';
							  echo '<button onclick="Click9(6)" style="float:left;width:30%;margin:1.5%;">'.$_SESSION["N6"].'</button>';
							  echo '<button onclick="Click9(7)" style="float:left;width:30%;margin:1.5%;">'.$_SESSION["N7"].'</button>';
							  echo '<button onclick="Click9(8)" style="float:left;width:30%;margin:1.5%;">'.$_SESSION["N8"].'</button>';
							  echo '<button onclick="Click9(9)" style="float:left;width:30%;margin:1.5%;">'.$_SESSION["N9"].'</button>';
							  
							  
							  $Que = "SELECT `Nume`, `M1`, `M2`, `M3`, `M4`, `M5`, `M6`, `M7`, `M8`, `M9` from meniuri where UserID=".$_SESSION["UID"]." and Nume='".addslashes($_SESSION["MP"])."'";
							  $Meniu = mysqli_query($con,$Que)->fetch_assoc();
							  
							  $_SESSION["M1"]=$Meniu["M1"];
							  $_SESSION["M2"]=$Meniu["M2"];
							  $_SESSION["M3"]=$Meniu["M3"];
							  $_SESSION["M4"]=$Meniu["M4"];
							  $_SESSION["M5"]=$Meniu["M5"];
							  $_SESSION["M6"]=$Meniu["M6"];
							  $_SESSION["M7"]=$Meniu["M7"];
							  $_SESSION["M8"]=$Meniu["M8"];
							  $_SESSION["M9"]=$Meniu["M9"];
						  }
					  }
					  ///daca exista si alte meniuri
					  {
						  $q = "select Nume from meniuri where UserID=".$_SESSION["UID"];
						  $result = mysqli_query($con,$q);
						  if($result && $result->num_rows>0)
						  {
							  
						   //echo '<h1>Alte meniuri</h1>';
						   echo '<form action="" method="post">';
						   echo '<div class="styled-select black rounded" style="align:center;text-align:center;margin:auto;">';
								  echo '<select onchange="javascript: form.submit();" name="Meniuri">';
								  echo "<option selected value=''>Alege alt meniu</option>";
								  while($row = $result->fetch_assoc())
									  echo "<option value='".$row['Nume']."'>".$row['Nume']."</option>";
								  echo '</select>';
							 echo '</div>';
						  //echo '<button>Schimba meniu</button>';
						  echo '</form>';
						  }
					  }
					  
					  ///select ca sa vedem ce activam
					  echo '<h1>Ce sa se activeze</h1>';
					  echo '<form action="" method="post">';
					  echo '<div class="styled-select black rounded" style="align:center;text-align:center;margin:auto;">';
							  echo '<select onchange="javascript: form.submit();" name="Activator">';
							  echo "<option selected value=''> </option>";
							  echo "<option value='Toate'>Toate</option>";
							  echo "<option value='Grupuri'>Grupuri</option>";
							  echo "<option value='Calculatoare'>Calculatoare</option>";
							  echo '</select>';
						 echo '</div>';
					  echo '</form>';
					  
					  if(!isset($_SESSION["Activator"]))
						$_SESSION["Activator"]='Grupuri';
					  
					  if(isset($_POST["Activator"]))
						  $_SESSION["Activator"]=$_POST["Activator"];
					  if(isset($_SESSION["Activator"]))
						  echo '<h1>'.$_SESSION["Activator"].'</h1><br>';
					  if(isset($_SESSION["Activator"]))
					  {
						  if($_SESSION["Activator"]=='Grupuri')
						  {
							  $q = "select Nume from grupuri where UserID=".$_SESSION["UID"];
							  $result = mysqli_query($con,$q);
							  if($result && $result->num_rows>0)
							  {
								  $pp=1;
								  while($row = $result->fetch_assoc())
								  {
									  echo '<input id="c'.$pp.'" style="margin-left:5%;" type="checkbox" value="'.$row['Nume'].'"><label for="c'.$pp.'" style="vertical-align: middle;  white-space: nowrap;width: 80%; overflow: hidden;text-overflow: ellipsis; display: inline-block;">   '.$row['Nume'].'</label><br>';
									  $pp++;
								  }
							  }
						  }
						  if($_SESSION["Activator"]=='Calculatoare')
						  {
							  $q = "select Nume from calculatoare where UserID=".$_SESSION["UID"];
							  $result = mysqli_query($con,$q);
							  if($result && $result->num_rows>0)
							  {
								  $pp=1;
								  while($row = $result->fetch_assoc())
								  {
									  echo '<input id="c'.$pp.'" style="display:inline;" margin-left:5%;" type="checkbox" value="'.$row['Nume'].'">
									  <label for="c'.$pp.'" style="vertical-align: middle;  white-space: nowrap;width: 80%; overflow: hidden;text-overflow: ellipsis; display: inline-block;">   '.$row['Nume'].'</label>
									  <input onclick="func(\''.addslashes($row['Nume']).'\')" style="display:inline;" type="submit" value="Vezi">
									  <br>';
									  //echo '<input id="c'.$pp.'" style="display:inline;" margin-left:5%;" type="checkbox" value="'.$row['Nume'].'"><label for="c'.$pp.'" style="vertical-align: middle;  white-space: nowrap;width: 80%; overflow: hidden;text-overflow: ellipsis; display: inline-block;">   '.$row['Nume'].'</label><form style="display:inline;" action="/printscreen.php" method="post"><input type="hidden" value="'.$row['Nume'].'" name="NumeCalculator" /><input type="submit" value="Vezi"></form><br>';
									  $pp++;
								  }
							  }
						  }
					  }
					  
					  
					  
					  ///select ca sa vedem ce activam
					  echo '<h1>Ce Macrou</h1>';
					  {
						  echo '<div class="styled-select black rounded" style="align:center;text-align:center;margin:auto;">';
						  echo '<select name="Macrou" id="ListaMacrou">';
							  $query = "SELECT concat(Nume,' - ',Descriere) A, ID B FROM `macrou` WHERE UserID = ".$_SESSION["UID"];
							$res = mysqli_query($con,$query);
							while($row = $res->fetch_assoc())                                            
							   echo "<option value='".$row['B']."'>".$row['A']."</option>";
						  echo '</select></div><br><br>
						  <h1>Cod macrou</h1>
						  <textarea style="margin-left: 5%;margin-right: 5%;width: 90%;resize: none;" id="codMacrou" placeholder="Poti sa scrii aici cod macrou, lasa liber daca doar vrei sa activezi un macrou" rows="4" cols="50"></textarea>
						  <br>
						  <br>
						  <button onclick="Click9(0)" >Porneste</button>
						  <br>
						  <br>
						  <button onclick="LogOut()" >Iesire</button>';
					  }
					  
					  
					  
					echo '</div>';
				  echo '</div>';
				echo '</div>';
			}
			mysqli_close($con);
		}
		?>
		
</body>
</html>


