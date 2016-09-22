//#define CapacidadeEstrada int
//#define TipoEstrada int
typedef enum CapacidadeEstrada {
	null, beco, viela, rua, avenida, rodovia, autoestrada
} CapacidadeEstrada;

typedef enum TipoEstrada {
	pedra, terra, areia, calcada, pavimentada
} TipoEstrada;

typedef struct Estrada {
	TipoEstrada tipo;
	CapacidadeEstrada capacidade;
} Estrada;

//#define TipoArea int
typedef enum TipoArea {
	residencial, comercial, industrial, publico, radioativo
} TipoArea;

typedef struct Area {
	TipoArea tipo;
} Area;

//#define TipoEnergia int
typedef enum TipoEnergia {
	solar,
	eolica,
	hidreletrica,
	gas,
	carvao,
	oleo,
	incineracao,
	nuclear,
	fusao,
	geotermica,
	biodiesel,
	biogas,
	maremotriz,
	quimica,
	energiaComercial // Vizinhos
} TipoEnergia;

typedef struct FonteEnergia {
	TipoEnergia;
} FonteEnergia;

//#define TipoFonte int
typedef enum TipoFonteAgua {
	bomba, caixaDagua, calha, dessalinizadora, condensadora, fonteAguaComercial
} TipoFonteAgua;

typedef struct FonteAgua {
	TipoFonteAgua tipo;
} FonteAgua;

//#define TipoTratamento int
typedef enum TipoTratamentoEsgoto {
	estacaoTratamentoEsgoto, tratamentoEsgotoComercial
} TipoTratamentoEsgoto;

typedef struct TratamentoEsgoto {
	TipoTratamentoEsgoto tipo;
} TratamentoEsgoto;

typedef enum TipoTratamentoLixo {
	aterro, incineradora, coletaSeletiva
} TipoTratamentoLixo;

typedef struct TratamentoLixo {
	TipoTratamentoLixo tipo;
} TratamentoLixo;

//#define receita float
//#define despesa float
typedef float MovimentacaoMaxima;
typedef struct Financas {
	MovimentacaoMaxima receita;
	MovimentacaoMaxima despesa;
	double saldo;
} Financas;

typedef struct Cidade {
	Estrada malhaRodoviaria;
	Area regiao;
	FonteEnergia distribuidoraEnergia;
	FonteAgua distribuidoraAgua;
	TratamentoEsgoto redeEsgoto;
	TratamentoLixo coletaLixo;
	Financas orcamento;
} Cidade;
