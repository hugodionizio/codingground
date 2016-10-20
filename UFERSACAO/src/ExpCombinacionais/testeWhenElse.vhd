ENTITY testeWhenElse IS
PORT (a, b, c : IN integer;
		z : OUT integer);
END testeWhenElse;

ARCHITECTURE behavior OF testeWhenElse IS
SIGNAL x : integer;
BEGIN
	x <= 3;
	z <= a WHEN (x > 3) ELSE
	     b WHEN (x < 3) ELSE
	     c;
END behavior;

