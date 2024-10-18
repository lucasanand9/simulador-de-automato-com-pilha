#include "automato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printEstado(Estados *a){
    printf("Nome: %s\nFinal: %i\nInicial: %i\n", a->nome, a->final, a->inicial);
}


void printEstados(Estados *estados, int quantidade){
    for (int i = 0; i < quantidade; i++){
        printEstado(&(estados[i]));
    }
}

void printAlfabeto(Alfabeto *alfabeto, int quantidade){
    for (int i = 0; i < quantidade; i++){
        printf("Alfabeto: %c\n", alfabeto[i].simbolo);
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

int verificaAlfabeto(char a, Alfabeto *alfa, int tamanho){
    for (int i = 0; i < tamanho; i++){
        if (a == alfa[i].simbolo){
            return 1;
        }
    }
    return 0;
}


int vazia(Pilha *pil)
{
  if (pil->topo == NULL)
    return 1;
  else
    return 0;
}

Pilha * cria(void){
    Pilha *p=NULL;
    p=(Pilha *)malloc(sizeof(Pilha));
    if (p)
    {
	    p->topo=NULL;
        p->tamPilha=0;
    }
    return p;
}

int empilha(Alfabeto *novo, Pilha *pil){   
    NoPilha *aux=NULL;
    aux=(NoPilha *) malloc(sizeof(NoPilha));
    if (aux!=NULL){
        memcpy(&(aux->alfa),novo, sizeof(Alfabeto)); //<<<<<<<<<<
	    aux->baixo=pil->topo;
     	pil->topo=aux;
	    (pil->tamPilha)++;
        return 1;
    }else{
        return 0;
    }
}

int desempilha(Alfabeto *reg, Pilha *pil){
    NoPilha *aux=NULL;	  
    if (vazia(pil)==0){	
        memcpy(reg, &(pil->topo->alfa),sizeof(Alfabeto)); //<<<<<<<
	aux=pil->topo->baixo;
	free(pil->topo);
	pil->topo=aux;
        (pil->tamPilha)--;
        return 1;
    }
    else
        return 0;
}

int verificaEstado(char a[10], Estados *estado, int tamanho){
    for (int i = 0; i < tamanho; i++){
        if (strcmp(a, estado[i].nome)){
            return 0;
        }
    }
    return 1;    
}