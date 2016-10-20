LIBRARY IEEE;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

-- Somador de 1 bit
ENTITY Somador_1bit IS
	PORT (
 		cin: IN BIT;
        	portA: IN BIT;
        	portB: IN BIT;
        	sum: OUT BIT;
        	cout: OUT BIT

		ReadAddress (*) : IN BIT;	
		Out4 : IN BIT;
		AddPCOut : OUT BIT
);
END Somador_1bit;

ARCHITECTURE comportamento OF somador IS
	BEGIN
		s <= a XOR b XOR cin;
		cout <= (a AND b) OR (a AND cin) OR (b AND cin);
END comportamento;


ARCHITECTURE behavior OF full_adder IS
BEGIN
       sum <= a XOR b XOR cin;
       cout <= (a AND b) OR (cin AND (a OR b));
END behavior;

-- Unidade Lógica Aritmética do MIPS

ENTITY ALU IS

	COMPONENT (
			
	PORT ( ReadData1 : IN BIT;	
		MuxRegOut : IN BIT;
		Zero : OUT BIT;
		ALUResultALU : OUT BIT; (12)
	--	
	-- Controles	
	--	
		ALUControlOut : IN BIT);
END ALU;

ARCHITECTURE ArqALU OF ALU IS
	BEGIN	
		Zero<=(MuxRegOut, ReadData1
	ALUResultALU (12)<=();
	-- 	
	--Controles	
	--	
END ArqALU;		ALUControlOut
