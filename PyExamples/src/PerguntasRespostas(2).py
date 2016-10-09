import random, time, math

LIMIT = 10

count = 0

tempo = 0
total_tempo = 0

answer = 0
z = 0

#op = raw_input("Digite o operador: ")

while answer == z:
	x = round(LIMIT*random.random())
	y = round(LIMIT*random.random())

	op = round(random.random())
	if op == 0:
		op = '+'
	else:
		op = '*'

# Operadores com duas variantes:
	if op == '+':
		z = x + y
	elif op == '-':
		z = x - y
	elif op == '*':
		z = x * y
	elif op == '/':
		z = round(x/y,3)
	elif op == '%':
		z = x % y
	elif op == '^':
		z = round(x**y,3)
	elif op == 'r':
		z = round(x**(1/y),3)
	elif op == 'log':
		z = round(math.log(x,y),3)
	elif op == 'atan':
		z = round(math.atan2(x,y),3)
	elif op == 'h':
		z = round(math.hypot(x,y),3)

# Operadores com uma variante:
	elif op == 's':
		z = round(math.sin(x*math.pi/180),4)
	elif op == 'c':
		z = round(math.cos(x*math.pi/180),4)
	elif op == 't':
		z = round(math.tan(x*math.pi/180),4)
	elif op == 'as':
		z = round(math.asin(x*180/math.pi),4)
	elif op == 'ac':
		z = round(math.acos(x*180/math.pi),4)
	elif op == 'at':
		z = round(math.atan(x*180/math.pi),4)
	elif op == 'sh':
		z = round(math.sinh(x),4)
	elif op == 'ch':
		z = round(math.cosh(x),4)
	elif op == 'th':
		z = round(math.tanh(x),4)
	elif op == 'ash':
		z = round(math.asinh(x),4)
	elif op == 'ach':
		z = round(math.acosh(x),4)
	elif op == 'ath':
		z = round(math.atanh(x),4)
	else:
		z = math.factorial(int(x))

	tempo = time.time()
	
	if op == '+' or op == '-' or op == '*' or op == '/' or op == '%' or op == '^' or op == 'r' or op == 'log' or op == 'atan' or op == 'h':
		answer = float(raw_input("Quanto equivale %d %s %d? " % (x,op,y)))
	else:
		answer = float(raw_input("Quanto equivale %s(%d)? " % (op,x)))

	tempo = time.time() - tempo
	total_tempo+= tempo

	print "Tempo de processamento cerebral = %f segundos" % tempo

	if answer != z:
#		print "Sua resposta foi %f, mas a resposta correta equivale a %f.\nEstude mais este assunto." % (answer,z)
		print "Estude mais este assunto. (%d acertos)\nTempo total = %f" % (count,total_tempo)
	else: print "OK"; count+=1
