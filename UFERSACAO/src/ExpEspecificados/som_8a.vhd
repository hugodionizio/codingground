ENTITY som_8a IS
  GENERIC(n     : INTEGER  := 3 );                -- numero de bits
  PORT   (x, y  : IN  BIT_VECTOR (n-1 DOWNTO 0);  -- entradas so somador
          ze    : IN  BIT;                        -- vem um
          s     : OUT BIT_VECTOR (n-1 DOWNTO 0);  -- saida
          zs    : OUT BIT);                       -- vai um
END som_8a;

ARCHITECTURE teste OF som_8a IS
BEGIN
  abc: PROCESS (x, y, ze)
    VARIABLE v : BIT_VECTOR (n DOWNTO 0);  -- vai um interno
  BEGIN
    v(0) := ze;
    abc: FOR i IN 0 TO n-1 LOOP                                     
      s(i)   <=  x(i) XOR y(i)  XOR v(i);                                
      v(i+1) := (x(i) AND y(i)) OR (x(i) AND v(i)) OR (y(i) AND v(i)); 
    END LOOP abc;
    zs   <= v(n);
  END PROCESS;
END teste;




