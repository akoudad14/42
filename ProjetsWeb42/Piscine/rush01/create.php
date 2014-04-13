<?PHP

if ($_POST['login'] == "" || $_POST['passwd'] == "")
{
	header("Location: errata.html");
	return ;
}
$login = $_POST['login'];
$passwd = hash("Whirlpool", $_POST['passwd']);
$compte = array("login" => $login, "passwd" => $passwd);
if (file_exists("../private") == FALSE)
{
	mkdir("../private");
	$data = array();
}
else if (file_exists("../private/passwd") == FALSE)
	$data = array();
else
{
	if (($string = file_get_contents("../private/passwd")) === FALSE)
	{
		header("Location: errata.html");
		return ;
	}
	$data = unserialize($string);
	foreach ($data as $elem)
	{
		if ($elem['login'] === $compte['login'])
		{
			header("Location: errata.html");
			return ;
		}
	}
}
$data[] = $compte;
if (file_put_contents("../private/passwd", serialize($data)) === FALSE)
	header("Location: errata.html");
echo "OK\n";
header("Location: index.html");

?>