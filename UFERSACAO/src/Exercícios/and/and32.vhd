LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY and32 IS
PORT (	a, b : IN STD_LOGIC_VECTOR[31 DOWNTO 0];
	s: OUT STD_LOGIC_VECTOR[31 DOWNTO 0]);
END and32;

ARCHITECTURE behavior OF and32 IS

BEGIN
  s <= a AND b;
END behavior;