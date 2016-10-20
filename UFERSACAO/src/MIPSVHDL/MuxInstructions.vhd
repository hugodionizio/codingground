library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Multiplexador das Instruções e para os Registradores (WriteRegister)
ENTITY MuxInstructions IS
	PORT ( Instruction20_16 (****) : IN BIT;	
		Instruction15_11 (5) : IN BIT;
		WriteRegister : OUT BIT;
	--	
	-- Controles	
	--	
		RegDst : IN BIT);
END MuxInstructions;

ARCHITECTURE ArqMuxInstructions OF MuxInstructions IS
	BEGIN	
		WriteRegister<=(Instruction15_11 (5), Instruction20_16 (****)
	-- 	
	--Controles	
	--	
END ArqMuxInstructions;		RegDst
