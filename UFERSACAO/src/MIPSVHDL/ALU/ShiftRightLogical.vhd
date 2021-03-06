LIBRARY IEEE;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

-- Deslocador de bits do PC
ENTITY ShiftRightLogical IS
	GENERIC (N : POSITIVE := 32); -- Para 26 bits
	PORT	(	
				A	: IN STD_LOGIC_VECTOR(N-1 DOWNTO 0);
				Cout	: OUT STD_LOGIC_VECTOR(N-1 DOWNTO 0)
			);
END ShiftRightLogical;

ARCHITECTURE ArqShiftRightLogical OF ShiftRightLogical IS
	BEGIN	
		Cout <= A(N-1 DOWNTO 1) & '0';
END ArqShiftRightLogical;