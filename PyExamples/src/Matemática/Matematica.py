#coding: utf-8
import math, string, random

def MDC(x1,x2):
	y1 = x1
	y2 = x2
	mmc = 1
	mdc = 1

	while x1 > 1 and x2 > 1:
		if x1 % mmc == 0 and x2 % mmc == 0:
			mdc = mdc * mmc
			x1/=mmc
			x2/=mmc
		elif x1 == mmc or x2 == mmc:
			mdc = y1 * y2
			break
		mmc+= 1
		if x1 < mmc or x2 < mmc:
			mmc = 1
	return mdc

def DEC_BIN(num1):
	numd = num1
	res = ''
	while num1 > 0:
		res = res + str(num1 % 2)
		num1 = int(num1/2)
	res = res[::-1]
	var = 0
	while var <= numd:
		num1 = var
		res = ''
		while num1 > 0:
			res = res + str(num1 % 2)
			num1 = int(num1/2)
		res = res[::-1]
		var = var + 1
	return res

# Sistemas de Equações Lineares
def SOMAR_LINHAS(LINHA_X,LINHA_Y):
	LINHA_R=range(len(LINHA_X))
	for i in range(len(LINHA_X)):
		LINHA_R[i]=LINHA_X[i]+LINHA_Y[i]
	return LINHA_R

def ESCALAR_LINHAS(k,LINHA_X):
	LINHA_R=range(len(LINHA_X))
	for i in range(len(LINHA_X)):
			LINHA_R[i]=k*LINHA_X[i]
	return LINHA_R

def SUBTRAIR_LINHAS(LINHA_X,LINHA_Y):
	return SOMAR_LINHAS(ESCALAR_LINHAS(-1,LINHA_Y),LINHA_X)

def SOMAR_ESCALA_LINHAS(k,LINHA_X,LINHA_Y):
	return SOMAR_LINHAS(ESCALAR_LINHAS(k,LINHA_X),LINHA_Y)

def ESCALAR_SOMAS_LINHAS(k,LINHA_X,LINHA_Y):
	return ESCALAR_LINHAS(k,SOMAR_LINHAS(LINHA_X,LINHA_Y))

def ESCALAR_SUBTR_SOMAS_LINHAS(k,LINHA_X,LINHA_Y):
	return ESCALAR_LINHAS(k,SUBTRAIR_LINHAS(LINHA_X,LINHA_Y))

def PERMUTAR_LINHAS(LINHA_X,LINHA_Y):
	LINHA_TEMP=LINHA_X
	LINHA_X=LINHA_Y
	LINHA_Y=LINHA_TEMP

# Progressões Aritmética e Geométrica
def PA(a1,n,r):	return a1+(n-1)*r
def SPA(a1,an,n):	return n*(a1+an)/2
def PG(a1,n,q):	return a1*q**(n-1)
def SPG_N(a1,n,q):	return a1*(q**n-1)/(q-1)
def SPG_AN(a1,an,q):	return (an*q-a1)/(q-1)
def SPG_I(a1,q):	a1/(1-q)
def PPG(a1,n,q):	return a1**n*q**(n*(n-1)/2)

# ponto, reta, polígono, poliedro
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
			4*a**0.5, # PERÍMETRO
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

def ANG_X(x2,x1,d):	return math.asin((x2-x1)/d)*180/math.pi
def ANG_Y(y2,y1,d):	return math.acos((y2-y1)/d)*180/math.pi
def ANG_Y(z2,z1,d):	return math.acos((z2-z1)/d)*180/math.pi
def RAIO(d):	return d/2
def PERIMETRO(r):	return 2*math.pi*r
def CIRCULO_S(r):	return math.pi*(r**2)
def VOLUME(r):	return (4/3)*math.pi*(r**3)

def PRISMA_B(a,l):	return a*l
def PRISMA_V(b,h):	return b*h

def PARALELEP_V(B,h):	return PRISMA_V(B,h)

