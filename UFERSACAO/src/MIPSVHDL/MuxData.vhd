library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Multiplexador da Memória de Dados e para os Registradores (escrita de dados - WriteData)
ENTITY MuxData IS
	PORT ( ReadData : IN BIT;	
		ALUResultALU (7) : IN BIT;
		WriteData : OUT BIT;
	--	
	-- Controles	
	--	
		MemtoReg : IN BIT);
END MuxData;

ARCHITECTURE ArqMuxData OF MuxData IS
	BEGIN	
		WriteData<=(ALUResultALU (7), ReadData
	-- 	
	--Controles	
	--	
END ArqMuxData;		MemtoReg
