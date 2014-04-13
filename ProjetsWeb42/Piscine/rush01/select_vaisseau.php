<!DOCTYPE html>
<?php
session_start();
?>
<html>
	<head>
		<meta charset="UTF-8">
		<title>Warhammer 2D</title>
		<style>
			#logleft{
			text-align: center;
			float: left;
			height: 500px;
			width: 50%;}
			#logright{
			text-align: center;
			float: left;
			height: 500px;
			width: 50%;}
			#submit{
				float: left;
			}
		</style>
	</head>
	<body>
	<div>
		<h1>Selectionner ses vaisseaux</h1>
		<div id="logleft">
			<form action="map.php" method="POST">
				<p><?php echo $_POST['login1']; ?></p>
				<select id="vaisseau11" name="vaisseau11" value="Vaisseau N1">
					<option>Cuirasse Imperial</option>
					<option>Destroyer Imperial</option>
					<option>Fregate Imperial</option>
					<option>Vesso Attak</option>
				</select>
				<br/>
				<select id="vaisseau12" name="vaisseau12">
					<option>Cuirasse Imperial</option>
					<option>Destroyer Imperial</option>
					<option>Fregate Imperial</option>
					<option>Vesso Attak</option>
				</select>
				<br/>
				<select id="vaisseau13" name="vaisseau13">
					<option>Cuirasse Imperial</option>
					<option>Destroyer Imperial</option>
					<option>Fregate Imperial</option>
					<option>Vesso Attak</option>
				</select>
				<br/>
				<select id="vaisseau14" name="vaisseau14">
					<option>Cuirasse Imperial</option>
					<option>Destroyer Imperial</option>
					<option>Fregate Imperial</option>
					<option>Vesso Attak</option>
				</select>
				</p>
			</form>
		</div>
		<div id="logright">
			<form action="map.php" method="POST">
				<p><?php echo $_POST['login2']; ?></p>
				<select id="vaisseau21" name="vaisseau21">
					<option>Cuirasse Imperial</option>
					<option>Destroyer Imperial</option>
					<option>Fregate Imperial</option>
					<option>Vesso Attak</option>
				</select>
				<br/>
				<select id="vaisseau12" name="vaisseau12">
					<option>Cuirasse Imperial</option>
					<option>Destroyer Imperial</option>
					<option>Fregate Imperial</option>
					<option>Vesso Attak</option>
				</select>
				<br/>
				<select id="vaisseau13" name="vaisseau13">
					<option>Cuirasse Imperial</option>
					<option>Destroyer Imperial</option>
					<option>Fregate Imperial</option>
					<option>Vesso Attak</option>
				</select>
				<br/>
				<select id="vaisseau14" name="vaisseau14">
					<option>Cuirasse Imperial</option>
					<option>Destroyer Imperial</option>
					<option>Fregate Imperial</option>
					<option>Vesso Attak</option>
				</select>
				</p>
				<p>
					<br><input id="submit" type="submit" name="submit" value="Fight"/>
				</p>
			</form>
		</div>
	</div>
	</body>
</html>
