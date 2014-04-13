<?PHP

session_start();

?>

<html>
	<head>
		<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
	</head>
	<body bgcolor="#FFFFF0">
		<form action="speak.php" method="POST">
			Message: <input type="text" name="msg">
		</form>
	</body>
</hmtl>

<?PHP
if (isset($_POST['msg']))
{ 
	$speak = array("login" => $_SESSION["loggued_on_user"], "time" => time(), "msg" => $_POST['msg']);
	if (file_exists("../private") === FALSE)
		mkdir("../private");
	else if (file_exists("../private/chat") === FALSE)
	$data = array();
	else
	{
		$fd = fopen("../private/chat", "r");
		if (flock($fd, LOCK_UN))
			flock($fd, LOCK_SH);
		$string = file_get_contents("../private/chat");
		$data = unserialize($string);
	}
	$data[] = $speak;
	$fd = fopen("../private/chat", "w");
	if (flock($fd, LOCK_UN))
		flock($fd, LOCK_EX);
	file_put_contents("../private/chat", serialize($data));
}
?>