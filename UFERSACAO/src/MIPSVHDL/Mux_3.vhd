LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY Mux_3 IS

PORT (

Ent1, Ent2: IN bit_VECTOR(31 downto 0);
Saida : OUT bit_VECTOR(31 downto 0);
Sel: std_logic);



END Mux_3;

ARCHITECTURE behavior OF Mux_3 IS

BEGIN
	process(sel) 	
	begin
		If (sel='0') then
			Saida <= Ent1;
		Else
			Saida <= Ent2;
		
		end If;
	end process;		
END behavior;