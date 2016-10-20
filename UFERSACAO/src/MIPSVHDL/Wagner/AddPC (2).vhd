library ieee;
use ieee.std_logic_1164.all;

entity addpc is
    Port(
        addpc: IN std_logic;
        valor4:IN std_logic_vector(31 downto 0); 
        cin  : IN std_logic;
        s    : OUT std_logic;
        cout : OUT std_logic);
end fullAdder;

architecture arcadd of addpc is
    signal aXorB : std_logic;
begin
    aXorB <= addpc xor valor4;
    s     <= aXorB xor cin;
    cout  <= (addpc and valor4) or (cin and aXorB);
end arcadd;