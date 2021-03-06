LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_signed.all;

-- com hierarquia
ENTITY AddPC IS
PORT (
		c0 : IN STD_LOGIC;
		ReadAddress, Out4 : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
		AddPCOut : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
		c4 : OUT STD_LOGIC);
END AddPC;

ARCHITECTURE ArqAddPC OF AddPC IS
	SIGNAL c : STD_LOGIC_VECTOR (3 DOWNTO 1);
	COMPONENT somador
		PORT (cin, a, b : IN STD_LOGIC;
				s, cout : OUT STD_LOGIC);
	END COMPONENT;
BEGIN
	SC0: somador PORT MAP (c0, ReadAddress(0), Out4(0), AddPCOut(0), c(1));
	SC1: somador PORT MAP (c(1), ReadAddress(1), Out4(1), AddPCOut(1), c(2));
	SC2: somador PORT MAP (c(2), ReadAddress(2), Out4(2), AddPCOut(2), c(3));
	SC3: somador PORT MAP (c(3), ReadAddress(3), Out4(3), AddPCOut(3), c4);
END ArqAddPC;