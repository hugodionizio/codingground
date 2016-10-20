	# Instruções para a transferência de dados (Linguagem de Máquina I - slide 25)
	# g = h + A[8]

	# $s1 = g
	# $s2 = h
	# $s3 = A

	lw $t0, 32($s3) # $t0 = A[8] | 8*4 bytes de Inteiros
	add $s1,$s2,$t0 # $s1 = $s2 + $t0
