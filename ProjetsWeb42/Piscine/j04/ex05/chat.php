<?PHP

date_default_timezone_set("Europe/Paris");

if (($string = @file_get_contents("../private/chat")) === FALSE)
	return ;
$tab = unserialize($string);
foreach($tab as $elem)
{
	$login = $elem['login'];
	$time  = $elem['time'];
	$msg   = $elem['msg'];
	$date  = date("c", $time);
	$h_m   = $date[11].$date[12].$date[13].$date[14].$date[15];
	if ($msg != "")
		echo "[$h_m] <b>$login</b>: $msg<br />"."\n";
}

?>