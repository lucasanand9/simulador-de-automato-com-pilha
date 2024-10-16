#include "automato.h"
#include <stdio.h>
#include <stdlib.h>

void printEstados(Estados *estados, int quantidade){
    for (int i = 0; i < quantidade; i++){
        printf("Estado: %s\n", estados[i].nome);
    }
}

void printAlfabeto(Alfabeto *alfabeto, int quantidade){
    for (int i = 0; i < quantidade; i++){
        printf("Estado: %c\n", alfabeto[i].simbolo);
    }
}

Estados * estadosFinais(Estados *estados, int quantidade, int *resultSaida){
    Estados *final;
    *resultSaida = 0;
    for (int i = 0; i < quantidade; i++){
        if(estados[i].final == 1){
            (*resultSaida)++;
            final = malloc(sizeof(Estados) *(*resultSaida));
            final[i-1] = estados[i-1];
        }
    }
    return final;
}

Estados * estadosIniciais(Estados *estados, int quantidade, int *resultSaida){
 Estados *inicial;
    *resultSaida = 0;
    for (int i = 0; i < quantidade; i++){
        if(estados[i].inicial == 1){
            (*resultSaida)++;
            inicial = malloc(sizeof(Estados) *(*resultSaida));
            inicial[i-1] = estados[i-1];
        }
    }
    return inicial;
}