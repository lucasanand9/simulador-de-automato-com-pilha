typedef struct{
    char nome[10]; 
    int inicial;
    int final;
}Estados;

typedef struct {
    char simbolo;
}Alfabeto;

typedef struct {
    Estados estadoAtual;
    Alfabeto simboloFita;
    Alfabeto simboloEmpilha;
    Estados estadoFinal;
    Alfabeto simboloDesempilha;
} fPrograma;

typedef struct NoPilha{
    Alfabeto alfa;
    struct NoPilha *baixo;
    
}NoPilha;


typedef struct pilha{
    NoPilha *topo;
    int tamPilha;
}Pilha;





void printEstado(Estados *a);
void printEstados(Estados *estados, int quantidade);
void printAlfabeto(Alfabeto *alfabeto, int quantidade);
Estados * estadosFinais(Estados *estados, int quantidade, int *resultSaida);
Estados * estadosIniciais(Estados *estados, int quantidade, int *resultSaida);
int verificaAlfabeto(char a, Alfabeto *alfa, int tamanho);
int verificaEstado(char a[10], Estados *estado, int tamanho);
fPrograma * funcaoPrograma();
int vazia(Pilha *pilha);
Pilha * cria(void);
int empilha(Alfabeto *reg, Pilha *pil);
int desempilha(Alfabeto *reg, Pilha *pil);

