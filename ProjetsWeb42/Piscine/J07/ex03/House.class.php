<?PHP

Class House {

	public function introduce() {

		print("House " . $this->getHouseName() . " of " . $this->getHouseSeat() . " : \"" . $this->GetHouseMotto() . "\"\n");
	}
}

?>