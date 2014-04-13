<?PHP

Class NightsWatch {

	private $_fighter = array();

	public function recruit($obj) {

		if (is_a($obj, 'IFighter'))
			$this->_fighter[] = $obj;
	}

	public function fight() {

		foreach ($this->_fighter as $obj)
			$obj->fight();		
	}
}

?>