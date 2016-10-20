library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Extensor de Sinal ou Sinal Extendido
ENTITY SignExtend IS
	PORT ( Instruction15_0 : IN BIT;	
		SignExtendOut : OUT BIT);
END SignExtend;

ARCHITECTURE ArqSignExtend OF SignExtend IS
	BEGIN	
		SignExtendOut<=(Instruction15_0 );
END ArqSignExtend;