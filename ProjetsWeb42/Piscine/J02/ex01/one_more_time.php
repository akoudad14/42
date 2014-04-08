#!/usr/bin/php
<?PHP

function 		month_in_english($mois)
{
	$month = "";

	if (preg_match('#^([Jj]anvier)$#', $mois) == TRUE)
		$month = "January ";
	else if (preg_match('#^([Ff][eé]vrier)$#', $mois) == TRUE)
		$month = "February ";
	else if (preg_match('#^([Mm]ars)$#', $mois) == TRUE)
		$month = "March ";
	else if (preg_match('#^([Aa]vril)$#', $mois) == TRUE)
		$month = "April ";
	else if (preg_match('#^([Mm]ai)$#', $mois) == TRUE)
		$month = "May ";
	else if (preg_match('#^([Jj]uin)$#', $mois) == TRUE)
		$month = "June ";
	else if (preg_match('#^([Jj]uillet)$#', $mois) == TRUE)
		$month = "July ";
	else if (preg_match('#^([Aa]o[uû]t)$#', $mois) == TRUE)
		$month = "August ";
	else if (preg_match('#^([Ss]eptembre)$#', $mois) == TRUE)
		$month = "September ";
	else if (preg_match('#^([Oo]ctobre)$#', $mois) == TRUE)
		$month = "October ";
	else if (preg_match('#^([Nn]ovembre)$#', $mois) == TRUE)
		$month = "November ";
	else if (preg_match('#^([Dd][eé]cembre)$#', $mois) == TRUE)
		$month = "December ";
	return ($month);
}

function 		print_good_time($time, $hms)
{
	$h_m_s	= explode(":", $hms);
	$time 	= $time + intval($h_m_s[0]) * 60 * 60 +	intval($h_m_s[1]) * 60 + intval($h_m_s[2]);
	return ($time);
}

$i 			= 0;
$date		= "";
$time		= 0;
$day		= "";
$pattern	= "/^([Ll]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi|[Dd]imanche)$/";

if ($argc == 1)
	return ;
date_default_timezone_set('Europe/Paris');
$tab = explode(" ", $argv[1]);
if (count($tab) != 5 || preg_match($pattern, $tab[0]) == FALSE)
	return (print("Wrong Format\n"));
$date = $tab[1]." ";
$date = $date.month_in_english($tab[2]);
$date = $date.$tab[3];
$time = strtotime($date);
if ($time === FALSE)
	return (print("Wrong Format\n"));
print(print_good_time($time, $tab[4])."\n");
?>