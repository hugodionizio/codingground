library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

ENTITY add1 IS

PORT (
a: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
b: IN STD_LOGIC_VECTOR (31 DOWNTO 0) 
sum, carry: OUT STD_LOGIC_VECTOR (31 DOWNTO 0));

END add1;

ARCHITECTURE behavior OF Add1 IS

BEGIN
    
    sum <= A xor B;
    carry <= A and B;
    
END behavior;