def DIAGONAL_F(a):	return a*2**0.5
def DIAGONAL_C(a):	return a*3**0.5
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
def PIRAMIDE_H_S_L(l,m):	return (m**2+(l/2)**2)**0.5
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

def FATORIAL(string1):
	valor1 = len(string1)
	valor2 = valor1 - 1
	while valor2 >= 1:
		valor1 = valor1 * valor2
		valor2 = valor2 - 1
	return valor1

# Combinatória
def PERMUTAR(x):	return math.factorial(x)
def ARRANJO(x,y):	return PERMUTAR(x)/PERMUTAR(x-y)
def COMBINAR(x,y):	return PERMUTAR(x)/(PERMUTAR(y)*PERMUTAR(x-y))
def COMBINAR_C(x,y):	return COMBINAR(x,x-y)
def COMBINAR_STIEV(x,y):	return COMBINAR(x-1,y-1)+COMBINAR(x,y)
def ARRANJO_REPETIDO(x,y):	return x**y

def PERMUTAR_REPETIDO(*x):
	permut = 0
	element = 1
	var_final = 0

	permut = float(x[0])

	for var_final in range(len(x)):
		var_final+=1
		if var_final == len(x): break
		element*=P(float(x[var_final]))

	return permut/element

def COMBINAR_BINOMIO(x,y):	return COMBINAR(x,y)

# Conjuntos
def PERTINENCIA(string1,string2):
	string3 = string1
	string4 = string2
	contido = var1 = var2 = 0

	while var1 < len(string1):
		var2 = 0
		while var2 < len(string1) and var1 < len(string1):
			if string1[var1] == string1[var2] and var1 != var2:	string1 = string1[:var2] + string1[var2+1:]
			var2+= 1
		var1+= 1

	var1 = 0
	while var1 < len(string2):
		var2 = 0
		while var2 < len(string2) and var1 < len(string2):
			if string2[var1] == string2[var2] and var1 != var2:	string2 = string2[:var2] + string2[var2+1:]
			var2+= 1
		var1+= 1

	if len(string1) < len(string2):
		contido = string1
		string1 = string2
		string2 = contido
		contido = 1

	num1 = len(string1)-1
	num2 = len(string2)-1
	var1 = var2 = 0
	count = -1

	for var1 in range(num2+1):
		var2 = 0
		for var2 in range(num1+1):
			if string1[var2] == string2[var1]:
				count+= 1

	if count == num2:
		if len(string3) == len(string4): return "anagrama"
		elif contido == 0: return "contém"
		else: return "está contido"
	else: return "não contém"

def UNIR_CONJUNTO(A,B):
	C = A+B

	for var1 in range(len(C)):	# localizar e contar
		for var2 in range(len(C)):
			if C[var1] == C[var2] and var1 != var2:
				C = C[:var2] + C[var2+1:]
			if var2 + 1 == len(C): break
		if var1 + 1 == len(C): break
	return C

def INTERSECCIONAR(CONJUNTO_A,CONJUNTO_B):
	INTERSECCIONADO = ''
	for var1 in range(len(CONJUNTO_A)):
		for var2 in range(len(CONJUNTO_B)):
			if CONJUNTO_A[var1] == CONJUNTO_B[var2]:
				INTERSECCIONADO = INTERSECCIONADO + CONJUNTO_B[var2]
	var1 = 0
	while var1 < len(INTERSECCIONADO):
		var2 = 0
		while var2 < len(INTERSECCIONADO) and var1 < len(INTERSECCIONADO):
			if INTERSECCIONADO[var1] == INTERSECCIONADO[var2] and var1 != var2:
				INTERSECCIONADO = INTERSECCIONADO[:var2] + INTERSECCIONADO[var2+1:]
			var2+= 1
		var1+= 1
	return INTERSECCIONADO

