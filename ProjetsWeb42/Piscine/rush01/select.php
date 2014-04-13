<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>Warhammer 2D</title>
		<link rel="stylesheet" type="text/css" href="css/index.css">
		<style>
			#deco
			{
				color: white;
			}
		</style>
	</head>
	<body>
	<div>
		<h1>Menu</h1>
		<form action="select_vaisseau.php" method="POST">
			<p id="form">Player 1: <input id="ident" type='text' name="login1" value=""/>
				Player 2: <input id="ident" type='text' name="login2" value=""/>
				<br /><input id="submit" type="submit" name="submit" value="Fight"/>
			</p>
		</form>
		<p><a id="deco" href="login2.php">Retourner au menu</a></p>
	</div>
	</body>
</html>
