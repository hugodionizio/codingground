LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_signed.all;

entity registrador_instrucao is
	port(
		Clk		: in bit; 	-- Clock do sistema
		Reset		: in bit; 	-- Reset
		Load_ir	: in bit; 	-- Bit para ativar carga do registrador de intruções
		Entrada	: in bit_vector (31 downto 0); 	-- Intrução a ser carregada
	Instrucao31_26	: out bit_vector (5 downto 0);	 --bits que vão pra unidade de controle
	Instrucao25_21	: out bit_vector (4 downto 0);	 -- read register1        
	Instrucao20_16	: out bit_vector (4 downto 0);	 --read register2 e mux parte baixa(0)
	Instrucao15_11	: out bit_vector (15 downto 0) -- mux parte alta(1)
            instrucao15_0             : out bit_vector(15 downto 0)  --extensor de sinal de 16 para 32 bits
	);
end registrador_instrucao;
-- Arquitetura que define o comportamento interno do Registrador de Intruções
-- Simulation

architecture behavior_registra of registrador_instrucao is
signal saida: bit_vector (31 downto 0); -- Sinal interno que guarda a intrução a ser modulada

	begin
	-- processo clock do sistema 
	process (clk, reset)

		begin

			if(reset = '1') then
				saida  <= "00000000000000000000000000000000";
			elsif (clk = '1' and clk' event) then
				if (load_ir = '1')	then
					saida (31 downto 0) <= entrada; -- Carrega instrução
				end if;
			end if;
	end process;
	Instrucao31_26 <= saida (31 downto 26); -- Modula instrução (31 a 26)
	Instrucao25_21 <= saida (25 downto 21); -- Modula instrução (25 a 21)
	Instrucao20_16 <= saida (20 downto 16); -- Modula instrução (20 a 16)
	Instrucao15_11 <= saida (15 downto 0); -- mux parte alta(1)
            Instrucao15_0 <= saida (15 downto 0);  -- Modula instrução (15 a 0)

end behavior_registra;