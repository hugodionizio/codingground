#coding: utf-8
import string

operadores = "+-*/^="

var_nomes = list("abcdefgh")
#var_nomes = list("a1")
var_constantes = ['-900.5','-800.7','-2.5','-1','1','1.5','2','900']
var_pottencias_1 = ['600.4','2','1.5','1','-1','-1.5','-2','-900.5']
var_posicionamento = 0

Eq = ''
while var_posicionamento < len(var_nomes):
	if str(var_constantes[var_posicionamento]) > '1':
		if var_nomes[var_posicionamento] >= '0' and var_nomes[var_posicionamento] <= '9':
			Eq = Eq + '+' + var_constantes[var_posicionamento]
		else:
			Eq = Eq + '+' + var_constantes[var_posicionamento] + var_nomes[var_posicionamento]
	elif str(var_constantes[var_posicionamento]) == '1':
		Eq = Eq + '+' + var_nomes[var_posicionamento]
	elif str(var_constantes[var_posicionamento]) == '-1':
		Eq = Eq + '-' + var_nomes[var_posicionamento]
	else:
		if var_nomes[var_posicionamento] >= '0' and var_nomes[var_posicionamento] <= '9':
			Eq = Eq + var_constantes[var_posicionamento]
		else:
			Eq = Eq + var_constantes[var_posicionamento] + var_nomes[var_posicionamento]
	if str(var_pottencias_1[var_posicionamento]) != '1' and str(var_pottencias_1[var_posicionamento]) != '0':
		Eq = Eq + '^' + var_pottencias_1[var_posicionamento]
	var_posicionamento+=1

Eq = Eq + "=0"

if Eq[0] == '+':
	Eq = Eq[1:]
	
print Eq

Eq = raw_input("Digite a equação: ")

if string.find(Eq,"=0") > -1:
	Eq = Eq[:-2]

var_nomes = range(string.count(Eq,'+') + string.count(Eq,'-') + string.count(Eq,'*') + string.count(Eq,'/') + string.count(Eq,'=') + 1 - string.count(Eq[0],'-') - string.count(Eq,'=-') - string.count(Eq,'^-'))
var_constantes = var_nomes[:]
var_pottencias_1 = var_nomes[:]
var_posicionamento = 0
var_origem = 0
var_final = 0

# Coletando variáveis
while var_posicionamento < len(var_nomes):
	if string.find(operadores,Eq[var_final]) != -1:
		var_origem+=1
		var_final==var_origem
	var_final+=1
	if var_final == var_origem:
		var_final+=1
	if var_final + 1 < len(Eq):
		while string.find(operadores,Eq[var_final]) == -1:
			if (Eq[var_origem] >= '0' and Eq[var_origem] <= '9' or Eq[var_origem] == '.') and var_origem < len(Eq):
				var_origem+=1
			var_final+=1
			if var_final == len(Eq): break
	if Eq[var_origem] >= '0' and Eq[var_origem] <= '9':
		var_nomes[var_posicionamento] = '1'
	else:
		var_nomes[var_posicionamento] = Eq[var_origem:var_final]
	if var_final < len(Eq):
		if Eq[var_final] == '^':
			var_final+=1
			if Eq[var_final] == '-':
				var_final+=1
			while string.find(operadores,Eq[var_final]) == -1:
				var_final+=1
				if var_final == len(Eq): break
	var_origem = var_final
	var_posicionamento+=1

# Coletando constantes
var_posicionamento = 0
var_origem = 0
var_final = 0

