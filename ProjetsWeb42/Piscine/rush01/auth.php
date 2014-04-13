<?php

function 	auth($login, $passwd)
{
	$h_passwd 	= hash("Whirlpool", $passwd);

	if (file_exists("../private") === FALSE)
		return (FALSE);
	if (($string = @file_get_contents("../private/passwd")) === FALSE)
		return (FALSE);
	$data = unserialize($string);
	foreach ($data as $compte)
	{
		if ($compte['login'] === $login && $compte['passwd'] === $h_passwd)
			return (TRUE);
	}
	return (FALSE);	
}