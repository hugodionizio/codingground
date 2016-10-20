library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Registradores
ENTITY Registers IS
	PORT ( ReadRegister1 (8) : IN BIT;	
		ReadRegister2 (9) : IN BIT;
		WriteRegister : IN BIT;
		WriteDataMux : IN BIT;
		ReadData1 : OUT BIT;
		ReadData2 (10: WriteDataReg) : OUT BIT;
	--	
	-- Controles	
	--	
		RegWrite : IN BIT);
END Registers;

ARCHITECTURE ArqRegisters OF Registers IS
	BEGIN	
		ReadData1<=(WriteDataMux, WriteRegister, ReadRegister2 (9), ReadRegister1 (8)
	ReadData2 (10: WriteDataReg)<=();
	-- 	
	--Controles	
	--	
END ArqRegisters;		RegWrite
