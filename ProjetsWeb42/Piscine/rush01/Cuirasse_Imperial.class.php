<?php
session_start();
class Cuirasse implements IVaisseau
{
	protected $name = $_SESSION['cuirasse_name'];
	protected $size = "2x7";
	protected $pc = 8;
	protected $pp = 12;
	protected $speed = 10;
	protected $maneuvre = 5;
	protected $shield = 2;
	protected $weapon = $_SESSION["cuirasse_weapon"];

	function set_size($x, $y)
	{
		if (!(is_numeric($x) && is_numeric($y)))
			# code...ERROR
		else
			$this->size = $x."x".$y;
	}

	function set_pc($x)
	{
		if ($pc == -1)
			$pc = 8;
		else if (!is_numeric($x))
			# code...ERROR
		else if (intval($x) < 1)
			# code... PLUS DE  POINT DE COQUE
		else
			$pc = intval($x);
	}

	function set_pp($x)
	{
		if ($pp == -1)
			$pp = 12;
		else if (!is_numeric($x))
			# code...ERROR
		else if (intval($x) > $pp || intval($x) < 0)
			# code...ERROR
		else
			$pp = intval($x);
	}

	function set_speed($x)
	{
		if(!is_numeric($x))
			# code...ERROR
		else
			$bp = intval($x);
	}

	function set_maneuvre($x)
	{
		if(!is_numeric($x))
			# code..ERROR.
		else
			$bp = intval($x);
	}

	function set_shield($x)
	{
		$this->shield = $x;
	}

	function set_weapon($w)
	{
		$this->weapon = $w;
	}
}

?>
