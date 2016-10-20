	# Instruções para soma e subtração
	# f = (g + h) - (i + j)

	# $0 = f
	# $1 = g
	# $2 = h
	# $3 = 1
	# $4 = j

	add $t0,$s1,$s2
	add $t1,$s3,$s4
	sub $s0,$t0,$t1
