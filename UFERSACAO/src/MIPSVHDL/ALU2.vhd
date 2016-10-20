-- Instância de Bibliotecas
LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- Nome simples: ALU
ENTITY ALU IS
	GENERIC (N : POSITIVE := 32); -- Para 32 bits
	PORT ( 
		ReadData1 			: IN STD_LOGIC_VECTOR (31 DOWNTO 0);	-- Operando ReadData1 da ALU
		ReadData2 			: IN STD_LOGIC_VECTOR (31 DOWNTO 0);	-- Operando ReadData2 da ALU
		ALUControlOut 		: IN STD_LOGIC_VECTOR(3 DOWNTO 0);		-- Seletor da operação da ALU
		ALUResultALU 		: OUT STD_LOGIC_VECTOR (31 DOWNTO 0);	-- Resultado da operação (SOMA, SUB, AND, OR, SOMAI, ORI, NOR, ANDI, SHIFTL, SHIFTR)
		Overflow 			: OUT STD_LOGIC							-- Sinaliza estouro aritmético
		);
END ALU;

-- Simulation
ARCHITECTURE ArchALU OF ALU IS
-- Sinais internos do processamento	
	SIGNAL tempOut: STD_LOGIC_VECTOR(31 DOWNTO 0);	-- Sinal que recebe valor temporário da operação realizada
 	SIGNAL somador: STD_LOGIC_VECTOR(31 DOWNTO 0);	-- Sinal que recebe o valor temporario da soma, soma imediata ou subtração
	SIGNAL c_signal: STD_LOGIC_VECTOR (31 DOWNTO 0);-- Vetor para auxílio no cálculo das operações e do estouro aritmético 
	SIGNAL novo_ReadData2	: STD_LOGIC_VECTOR (31 DOWNTO 0);	-- Vetor que fornece o operando ReadData2, 1 ou NOT(ReadData2) para operações de soma, soma imediata ou subtração respectivamente
	SIGNAL immediate		: STD_LOGIC_VECTOR(31 DOWNTO 0);  		-- Vetor para somador imediato
	SIGNAL overflow_temp: STD_LOGIC;										-- Bit que armazena valor temporário do estouro
	CONSTANT Zero		: STD_LOGIC_VECTOR(31 DOWNTO 0) := "00000000000000000000000000000000";	-- Constante com o valor do elemento neutro para somas lógicas imediatas
	CONSTANT K_1_const		: STD_LOGIC_VECTOR(31 DOWNTO 0) := "11111111111111111111111111111111";	-- Constante com o valor do elemento neutro para produtos lógicos imediatos
	BEGIN

		WITH ALUControlOut SELECT
	
			tempOut <= 	ReadData1						WHEN "0000",	-- LOAD
			  			somador							WHEN "0001",	-- SOMA
			  			somador							WHEN "0010",	-- SUB
			  			(ReadData1 AND ReadData2)  		WHEN "0011",	-- AND
			  			(ReadData1 OR ReadData2) 		WHEN "0110",	-- OR              
              			(ReadData1 NOR ReadData2)		WHEN "0101",	-- NOR
			  			somador							WHEN "0100",	-- SOMA IMEDIATA
			  			'0' & ReadData1(N-1 DOWNTO 1)	WHEN "0111",	-- DESLOCAMENTO À ESQUERDA
			  			ReadData1(N-1 DOWNTO 1) & '0'	WHEN "1000",	-- DESLOCAMENTO À DIREITA
			  			(ReadData1 AND K_1_const)		WHEN "1001",	-- ANDI
			  			(ReadData1 OR Zero)				WHEN "1010",	-- ORI		  			
             			"00000000000000000000000000000000" WHEN OTHERS;	-- NÃO DEFINIDO
			
			ALUResultALU <= tempOut;
			
			immediate <= "00000000000000000000000000000000";
			
