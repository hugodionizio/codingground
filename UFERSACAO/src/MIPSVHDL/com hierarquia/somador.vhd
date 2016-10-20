LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY somador IS
PORT (cin, a, b : IN STD_LOGIC;
		s, cout : OUT STD_LOGIC);
END somador;

ARCHITECTURE comportamento OF somador IS
BEGIN
	s <= a XOR b XOR cin;
	cout <= (a AND b) OR (a AND cin) OR (b AND cin);
END comportamento;