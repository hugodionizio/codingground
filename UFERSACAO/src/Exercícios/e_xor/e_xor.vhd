-- Componente: e_xor.vhd
-- Função : 
-- Autor(es) : ARAÚJO, Sílvio Roberto Fernandes; SANTOS, Hugo Dionizio.
-- Data : 09-05-2013 23:04:08

-- Interface do componente
-- Seção de Pacotes
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.all;
USE IEEE.STD_LOGIC_UNSIGNED.all;

-- Descrição do Componente
-- Seção da Entidade
ENTITY e_xor IS
	PORT (a, b: IN BIT; -- entradas, valores 0 ou 1
	c: OUT BIT); -- saída, valores 0 ou 1
END e_xor;

-- Seção da Arquitetura
ARCHITECTURE teste OF e_xor IS
--SIGNAL int1, int2;
	BEGIN
		c <= (a AND (NOT b)) OR ((NOT a) AND b);
END teste;

-- Seção de Configuração
--CONFIGURATION
--END

-- Fim do Componente
