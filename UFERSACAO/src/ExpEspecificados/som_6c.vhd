ENTITY som_6c IS
  GENERIC(n     : INTEGER  := 3 );                -- numero de bits
  PORT   (x, y  : IN  BIT_VECTOR (n-1 DOWNTO 0);  -- entradas so somador
          ze    : IN  BIT;                        -- vem um
          s     : OUT BIT_VECTOR (n-1 DOWNTO 0);  -- saida
          zs    : OUT BIT);                       -- vai um
END som_6c;

ARCHITECTURE teste OF som_6c IS
  SIGNAL v : BIT_VECTOR (n DOWNTO 0);  -- vai um interno
BEGIN
  v(0) <= ze;
  zs   <= v(n);
  abc: FOR i IN 0 TO n-1 GENERATE                                     
    s(i)   <=  x(i) XOR y(i)  XOR v(i);                                
    v(i+1) <= (x(i) AND y(i)) OR (x(i) AND v(i)) OR (y(i) AND v(i)); 
  END GENERATE abc;
END teste;




