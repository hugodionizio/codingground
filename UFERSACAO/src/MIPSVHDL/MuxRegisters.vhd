library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Multiplexador dos Registradores e para a Memória de Dados
ENTITY MuxRegisters IS
	PORT ( ReadData2 (6) : IN BIT;
		SignExtendOut : IN BIT;
		MuxRegOut : OUT BIT;
	--	
	-- Controles	
	--	
		ALUSrc : IN BIT);
END MuxRegisters;

ARCHITECTURE ArqMuxRegisters OF MuxRegisters IS
	BEGIN	
		MuxRegOut<=(SignExtendOut, ReadData2 (6))
	-- 	
	--Controles	
	--	
END ArqMuxRegisters;		ALUSrc
