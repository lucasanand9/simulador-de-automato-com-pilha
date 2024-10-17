typedef struct{
    char nome[10]; 
    int inicial;
    int final;
}Estados;

typedef struct {
    char simbolo;
}Alfabeto;

void printEstado(Estados *a);
void printEstados(Estados *estados, int quantidade);
void printAlfabeto(Alfabeto *alfabeto, int quantidade);
Estados * estadosFinais(Estados *estados, int quantidade, int *resultSaida);
Estados * estadosIniciais(Estados *estados, int quantidade, int *resultSaida);