k = 1
while var_posicionamento < len(var_nomes):
	while ((Eq[var_final] >= '0' and Eq[var_final] <= '9') or (var_final == var_origem and Eq[var_origem] == '+') or (var_final == var_origem and Eq[var_origem] == '-') or Eq[var_final] == '.') and var_final < len(Eq):
		var_final+=1
		if var_final == len(Eq): break
	if var_final == var_origem:
		var_final+=1
	if (Eq[var_final-1] < '0' or Eq[var_final-1] > '9' or Eq[var_final-1] == '+') and Eq[var_origem] != '-':
		var_constantes[var_posicionamento] = k
	elif (Eq[var_final-1] < '0' or Eq[var_final-1] > '9' or Eq[var_final-1] == '+') and Eq[var_origem] == '-':
		var_constantes[var_posicionamento] = -k
	else:
		var_constantes[var_posicionamento] = k*float(Eq[var_origem:var_final])
	if var_final == len(Eq): break
	while string.find(operadores,Eq[var_final]) == -1 and var_final < len(Eq):
		var_final+=1
		if var_final == len(Eq): break
	if var_final < len(Eq):
		if Eq[var_final] == '^':
			var_final+=1
			if Eq[var_final] == '-':
				var_final+=1
			while ((Eq[var_final] >= '0' and Eq[var_final] <= '9') or Eq[var_final] == '.' or string.find(operadores,Eq[var_final]) == -1) and var_final < len(Eq):
				var_final+=1
				if var_final == len(Eq): break
	if var_final < len(Eq):
		if Eq[var_final] == '=':
			var_final+=1
			k = -1
	var_origem = var_final
	var_posicionamento+=1

# Coletando potências
var_posicionamento = 0
var_origem = 0
var_final = 0
k = 1

while var_posicionamento < len(var_nomes):
	if string.find(operadores,Eq[var_origem]) != -1:
		var_origem+=1
 	while var_origem < len(Eq) and string.find(operadores,Eq[var_origem]) == -1:
		var_origem+=1
	if var_origem < len(Eq):
		if Eq[var_origem] == '^':
			var_origem+=1
			var_final = var_origem
			if Eq[var_final] == '-':
				var_final+=1
			while var_final < len(Eq) and (Eq[var_final] >= '0' or Eq[var_final] == '.') and string.find(operadores,Eq[var_final]) == -1:
				var_final+=1
			var_pottencias_1[var_posicionamento] = k*float(Eq[var_origem:var_final])
			var_origem = var_final+1
		else:
			var_pottencias_1[var_posicionamento] = k
	else:
		var_pottencias_1[var_posicionamento] = k
	var_posicionamento+=1

print "var_nomes = " + str(var_nomes)
print "var_constantes = " + str(var_constantes)
print "var_potências = " + str(var_pottencias_1)

var_nome = ''
var_constante = 1
var_pottencia = 1

if string.find(Eq,'=') == -1:
	Eq = Eq + "=0"

print "Equação geral: %s" % Eq
print "Operação da esquerda: %s" % Eq[:string.find(Eq,'=')]
print "Operação da direita: %s" % Eq[string.find(Eq,'=')+1:]

var_nome = Eq[0]

if string.find(Eq[:string.find(Eq,'=')],var_nome) > -1:
	print "Operação da esquerda"
	Eq = string.replace(Eq,var_nome,'')
	Eq = var_nome + '=' + Eq[string.find(Eq,'=')+1:] + '-' + '(' + Eq[:string.find(Eq,'=')]
elif string.find(Eq[string.find(Eq,'=')+1:],var_nome) > -1:
	print "Operação da direita"
	Eq = string.replace(Eq,var_nome,'')
	Eq = var_nome + '=' + Eq[:string.find(Eq,'=')] + '-' + Eq[string.find(Eq,'=')+1:]
else:
	print "A variável \"%s\" não pertence a %s" % (var_nome,Eq)

Eq = string.replace(Eq,'++','+')
Eq = string.replace(Eq,'--','+')
Eq = string.replace(Eq,'+-','-')
Eq = string.replace(Eq,'-+','-')
Eq = string.replace(Eq,'(+','(')

if Eq[0] == '+':
	Eq = Eq[1:]
if Eq[len(Eq)-1] == '+' or Eq[len(Eq)-1] == '-':
	Eq = Eq[:len(Eq)-1]

Eq = Eq + ')'

print Eq
