<?PHP

session_start();

echo "<html><body>\n";
echo "<form action=\"index.php\" method=\"get\">\n";
echo "   Identifiant: <input type='text' name=\"login\" value=\"";
if (isset($_GET['submit']) && $_GET['submit'] === 'OK' && isset($_GET['login']))
	echo $_GET['login'];
else if (isset($_SESSION['login']))
	echo $_SESSION['login'];
else
	echo "";
echo "\"/>\n";
echo "   <br />\n";
echo "   Mot de passe: <input type=\"password\" name=\"passwd\" value=\"";
if (isset($_GET['submit']) && $_GET['submit'] === 'OK' && isset($_GET['passwd']))
	echo $_GET['passwd'];
else if (isset($_SESSION['passwd']))
	echo $_SESSION['passwd'];
else
	echo "";
echo "\"/>\n";
echo "   <input type=\"submit\" name=\"submit\" value=\"OK\"/>\n";
echo "</form>\n";
echo "</body></html>\n";
if (isset($_GET['submit']) && $_GET['submit'] === 'OK')
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}
?>