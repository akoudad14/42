<?PHP

Class UnholyFactory {

	private $_fighter = array();

	public function absorb($obj) {

		if (is_a($obj, 'Fighter')) {

			foreach ($this->_fighter as $fighter) {
				
				if (array_key_exists($obj->fighter, $fighter))
					return (print("(Factory already absorbed a fighter of type " . $obj->fighter . ")\n"));
			}
			print("(Factory absorbed a fighter of type " . $obj->fighter . ")\n");
			$this->_fighter[] = array($obj->fighter => $obj);
		}
		else
			print("(Factory can't absorb this, it's not a fighter)\n");
	}

	public function fabricate($name) {

		foreach ($this->_fighter as $fighter) {
				
			if (array_key_exists($name, $fighter)) {

				print("(Factory fabricates a fighter of type " . $name . ")\n");
				return $fighter[$name];
			}
		}
		print("(Factory hasn't absorbed any fighter of type " . $name . ")\n");
		return (null);
	}
}


?>