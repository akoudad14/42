<?php

include("auth.php");

session_start();

$login 		= $_POST['login'];
$passwd 	= $_POST['passwd'];

if (auth($login, $passwd) == FALSE)
{
	$_SESSION["loggued_on_user"] = "";
	exit("ERROR\n");
}
else
	$_SESSION["loggued_on_user"] = $login;

?>

<html>
	<head>
		<meta charset="UTF-8">
		<title>Chat</title>
		<style>
			h1
			{
			/*	border: 1px black solid;*/
				background-color: #FFFACD;
				color: #F4A460;
				width: 100px;
				text-align: center;
				margin-left: 500px;
			}
		</style>
	</head>
	<body bgcolor="#FFFFE0">
		<h1 >CHAT</h1>
		<div bgcolor="#F4A460">
    		<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe>
    		<iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>
		</div>
	</body>
</html>
