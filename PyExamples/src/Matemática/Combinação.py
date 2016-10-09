string1 = 'boa'

valor1 = len(string1)
valor2 = valor1 - 1

valor3 = 2
valor4 = valor1 - valor3

while valor2 >= 1:
	valor1 = valor1 * valor2
	valor2 = valor2 - 1

valor2 = valor4 - 1

while valor2 >= 1:
	valor4 = valor4 * valor2
	valor2 = valor2 - 1

valor5 = valor3
valor2 = valor5 - 1

while valor2 >= 1:
	valor5 = valor5 * valor2
	valor2 = valor2 - 1

valor1 = valor1/(valor4*valor5)

print 'Combinaciaum (' + (string1) + ',' + str(valor3) + ') = ' + str(valor1)
