<?PHP

session_start();

$name = "";
$surname = "";
$birthday = "";
$mail = "";
$ok = 0;

if (file_exists("../profil") && file_exists("../profil/profil"))
{
	$login = $_SESSION["loggued_on_user"];
	if (($string = file_get_contents("../profil/profil")) == false)
	{
		header("Location: errata.html");
		return ;
	}
	$data = unserialize($string);
	foreach ($data as $elem)
	{
		if ($elem['login'] == $login)
		{
			$name = $elem['nom'];
			$surname = $elem['surname'];
			$birthday = $elem['birthday'];
			$mail = $elem['mail'];
			$ok = 1;
		}
	}
	if ($ok == 0)
	{
		header("Location: modif_profil.php");
		 return ;
	}
}
else
{
	 header("Location: modif_profil.php");
	 return ;
}
?>


<html>
<head>
	<meta charset="UTF-8">
	<title>Warhammer 2D</title>
	<link rel="stylesheet" type="text/css" href="profil.css">
</head>
<body>
	<div>
		<form method="POST">
			<p>Nom: <?php echo $name ?>
				<br />Prénom: <?php echo $surname ?>
				<br />Date de naissance: <?php echo $birthday ?>
				<br />E-mail: <?php echo $mail ?>
			</p>
		</form>
		<p><a href="modif_profil.php">Changer informations</a></p>
		<p><a href="login2.php">Retourner au menu</a></p>
	</div>
</body>
</html>