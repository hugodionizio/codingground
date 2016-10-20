LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY maquina_estados IS
  PORT (
         entrada : IN std_logic;
         clock : IN std_logic;
         saida : OUT std_logic
        );
END maquina_estados;

ARCHITECTURE behavior OF maquina_estados IS
TYPE estado IS (A, B, C);
SIGNAL estado_atual, proximo_estado : estado;
BEGIN 

PROCESS (clock, entrada)
BEGIN
  CASE estado_atual IS
    WHEN A =>
      saida <= ‘0’;
      IF (entrada = ‘1’) THEN
        proximo_estado <= B;
      END IF;
	WHEN B =>
      saida <= ‘0’;
      IF (entrada = ‘0’) THEN
        proximo_estado <= C;
      END IF;

    WHEN C =>
      saida <= ‘1’;
      proximo_estado <= A;
  END CASE;
END PROCESS;

 ATUALIZA_ESTADO : PROCESS (clock)
BEGIN
  IF (clock’event AND clock = ‘1’) THEN
    estado_atual <= proximo_estado;
  END IF;
END PROCESS ATUALIZA_ESTADO;
END behavior;