def COMPLEMENTO(UNIVERSO,CONJUNTO):
	COMPLEMENTO = ''
	for var1 in range(len(UNIVERSO)):
		var2 = 0
		while var2 < len(CONJUNTO) and UNIVERSO[var1] != CONJUNTO[var2]:
			if var2 == len(CONJUNTO)-1:
				COMPLEMENTO = COMPLEMENTO + UNIVERSO[var1]
			var2+= 1
	var1 = 0
	while var1 < len(COMPLEMENTO):
		var2 = 0
		while var2 < len(COMPLEMENTO) and var1 < len(COMPLEMENTO):
			if COMPLEMENTO[var1] == COMPLEMENTO[var2] and var1 != var2:
				COMPLEMENTO = COMPLEMENTO[:var2] + COMPLEMENTO[var2+1:]
			var2+= 1
		var1+= 1
	return COMPLEMENTO

def SUBCONJUNTOS(string1):
	string2 = string1
	var1 = 0
	var2 = 0

	while var1 < len(string1): 		# localizar e contar
		var2 = 0
		while var2 < len(string1) and var1 < len(string1):
			if string1[var1] == string1[var2] and var1 != var2:
				string1 = string1[:var2] + string1[var2+1:]
			var2 = var2 + 1
		var1 = var1 + 1

	num1 = 2**len(string1)

	print string2 + ' tem ' + str(num1) + ' subconjuntos'


	numd = num1-1
	var1 = 0
	var2 = 0
	bar = ''

	while var1 <= numd:
		num1 = var1
		res = ''
		while num1 > 0:
			res = res + str(num1 % 2)
			num1 = int(num1/2)

		res = res[::-1]
		if var2 < len(string1) - len(res):
			while var2 <= len(string1) - len(res):
				res = '0' + res
				var2 = var2 + 1
		var2 = len(string1)
		while var2 > 0:
			if res[len(res)-var2] == '1':
				res = res.replace('1',string1[len(res)-var2],1)
			var2 = var2 - 1
		if len(res) != res.count('0'):
			res = res.replace('0','')
			bar = bar + ' (' + (res) + ')'
		else:
			bar = '(0)'
		var1 = var1 + 1

	return bar

# Matrizes
def NOVA_MATRIZ(LINHAS=0,COLUNAS=0):
	if LINHAS == 0:
		LINHAS=2
	if COLUNAS == 0:
		COLUNAS=LINHAS
	A=LINHAS*[range(COLUNAS)]
	for l in range(LINHAS):
		A[l]=A[l][:]
	return A+[0.0,0] # Matriz A + nova linha para memorizar os maiores elementos da matriz e com maior quantidade de digitos, respectivamente

def DIAGONAL_PRINCIPAL(MATRIZ):
	MATRIZ_TEMP=MATRIZ[:]
	d=0
	for l in range(len(MATRIZ_TEMP[0])):
		for c in range(len(MATRIZ_TEMP)-2):
			if (l == c):
				d+= MATRIZ_TEMP[l][c]
	return d

def SOMAR_MATRIZ(*MATRIZES):
	MATRIZ_TEMP=NOVA_MATRIZ(len(MATRIZES[0])-2,len(MATRIZES[0][0]))
	for l in range(len(MATRIZES[0])-2):
		for c in range(len(MATRIZES[0][0])):
			MATRIZ_TEMP[l][c]=0
	for SOMA in range(len(MATRIZES)):
		for l in range(len(MATRIZ_TEMP)-2):
			for c in range(len(MATRIZ_TEMP[0])):
				MATRIZ_TEMP[l][c]+= MATRIZES[SOMA][l][c]
		SOMA+=1
	return MATRIZ_TEMP

def ESCALAR_MATRIZ(*ELEMENTOS):
	ESCALAR = 1
	for i in range(len(ELEMENTOS)-1):
		ESCALAR*=ELEMENTOS[i]
	MATRIZ_TEMP=NOVA_MATRIZ(len(ELEMENTOS[-1])-2,len(ELEMENTOS[-1][0]))
	MATRIZ_1_TEMP=ELEMENTOS[-1][:]

	for l in range(len(MATRIZ_TEMP)-2):
		for c in range(len(MATRIZ_TEMP[0])):
			MATRIZ_TEMP[l][c] = ESCALAR*MATRIZ_1_TEMP[l][c]
	return MATRIZ_TEMP

