<?php

include("auth.php");

session_start();

$login 		= $_POST['login'];
$passwd 	= $_POST['passwd'];

if (($login == "" || $passwd == "" || auth($login, $passwd) == FALSE))
{
	$_SESSION["loggued_on_user"] = "";
	header("Location: errata.html");
	return ;
}
else
	$_SESSION["loggued_on_user"] = $login;
?>

<html>
	<head>
		<meta charset="UTF-8">
		<title>Warhammer2D</title>
		<link rel="stylesheet" type="text/css" href="css/login.css">
	</head>
	<body>
		<h1>Warhammer 2D</h1>
		<h2>Bienvenue <?php echo $login ?></h2>
		<ul>
			 <li><a href="select.php">Jouer</a></li>
			 <li><a href="profil.php">Mon profil</a></li>
 			 <li><a href="chatter.php">Chat</a></li>
		</ul>
		<p id="logout"><a id="deco" href="logout.php">Se déconnecter</a>
	</body>
</html>
