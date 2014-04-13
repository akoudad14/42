<?PHP

Class Jaime {

	public function sleepWith($obj) {

	$name = get_class($obj);
	if ($name === "Tyrion")
		print ("Not even if I'm drunk !\n");
	else if ($name === "Sansa")
		print ("Let's do this.\n");
	else if ($name === "Cersei")
		print ("With pleasure, but only in a tower in Winterfell, then.\n");
	}
}

?>