def SUBTRAIR_MATRIZ(MATRIZ_1,MATRIZ_2):
	return SOMAR_MATRIZ(MATRIZ_1,ESCALAR_MATRIZ(-1,MATRIZ_2))

def MULTIPLICAR_MATRIZ(MATRIZ_1,MATRIZ_2):
	MATRIZ_TEMP=NOVA_MATRIZ(len(MATRIZ_1)-2,len(MATRIZ_1[0]))
	for l in range(len(MATRIZ_TEMP)-2):
		for c in range(len(MATRIZ_TEMP[0])):
			MATRIZ_TEMP[l][c]=0
	m=0
	for l in range(len(MATRIZ_TEMP)-2):
		n=0
		for c in range(len(MATRIZ_TEMP[0])):
			for z in range(len(MATRIZ_TEMP[0])):
				if n<len(MATRIZ_2[0]):
					MATRIZ_TEMP[l][c]+= MATRIZ_1[m][z]*MATRIZ_2[z][n]
					if m+1<len(MATRIZ_TEMP)-2:
						m+=1
					if n+1<len(MATRIZ_2[0]):
						n+=1
	return MATRIZ_TEMP

def TRANSPOR_MATRIZ(MATRIZ):
	MATRIZ_TEMP=NOVA_MATRIZ(len(MATRIZ[0]),len(MATRIZ)-2)
	for l in range(len(MATRIZ_TEMP)-2):
		for c in range(len(MATRIZ_TEMP[0])):
			MATRIZ_TEMP[l][c]= MATRIZ[c][l]
	return MATRIZ_TEMP

def IDENTIDADE(MATRIZ):
	MATRIZ_TEMP=NOVA_MATRIZ(len(MATRIZ[0]))
	for l in range(len(MATRIZ_TEMP[0])):
		for c in range(len(MATRIZ_TEMP[0])):
			if l == c:
				MATRIZ_TEMP[l][c]=1
			else:
				MATRIZ_TEMP[l][c]=0
	return MATRIZ_TEMP

def DETERMINANTE_MATRIZ(MATRIZ):
	if len(MATRIZ[0]) > 2:
		MATRIZ_NOVA=NOVA_MATRIZ(len(MATRIZ[0])-1)
		DETERMINANTE=0
		for i in range(len(MATRIZ[0])):
			k=0
			for j in range(len(MATRIZ[0])):
				if j != i:
					MATRIZ_NOVA[k]=MATRIZ[j][1:]
					k+=1
			DETERMINANTE+=(-1)**i*MATRIZ[i][0]*DETERMINANTE_MATRIZ(MATRIZ_NOVA)
	else:
		DETERMINANTE = MATRIZ[0][0]*MATRIZ[1][1]-MATRIZ[1][0]*MATRIZ[0][1]
	return DETERMINANTE

def COFATOR_MATRIZ(MATRIZ):
	MATRIZ_COFATOR=ALTERAR_MATRIZ(NOVA_MATRIZ(len(MATRIZ[0])))
	if len(MATRIZ) > 4:
		MATRIZ_MENOR=ALTERAR_MATRIZ(NOVA_MATRIZ(len(MATRIZ[0])-1))
	else:
		MATRIZ_MENOR=ALTERAR_MATRIZ(NOVA_MATRIZ())
	kl=0
	kc=0
	for m in range(len(MATRIZ[0])):
		for n in range(len(MATRIZ[0])):
			for l in range(len(MATRIZ[0])):
				for c in range(len(MATRIZ[0])):
