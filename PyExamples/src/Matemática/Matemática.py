#coding: utf-8
import math

# ponto, reta, polígono, poliedro

def PA(a1,n,r):	return a1+(n-1)*r
def SPA(a1,an,n):	return n*(a1+an)/2
def PG(a1,n,q):	return a1*q**(n-1)
def SPG_N(a1,n,q):	return a1*(q**n-1)/(q-1)
def SPG_AN(a1,an,q):	return (an*q-a1)/(q-1)
def SPG_I(a1,q):	a1/(1-q)
def PPG(a1,n,q):	return a1**n*q**(n*(n-1)/2)

def QUADRADO_LADO(l):
	QUADRADO =      [
			l, # LADO
			l*2**0.5, # DIAGONAL
			4*l, # PERÍMETRO
			l**2 # ÁREA
			]
	return QUADRADO

def QUADRADO_PERIMETRO(p):
	QUADRADO =      [
			p/4, # LADO
			(p/4)*2**0.5, # DIAGONAL
			p, # PERÍMETRO
			(p/4)**2 # ÁREA
			]
	return QUADRADO

def QUADRADO_DIAGONAL(d):
	QUADRADO =      [
			d/2**0.5, # LADO
			d, # DIAGONAL
			4*2**0.5, # PERÍMETRO
			d**2/2 # ÁREA
			]
	return QUADRADO

def QUADRADO_AREA(a):
	QUADRADO =      [
			a**0.5, # LADO
			a**0.5*2**0.5, # DIAGONAL
			4*a**0.5 # PERÍMETRO
			a # ÁREA
			]
	return QUADRADO

def NOVO_QUADRADO(L=1):	return QUADRADO_LADO(L)

def CLASSE_QUADRADO(L=1):
	QUADRADO_BASE = NOVO_QUADRADO(L)
	class QUADRADO:
		LADO = QUADRADO_BASE[0]
		DIAGONAL = QUADRADO_BASE[1]
		PERIMETRO = QUADRADO_BASE[2]
		AREA = QUADRADO_BASE[3]

def PRISMA_B(a,l):	return a*l
def PRISMA_V(b,h):	return b*h

def PARALELEP_V(B,h):	return PRISMA_V(B,h)

def DIAGONAL_F(a):	return a*2**0.5
def DIAGONAL_F(a):	return a*3**0.5
def S(a):	return 6*a**2
def CUBO_V(a):	return PARALELEP_V(PRISMA_B(a,a),a)

def TRIANG_EQ_H(a):	return a*3**0.5/2
def TRIANG_EQ_S(a):	return a**2*3**0.5/4

def HEXAG_R_B(a):	return 6*TRIANG_EQ_S(a)
def HEXAG_R_S_L(a,l):	return 6*a*l
def HEXAG_R_S_TV(a,l):	return 2*HEXAG_R_B(a)+HEXAG_R_S_L(a,l)
def HEXAG_R_V(a,h):	return HEXAG_R_B(a)*h

def PIRAMIDE_H_AP_B(l):	return l*3**0.5/2
def PIRAMIDE_H_AP_L(l,h):	return (PIRAMIDE_H_AP_B(l)**2+h**2)**0.5
def PIRAMIDE_H_S_L(l.m):	return (m**2+(l/2)**2)**0.5
def PIRAMIDE_H_B(l):	return 6*l/2*PIRAMIDE_H_AP_B(l)
def PIRAMIDE_H_L(l,h):	return 6*l/2*PIRAMIDE_H_AP_L(l,h)
def PIRAMIDE_H_S(l,h):	return PIRAMIDE_H_L(l,h)+PIRAMIDE_H_B(l)
def PIRAMIDE_H_S_TV(d,l,h):	return d**2*PIRAMIDE_H_B(l)/h**2
def PIRAMIDE_H_V(l,h):	return (1/3)*PIRAMIDE_H_B(l)*h
def PIRAMIDE_H_V_TC(l,l_2,h):	return (h/3)*(PIRAMIDE_H_B(l)+(PIRAMIDE_H_B(l)*PIRAMIDE_H_B(l_2))**0.5+PIRAMIDE_H_B(l_2))

