ENTITY som_2b IS
  PORT (x, y : IN  BIT_VECTOR(3 DOWNTO 0);  -- entradas do somador
        ze   : IN  BIT;                     -- entrada  vem um
        s    : OUT BIT_VECTOR(3 DOWNTO 0);  -- soma
        zs   : OUT BIT);                    -- vai um
END som_2b;

ARCHITECTURE estrutural OF som_2b IS
  COMPONENT som_1a
    PORT   (a, b, ve : IN  BIT;  s, vs : OUT BIT); 
  END COMPONENT;

  SIGNAL v   : BIT_VECTOR (3 DOWNTO 1);  -- vai um interno
BEGIN
  x0: som_1a PORT MAP(     x(0),      y(0),      ze,         s(0),       v(1));
  x1: som_1a PORT MAP(     x(1),      y(1),      v(1),       s(1),       v(2));  
  x2: som_1a PORT MAP(b => y(2), a => x(2), s => s(2), ve => v(2), vs => v(3));
  x3: som_1a PORT MAP(     x(3),      y(3),      v(3),       s(3),       zs);
END estrutural;