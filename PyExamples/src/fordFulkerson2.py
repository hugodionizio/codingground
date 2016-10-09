#coding: utf-8

# Algoritmo: FordFulkerson.py
# Função: Fluxo Máximo ou Ford-Fulkerson:
#		Aumentar o fluxo de uma rede iterativamente em uma rede
# 		até que ele não possa mais ser aumentado
# Autor: SANTOS, Hugo Dionizio.
# Data: 26/02/2014 00:35:58 - 01/03/2014 23:35:48  

# Classes:
# Aresta
# FluxoRede

# Métodos para FluxoRede
# adicionarVertice(self, vertice)
# getArestas(self, v)
# adicionarAresta(self, u, v, w=0)
# fluxoMaximo(self, origem, alvo)
# encontrarCaminho(self, origem, alvo, caminho)

# Entrada: uma rede s-t N
# Saída: um fluxo máximo f na rede N
class Aresta(object):
	# Atributos
	def __init__(self, u, v, w):
		self.origem = u;
		self.alvo = v;
		self.capacidade = w;

	# Encapsulamento
	def __repr__(self):
		return "%s->%s:%s" % (self.origem, self.alvo, self.capacidade);

class FluxoRede(object):
	# Atributos
	def __init__(self):
		self.adj = {};
		self.fluxo = {};

	def adicionarVertice(self, vertice):
		self.adj[vertice] = [];

	def getArestas(self, v):
		return self.adj[v];

	def adicionarAresta(self, u, v, w=0):
		if u == v:
			raise ValueError("u == v");
		aresta = Aresta(u,v,w);
		rAresta = Aresta(v,u,0);
		aresta.rAresta = rAresta;  # o rAresta não é definido na classe Aresta
		rAresta.rAresta = aresta;
		self.adj[u].append(aresta);
		self.adj[v].append(rAresta);
		self.fluxo[aresta] = 0;
		self.fluxo[rAresta] = 0;

	# Fluxo Máximo
	def fluxoMaximo(self, origem, alvo):
		# Inicialização
		caminho = self.encontrarCaminho(origem, alvo, []);

		# Aumento do Fluxo
		while caminho != None: # enquanto existir um caminho f-aumentante na rede N
			fluxosRemanescentes = [aresta.capacidade - self.fluxo[aresta] for aresta in caminho]; # D(e)
			fluxo = min(fluxosRemanescentes); # seja Fluxo remanescente D(Q) = min{D(e)} para todo e pertecente a Q
			for aresta in caminho: # para cada arco e do caminho f-aumentante Q
				self.fluxo[aresta]+= fluxo; # se e é um arco de avanço: f(e) = f(D(e)) + Q
				self.fluxo[aresta.rAresta]-= fluxo; # senão: f(e) = f(D(e)) - Q
			caminho = self.encontrarCaminho(origem, alvo, []); # ache um caminho f-aumentante Q
		return sum(self.fluxo[aresta] for aresta in self.getArestas(origem)); # retorne fluxo f

	# Achando um Caminho Aumentante
	def encontrarCaminho(self, origem, alvo, caminho):
		if origem == alvo: # Inicialize o conjunto de vértices V(s) = {s}
			return caminho; # retorne o caminho f-aumentante reconstruído pelos ponteiros backpoint


		for aresta in self.getArestas(origem): # enquanto o conjunto Vs não contém o sorvedor t
			fluxoRemanescente = aresta.capacidade - self.fluxo[aresta];
			if fluxoRemanescente > 0 and not aresta in caminho: # se existir um arco de fronteira usável
				result = self.encontrarCaminho(aresta.alvo, alvo, caminho + [aresta]); # V(s) = V(s) U {w}
				if result != None:
					return result; # retorne o corte s-t <V(s), V(N)-V(s)>

print "Questão 01";
print 'capacidade (s -> a) = ',9;
print 'capacidade (s -> b) = ',8;
print 'capacidade (a -> t) = ',7;
print 'capacidade (a -> b) = ',3;
print 'capacidade (b -> t) = ',9;
g = FluxoRede();
[g.adicionarVertice(v) for v in "sabt"]
[None, None, None, None, None, None]
g.adicionarAresta('s','a',9);
g.adicionarAresta('s','b',8);
g.adicionarAresta('a','t',7);
g.adicionarAresta('a','b',3);
g.adicionarAresta('b','t',9);
print g.fluxoMaximo('s','t');
