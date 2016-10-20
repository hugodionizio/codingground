LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY mux_2 IS
PORT ( 	i0, i1, i2, i3	: IN BIT; 	-- entradas
		sel				: IN BIT_VECTOR(1 DOWNTO 0); 	-- selecao
		ot				: OUT BIT);	-- saida
END mux_2;

ARCHITECTURE teste OF mux_2 IS
BEGIN
	WITH sel SELECT
	  ot <= 	i0 WHEN "00",
  				i1 WHEN "01",
				i2 WHEN "10",
				i3 WHEN "11";
END teste;