#					print m,n,l,c,kl,kc
					if l != m and c != n:
						MATRIZ_MENOR[kl][kc]=MATRIZ[l][c]
						if kc+1 < len(MATRIZ_MENOR[0]):	kc+=1
						else:
							kc=0
							if kl+1 < len(MATRIZ_MENOR[0]):	kl+=1
							else:	kl=0
#			print m,n
			if len(MATRIZ) > 4: MATRIZ_COFATOR[m][n] = (-1)**(m+n)*DETERMINANTE_MATRIZ(MATRIZ_MENOR); #print '\n',MATRIZ_MENOR
			else: MATRIZ_COFATOR[m][n] = (-1)**(m+n)*MATRIZ_MENOR[m][n]
	return MATRIZ_COFATOR

def ADJUNTA_MATRIZ(MATRIZ):
	return TRANSPOR_MATRIZ(COFATOR_MATRIZ(MATRIZ))

def INVERTER_MATRIZ(MATRIZ):
	return ESCALAR_MATRIZ(1.0/DETERMINANTE_MATRIZ(MATRIZ),ADJUNTA_MATRIZ(MATRIZ))

def ALTERAR_MATRIZ(MATRIZ):
	MATRIZ_TEMP=MATRIZ[:]
	for l in range(len(MATRIZ_TEMP)-2):
		for c in range(len(MATRIZ_TEMP[0])):
			MATRIZ_TEMP[l][c]=round(10*math.cos(2*random.random()*math.pi),3)
			MATRIZ_TEMP[l][c]=int(10*math.cos(2*random.random()*math.pi))
#			MATRIZ_TEMP[l][c]=float(raw_input("Informe o elemento %dX%d: " % (l,c)))
	return MATRIZ_TEMP

def ALINHAR_MATRIZ(MATRIZ):
	MATRIZ_TEMP=MATRIZ[:]
	for l in range(len(MATRIZ_TEMP)-2):
		for c in range(len(MATRIZ_TEMP[0])):
			if MATRIZ_TEMP[-2] < MATRIZ_TEMP[l][c]:
				MATRIZ_TEMP[-2] = MATRIZ_TEMP[l][c] # maior valor
			if MATRIZ_TEMP[-1] < len(str(MATRIZ_TEMP[l][c])):
				MATRIZ_TEMP[-1] = len(str(MATRIZ_TEMP[l][c])) # dígitos do número
	return MATRIZ_TEMP

def DESENHAR_MATRIZ(MATRIZ):
	MATRIZ_TEMP=MATRIZ[:]
	MATRIZ_TEMP=ALINHAR_MATRIZ(MATRIZ_TEMP)
	for l in range(len(MATRIZ_TEMP)-2):
		print '|',
		for c in range(len(MATRIZ_TEMP[0])):
			print str(float(MATRIZ_TEMP[l][c])) + str((MATRIZ_TEMP[-1]-len(str(MATRIZ_TEMP[l][c])))*'0'),
		print '|'

def DECIMAIS_MATRIZ(MATRIZ):
	v=0
	if str(MATRIZ[-2])[-1] != '0':
		v = len(str(MATRIZ[-2])[string.find(str(MATRIZ[-2]),'.')+1:])
	return v

def TITULO_MATRIZES():
	TITULO_MATRIZ="MATRIZES"
	for i in range(len(TITULO_MATRIZ)):
		print (i)*str(int(10*random.random())),TITULO_MATRIZ[i],(len(TITULO_MATRIZ)-i-1)*str(int(10*random.random()))

# Plano Cartesiano
def DISTANCIA(x1,y1,z1,x2,y2,z2): return ((x2-x1)**2+(y2-y1)**2+(z2-z1)**2)**0.5

def VELOCIDADE(d,t): return d/t
def DESLOCAMENTO(v,t): return v*t
def ACELERAMENTO(v,t): return v/t
def FORCA(m,a): return m*a
def PRESSAO(F,A): return F/A
def ENERGIA(F,d): return F*d
def DENSIDADE(m,V): return m/V

#almaviva
