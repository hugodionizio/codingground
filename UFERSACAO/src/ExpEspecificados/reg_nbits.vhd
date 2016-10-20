LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY reg_nbits IS
GENERIC (N : POSITIVE := 8);
PORT (d : IN STD_LOGIC_VECTOR(N-1 DOWNTO 0);
		clk : IN STD_LOGIC;
		q : OUT STD_LOGIC_VECTOR(N-1 DOWNTO 0));
END reg_nbits;

ARCHITECTURE behavior OF reg_nbits IS
BEGIN
	PROCESS(clk)
	BEGIN
		IF RISING_EDGE(clk) THEN
			q <= d;
		END IF;
	END PROCESS;
END behavior;

