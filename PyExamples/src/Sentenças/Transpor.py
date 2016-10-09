string1 = str('')
string2 = raw_input('Digite um texto: ')

print string1 + '|' + string2

num2 = len(string2)
while num2 > 0:
	string1 = string1 + string2[0]
	string2 = string2[1:]
	print string1 + '|' + string2
	num2 = num2 - 1

num2 = len(string1)
while num2 > 0:
	string2 = string1[len(string1)-1] + string2
	string1 = string1[:-1]
	print string1 + '|' + string2
	num2 = num2 - 1
