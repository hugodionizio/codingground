string1 = ''
string2 = 'buzinas'
mem = string2

print string1 + ' ' + string2

string1 = string1 + string2
string2 = ''

print string1 + ' ' + string2

string1 = ''
string2 = mem

string1 = string1 + string2[:3]
string2 = string2[3:]

print string1 + ' ' + string2

string1 = ''
string2 = mem

string1 = string1 + string2[3:]
string2 = string2[:3]

print string1 + ' ' + string2

string1 = ''
string2 = mem

string1 = string1 + string2[2:-3]
string2 = string2[:2] + string2[-3:]

print string1 + ' ' + string2

string1 = ''
string2 = mem

string1 = string1 + string2[2] + string2[-3]
string2 = string2[:2] + string2[3:-3] + string2[-2:]

print string1 + ' ' + string2
