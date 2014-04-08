#!/usr/bin/php
<?PHP

$string 	= "";
$pattern	= array("/^[\t ]*/", "/[\t ]+/", "/[\t ]*$/");
$replace	= array("", " ", "");

if ($argc === 1)
	return ;
$string = $argv[1];
$string = preg_replace($pattern, $replace, $string);
echo $string."\n";

?>