--Shift Left 26
--deslocamento da entrada (26 bits) para a esquerda em 2 bits, 
--resultando em uma sa�da de 28 bits.

library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

ENTITY shiftleft26 IS
     PORT(
		entrada  : in bit_vector(25 downto 0);
		saida    : out bit_vector(27 downto 0)
		  );
END shiftleft26;

ARCHITECTURE deslocamento OF shiftleft26 IS

begin
            saida(0) <= '0';
            saida(1) <= '0';
			saida(27 downto 2) <= entrada(25 downto 0);
			
END deslocamento;

--C�digo comportamental VHDL do Shift_Left26_28.