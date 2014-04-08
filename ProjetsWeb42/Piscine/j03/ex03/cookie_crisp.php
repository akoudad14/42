<?PHP

if (isset($_GET))
{
	if ($_GET['action'] === "set" && isset($_GET['name']) && isset($_GET['value']))
		setcookie($_GET['name'], $_GET['value'], time() + 3600);
	else if ($_GET['action'] === "get")
	{
		if (isset($_COOKIE) && isset($_COOKIE[$_GET['name']]))
			echo $_COOKIE[$_GET['name']]."\n";
	}
	else if ($_GET['action'] === "del")
		setcookie($_GET['action'], NULL, -1);
}
?>