def PIRAMIDE_Q_A(b):	return b**0.5
def PIRAMIDE_Q_AP_B(l):	return l/2
def PIRAMIDE_Q_H(m,l):	return (m**2-PIRAMIDE_Q_AP_B(l)**2)**0.5
def PIRAMIDE_Q_S_L(l):	return (m**2+(l/2)**2)**0.5
def PIRAMIDE_Q_L(l,m):	return 4*l/2*m
def PIRAMIDE_Q_S(l,m,b):	return PIRAMIDE_Q_L(l,m)+b
def PIRAMIDE_Q_S_TV(d,b,m,l):	return d**2*b/(PIRAMIDE_Q_H(m,l))**2
def PIRAMIDE_Q_V(b,h):	return (1/3)*b*h
def PIRAMIDE_Q_V_TC(b,b_2,h):	return (h/3)*(b+(b*b_2)**0.5+b_2)

def PIRAMIDE_T_B(l,a):	return l*a
def PIRAMIDE_T_V(l,a,h):	return (1/3)*PIRAMIDE_T_B(l,a)*h
def PIRAMIDE_T_V_TC(l,a,l_2,a_2,h):	return (h/3)*(PIRAMIDE_T_B(l,a)+(PIRAMIDE_T_B(l,a)*PIRAMIDE_T_B(l_2,a_2))**0.5+PIRAMIDE_T_B(l_2,a_2))

def TETRAEDRO_A(a):	return (a**2-(a*3**0.5/3)**2)**0.5
def TETRAEDRO_S_F(a):	return a**2*3**0.5
def TETRAEDRO_S(a):	return 4*TETRAEDRO_S_F(a)
def TETRAEDRO_S_TV(d,b,a):	return d**2*TETRAEDRO_S(a)/(TETRAEDRO_H(a))**2
def TETRAEDRO_V(b,h):	return (1/3)*b*h
def TETRAEDRO_V_TC(b,b_2,h):	return (h/3)*(b+(b*b_2)**0.5+b_2)

def CILINDRO_E_H(r):	return 2*r

def CILINDRO_C_R_S_L(r,h):	return 2*math.pi*r*h
def CILINDRO_C_R_B(r):	return math.pi*r**2
def CILINDRO_C_R_S(r,h):	return CILINDRO_C_R_S_L(r,h)+2*CILINDRO_C_R_B(r)
def CILINDRO_C_R_V(r,h):	return math.pi*r**2*h

def CONE_R_B(r):	return math.pi*r**2
def CONE_R_G(r,h):	return (r**2+h**2)**0.5
def CONE_R_R_TV(r,h,d):	return d*r/h
def CONE_R_S_TV(b,h,d):	return (d/h)**2*b
def CONE_R_S_ST(r,l):	return l*r/2
def CONE_R_S_L(r,h):	return math.pi*r*CONE_R_G(r,h)
def CONE_R_S(r,h):	return CONE_R_S_L(r,h)+CONE_R_B(r)
def CONE_R_S_TC(r,r_2,h):	return CONE_R_S_L(r+r_2,h)+CONE_R_B(r)+CONE_R_B(r_2)
def CONE_R_V(r,h):	return (1/3)*CONE_R_B(r)*h
def CONE_R_V_TC(r,r_2,h):	return (h/3)*(CONE_R_B(r)+(CONE_R_B(r)*CONE_R_B(r_2))**0.5+CONE_R_B(r_2))

def CONE_E_G(r):	return 2*r
def CONE_E_H(r):	return r*3**0.5

