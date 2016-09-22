Shannon-Fano () {}
//Estruturas de dados
Pilha conjunto;
Heap conjunto0, conjunto1, elemento;
int alfabeto[]
float max_prob, probabilidade;

// Interface
empilha(&conjunto, alfabeto);
Heap desempilha(&conjunto);
Heap conjuntoVazio();
float somatorio(conjunto0);
void enfileira(elemento);
concatena(elemento.código, 0);
tamanho(conjunto0);

// Programa
empilha(&conjunto, alfabeto);

// Processa enquanto houver conjuntos com mais de um elemento 
while (conjunto != NULL) {
   conjunto0 = desempilha(&conjunto);
   conjunto1 = conjuntoVazio();
   max_prob = somatorio(conjunto0);
   probabilidade = 0;

   // Divide em duas partes de probabilidades semelhantes
   while (probabilidade < (max_prob/2)) {
      elemento = remove(&conjunto0, menor_elemento(conjunto0));
      conjunto1.enfileira(elemento);
      probabilidade+= elemento.valor;
   }

   # Acrescenta um dígito no código de cada metade
   for (elemento em conjunto0) {
      concatena(elemento.código, 0);
   }
   for (elemento em conjunto1) {
      concatena(elemento.código, 1);
   }

   # repete até o conjunto estar com apenas um elemento.
   if (tamanho(conjunto0) > 1) {
      conjunto.empilha(conjunto0);
   }
   if (tamanho(conjunto1) > 1) {
      conjunto.empilha(conjunto1);
   }
}
