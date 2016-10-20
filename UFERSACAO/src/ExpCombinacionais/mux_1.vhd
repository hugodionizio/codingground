LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY mux_1 IS
	PORT( 	i0, i1, i2, i3	: IN BIT; 	-- entradas
			s0, s1			: IN BIT; 	-- selecao
			ot				: OUT BIT);	-- saida
END mux_1;

ARCHITECTURE teste OF mux_1 IS
BEGIN
	ot <= 	i0 WHEN s1 = '0' AND s0 = '0' ELSE
			i1 WHEN s1 = '0' AND s0 = '1' ELSE
			i2 WHEN s1 = '1' AND s0 = '0' ELSE
			i3;			
END teste;