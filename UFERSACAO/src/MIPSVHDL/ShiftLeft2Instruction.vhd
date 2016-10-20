LIBRARY IEEE;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

-- Deslocador de bits do PC
ENTITY ShiftLeft2Instruction IS
	GENERIC (N : POSITIVE := 26); -- Para 26 bits
	PORT	(	
				Instruction25_0	: IN STD_LOGIC_VECTOR(N-1 DOWNTO 0);
				JumpAddress	: OUT STD_LOGIC_VECTOR(N-1 DOWNTO 0)
			);
END ShiftLeft2Instruction;

ARCHITECTURE ArqShiftLeft2Instruction OF ShiftLeft2Instruction IS
	BEGIN	
		JumpAddress <= '0' & Instruction25_0(N-1 DOWNTO 1);
END ArqShiftLeft2Instruction;
