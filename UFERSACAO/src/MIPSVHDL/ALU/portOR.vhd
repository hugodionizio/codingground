library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;


entity portOR is 
--porta or de duas entradas
port (a, b: IN std_logic_vector (31 downto 0);
		 c: OUT std_logic_vector (31 downto 0));
end portOR;

architecture behavior of portOR is
begin
	c <= a OR b;
end behavior;

