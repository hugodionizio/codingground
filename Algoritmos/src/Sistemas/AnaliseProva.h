/*
 * Automatizador de construção de informação via gabarito
 * 
 * Ler questão na prova
 * Copia o enunciado
 * Ler questão no gabarito
 * Armazena a alternativa apontada pelo gabarito
 * Copia a informação da alternativa da prova de acordo com a apontada pelo gabarito
 * Se a informação for uma sequência de validações de afirmações, assinala-se as sequências da prova, negando as falsas
 */

char *lerProva(FILE, int);
char *copiaEnunciado(char *);
char *lerGabarito(FILE, int);
char buscaAlternativaCorretaGabarito(char *, int);
char *copiaAlternativaCorreta(char *, char);
char *verificaSequencias(char *);
