def paralelo(*x):
	Req = 0
	var_origem = 0
	var_final = 0

	while var_final < len(x):
		Req+=1/float(x[var_final])
		var_final+=1

	return 1/Req

def triangulo(x,y,z):
	return x*z/(x+y+z)

def estrela(x,y,z):
	return (x*y+x*z+y*z)/z
