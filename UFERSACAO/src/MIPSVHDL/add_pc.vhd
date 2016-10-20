library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

ENTITY add_pc IS

PORT (
a: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
b: IN STD_LOGIC_VECTOR (31 DOWNTO 0) := "00000000000000000000000000000100";
sum, carry: OUT STD_LOGIC_VECTOR (31 DOWNTO 0));

END add_pc;

ARCHITECTURE behavior OF Add_PC IS

BEGIN
    
    sum <= A xor B;
    carry <= A and B;
    
END behavior;