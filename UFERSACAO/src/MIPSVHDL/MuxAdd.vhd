library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Multiplexador do Somador AddShiftSign, do sinal extendido
ENTITY MuxAdd IS
	PORT ( AddPCOut (x) : IN BIT;	
		ALUResultAddPC : IN BIT;
		MuxAddOut : OUT BIT;
	--	
	-- Controles	
	--	
		ANDOut : IN BIT;
END MuxAdd;

ARCHITECTURE ArqMuxAdd OF MuxAdd IS
	BEGIN	
		MuxAddOut<=(ALUResultAddPC, AddPCOut (x)
	-- 	
	--Controles	
	--	
		ANDOut
END ArqMuxAdd;
