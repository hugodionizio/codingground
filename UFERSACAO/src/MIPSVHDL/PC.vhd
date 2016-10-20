library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Contador de Programa (PC)
ENTITY PC IS
	PORT ( MuxMuxOut : IN BIT;	
		ReadAddress (*) : OUT BIT);
END PC;

ARCHITECTURE ArqPC OF PC IS
	BEGIN	
		ReadAddress (*)<=(MuxMuxOut );
END ArqPC;
