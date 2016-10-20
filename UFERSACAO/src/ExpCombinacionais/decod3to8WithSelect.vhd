LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY decod3to8WithSelect IS
PORT (
	endereco  : IN BIT_VECTOR(2 DOWNTO 0);
	Saida	      : OUT BIT_VECTOR(7 DOWNTO 0)  );
END decod3to8WithSelect;

ARCHITECTURE behavior OF decod3to8WithSelect IS
BEGIN
	WITH endereco SELECT
	  Saida <=  "00000001" WHEN "000",	        	        
				"00000010" WHEN "001",
		        "00000100" WHEN "010",
	 	        "00001000" WHEN "011",
		        "00010000" WHEN "100",
 	            "00100000" WHEN "101",
                "01000000" WHEN "110",
		        "10000000" WHEN "111";
END behavior;
