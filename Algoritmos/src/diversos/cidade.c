#define TipoEstrada int
#define CapacidadeEstrada int

enum {beco, viela, rua, avenida, rodovia, autoestrada};
enum {pedra, terra, areia, calçada, pavimentada};

struct estrada{
	TipoEstrada;
};

#define TipoArea int

enum {residencial, comercial, industrial, pública, radioativa};

struct area{
	TipoArea;
};

enum {solar, eolica, hidreletrica, gas, carvao, oleo, incineradora, nuclear, fusao, geotermica, biodiesel, biogas, maremotriz, quimica, comercial};

#define TipoEnergia int

struct UsinaEnergia{
	TipoEnergia;
};

enum {bomba, calha, dessalinizadora, condensadora, comercial};

#define TipoFonte int

struct FonteAgua{
	TipoFonte;
};

enum {CaixaDagua, TratamentoEsgoto};

#define TipoTratamento int

struct TratamentoEsgoto{
	TipoTratamentoEsgoto;
};

enum {aterro, incineradora, ColetaSeletiva};

struct TratamentoLixo{
	TipoTratamentoLixo;
};

#define receita float
#define despesa float

struct financas{
	receita;
	despesa;
};

struct cidade{
	estrada MalhaRodoviaria;
	area regiao;
	FonteEnergia DistribuidoraEnergia;
	FonteAgua DistribuidoraAgua;
	TratamentoEsgoto RedeEsgoto;
	TratamentoLixo ColetaLixo;
	financas orcamento;
};