LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY mux_ALU_PC IS
PORT (
	ALUresult : in STD_LOGIC_VECTOR(31 downto 0);
	PC_4 : in STD_LOGIC_VECTOR(31 downto 0);
            ALUsrc: IN  STD_LOGIC;
	Saida : out STD_LOGIC_VECTOR(31 downto 0)
	);
END mux_ALU_PC;

ARCHITECTURE behavior OF mux_ALU_PC IS
BEGIN
Process(ALUsrc)
	IF (ALUsrc = '1') THEN
           
           If (ALUsrc = '0') then  
	Saida <= PC_4;
           ELSE
           Saida <=ALUresult;
END behavior;