<?php

interface IVaisseau
{
	function get_name();
	function get_size();
	function get_sprite();
	function get_pc(); /* bp is used for body point*/
	function get_pp();
	function get_speed();
	function get_maneuv();
	function get_shield();
	function get_weapon();
	function set_name();
	function set_size();
	function set_pc();
	function set_pp();
	function set_speed();
	function set_maneuvre();
	function set_weapon();
}

?>
