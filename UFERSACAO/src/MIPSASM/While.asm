# Salvar 

Loop:	sll $t1, $s3, 2		# $t1 = 4*1
	add $t1, $t1, $s6	# $t1 = endereço de save[i]
	lw $t0, 0($t1)		# $t0 = save[i]
	bne $t0, $s5, Exit	# vá para exit se save[i] != k
	addi $s3, $s3, 1	# i = i + 1
	j Loop
Exit:
