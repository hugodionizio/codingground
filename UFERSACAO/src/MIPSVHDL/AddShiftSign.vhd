library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Somador do Somador AddPC (PC+4), com o Deslocador de bits, ShiftSign32 (Shift left 2), da Unidade de Extensão de Sinal (Sign Extend)
ENTITY AddShiftSign IS
	PORT ( AddPCOut (**) : IN BIT;	
		ShiftSign32Out : IN BIT;
		ALUResultAddPC : OUT BIT);
END AddShiftSign;

ARCHITECTURE ArqAddShiftSign OF AddShiftSign IS
	BEGIN	
		ALUResultAddPC<=(ShiftSign32Out, AddPCOut (**) );
END ArqAddShiftSign;


