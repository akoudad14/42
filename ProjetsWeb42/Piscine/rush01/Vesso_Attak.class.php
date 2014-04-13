<?php

class Vesso implements IVaisseau
{
	protected $name = "";
	protected $size = "1x2";
	protected $pc = 4;
	protected $pp = 10;
	protected $speed = 19;
	protected $maneuv = 3;
	protected $shield = 0;
	protected $weapon = "";

	function set_name($str)
	{
		if (strlen($str) < 10)
			# code...
		else
			$name = $str;
	}

	function set_size($x, $y)
	{
		if (!(is_numeric($x) && is_numeric($y)))
			# code...
		else
		{
			if (intval($x) != 1 || (intval($y) > 3 && intval($y) < 2)
				# code...
			else
				$size = $x."x".$y." cases";
		}
	}

	function set_pc($x)
	{
		if ($pc == -1)
			$pc = 4;
		elseif (!is_numeric($x))
			# code...
		elseif (intval($x) > $pc || intval($x) < 0)
			# code...
		else
		{
			$pc = intval($x);
		}
	}

	function set_pp($x)
	{
		if ($pp == -1)
			$pp = 10;
		elseif (!is_numeric($x))
			# code...
		elseif (intval($x) > $pp || intval($x) < 0)
			# code...
		else
		{
			$pp -= intval($x);
		}
	}

	function set_speed($x)
	{
		if(!is_numeric($x))
			# code...
		elseif (intval($x) > 19)
			# code...
		else
		{
			$bp = intval($x);
		}
	}

	function set_maneuv($x)
	{
		if(!is_numeric($x))
			# code...
		elseif (intval($x) < 4)
			# code...
		else
		{
			$bp = intval($x);
		}
	}

	function set_shield($x)
	{
		$shield += $x;
	}

	function set_weapon($wk)
	{
		$weapon = $wk;
	}
}

?>
