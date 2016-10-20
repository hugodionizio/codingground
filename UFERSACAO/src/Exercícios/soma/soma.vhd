-- soma: soma.vhd
-- Função : Somar dois valores inteiros 'a' e 'b' com saída em 'c'
-- Autor(es) : SANTOS, Hugo Dionizio
-- Data : 10-05-2013 11:17:49

-- Interface do componente
-- Seção de Pacotes
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.all;
USE IEEE.STD_LOGIC_UNSIGNED.all;

-- Descrição do componente
-- Seção da Entidade
ENTITY soma IS
	PORT (a, b: INTEGER; -- entradas, valores entre -2**31 e 2**31-1
		c: OUT INTEGER); -- saída, valores entre 	-2**31 e 2**31-1
END soma;

-- Seção da Arquitetura
ARCHITECTURE teste OF soma IS
	BEGIN
		c <= a+b;
END teste;

-- Seção de Configuração
--CONFIGURATION
--END;

-- Fim do componente
