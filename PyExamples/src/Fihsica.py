C = 6.3e18 # quantidade de elétrons em um Coulomb
E_0 = 8.9e-12 # permissividade elétrica no vácuo
eV = q_e # elétron-volt (J)
N_A = 6e23
d_Cu = 9e3
M_Cu = 6.4e-2

# Constantes físicas fundamentais ou universais
c = 299792458 # velocidade da luz (m/s)
G = 6.67428e-11 # gravitação universal ou newtoniana (m³/(k.s²))
G_U = 1e-4 # Incerteza relativa padrão de G
h = 6.62606896e-34 # constante de Planck (J.s)
h_2pi = 1.054571628e-34 # constante de Planck reduzida (J.s)
h_U = 5e-8 # Incerteza relativa de h e h_2pi

# Constantes eletromagnéticas
u_0 = 4e-7*math.pi # constante magnética (N/A²)
E_0 = 1/(u_0*c*c) # constante elétrica - 8.854187[817] (F/m)
Z_0 = u_0*c # [373.730313] # caracterísitca da impedância no vácuo (ohm)
k = 1/(4*math.pi*E_0) # 9e9 - constante eletrostática para meio vácuo (N.m²/C²)
q_e = 1.602176487e-19 # carga de um elétron ou elementar (C)
u_B = 9.27400915e-24 # momento magnético ou magneton de Bohr
G_0 = 2*q_e**2/h # condutância quântica
G_0__1 = 1/G_0 # resistência quântica ou inverso da condutância quântica
K_J = 2*q_e/h # constante de Josephson
phi_0 = h/2*q_e # fluxo magnético quântico
u_N = e*h_U/2m_p # momento magnético nuclear ou magneton nuclear
R_K = h/q_e**2 # constante de von Klitzing

k_ar = 1.00054k
k_parafina_min = 2k
k_parafina_max = 2.5k
k_teflon = 2.1k
k_ohleo_silicone = 2.5k
k_isopor = 2.6k
k_nailon = 3.5k
k_papel = 3.7k
k_quartzo_fundido_min = 3.8k
k_quartzo_fundido_max = 4.1k
k_baquelite = 4.9k
k_vidro_pirex_min = 4k
k_vidro_pirex_max = 6k
k_neoprene = 6.7k
k_Si = 12k
k_Ge = 16k
k_H20 = 80k
k_titanato_estroncio = 230k

rd_ar = 3
rd_parafina = 10
rd_ohleo_silicone = 60
rd_isopor = 24
rd_nailon = 14
rd_papel = 16
rd_baquelite = 24
rd_vidro_pirex = 14
rd_neoprene = 12
rd_titanato_estroncio = 8

# Constantes atômicas e nucleares
a_0 = a/4*math.pi*R_inf # raio de Bohr
r_e = q_e**2/4*math.pi*E_0*m_e*c*c # raio clássico do elétron
m_e = 9.10938215 # massa do elétron
Fcc = G_F/(h_U*c)**3 = 1.6639e-5 # constante de acoplamento de Fermi
a = u_0*q_e**2*c/(2*h) = q_e**2/(4*math.pi*E_0*h_U*c) = 7.2973525376e-3 # constante de estrutura fina
E_h = 2*R_inf*h*c # energia de Hartree
m_p = 1.672621637e-27 # massa do próton
h/2m_e = 3.636947550e-4 # quantum de circulação
R_inf = a*a*m_e*c/(2*h) # constante de Rydberg
(8*math.pi/3)*r_e**2 # seccção de cruzamento de Thomson
(math.sin(theta_w))**2 = 1 - (m_w/m_z)**2 # ângulo de mistura fraca ou ângulo de Weinberg

# Constantes fisico-químicas
m_u = 1 u # unidade de massa atômica
N_A = L = 6.0221415e23 # número de Avogadro
k = k_B = R/N_A*q_e # constante de Boltzmann
F = N_A*q_e # constante de Faraday
c_1 = 2*math.pi*h*c*c # primeira constante de radiação
c_1L = 1.19104282e-16 # primeira constante de radiação para espectro de radiação
n_0 = N_A/Vm # constante de Loschmidt (a 27315/100 K e 101325 Pa)
R = 8.314472 # constante dos gases
mPc = N_A*h # constante molar de Planck
V_m = R*T/p # volume molar de um gás ideal
S_0/R = 5/2+ln[(2*math.pi*m_u*k*T/h*h)**(3/2)*k*T/p] # constante de Sackur-Tetrode
c_2 = h*c/k # segunda constante de radiação
sigma = ((math.pi)**2/60)*k**4/(h_U**3*c*c) # constante de Stefan-Boltzmann
b = ((h*c)/k)/W(x*exp(x)/(exp(x)-1)-5) # constante da lei do deslocamento de Wien (x=4.965114231)

# Constantes de valores adotados
K_J__90 = 4.835979e14 # valor convencional da constante de Josephson
R_K__90 = 25812.807 # valor convencional da constante de von Klitzing
M_u = M_12C/12 = 1e-3 # constante de massa molar
M_12C = N_A*m_12C # constante de massa molar para carbono-12
g_n = 9.80665 # gravidade terrestre padrão
atm = 101325 # atmosfera padrão

# Unidades naturais
L_P = (h_U*G/c**3)**0.5 # comprimento de Planck
m_P = (h_U*c/G)**0.5 # massa de Planck
t_P = l_P/c # tempo de Planck
q_P = (4*math.pi*E_0*h_U*c)**0.5 # carga elétrica de Planck
T_P = m_P*c**20k_B = (h_U*c**5/G*k_B**2)**0.5 # temperatura de Planck