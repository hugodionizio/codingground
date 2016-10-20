LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_signed.all;

-- com hierarquia
ENTITY somador32Bits IS
PORT (
		c0 : IN STD_LOGIC;
		a, b : IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		s : OUT STD_LOGIC_VECTOR (31 DOWNTO 0);
		c32 : OUT STD_LOGIC);
END somador32Bits;

ARCHITECTURE comportamento OF somador32Bits IS
	SIGNAL c : STD_LOGIC_VECTOR (31 DOWNTO 1);
	COMPONENT somador
		PORT (cin, a, b : IN STD_LOGIC;
				s, cout : OUT STD_LOGIC);
	END COMPONENT;
BEGIN
	SC0: somador PORT MAP (c0, a(0), b(0), s(0), c(1));
	SC1: somador PORT MAP (c(1), a(1), b(1), s(1), c(2));
	SC2: somador PORT MAP (c(2), a(2), b(2), s(2), c(3));
	SC3: somador PORT MAP (c(3), a(3), b(3), s(3), c(4));
	SC4: somador PORT MAP (c(4), a(4), b(4), s(4), c(5));
	SC5: somador PORT MAP (c(5), a(5), b(5), s(5), c(6));
	SC6: somador PORT MAP (c(6), a(6), b(6), s(6), c(7));
	SC7: somador PORT MAP (c(7), a(7), b(7), s(7), c(8));
	SC8: somador PORT MAP (c(8), a(8), b(8), s(8), c(9));
	SC9: somador PORT MAP (c(9), a(9), b(9), s(9), c(10));
	SC10: somador PORT MAP (c(10), a(10), b(10), s(10), c(11));
	SC11: somador PORT MAP (c(11), a(11), b(11), s(11), c(12));
	SC12: somador PORT MAP (c(12), a(12), b(12), s(12), c(13));
	SC13: somador PORT MAP (c(13), a(13), b(13), s(13), c(14));
	SC14: somador PORT MAP (c(14), a(14), b(14), s(14), c(15));
	SC15: somador PORT MAP (c(15), a(15), b(15), s(15), c(16));
	SC16: somador PORT MAP (c(16), a(16), b(16), s(16), c(17));
	SC17: somador PORT MAP (c(17), a(17), b(17), s(17), c(18));
	SC18: somador PORT MAP (c(18), a(18), b(18), s(18), c(19));
	SC19: somador PORT MAP (c(19), a(19), b(19), s(19), c(20));
	SC20: somador PORT MAP (c(20), a(20), b(20), s(20), c(21));
	SC21: somador PORT MAP (c(21), a(21), b(21), s(21), c(22));
	SC22: somador PORT MAP (c(22), a(22), b(22), s(22), c(23));
	SC23: somador PORT MAP (c(23), a(23), b(23), s(23), c(24));
	SC24: somador PORT MAP (c(24), a(24), b(24), s(24), c(25));
	SC25: somador PORT MAP (c(25), a(25), b(25), s(25), c(26));
	SC26: somador PORT MAP (c(26), a(26), b(26), s(26), c(27));
	SC27: somador PORT MAP (c(27), a(27), b(27), s(27), c(28));
	SC28: somador PORT MAP (c(28), a(28), b(28), s(28), c(29));
	SC29: somador PORT MAP (c(29), a(29), b(29), s(29), c(30));
	SC30: somador PORT MAP (c(30), a(30), b(30), s(30), c(31));	
	SC31: somador PORT MAP (c(31), a(31), b(31), s(31), c32);
END comportamento;