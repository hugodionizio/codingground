LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_signed.all;

-- sem hierarquia
ENTITY PortAND4Bits IS
PORT (
		a, b : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
		Cout : OUT STD_LOGIC);
END PortAND4Bits;

ARCHITECTURE arqPortAND4Bits OF PortAND4Bits IS
	SIGNAL c : STD_LOGIC_VECTOR (3 DOWNTO 1);
BEGIN
	c(1) <= (a(0) AND b(0));
	c(2) <= (a(1) AND b(1)) AND (a(1) AND c(1));
	c(3) <= (a(2) AND b(2)) AND (a(2) AND c(2));
	Cout <= (a(3) AND b(3)) AND (a(3) AND c(3));
END arqPortAND4Bits;