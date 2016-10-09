import time

x='a'

while x != '':
	tempo = time.time()
	x = raw_input()
	print time.time() - tempo
#	print '%s' % x
