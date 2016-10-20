library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity Sub is
port (
		a, b: IN std_logic_vector (31 downto 0);
		c: OUT std_logic_vector (31 downto 0));
end entity;

architecture comportamento of Sub is
begin
	c <= a - b;
end comportamento;