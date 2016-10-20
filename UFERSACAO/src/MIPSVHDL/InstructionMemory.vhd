library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Memória de Instruções
ENTITY InstructionMemory IS
	PORT ( ReadAddress (*) : IN BIT;	
		Instruction31_0 (11) : OUT BIT);
END InstructionMemory;

ARCHITECTURE ArqInstructionMemory OF InstructionMemory IS
	BEGIN	
		Instruction31_0 (11)<=(ReadAddress (*) );
END ArqInstructionMemory;
