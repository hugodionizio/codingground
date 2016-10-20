library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Multiplexador do Multiplexador, do Somador do PC com o Sinal Extendido, para o PC
ENTITY MuxMux IS
	PORT ( JumpAddress : IN BIT;	
		MuxAddOut : IN BIT;
		MuxMuxOut : OUT BIT;
	--	
	-- Controles	
	--	
		Jump : IN BIT);
END MuxMux;

ARCHITECTURE ArqMuxMux OF MuxMux IS
	BEGIN	
		MuxMuxOut<=(MuxAddOut, JumpAddress)
	-- 	
	--Controles	
	--	
END ArqMuxMux;		Jump
