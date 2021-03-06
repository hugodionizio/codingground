LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_signed.all;

-- sem hierarquia
ENTITY somador32Bits IS
PORT (
		c0 : IN STD_LOGIC;
		a, b : IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		s : OUT STD_LOGIC_VECTOR (31 DOWNTO 0);
		c32 : OUT STD_LOGIC);
END somador32Bits;

ARCHITECTURE comportamento OF somador32Bits IS
	SIGNAL c : STD_LOGIC_VECTOR (31 DOWNTO 1);
BEGIN
	s(0) <= a(0) XOR b(0) XOR c0;
	c(1) <= (a(0) AND b(0)) OR (a(0) AND c0) OR (b(0) AND c0);
	s(1) <= a(1) XOR b(1) XOR c(1);
	c(2) <= (a(1) AND b(1)) OR (a(1) AND c(1)) OR (b(1) AND c(1));
	s(2) <= a(2) XOR b(2) XOR c(2);
	c(3) <= (a(2) AND b(2)) OR (a(2) AND c(2)) OR (b(2) AND c(2));
	s(3) <= a(3) XOR b(3) XOR c(3);
	c(4) <= (a(3) AND b(3)) OR (a(3) AND c(3)) OR (b(3) AND c(3));
	s(4) <= a(4) XOR b(4) XOR c(4);
	c(5) <= (a(4) AND b(4)) OR (a(4) AND c(4)) OR (b(4) AND c(4));
	s(5) <= a(5) XOR b(5) XOR c(5);
	c(6) <= (a(5) AND b(5)) OR (a(5) AND c(5)) OR (b(5) AND c(5));
	s(6) <= a(6) XOR b(6) XOR c(6);
	c(7) <= (a(6) AND b(6)) OR (a(6) AND c(6)) OR (b(6) AND c(6));
	s(7) <= a(7) XOR b(7) XOR c(7);
	c(8) <= (a(7) AND b(7)) OR (a(7) AND c(7)) OR (b(7) AND c(7));
	s(8) <= a(8) XOR b(8) XOR c(8);
	c(9) <= (a(8) AND b(8)) OR (a(8) AND c(8)) OR (b(8) AND c(8));
	s(9) <= a(9) XOR b(9) XOR c(9);
	c(10) <= (a(9) AND b(9)) OR (a(9) AND c(9)) OR (b(9) AND c(9));
	s(10) <= a(10) XOR b(10) XOR c(10);
	c(11) <= (a(10) AND b(10)) OR (a(10) AND c(10)) OR (b(10) AND c(10));
	s(11) <= a(11) XOR b(11) XOR c(11);
	c(12) <= (a(11) AND b(11)) OR (a(11) AND c(11)) OR (b(11) AND c(11));
	s(12) <= a(12) XOR b(12) XOR c(12);
	c(13) <= (a(12) AND b(12)) OR (a(12) AND c(12)) OR (b(12) AND c(12));
	s(13) <= a(13) XOR b(13) XOR c(13);
	c(14) <= (a(13) AND b(13)) OR (a(13) AND c(13)) OR (b(13) AND c(13));
	s(14) <= a(14) XOR b(14) XOR c(14);
	c(15) <= (a(14) AND b(14)) OR (a(14) AND c(14)) OR (b(14) AND c(14));
	s(15) <= a(15) XOR b(15) XOR c(15);
	c(16) <= (a(15) AND b(15)) OR (a(15) AND c(15)) OR (b(15) AND c(15));
	s(16) <= a(16) XOR b(16) XOR c(16);
	c(17) <= (a(16) AND b(16)) OR (a(16) AND c(16)) OR (b(16) AND c(16));
	s(17) <= a(17) XOR b(17) XOR c(17);
	c(18) <= (a(17) AND b(17)) OR (a(17) AND c(17)) OR (b(17) AND c(17));
	s(18) <= a(18) XOR b(18) XOR c(18);
	c(19) <= (a(18) AND b(18)) OR (a(18) AND c(18)) OR (b(18) AND c(18));
	s(19) <= a(19) XOR b(19) XOR c(19);
	c(20) <= (a(19) AND b(19)) OR (a(19) AND c(19)) OR (b(19) AND c(19));
	s(20) <= a(20) XOR b(20) XOR c(20);
	c(21) <= (a(20) AND b(20)) OR (a(20) AND c(20)) OR (b(20) AND c(20));
	s(21) <= a(21) XOR b(21) XOR c(21);
	c(22) <= (a(21) AND b(21)) OR (a(21) AND c(21)) OR (b(21) AND c(21));
	s(22) <= a(22) XOR b(22) XOR c(22);
	c(23) <= (a(22) AND b(22)) OR (a(22) AND c(22)) OR (b(22) AND c(22));
	s(23) <= a(23) XOR b(23) XOR c(23);
	c(24) <= (a(23) AND b(23)) OR (a(23) AND c(23)) OR (b(23) AND c(23));
	s(24) <= a(24) XOR b(24) XOR c(24);
	c(25) <= (a(24) AND b(24)) OR (a(24) AND c(24)) OR (b(24) AND c(24));
	s(25) <= a(25) XOR b(25) XOR c(25);
	c(26) <= (a(25) AND b(25)) OR (a(25) AND c(25)) OR (b(25) AND c(25));
	s(26) <= a(26) XOR b(26) XOR c(26);
	c(27) <= (a(26) AND b(26)) OR (a(26) AND c(26)) OR (b(26) AND c(26));
	s(27) <= a(27) XOR b(27) XOR c(27);
	c(28) <= (a(27) AND b(27)) OR (a(27) AND c(27)) OR (b(27) AND c(27));
	s(28) <= a(28) XOR b(28) XOR c(28);
	c(29) <= (a(28) AND b(28)) OR (a(28) AND c(28)) OR (b(28) AND c(28));
	s(29) <= a(29) XOR b(29) XOR c(29);
	c(30) <= (a(29) AND b(29)) OR (a(29) AND c(29)) OR (b(29) AND c(29));
	s(30) <= a(30) XOR b(30) XOR c(30);
	c(31) <= (a(30) AND b(30)) OR (a(30) AND c(30)) OR (b(30) AND c(30));
	s(31) <= a(31) XOR b(31) XOR c(31);
	c32 <= (a(31) AND b(31)) OR (a(31) AND c(31)) OR (b(31) AND c(31));
END comportamento;