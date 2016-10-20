-- Library instances
LIBRARY ieee;
USE ieee.std_logic_1164.all;

-- Short name: AND
ENTITY ANDPort IS
	PORT ( Branch : IN STD_LOGIC;	
		Zero : IN STD_LOGIC;
		ANDOut : OUT STD_LOGIC);
		
END ANDPort;

ARCHITECTURE ArchANDPort OF ANDPort IS
	BEGIN	
		ANDOut<=(Zero AND Branch);
END ArchANDPort;