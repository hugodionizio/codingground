string1 = raw_input('Digite um texto: ')
string2 = string1
string3 = ''
var1 = 0
var2 = 0

while var1 < len(string1): 		# localizar e contar
	var2 = 0
#	print string1[var1] + ' ' + string1[var2]
	while var2 < len(string1) and var1 < len(string1):
#		print '2' + string1[var1] + ' ' + string1[var2]
		if string1[var1] == string1[var2] and var1 != var2:
			string1 = string1[:var2] + string1[var2+1:]
		var2 = var2 + 1
	var1 = var1 + 1

var1 = 0
var2 = 0
count = 0

string3 = list(string1)

while var1 < len(string1):
#	print var1
	var2 = 0
	count = 0
	while var2 < len(string1) and var1 < len(string1):
#		print var2
#		print ''.join(string3)
		if string1[var1] < string1[var2]:
			count = count + 1
		if var2 == len(string1) - 1:
			string3[count] = string1[var1]
		var2 = var2 + 1
	var1 = var1 + 1

string3 = ''.join(string3)

print string2 + ' em ordem crescente: ' + string3
