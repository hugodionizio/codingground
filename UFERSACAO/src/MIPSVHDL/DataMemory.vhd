library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Memória de Dados
ENTITY DataMemory IS
	PORT ( Address (12) : IN BIT;	
		WriteDataReg : IN BIT;
		ReadData : OUT BIT;
	--	
	-- Controles	
	--	
		MemWrite : IN BIT;
		MemRead : IN BIT);
END DataMemory;

ARCHITECTURE ArqDataMemory OF DataMemory IS
	BEGIN	
		ReadData<=(WriteDataReg, Address (12)
	-- 	
	--Controles	
	--	
END ArqDataMemory;		MemRead, MemWrite