--------------------------------------------------------------------------------
--			Região que calcula a soma, soma imediata e subtração			  --	
--------------------------------------------------------------------------------
		WITH ALUControlOut SELECT
    		
			novo_ReadData2 <= ReadData2  		WHEN "0001",  -- Soma
   				      immediate 	WHEN "0100",  -- Imediato
                      NOT(ReadData2) 	WHEN OTHERS; -- Subtração e outros	
  	
    		somador(0) <= ReadData1(0) XOR novo_ReadData2(0) XOR ALUControlOut(1);
			somador(1) <= ReadData1(1) XOR novo_ReadData2(1) XOR c_signal(0);
			somador(2) <= ReadData1(2) XOR novo_ReadData2(2) XOR c_signal(1);
			somador(3) <= ReadData1(3) XOR novo_ReadData2(3) XOR c_signal(2);
			somador(4) <= ReadData1(4) XOR novo_ReadData2(4) XOR c_signal(3);
			somador(5) <= ReadData1(5) XOR novo_ReadData2(5) XOR c_signal(4);
			somador(6) <= ReadData1(6) XOR novo_ReadData2(6) XOR c_signal(5);
			somador(7) <= ReadData1(7) XOR novo_ReadData2(7) XOR c_signal(6);
			somador(8) <= ReadData1(8) XOR novo_ReadData2(8) XOR c_signal(7);
			somador(9) <= ReadData1(9) XOR novo_ReadData2(9) XOR c_signal(8);
			somador(10) <= ReadData1(10) XOR novo_ReadData2(10) XOR c_signal(9);
			somador(11) <= ReadData1(11) XOR novo_ReadData2(11) XOR c_signal(10);
			somador(12) <= ReadData1(12) XOR novo_ReadData2(12) XOR c_signal(11);
			somador(13) <= ReadData1(13) XOR novo_ReadData2(13) XOR c_signal(12);
			somador(14) <= ReadData1(14) XOR novo_ReadData2(14) XOR c_signal(13);
			somador(15) <= ReadData1(15) XOR novo_ReadData2(15) XOR c_signal(14);
			somador(16) <= ReadData1(16) XOR novo_ReadData2(16) XOR c_signal(15);
			somador(17) <= ReadData1(17) XOR novo_ReadData2(17) XOR c_signal(16);
			somador(18) <= ReadData1(18) XOR novo_ReadData2(18) XOR c_signal(17);
			somador(19) <= ReadData1(19) XOR novo_ReadData2(19) XOR c_signal(18);
			somador(20) <= ReadData1(20) XOR novo_ReadData2(20) XOR c_signal(19);
			somador(21) <= ReadData1(21) XOR novo_ReadData2(21) XOR c_signal(20);
			somador(22) <= ReadData1(22) XOR novo_ReadData2(22) XOR c_signal(21);
			somador(23) <= ReadData1(23) XOR novo_ReadData2(23) XOR c_signal(22);
			somador(24) <= ReadData1(24) XOR novo_ReadData2(24) XOR c_signal(23);
			somador(25) <= ReadData1(25) XOR novo_ReadData2(25) XOR c_signal(24);
			somador(26) <= ReadData1(26) XOR novo_ReadData2(26) XOR c_signal(25);
			somador(27) <= ReadData1(27) XOR novo_ReadData2(27) XOR c_signal(26);
			somador(28) <= ReadData1(28) XOR novo_ReadData2(28) XOR c_signal(27);
			somador(29) <= ReadData1(29) XOR novo_ReadData2(29) XOR c_signal(28);
			somador(30) <= ReadData1(30) XOR novo_ReadData2(30) XOR c_signal(29);
			somador(31) <= ReadData1(31) XOR novo_ReadData2(31) XOR c_signal(30);

			c_signal(0) <=    (ALUControlOut(1) AND (ReadData1(0) OR novo_ReadData2(0))) OR (ReadData1(0) AND novo_ReadData2(0));
	    	c_signal(1) <= (c_signal(0) AND (ReadData1(1) OR novo_ReadData2(1))) OR (ReadData1(1) AND novo_ReadData2(1));
			c_signal(2) <= (c_signal(1) AND (ReadData1(2) OR novo_ReadData2(2))) OR (ReadData1(2) AND novo_ReadData2(2));
			c_signal(3) <= (c_signal(2) AND (ReadData1(3) OR novo_ReadData2(3))) OR (ReadData1(3) AND novo_ReadData2(3));
			c_signal(4) <= (c_signal(3) AND (ReadData1(4) OR novo_ReadData2(4))) OR (ReadData1(4) AND novo_ReadData2(4));
			c_signal(5) <= (c_signal(4) AND (ReadData1(5) OR novo_ReadData2(5))) OR (ReadData1(5) AND novo_ReadData2(5));
			c_signal(6) <= (c_signal(5) AND (ReadData1(6) OR novo_ReadData2(6))) OR (ReadData1(6) AND novo_ReadData2(6));
			c_signal(7) <= (c_signal(6) AND (ReadData1(7) OR novo_ReadData2(7))) OR (ReadData1(7) AND novo_ReadData2(7));
			c_signal(8) <= (c_signal(7) AND (ReadData1(8) OR novo_ReadData2(8))) OR (ReadData1(8) AND novo_ReadData2(8));
		    c_signal(9) <= (c_signal(8) AND (ReadData1(9) OR novo_ReadData2(9))) OR (ReadData1(9) AND novo_ReadData2(9));
			c_signal(10) <= (c_signal(9) AND (ReadData1(10) OR novo_ReadData2(10))) OR (ReadData1(10) AND novo_ReadData2(10));
			c_signal(11) <= (c_signal(10) AND (ReadData1(11) OR novo_ReadData2(11))) OR (ReadData1(11) AND novo_ReadData2(11));
			c_signal(12) <= (c_signal(11) AND (ReadData1(12) OR novo_ReadData2(12))) OR (ReadData1(12) AND novo_ReadData2(12));
			c_signal(13) <= (c_signal(12) AND (ReadData1(13) OR novo_ReadData2(13))) OR (ReadData1(13) AND novo_ReadData2(13));
			c_signal(14) <= (c_signal(13) AND (ReadData1(14) OR novo_ReadData2(14))) OR (ReadData1(14) AND novo_ReadData2(14));
			c_signal(15) <= (c_signal(14) AND (ReadData1(15) OR novo_ReadData2(15))) OR (ReadData1(15) AND novo_ReadData2(15));
			c_signal(16) <= (c_signal(15) AND (ReadData1(16) OR novo_ReadData2(16))) OR (ReadData1(16) AND novo_ReadData2(16));
		    c_signal(17) <= (c_signal(16) AND (ReadData1(17) OR novo_ReadData2(17))) OR (ReadData1(17) AND novo_ReadData2(17));
			c_signal(18) <= (c_signal(17) AND (ReadData1(18) OR novo_ReadData2(18))) OR (ReadData1(18) AND novo_ReadData2(18));
			c_signal(19) <= (c_signal(18) AND (ReadData1(19) OR novo_ReadData2(19))) OR (ReadData1(19) AND novo_ReadData2(19));
			c_signal(20) <= (c_signal(19) AND (ReadData1(20) OR novo_ReadData2(20))) OR (ReadData1(20) AND novo_ReadData2(20));
			c_signal(21) <= (c_signal(20) AND (ReadData1(21) OR novo_ReadData2(21))) OR (ReadData1(21) AND novo_ReadData2(21));
			c_signal(22) <= (c_signal(21) AND (ReadData1(22) OR novo_ReadData2(22))) OR (ReadData1(22) AND novo_ReadData2(22));
			c_signal(23) <= (c_signal(22) AND (ReadData1(23) OR novo_ReadData2(23))) OR (ReadData1(23) AND novo_ReadData2(23));
			c_signal(24) <= (c_signal(23) AND (ReadData1(24) OR novo_ReadData2(24))) OR (ReadData1(24) AND novo_ReadData2(24));
		    c_signal(25) <= (c_signal(24) AND (ReadData1(25) OR novo_ReadData2(25))) OR (ReadData1(25) AND novo_ReadData2(25));
			c_signal(26) <= (c_signal(25) AND (ReadData1(26) OR novo_ReadData2(26))) OR (ReadData1(26) AND novo_ReadData2(26));
			c_signal(27) <= (c_signal(26) AND (ReadData1(27) OR novo_ReadData2(27))) OR (ReadData1(27) AND novo_ReadData2(27));
			c_signal(28) <= (c_signal(27) AND (ReadData1(28) OR novo_ReadData2(28))) OR (ReadData1(28) AND novo_ReadData2(28));
			c_signal(29) <= (c_signal(28) AND (ReadData1(29) OR novo_ReadData2(29))) OR (ReadData1(29) AND novo_ReadData2(29));
			c_signal(30) <= (c_signal(29) AND (ReadData1(30) OR novo_ReadData2(30))) OR (ReadData1(30) AND novo_ReadData2(30));
			c_signal(31) <= (c_signal(30) AND (ReadData1(31) OR novo_ReadData2(31))) OR (ReadData1(31) AND novo_ReadData2(31));

			overflow_temp <= c_signal(31) XOR c_signal(30);
		
		   Overflow <= overflow_temp;
END ArchALU;
