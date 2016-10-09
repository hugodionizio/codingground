#coding: utf-8
x=['-','9','0','.5','5','abacate','^','-','9','0','.7','9']
z = 0

while z <= len(x):
	print x[:z]
	z+=1

V = 110
R1 = 200
R2 = 200
V1 = 50
V2 = 60
I1 = 0
I2 = 0

def relay(V):
	if V > 0:
		I1 = V1/R1
		I2 = 0
	else:
		I2 = V2/R2
		I1 = 0
	return I1

print relay(0)
print relay(110)
