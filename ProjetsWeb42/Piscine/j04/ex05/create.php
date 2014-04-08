<?PHP

$submit = $_POST['submit'];

if ($submit !== 'OK' || $_POST['login'] === "" || $_POST['passwd'] === "")
	return (print("ERROR\n"));
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
		return (print("ERROR\n"));
	$data = unserialize($string);
	foreach ($data as $elem)
	{
		if ($elem['login'] === $compte['login'])
			return (print("ERROR\n"));
	}
}
$data[] = $compte;
if (file_put_contents("../private/passwd", serialize($data)) === FALSE)
	return (print("ERROR\n"));
echo "OK\n";
header("Location: index.html");

?>