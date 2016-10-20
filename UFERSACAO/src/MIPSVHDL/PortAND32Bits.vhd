LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_signed.all;

-- sem hierarquia
ENTITY PortAND32Bits IS
PORT (
		a, b : IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		Cout : OUT STD_LOGIC);
END PortAND32Bits;

ARCHITECTURE arqPortAND32Bits OF PortAND32Bits IS
	SIGNAL c : STD_LOGIC_VECTOR (31 DOWNTO 1);
BEGIN
	c(1) <= (a(0) AND b(0));
	c(2) <= (a(1) AND b(1)) AND (a(1) AND c(1));
	c(3) <= (a(2) AND b(2)) AND (a(2) AND c(2));
	c(4) <= (a(3) AND b(3)) AND (a(3) AND c(3));
	c(5) <= (a(4) AND b(4)) AND (a(4) AND c(4));
	c(6) <= (a(5) AND b(5)) AND (a(5) AND c(5));
	c(7) <= (a(6) AND b(6)) AND (a(6) AND c(6));
	c(8) <= (a(7) AND b(7)) AND (a(7) AND c(7));
	c(9) <= (a(8) AND b(8)) AND (a(8) AND c(8));
	c(10) <= (a(9) AND b(9)) AND (a(9) AND c(9));
	c(11) <= (a(10) AND b(10)) AND (a(10) AND c(10));
	c(12) <= (a(11) AND b(11)) AND (a(11) AND c(11));
	c(13) <= (a(12) AND b(12)) AND (a(12) AND c(12));
	c(14) <= (a(13) AND b(13)) AND (a(13) AND c(13));
	c(15) <= (a(14) AND b(14)) AND (a(14) AND c(14));
	c(16) <= (a(15) AND b(15)) AND (a(15) AND c(15));
	c(17) <= (a(16) AND b(16)) AND (a(16) AND c(16));
	c(18) <= (a(17) AND b(17)) AND (a(17) AND c(17));
	c(19) <= (a(18) AND b(18)) AND (a(18) AND c(18));
	c(20) <= (a(19) AND b(19)) AND (a(19) AND c(19));
	c(21) <= (a(20) AND b(20)) AND (a(20) AND c(20));
	c(22) <= (a(21) AND b(21)) AND (a(21) AND c(21));
	c(23) <= (a(22) AND b(22)) AND (a(22) AND c(22));
	c(24) <= (a(23) AND b(23)) AND (a(23) AND c(23));
	c(25) <= (a(24) AND b(24)) AND (a(24) AND c(24));
	c(26) <= (a(25) AND b(25)) AND (a(25) AND c(25));
	c(27) <= (a(26) AND b(26)) AND (a(26) AND c(26));
	c(28) <= (a(27) AND b(27)) AND (a(27) AND c(27));
	c(29) <= (a(28) AND b(28)) AND (a(28) AND c(28));
	c(30) <= (a(29) AND b(29)) AND (a(29) AND c(29));
	c(31) <= (a(30) AND b(30)) AND (a(30) AND c(30));
	Cout <= (a(31) AND b(31)) AND (a(31) AND c(31));
END arqPortAND32Bits;
