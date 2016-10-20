library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;


entity portNOR is 
--porta or de duas entradas
port (a, b: IN std_logic_vector (31 downto 0);
		 c: OUT std_logic_vector (31 downto 0));
end portNOR;

architecture behavior of portNOR is
begin
	c <= a NOR b;
end behavior;

