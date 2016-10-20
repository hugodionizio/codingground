# Armazenar a diferença de duas somas, então mostrar

	.data
	.text 
	add $t0,$zero,4	# g (inicializando g)
	add $t1,$zero,3	# h (inicializando h)
	add $t2,$zero,2	# i (inicializando i)
	add $t3,$zero,1	# j (inicializando j)
	add $t4,$t0,$t1	# s1=g+h
	add $t5,$t2,$t3	# s2=i+j
	sub $s0,$t4,$t5	# f=s1-s2
