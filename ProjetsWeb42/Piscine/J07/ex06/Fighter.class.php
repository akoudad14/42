<?PHP

abstract Class Fighter {

	public $fighter;

	public function __construct($type) {
		$this->fighter = $type;
	}

	abstract public function fight($name);
}

?>