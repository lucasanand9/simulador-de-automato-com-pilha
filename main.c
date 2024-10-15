#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

int main(){
    Estados *estados;

    int index = 0;
    printf("Digite quais sao os estados:\n");
    int quantidadeEstados = 0;
    while (index != -1){
        quantidadeEstados++;
        printf("Qual o nome do novo estado\n");
        estados = malloc(sizeof(Estados)*quantidadeEstados);
        scanf(" %s", estados[quantidadeEstados-1]);

        printf("Digite 0 para adicionar um novo estado e -1 para sair:/n");
        scanf("%i", &index);
    }
}