def ESFERA_SEC(r,d):	 return (r**2-d**2)**0.5
def ESFERA_P_D(r,d):	 return (2*r*(r-d))**0.5
def ESFERA_V(r):	 return (4/3)*math.pi*r**3
def ESFERA_S(r):	 return 4*math.pi*r**2
def ESFERA_R_I_CB(a):	 return a/2
def ESFERA_R_C_CB(a):	 return a*3**0.5/2
def ESFERA_R_I_T(a):	 return a*6**0.5/12
def ESFERA_R_C_T(a):	 return a*6**0.5/4
def ESFERA_R_I_CN(r,h):	 return r*((r**2+h**2)**0.5-r)/h
def ESFERA_R_C_CN(r,h):	 return (r**2+h**2)/(2*h)

def P(x):	return math.factorial(x)
def A(x,y):	return P(x)/P(x-y)
def C(x,y):	return P(x)/(P(y)*P(x-y))
def CC(x,y):	return C(x,x-y)
def CS(x,y):	return C(x-1,y-1)+C(x,y)
def AR(x,y):	return x**y

def PR(*x):
	permut = 0
	element = 1
	var_final = 0

	permut = float(x[0])

	for var_final in range(len(x)):
		var_final+=1
		if var_final == len(x): break
		element*=P(float(x[var_final]))

	return permut/element

def CB(x,y):	return C(x,y)

def U(A,B):	return 0
def U_INV(A,B):	return 0
def COMP(A,U):	return len(U)-len(A)

def DISTANCIA(x1,y1,z1,x2,y2,z2): return ((x2-x1)**2+(y2-y1)**2+(z2-z1)**2)**0.5

x1 = float(raw_input('Situe x1: '))
y1 = float(raw_input('Situe y1: '))
z1 = float(raw_input('Situe z1: '))
x2 = float(raw_input('Situe x2: '))
y2 = float(raw_input('Situe y2: '))
z2 = float(raw_input('Situe z2: '))
d = DISTANCIA(x1,y1,z1,x2,y2,z2)
#D = pow((x2-x1)**2+(y2-y1)**2+(z2-z1)**2,0.5)

angx = math.asin((x2-x1)/d)*180/math.pi
angy = math.acos((y2-y1)/d)*180/math.pi
angz = math.acos((z2-z1)/d)*180/math.pi
r = d/2
Per = 2*math.pi*r
A = math.pi*(r**2)
V = (4/3)*math.pi*(r**3)

l1=d/2**0.5
l2=d/3**0.5

def VELOCIDADE(d,t): return d/t
def DESLOCAMENTO(v,t): return v*t
def ACELERAMENTO(v,t): return v/t
def FORCA(m,a): return m*a
def PRESSAO(F,A): return F/A
def ENERGIA(F,d): return F*d
def DENSIDADE(m,V): return m/V

print 'Deslocamento entre P1 e P2 = %f m\nÂngulo de x = %f rad\nÂngulo de y = %f rad\nÂngulo de z = %f rad\nRaio = %f m\nPerímetro = %f m\
	\nÁrea = %f m^2\nVolume = %f m^3\nLado do cubo externo = %f m\nLado do cubo interno = %f m' % (d,angx,angy,angz,r,Per,A,V,l1,l2)

t = float(raw_input('Determine o tempo (em s): '))

v = VELOCIDADE(d,t)
d = DESLOCAMENTO(v,t)
a = ACELERAMENTO(v,t)

print 'Velocidade = %f m/s\nPosicionamento atual = %f m\nAceleração atual = %f m/s^2' % (v,d,a)

#ascii = 0
#array = ''
#while ascii < 255:
#	array = array + ' %c' % ascii
#	ascii = ascii + 1
#print array

m = float(raw_input('Informe a massa: (kg): '))

F = FORCA(m,a)
P = PRESSAO(F,A)
E = ENERGIA(F,d)
D = DENSIDADE(m,V)

print 'Peso = %f N\nPressão = %f Pa\nEnergia = %f J\nDensidade = %f kg/m^3' % (F,P,E,D)
