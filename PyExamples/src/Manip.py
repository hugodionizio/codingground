#coding: utf-8
string1 = str('')
string2 = str('ararada')
num = 0
count = 0
char = 'a'
char2 = 'u'

count1 = 0
lgc = 1

while num < len(string2): 		# localizar e contar
	if string2[num] == char:
		count = count + 1
	num = num + 1
print count

if count > 0:
	num = 0
	lim = len(string2)
	while num < lim and lgc != 3 and lgc != 0:
		if string2[0] == char:
			lgc = int(raw_input('Caractere encontrado. Substituir (0 = Nenhum; 1 = Pular; 2 = Este; 3 = Todos)? '))
			if lgc == 3: string2 = string2.replace(char,char2)
			elif lgc == 2:
					string2 = string2.replace(char,char2,1)
					count1 = count1 + 1
			if lgc == 0: count = 0
			elif lgc != 3: count = count - 1
		string1 = string1 + string2[0]
		string2 = string2[1:]
		print string1 + '|' + string2
		num = num + 1
count = count + count1
string1 = string1 + string2
print string1 + ': ' + str(count) + ' substituições'
