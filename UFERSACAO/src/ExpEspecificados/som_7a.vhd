ENTITY som_7a IS
  GENERIC(n     : INTEGER  := 3 );                -- numero de bits
  PORT   (x, y  : IN  BIT_VECTOR (n-1 DOWNTO 0);  -- entradas so somador
          ze    : IN  BIT;                        -- vem um
          s     : OUT BIT_VECTOR (n-1 DOWNTO 0);  -- saida
          zs    : OUT BIT);                       -- vai um
END som_7a;

ARCHITECTURE estrutural OF som_7a IS
  COMPONENT som_1a                         
    PORT   (a, b, ve : IN  BIT;  s, vs  : OUT BIT); 
  END COMPONENT;
  SIGNAL v : BIT_VECTOR (n-1 DOWNTO 1);  -- vai um interno
BEGIN
  global: FOR i IN 0 TO n-1 GENERATE
    def: IF i=0 GENERATE
      primeira: som_1a PORT MAP (x(i), y(i), ze,  s(i), v(i+1));  -- 1a celula
    END GENERATE def;
    abc: IF (i > 0) AND (i < n-1) GENERATE
      centro: som_1a PORT MAP  (x(i), y(i), v(i), s(i), v(i+1));  -- celulas centro
    END GENERATE abc;
    ghi: IF i=n-1 GENERATE
      ultima: som_1a PORT MAP  (x(i), y(i), v(i), s(i), zs);      -- ultima celula
    END GENERATE ghi;
  END GENERATE global;
END estrutural;



