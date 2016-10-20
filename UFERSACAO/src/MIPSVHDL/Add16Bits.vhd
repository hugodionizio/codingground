LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_signed.all;

ENTITY somador16bits IS
PORT ( a, b : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
s : OUT STD_LOGIC_VECTOR (15 DOWNTO 0));
END somador16bits;

ARCHITECTURE comportamento OF somador16bits IS
BEGIN
s <= a + b;
END comportamento;