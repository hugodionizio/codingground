LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_signed.all;

-- sem hierarquia
ENTITY somador4Bits IS
PORT (
		c0 : IN STD_LOGIC;
		a, b : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
		s : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
		c4 : OUT STD_LOGIC);
END somador4Bits;

ARCHITECTURE comportamento OF somador4Bits IS
	SIGNAL c : STD_LOGIC_VECTOR (31 DOWNTO 1);
BEGIN
s(0) <= a(0) XOR b(0) XOR c0;
c(1) <= (a(0) AND b(0)) OR (a(0) AND c0) OR (b(0) AND c0);
s(1) <= a(1) XOR b(1) XOR c(1);
c(2) <= (a(1) AND b(1)) OR (a(1) AND c(1)) OR (b(1) AND c(1));
s(2) <= a(2) XOR b(2) XOR c(2);
c(3) <= (a(2) AND b(2)) OR (a(2) AND c(2)) OR (b(2) AND c(2));
s(3) <= a(3) XOR b(3) XOR c(3);
c4 <= (a(3) AND b(3)) OR (a(3) AND c(3)) OR (b(3) AND c(3));
END comportamento;