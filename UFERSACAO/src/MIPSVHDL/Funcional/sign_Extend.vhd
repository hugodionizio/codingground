
--SignExtend
--Extensor de 16 para 32 bits, cujo comportamento é descrito abaixo.

 library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

ENTITY sign_Extend IS                               -- sign Extend
	PORT(
		Instrucao15_0 : IN 	bit_vector(15 downto 0);  
		Clk           : IN bit;                           
		Saida32_0     : OUT bit_vector(31 downto 0)  
	           );
END sign_Extend;

ARCHITECTURE sextend OF sign_Extend IS              
             
Signal temp : bit_vector (31 downto 0);	

begin
	process(Clk)
		begin
		case Clk is
			when '0' =>
				if (instrucao15_0(15)= '1' ) then 
                 temp(31 downto 16) <= "1111111111111111"; --parte alta da instrução hi 
			     temp(15 downto 0)  <= instrucao15_0;       --lo
				else 
				 temp(31 downto 16) <= "0000000000000000";
				 temp(15 downto 0)  <= instrucao15_0;
				end if;	
		    when '1' => 
				temp(31 downto 16) <= instrucao15_0;
				temp(15 downto 0) <= "0000000000000000";		
		end case;
			saida32_0 <= temp;
    end process;
END sextend;

--Código: comportamento VHDL do Sign Extend.