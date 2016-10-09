#coding: utf-8
import math

d_Cu = 9e3
M_Cu = 6.4e-2

# Constantes físicas fundamentais ou universais
c = 299792458 # velocidade da luz (m/s)
G = 6.67428e-11 # gravitação universal ou newtoniana (m³/(k.s²))
G_U = 1e-4 # Incerteza relativa padrão de G
h = 6.62606896e-34 # constante de Planck (J.s)
h_2pi = h/(2*math.pi) # 1.054571628e-34 - constante de Planck reduzida (J.s)
h_U = 5e-8 # Incerteza relativa de h e h_2pi

# Constantes eletromagnéticas
u_0 = 4e-7*math.pi # constante magnética (N/A²)
E_0 = 1/(u_0*c*c) # constante elétrica ou permissividade elétrica no vácuo - 8.854187[817]e-12 (F/m)
Z_0 = u_0*c # [373.730313] - caracterísitca da impedância no vácuo (Ω)
k = 1/(4*math.pi*E_0) # 9e9 - constante eletrostática para meio vácuo (N.m²/C²)
q_e = 1.602176487e-19 # carga de um elétron ou elementar (C)
u_B = 9.27400915e-24 # momento magnético ou magneton de Bohr (J/T)
u_B_U = 2.5e-8 # incerteza relativa padrão de u_B
G_0 = 2*q_e**2/h # condutância quântica (S)
G_0_U = 6.8e-10 # incerteza relativa padrão de G_0
G_0__1 = 1/G_0 # resistência quântica ou inverso da condutância quântica (Ω)
G_0__1_U = 6.8e-10 # incerteza relativa padrão de G_0__1
K_J = 2*q_e/h # constante de Josephson (Hz/V)
K_J_U = 2.5e-8 # incerteza relativa padrão de K_J
phi_0 = h/2*q_e # fluxo magnético quântico (Wb)
phi_0_U = 2.5e-8 # incerteza relativa padrão de phi_0
u_N = e*h_2pi/2m_p # momento magnético nuclear ou magneton nuclear (J/T)
u_N_U = 8.6e-8 # incerteza relativa padrão de u_N
R_K = h/q_e**2 # constante de von Klitzing (Ω)
R_K_U = 6.8e-10 # incerteza relativa padrão de R_K
eV = q_e # elétron-volt (J)
C = 1/q_e # 6.242e18 - quantidade de elétrons em um Coulomb

# Constantes dielétricas
k_ar = 1.00054*k
k_parafina_min = 2*k
k_parafina_max = 2.5*k
k_teflon = 2.1*k
k_ohleo_silicone = 2.5*k
k_isopor = 2.6*k
k_nailon = 3.5*k
k_papel = 3.7*k
k_quartzo_fundido_min = 3.8*k
k_quartzo_fundido_max = 4.1*k
k_baquelite = 4.9*k
k_vidro_pirex_min = 4*k
k_vidro_pirex_max = 6*k
k_neoprene = 6.7*k
k_Si = 12*k
k_Ge = 16*k
k_H20 = 80*k
k_titanato_estroncio = 230*k

# Constantes de rigidez dielétrica (V/m)
rd_ar = 3e6
rd_parafina = 10e6
rd_ohleo_silicone = 60e6
rd_isopor = 24e6
rd_nailon = 14e6
rd_papel = 16e6
rd_baquelite = 24e6
rd_vidro_pirex = 14e6
rd_neoprene = 12e6
rd_titanato_estroncio = 8e6

