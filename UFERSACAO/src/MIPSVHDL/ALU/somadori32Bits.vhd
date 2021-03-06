library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity somadori32Bits is
port (
		a: IN std_logic_vector (31 downto 0);
		c: OUT std_logic_vector (31 downto 0));
end entity;

architecture comportamento of somadori32Bits is
CONSTANT z : std_logic_vector (31 downto 0) := "00000000000000000000000000000000";
begin
	c <= a + z;
end comportamento;