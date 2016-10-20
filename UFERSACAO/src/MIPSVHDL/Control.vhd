library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

-- Unidade de Controle (Central)
ENTITY Control IS
	PORT ( Instruction31_26 (***) : IN BIT;	
		RegDst : OUT BIT;
		Jump : OUT BIT;
		Branch : OUT BIT;
		MemRead : OUT BIT;
		MemtoReg : OUT BIT;
		ALUOp : OUT BIT;
		MemWrite : OUT BIT;
		ALUScr : OUT BIT;
		RegWrite : OUT BIT);
END Control;

ARCHITECTURE ArqControl OF Control IS
	BEGIN	
		RegDst<=(Instruction31_26 (***));
		Jump<=();
		Branch<=();
		MemRead<=();
		MemtoReg<=();
		ALUOp<=();
		MemWrite<=();
		ALUScr<=();
		RegWrite<=();
END ArqControl;
