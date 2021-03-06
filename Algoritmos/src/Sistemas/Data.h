//Data: 27/11/2012 17:24

#include <string.h>

typedef struct {
	int Dia;
	int Mes;
	int Ano;
} Data;

// Interface (protótipos) ou índice da Biblioteca
bool ValidaData (int dia, int mes, int ano, Data *data);
bool FormaData (char *expressaoData, Data *data);
int DiasMes (int mes);
int SomaData (Data data, int dias);
int SubtracaoData (Data data, int dias);
bool PrintExtensoData (Data data);
Data Pascoa (int ano);
bool AnoBissexto (int ano);
bool SeparaData(Data data, int *dia, int *mes, int *ano);
Data GregorianaJuliana(Data dataGregoriana);
Data JulianaGregoriana(Data dataJuliana);
int DiaSemana(Data data);
Data SextaFeiraSanta (int ano);
Data Carnaval (int ano);
Data CorpusChristi (int ano);
bool Calendario (int ano);
bool ErroData();

bool teste () {
}

bool ValidaData (int dia, int mes, int ano, Data *data) {
	bool validade = false;

	if (ano > -1)
		switch (mes) {
			case 4:
			case 6:
			case 9:
			case 11: if (dia == 30) {
					data->Dia = dia;
					data->Mes = mes;
					data->Ano = ano;
					validade = true;
				}
				break;
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: if (dia == 31) {
					data->Dia = dia;
					data->Mes = mes;
					data->Ano = ano;
					validade = true;
				}
				break;
			case 2: if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
					if (dia == 29) {
						data->Dia = dia;
						data->Mes = mes;
						data->Ano = ano;
						validade = true;
					}
					else if (dia == 28) {
						data->Dia = dia;
						data->Mes = mes;
						data->Ano = ano;
						validade = true;
					}
				break;
			default: validade = false;
		}
		else validade = false;

	return validade;
}

bool FormaData (char *expressaoData, Data *data) {
	bool validade = false;
	int dia, mes, ano;

	if (strlen(expressao) == 10) {
		if (expressao[2] == '/' && expressao[5] == '/') {
			dia = (int)(expressao[0]-48)*10+(int)(expressao[1]-48);
			mes = (int)(expressao[3]-48)*10+(int)(expressao[4]-48);
			ano = (int)(expressao[6]-48)*1000+(int)(expressao[7]-48)*100+(int)(expressao[8]-48)*10+(int)(expressao[9]-48);
		}
	}
	validade = ValidaData(dia, mes, ano, data);

	return validade;
}

int DiasMesSemFevereiro (int mes) {
	int dias;

	switch (mes) {
		case 4:
		case 6:
		case 9:
		case 11: dias = 30; break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: dias = 31;
		case 2: dias = 28;
		default: {
			ErroData();
			dias = -366;
		}
	}

	return dias;
}

