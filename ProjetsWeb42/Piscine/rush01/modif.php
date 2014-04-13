<?PHP

$submit = $_POST['submit'];
$i 		= 0;
$compte	= array();
$ok 	= 0;

if ($_POST['login'] === "" || $_POST['oldpw'] === "" || $_POST['newpw'] === "")
{
	header("Location: errata.html");
	return ;
}
$login = $_POST['login'];
$oldpw = hash("Whirlpool", $_POST['oldpw']);
$newpw = hash("Whirlpool", $_POST['newpw']);
if (($string = @file_get_contents("../private/passwd")) === FALSE)
{
	header("Location: errata.html");
	return ;
}
$data = unserialize($string);
while (isset($data[$i]))
{
	$compte = $data[$i];
	if ($compte['login'] === $login && $compte['passwd'] === $oldpw)
	{
		$ok = 1;
		break ;
	}
	++$i;
}
if ($ok == 0)
	return (print("ERROR\n"));
$data[$i]['passwd'] = $newpw;
if (file_put_contents("../private/passwd", serialize($data)) === FALSE)
{
	header("Location: errata.html");
	return ;
}
echo "OK\n";
header("Location: index.html");

?>