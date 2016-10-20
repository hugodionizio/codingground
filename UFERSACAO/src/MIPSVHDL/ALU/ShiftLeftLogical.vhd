LIBRARY IEEE;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

-- Deslocador de bits da ALU para esquerda
ENTITY ShiftLeftLogical IS
	GENERIC (N : POSITIVE := 32); -- Para 32 bits
	PORT	(	
				A	: IN STD_LOGIC_VECTOR(N-1 DOWNTO 0);
				Cout	: OUT STD_LOGIC_VECTOR(N-1 DOWNTO 0)
			);
END ShiftLeftLogical;

ARCHITECTURE ArqShiftLeftLogical OF ShiftLeftLogical IS
	BEGIN	
		Cout <= '0' & A(N-1 DOWNTO 1);
END ArqShiftLeftLogical;