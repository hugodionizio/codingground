string1 = 'porta'
string2 = 'portachata'
string3 = string1
string4 = string2
contido = 0
var1 = 0
var2 = 0

while var1 < len(string1):
	var2 = 0
	while var2 < len(string1) and var1 < len(string1):
		if string1[var1] == string1[var2] and var1 != var2:
			string1 = string1[:var2] + string1[var2+1:]
		var2 = var2 + 1
	var1 = var1 + 1

var1 = 0

while var1 < len(string2):
	var2 = 0
	while var2 < len(string2) and var1 < len(string2):
		if string2[var1] == string2[var2] and var1 != var2:
			string2 = string2[:var2] + string2[var2+1:]
		var2 = var2 + 1
	var1 = var1 + 1

if len(string1) < len(string2):
	contido = string1
	string1 = string2
	string2 = contido
	contido = 1

#print string1 + ' ' + string2

num1 = len(string1)-1
num2 = len(string2)-1
var1 = 0
var2 = 0
count = -1

print num1
print num2

while var1 <= num2:
	var2 = 0
	while var2 <= num1:
		if string1[var2] == string2[var1]:
			count = count + 1
			print string1[var2] + ' = ' + string2[var1]
		var2 = var2 + 1
	var1 = var1 + 1

print count

if count == num2:
	if len(string3) == len(string4): print string3 + ' eh anagrama de ' + string4
	elif contido == 0: print string3 + ' contem ' + string4
	else: print string3 + ' estah contido em ' + string4
else: print string3 + ' naum contem ' + string4
