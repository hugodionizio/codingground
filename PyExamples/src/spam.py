#coding: utf-8
#int next, gabarito, uniaum;
print 2 ** 8 # Eleva a uma potência
print 'the bridge side ' + 'of life' # + significa concatenação
import sys
print sys.platform
num1 = 0
num2 = 0
print '-  0  1  2  3  4  5  6  7  8  9'
while num1 < 10:
	barra = str(num1)
	num2 = 0
	while num2 < 10:
		if num1 - num2 > -1:
			barra = barra + '  ' + str(num1 - num2)
		else:
			barra = barra + ' ' + str(num1 - num2)
		num2 = num2 + 1
	num1 = num1 + 1
	print barra
valor = 2
print '\nQuanto é ' + str(valor) + ' + ' + str(valor) + '?'
next = int(raw_input())
#print next
gabarito = valor + valor
uniaum = str(valor) + str(valor)
uniaum = int(uniaum)
#print uniaum
if next == gabarito:
	print 'Isso!'
elif next == uniaum:
	print 'Isso é uma operação aritmética!'
elif next < gabarito:
	print 'É maior que isso!'
elif next > gabarito:
	print 'É menor que isso!'
else:
	print 'Errado!'


# int = [signal][decimal]: 2 = [1][1][0]; -3 = [0][1][1]; n = [a1]...[an], {a1,...,an e [0:1]} => decimal = [a1]...[a4]
# -9 = 01001; -8 = 01000; -7 = 00111; -6 = 00110; -5 = 00101; -4 = 00100; -3 = 00011; -2 = 00010; -1 = 00001;
# 0 = 00000; 1 = 10001; 2 = 10010; 3 = 10011;	4 = 10100; 5 = 10101; 6 = 10110; 7 = 0111;		8 = 11000; 9 = 11001;
# 10 (A) = 11010; 11 (B) = 11011; 12 (C) = 11100; 13 (D) = 11101; 14 (E) = 11110; 15 (F) = 11111
# char = [a1]...[a8]
# word = [char1][char2] = [a1]...[a16]
# dword = [word1][word2] = [char1]...[char4] = [a1]...[a32]
