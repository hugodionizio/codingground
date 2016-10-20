library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity portORI is
--porta or de duas entradas
port (	a, b: IN std_logic_vector (31 downto 0);
		 c: OUT std_logic_vector (31 downto 0));
end portORI;

architecture behavior of portORI is
CONSTANT z : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
begin
	--b(0) <= z(0);
	c <= a OR b OR z;
end behavior;