# Constantes atômicas e nucleares
a_0 = a/4*math.pi*R_inf # raio de Bohr (m)
a_0_U = 3.3e-9 # incerteza relativa padrão de a_0
r_e = q_e**2/4*math.pi*E_0*m_e*c*c # raio clássico do elétron (m)
r_e_U = 2.1e-9 # incerteza relativa padrão de r_e
m_e = 9.10938215 # massa do elétron (kg)
m_e_U = 5e-8 # incerteza relativa padrão de m_e
G_F = 3.6858201952876524e-82 # "Constante gravitacional de Fermi"?
Fcc = G_F/(h_2pi*c)**3 # 1.6639e-5 - constante de acoplamento de Fermi (1/GeV²)
Fcc_U = 8.6e-6 # incerteza relativa padrão de Fcc
a = u_0*q_e**2*c/(2*h) # q_e**2/(4*math.pi*E_0*h_2pi*c) = 7.2973525376e-3 - constante de estrutura fina
a_U = 6.8e-10 # incerteza relativa padrão de a
E_h = 2*R_inf*h*c # energia de Hartree (J)
E_h_U = 1.7e-7 # incerteza relativa padrão de E_h
m_p = 1.672621637e-27 # massa do próton (kg)
m_p_U = 5e-8 # incerteza relativa padrão de m_p
q_c = h/2m_e # 3.636947550e-4 - quantum de circulação (m²/s)
q_c_U = 6.7e-9 # incerteza relativa padrão de q_c
R_inf = a*a*m_e*c/(2*h) # constante de Rydberg (1/m)
R_inf_U = 6.6e-12 # incerteza relativa padrão de R_inf
Ts = (8*math.pi/3)*r_e**2 # seccção de cruzamento de Thomson (m²)
Ts_U = 2e-8 # incerteza relativa padrão de Ts
theta_w = 28120528707284030389920038369925
Wa = (math.sin(theta_w/1e30))**2 # 1 - (m_w/m_z)**2 - ângulo de mistura fraca ou ângulo de Weinberg
Wa_U = 3.4e-3 # incerteza relativa padrão de Wa

# Constantes fisico-químicas
m_u = 1.66053886e-27 # unidade de massa atômica (kg)
m_u_U = 1.7e-7 # incerteza relativa padrão de m_u
N_A = L = 6.0221415e23 # número de Avogadro (1/mol)
N_A_U = 1.7e-7 # incerteza relativa padrão de N_A
k_B = R/N_A*q_e # k - constante de Boltzmann (J/k)
k_B_U = 1.8e-6 # incerteza relativa padrão de k
F = N_A*q_e # constante de Faraday (C/mol)
F_U = 8.6e-8 # incerteza relativa padrão de F
c_1 = 2*math.pi*h*c*c # primeira constante de radiação (W.m²)
c_1_U = 5e-8 # incerteza relativa padrão de c_1
c_1L = 1.19104282e-16 # primeira constante de radiação para espectro de radiação (W.m²/sr)
c_1L_U = 1.7e-7 # incerteza relativa padrão de c_1L
n_0 = N_A/Vm # constante de Loschmidt (a 27315/100 K e 101325 Pa)  (1/m³)
n_0_U = 1.8e-6 # incerteza relativa padrão de n_0
R = 8.314472 # constante dos gases (J/(K.mol))
R_U = 1.7e-6 # incerteza relativa padrão de R
mPc = N_A*h # constante molar de Planck (J.s/mol)
mPc_U = 6.7e-9 # incerteza relativa padrão de mPc
T_C = 273.15 # 0º C em K
T_K_min = 1
V_m = R*T/p # volume molar de um gás ideal (m³/mol)
V_m_U = 1.7e-6 # incerteza relativa padrão de V_m
ST = (5/2)+ln[(2*math.pi*m_u*k*T/h*h)**(3/2)*k*T/p] # S_0/R - constante de Sackur-Tetrode
ST_U = 3.8e-6 # incerteza relativa padrão de ST
c_2 = h*c/k # segunda constante de radiação (m.K)
c_2_U = 1.7e-6 # incerteza relativa padrão de c_2
sigma = ((math.pi)**2/60)*k**4/(h_2pi**3*c*c) # constante de Stefan-Boltzmann (W/(m².K².K²))
sigma_U = 7e-6 # incerteza relativa padrão de sigma
b = ((h*c)/k)/W(x*exp(x)/(exp(x)-1)-5) # constante da lei do deslocamento de Wien (x=4.965114231) (m.K)
b_U = 1.7e-6 # incerteza relativa padrão de b

# Constantes de valores adotados
K_J__90 = 4.835979e14 # valor convencional da constante de Josephson (Hz/V)
R_K__90 = 25812.807 # valor convencional da constante de von Klitzing (Ω)
M_u = M_12C/12 = 1e-3 # constante de massa molar (kg/mol)
M_12C = N_A*m_12C # constante de massa molar para carbono-12 (kg/mol)
g_n = 9.80665 # gravidade terrestre padrão (m/s²)
atm = 101325 # atmosfera padrão (Pa)

# Unidades naturais
L_P = (h_2pi*G/c**3)**0.5 # comprimento de Planck (m)
m_P = (h_2pi*c/G)**0.5 # massa de Planck (kg)
t_P = l_P/c # tempo de Planck (s)
q_P = (4*math.pi*E_0*h_2pi*c)**0.5 # carga elétrica de Planck (C)
T_P = m_P*c**20/k_B # || (h_2pi*c**5/G*k_B**2)**0.5 - temperatura de Planck (K)