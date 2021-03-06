LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
 
ENTITY ula IS
GENERIC (N : POSITIVE := 32); -- 32 bits
PORT (	Cin 	 : IN STD_LOGIC;
A, B      	: IN STD_LOGIC_VECTOR(N-1 DOWNTO 0);
Sum       	: OUT STD_LOGIC_VECTOR(N-1 DOWNTO 0);
Cout 	: OUT STD_LOGIC);
END ula; 

ARCHITECTURE arqPortAnd OF PortAnd IS
 SIGNAL int_carry : STD_LOGIC_VECTOR(N-1 DOWNTO 0);
SIGNAL sum_t	 : STD_LOGIC_VECTOR(N-1 DOWNTO 0);
BEGIN
 sum_t <= A(N-1 DOWNTO 0) AND B(N-1 DOWNTO 0) XOR (int_carry (N-2 DOWNTO 0) &Cin);
  int_carry(0) <= ((A(0) OR B(0)) AND Cin) OR (A(0) AND B(0));
 CASCADE_CARRY:
  FOR I in 1 TO N-1 GENERATE
    int_carry(I) <= ((A(I) OR B(I)) AND int_carry(I-1)) OR (A(I) AND B(I));
  END GENERATE CASCADE_CARRY;
 --
	PROCESS(A, B, sum_t)
	BEGIN
	IF ( (sum_t(N - 1) = '1') OR ( A = NOT B)) THEN
		Cout <= '1';
	ELSE
		Cout <= '0';
	END IF;
	END PROCESS;
 Sum  <= sum_t;
END arqPortAnd;