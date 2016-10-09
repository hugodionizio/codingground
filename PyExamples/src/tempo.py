import time
#y=9
#print y
y=time.time()-time.time()
while y == 0 or y >= -1.53674316405e-06:
	y=time.time()-time.time()
	print 'y = ' + str(y)
#	raw_input()

#x=0
#while y < time.time()-time.time():
#	x+=1
#print x

z=0
while z < 100000:
	z=0
#	x = time.time()-time.time()
	while y < time.time()-time.time():
#		x = time.time()-time.time()
#		print x,
		z+=1
	print y, z,
#	if z < 10000: raw_input()
print z
