#coding: utf-8
import random

x = range(3)
y = x[:]
random.shuffle(y)

print str(x) + '(aleatório) = ' + str(y)

z = 0
while x != y:
	random.shuffle(y)
	z += 1
	print y

print z
