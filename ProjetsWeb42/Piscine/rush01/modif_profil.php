 <?PHP
session_start();

if (isset($_POST['nom']) == false || isset($_POST['prenom']) == false
	|| isset($_POST['naissance']) == false || isset($_POST['e-mail']) == false)
{
	echo "Champ(s) vide(s)\n";
	header("Location: modif_profil.html");
	return ;
}
$profil = array("login" => $_SESSION['loggued_on_user'], "nom" => $_POST['nom'], "surname" => $_POST['prenom'],
				 "birthday" => $_POST['naissance'], "mail" => $_POST["e-mail"]);
if (file_exists("../profil") == FALSE)
{
	mkdir("../profil");
	$data = array();
}
else if (file_exists("../profil/profil") == FALSE)
	$data = array();
else
{
	if (($string = file_get_contents("../profil/profil")) == FALSE)
	{
		header("Location: errata.html");
		return ;
	}
	$data = unserialize($string);
}
$data[] = $profil;
if (file_put_contents("../profil/profil", serialize($data)) == FALSE)
	header("Location: errata.html");
 header("Location: profil.php");

?>