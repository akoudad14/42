<?PHP

Class Tyrion {

	public function sleepWith($obj) {

	$name = get_class($obj);
	if ($name === "Jaime" || $name === "Cersei")
		print ("Not even if I'm drunk !\n");
	else if ($name === "Sansa")
		print ("Let's do this.\n");
	}
}