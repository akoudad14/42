#!/usr/bin/php
<?PHP

$string	= file_get_contents($argv[1]);
$i 		= 0;
$tmp	= "";
$len	= strlen($string);

while ($i < $len)
{
	$tmp = $string[$i].$string[$i + 1];
	if (strcmp($tmp, "<a") == 0)
	{
		$i = $i + 2;
		while (strcmp($tmp, "a>") != 0)
		{
			$string[$i] = strtoupper($string[$i]);
			++$i;
			$tmp = $string[$i].$string[$i + 1];
		}
		$i = $i + 2;;
	}
	else
		++$i;
}
print($string);
?>