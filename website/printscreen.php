<?php

if ( ! session_id() ) @ session_start();

header("Cache-Control: no-store, no-cache, must-revalidate, max-age=0");
header("Cache-Control: post-check=0, pre-check=0", false);
header("Pragma: no-cache");


echo '<html>';
echo '    <head>';
echo '        <meta charset="utf-8">  ';    
echo '        <title>Macroul</title>';
		echo '<link rel="icon" href="res/macrou.ico">';
		echo "<script src='http://cdnjs.cloudflare.com/ajax/libs/jquery/2.1.3/jquery.min.js'></script>";
		echo '<script src="https://code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.js"></script>';
		echo '<script src="js/index.js"></script>';
    echo '</head>';
echo '<body id="baudy" style="margin: 0px;">';


	
	if(isset($_POST['NumeCalculator']))
		$_SESSION['NumeCalculator']=$_POST['NumeCalculator'];
echo '<div oncontextmenu="MOA(0);return false;">';
//echo '<img id="audi" style="width:100vw;height:100vh;" src="printscreens/'.$_SESSION["UID"].'_'.$_SESSION['NumeCalculator'].'.jpg"  />';

			
			//$con = mysqli_connect("64.62.211.131","teo2m_mruser","google","teo2m_macroul");
			$con = mysqli_connect("93.188.160.43","u751888225_teo2m","G0jmQXkOoKcG","u751888225_macro");
			$sql = "SELECT `Poza` FROM `teamviewer` WHERE UserID_Nume='".$_SESSION["UID"].'_'.$_SESSION['NumeCalculator']."'";
			
			//echo $sql;
			
			$result = mysqli_query($con,$sql);
				if($result && $result->num_rows>0)//logat
					$da=$result->fetch_assoc()['Poza'];
				else
					die();
			echo '<img id="audi" style="width:100vw;height:100vh;" src="data:image/jpeg;base64,'.base64_encode( $da).'"/>';
			
			
			
			$useragent=$_SERVER['HTTP_USER_AGENT'];
			if(preg_match('/(android|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i',$useragent)||preg_match('/1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i',substr($useragent,0,4)))
			{
				echo '
				<input id="aidiba" type="text" style="background-color:rgb(150,130,200);height:30px;width:40%;">
				';
			}
	
	
echo '</div></body></html>';


//ssseeeepppppppp
	

?>
<style>

.ui-loader {
  display:none !important;
}

</style>
    <script>

		x=0;
		y=0;
		x0=0;
		y0=0;
		$("body").mousemove(function(e) {
			x0 = e.pageX;
			y0 = e.pageY;
		});
		function poza()
		{
			$.post("ImgAjax.php",function(data){
				  $("#audi").prop("src",data);
				  setTimeout(poza,333);
			 });
		}	
		poza();
		//setInterval(poza,3000);
		function MOA(tip,glo)//mother of all   0=right 1=1 2=double
		{
			if(tip==0)
			{
				x=x0;
				y=y0;
			}
			//alert(tip + " " + xCord / $( document ).width() * 100 + " " yCord / $( document ).height() * 100);
			var xPercent = x/$(window).width();
			
			var elementExists = document.getElementById("aidiba");
			var minus=0;
			if(elementExists!=null)
				minus=30;
		
			var yPercent = y/($(window).height()-minus);
			//  alert("x: "+x+" x%: "+xPercent+"    y:"+y+" y%: "+yPercent);
			//alert(tip + " " + minus + " " + yPercent*100 + " "+ $(window).height());
			
			if(tip==5)
			{
				$.ajax(
				{
					url: "TV.php",
					type:'POST',
					data:
					{
						t: tip,
						x: glo
					},
					success: function(msg)
					{
					}               
				});
			}
			else
			{
				if(tip==3 || tip==4)//key
				{
					//console.log("da "+tip);
					$.ajax(
					{
						url: "TV.php",
						type:'POST',
						data:
						{
							t: tip,
							x: glo
						},
						success: function(msg)
						{
						}               
					});
				}
				else//mouse      ana aararearebcuaiosaidoasjiodsjaiojdasiojdiasjiodsaiojiodsadjsa
				{
					//alert("click: ");
					console.log("nu "+tip);
					$.ajax(
					{
						url: "TV.php",
						type:'POST',
						data:
						{
							t: tip,
							x: xPercent,
							y: yPercent
						},
						success: function(msg)
						{
						}               
					});
				}
			}
		}
		
		if(document.getElementById("aidiba")!=null)
		{
			$("#aidiba").on('keyup', function (e) {
				if (e.keyCode == 13) {
					var glo=document.getElementById("aidiba").value;
					if(glo=="")
					{
						MOA(3,13);
						MOA(4,13);
					}
					else
					{
						MOA(5,glo);
						document.getElementById("aidiba").value="";
					}
					//alert("DA");
				}
			});
		}


		var makeDoubleClick = function(e) {
		  var clicks = 0,
			  timeout;

		  return function (e) {
			  x = e.pageX;
			  y = e.pageY;
			  
			
			clicks++;
			if (clicks == 1) {
			  timeout = setTimeout(function () {
				MOA(1);
				clicks = 0;
			  }, 222);
			} else {
			  clearTimeout(timeout);
			  MOA(2);
			  clicks = 0;
			}
		  };
		}
		function keyprs1(e)
		{
			//alert("ai apasat: "+(e.keyCode || e.which));
			var glo=e.keyCode;
			MOA(3,glo);
			//console.log("Pressed: "+e.keyCode);
		}
		function keyprs2(e)
		{
			//alert("ai releisuit: "+e.keyCode);
			var glo=e.keyCode;
			MOA(4,glo);
			//console.log(e.keyCode);
		}
		

		if(document.getElementById("aidiba")!=null)///telefon
		{
			document.getElementById('audi').addEventListener('click', makeDoubleClick(), false);
			document.getElementById('audi').addEventListener('vclick', makeDoubleClick(), false);

		}
		else
		{
			///anna aare o bbanabananaoana
			document.getElementById('baudy').addEventListener('click', makeDoubleClick(), false);
			document.getElementById('baudy').addEventListener('vclick', makeDoubleClick(), false);
			document.getElementById('baudy').addEventListener("keydown", keyprs1, false);
			document.getElementById('baudy').addEventListener("keyup", keyprs2, false);
		}
		///a
    </script>
	