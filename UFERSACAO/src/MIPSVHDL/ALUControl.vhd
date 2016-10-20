library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Controle da ALU
ENTITY ALUControl IS
	PORT ( Instruction5_0 : IN BIT;	
		ALUControlOut : OUT BIT;
	--	
	-- Controles	
	--	
		ALUOp : IN BIT);
END ALUControl;

ARCHITECTURE ArqALUControl OF ALUControl IS
	BEGIN	
		ALUControlOut<=(Instruction5_0);
	-- 	
	--Controles	
	--	
END ArqALUControl;		ALUOp
