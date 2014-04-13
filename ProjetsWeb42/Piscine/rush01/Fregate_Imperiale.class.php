<?php
session_start();
class Frigate implements IVaisseau
{
	protected $name = $_SESSION['frigate_name'];
	protected $size = "1x4";
	protected $pc = 5;
	protected $pp = 10;
	protected $speed = 15;
	protected $maneuv = 4;
	protected $shield = 0;
	protected $weapon = "";
	
	function set_size($x, $y)
	{
		if (!(is_numeric($x) && is_numeric($y)))
			# code...
		else
		{
			if (intval($x) != 1 || intval($y) > 4)
				# code...
			else
				$size = $x."x".$y." cases";
		}
	}

	function set_pc($x)
	{
		if ($pc == -1)
		{
			if(!is_numeric($x))
				# code...
			elseif (intval($x) > 5)
				# code...
			else
			{
				$pc = intval($x);
			}
		}
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
		{
			if(!is_numeric($x))
				# code...
			elseif (intval($x) > 10)
				# code...
			else
			{
				$pp = intval($x);
			}
		}
		elseif (!is_numeric($x))
			# code...
		elseif (intval($x) > $pp || intval($x) < 0)
			# code...
		else
		{
			$pp = intval($x);
		}
	}

	function set_speed($x)
	{
		if(!is_numeric($x))
			# code...
		elseif (intval($x) > 15)
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
