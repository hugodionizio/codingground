--Shift Left2 de 32 bits
--desloca a entrada (32 bits) para a esquerda em 2 bits, 
--resultando em uma sa�da de 32 bits e coloca zero nos 
--dois bits menos significativos.
library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity shiftinicio2_0 is
port(
	entrada : in bit_vector (31 downto 0);
	Saida   : out bit_vector (31 downto 0)
	);
end shiftinicio2_0;

architecture behavioral of shiftinicio2_0 is

signal saida_temp : bit_vector(31 downto 0);

begin
	saida_temp(0) <= '0';
	saida_temp(1) <= '0';
		saida_temp(31 downto 2) <= entrada(29 downto 0);
	Saida <= saida_temp;

end behavioral;


  --     c�digo comportamental VHDL do shiftleft2_32.