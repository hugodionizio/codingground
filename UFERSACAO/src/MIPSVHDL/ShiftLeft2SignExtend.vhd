library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Deslocador de bits (Shift Left 2) do Sinal Extendido (SignExtend)
ENTITY ShiftLeft2SignExtend IS
	PORT ( SignExtendOut : IN BIT;	
		ShiftSign32Out : OUT BIT);
END ShiftLeft2SignExtend;

ARCHITECTURE ArqShiftLeft2SignExtend OF ShiftLeft2SignExtend IS
	BEGIN	
		ShiftSign32Out<=(SignExtendOut );
END ArqShiftLeft2SignExtend;