int SomaData (Data data, int dias) {
	int soma=0;

	if (ValidaData(data->dia, data->mes, data->ano, data) ==  true) {
		switch (mes) {
			case 12: soma+= DiasMes(data->mes);
			case 11: soma+= DiasMes(data->mes);
			case 10: soma+= DiasMes(data->mes);
			case 9: soma+= DiasMes(data->mes);
			case 8: soma+= DiasMes(data->mes);
			case 7: soma+= DiasMes(data->mes);
			case 6: soma+= DiasMes(data->mes);
			case 5: soma+= DiasMes(data->mes);
			case 4: soma+= DiasMes(data->mes);
			case 3: soma+= DiasMes(data->mes);
			case 2: if (AnoBissexto(ano) == true) {soma+= 29;}
				else {soma+= 28;}
			case 1: soma+= DiasMes(data->mes);
		}
		soma = soma - (DiasMes(data->mes) - data->dia) + dias;
	else {
		ErroData();
		soma = -366;
	}

	return soma;
}

int SubtracaoData (Data data, int dias) {
	int subtração=0;

	if (ValidaData(data->dia, data->mes, data->ano, data) ==  true) {
		switch (mes) {
			case 12: soma+= DiasMes(data->mes);
			case 11: soma+= DiasMes(data->mes);
			case 10: soma+= DiasMes(data->mes);
			case 9: soma+= DiasMes(data->mes);
			case 8: soma+= DiasMes(data->mes);
			case 7: soma+= DiasMes(data->mes);
			case 6: soma+= DiasMes(data->mes);
			case 5: soma+= DiasMes(data->mes);
			case 4: soma+= DiasMes(data->mes);
			case 3: soma+= DiasMes(data->mes);
			case 2: if (AnoBissexto(ano) == true) {soma+= 29;}
				else {soma+= 28;}
			case 1: soma+= DiasMes(data->mes);
		}
		soma = soma - (DiasMes(data->mes) - data->dia) - dias;
	else {
		ErroData();
		soma = -366;
	}

	return subtracao;
}

bool PrintExtensoData (Data data) {
	int validade = false;

	validade = ValidaData(data->dia, data->mes, data->ano, data);
	if (validade ==  true) {
		printf ("%d de ", data->dia);
		switch (data->mes) {
			case 1: printf ("janeiro"); break;
			case 2: printf ("fevereiro"); break;
			case 3: printf ("março"); break;
			case 4: printf ("abril"); break;
			case 5: printf ("maio"); break;
			case 6: printf ("junho"); break;
			case 7: printf ("julho"); break;
			case 8: printf ("agosto"); break;
			case 9: printf ("setembro"); break;
			case 10: printf ("outubro"); break;
			case 11: printf ("novembro"); break;
			case 12: printf ("dezembro"); break;
		}
		printf (" de %d", data->ano);
	}

	return validade;
}

Data Pascoa (int ano) {
	Data data;
	int a, b, c, d, e, g, h, j, k, m, n, r, p;

	if (ano > -1) {
		a = (ano) % 19;
		b = (ano) / 100;
		c = (ano) % 100;

		d = b / 4;
		e = b % 4;

		g = (8 * b + 13) / (25);
		h = (19 * a + b - d - g + 15) / (30);

		j = (c) / (4);
		k = (c) % (4);

		m = (a + 11 * h) / (319);

		r = (2 * e + 2 * j - k - h + m + 32) % (7);
		n = (h - m + r + 90) / (25);

		p = (h - m + r + n + 19) % (32);

		printf ("a = %d, b = %d, c = %d, d = %d, e = %d, g = %d, h = %d, j = %d, k = %d, m = %d, n = %d, p = %d, r = %d", a, b, c, d, e, g, h, j, k, m, n, p, r);

		data.Dia = r;
		data.Mes = p;
		data.Ano = ano;
	}
	else {
		printf ("Ano sinalizado negativamente.");
		ValidaData(14,3,1);
	}

	return data;
}

bool AnoBissexto (int ano) {
	bool bissexto = false;

	if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
		bissexto = true;

	return bissexto;
}


bool SeparaData(Data data, int *dia, int *mes, int *ano) {
	validade = false;

	validade = ValidaData(data);

	if (validade == true) {
		*dia = data.dia;
		*mes = data.mes;
		*ano = data.ano;
	}
	else
		ErroData();

	return validade;
}

Data GregorianaJuliana(Data dataGregoriana) {
	Data dataJuliana;
	int dia, mes, ano;

	SeparaData(dataGregoriana, &dia, &mes, &ano);

/*
	(1461 *	(ano + 4800 + (mes - 14) / 12))	/ 4 +
	(367 * (mes - 2 -12 *((mes - 14) / 12))) / 12 - 
	(3 * ((ano + 4900 + (mes - 14) / 12) / 100)) / 4 +
	dia - 32075;
*/
	return dataJuliana;
}

Data JulianaGregoriana(Data dataJuliana) {
	Data dataGregoriana;
	int DataJuliana; // dias
	int B, N, K, J, dia, mes, ano;

	B = DataJuliana + 68569;
	N = (4 * B) / 146097;
	B = B - ((146097 * N + 3) / 4);
	K = (4000 * (B + 1)) / 146001;
	B = (B - (1461 * K) / 4) + 31;
	J = (80 * B) / 2447;
	dia = B - (2447 * J) / 80;
	mes = J + 2 - (12 * B);
	ano = 100 * (N - 49) + K + B;
	ValidaData(dia, mes, ano, &dataGregoriana);

	return dataGregoriana;
}

int DiaSemana(Data data) {
	int dSemana, dia, mes, ano;

	dia = data.dia;
	mes = data.mes;
	ano = data.ano;

	dSemana = ano + dia + 3 * (mes - 1) - 1;
	if (mes < 3)
		ano--;
	else
		dSemana -= int(0.4*mes+2.3);
	dSemana += int(ano/4) - int((ano/100+1)*0.75);
	dSemana %= 7;

	return dSemana;
}

Data SextaFeiraSanta (int ano) {
	Data sextaFeiraSanta;
	
// Data da Páscoa - 2;

	return sextaFeiraSanta;
}

Data Carnaval (int ano) {
	Data carnaval;

// Data da Páscoa - 47;

	return carnaval;
}

Data CorpusChristi (int ano) {
	Data corpusChristi;

// Data da Páscoa + 60;

	return corpusChristi;
}

bool Calendario (int ano) {
	bool validade = false;

	validade = true;

	return validade;
}

bool ErroData() {
	bool validade = false;

	printf ("\nData inválida.\n");
	validade = true;

	return validade;
}
