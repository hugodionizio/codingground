library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;


entity portANDI is 
--porta or de duas entradas
port (	a, b: IN std_logic_vector (31 downto 0);
		 c: OUT std_logic_vector (31 downto 0));
end portANDI;

architecture behavior of portANDI is
CONSTANT z : STD_LOGIC_VECTOR (31 downto 0) := "11111111111111111111111111111111";
begin
	c <= a AND b AND z;
end behavior;

