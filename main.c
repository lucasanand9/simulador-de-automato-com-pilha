#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automato.h"

int main(){
    Estados *estados  = malloc(sizeof(Estados));
    Alfabeto *alfabeto = malloc(sizeof(Alfabeto));
    Alfabeto *alfaPilha = malloc(sizeof(Alfabeto));
    fPrograma *funcPrograma = malloc(sizeof(fPrograma));
    
    int index = 0;
    printf("Digite qual eh o alfabeto:\n");
    int simbolosDoAlfabeto = 0;
    while (index != -1){
        simbolosDoAlfabeto++;
        printf("Digite um simbolo para o alfabeto:\n");
        alfabeto = realloc(alfabeto, simbolosDoAlfabeto);
        scanf(" %c", &(alfabeto[simbolosDoAlfabeto-1].simbolo));
        getchar();
        printf("Digite 0 para adicionar um novo simbolo ou -1 para sair:\n");
        scanf(" %i", &index);
    }
    simbolosDoAlfabeto += 2;
    alfabeto = realloc(alfabeto, simbolosDoAlfabeto);
    alfabeto[simbolosDoAlfabeto-2].simbolo = 'E';
    alfabeto[simbolosDoAlfabeto-1].simbolo = '?';



    index = 0;
    printf("Digite quais sao os estados:\n");
    int quantidadeEstados = 0;
    while (index != -1){
        quantidadeEstados++;
        printf("Qual o nome do novo estado:\n");
        estados = realloc(estados, quantidadeEstados);
        scanf(" %s", estados[quantidadeEstados-1].nome);
        printf("Esse estado eh final?(1 - sim | 0 - nao)\n");
        scanf("%i", &(estados[quantidadeEstados-1]).final);
        printf("Esse estado eh inicial?(1 - sim | 0 - nao)\n");
        scanf("%i",&(estados[quantidadeEstados-1]).inicial );
        printf("Digite 0 para adicionar um novo estado ou -1 para sair:\n");
        scanf("%i", &index);
    }

    index = 0;
    printf("Digite qual eh o alfabeto da pilha:\n");
    int simbolosDoAlfabetoDaPilha = 0;
    while (index != -1){
        simbolosDoAlfabetoDaPilha++;
        printf("Digite um novo simbolo para o alfabeto:\n");
        alfaPilha = realloc(alfaPilha, simbolosDoAlfabetoDaPilha);
        scanf(" %c", &(alfaPilha[simbolosDoAlfabetoDaPilha-1].simbolo));
        getchar();
        printf("Digite 0 para adicionar um novo simbolo ou -1 para sair:\n");
        scanf("%i", &index);
    }
    simbolosDoAlfabetoDaPilha += 2;
    alfaPilha = realloc(alfaPilha, simbolosDoAlfabetoDaPilha);
    alfaPilha[simbolosDoAlfabetoDaPilha-2].simbolo = 'E';
    alfaPilha[simbolosDoAlfabetoDaPilha-1].simbolo = '?';



    index = 0;
    printf("Digite a funcao programa:\n");
    int funcProgramaCont = 0;
    int vdd = 1;
    while (index != -1){
        char nomeEstado[10];
        funcProgramaCont++;
        funcPrograma = realloc(funcPrograma, funcProgramaCont);
        do{
            if (!vdd){
                printf("Esse estado nao existe, tente novamente:\n");
            }
            
            printf("Digite o nome do estado inicial:\n");
            scanf(" %s", nomeEstado);
            vdd = verificaEstado(nomeEstado, estados, quantidadeEstados); 
        } while (!vdd);
        strcpy((funcPrograma[funcProgramaCont-1]).estadoAtual.nome, nomeEstado);
        

        printf("Qual o simbolo que sera lido na fita:\n");
        char simbAlfa;
        do{
            if (!vdd){
                printf("Esse simbolo nao existe, tente novamente:\n");
            }
            printf("Digite o simbolo do alfabeto:\n");
            scanf(" %c", &simbAlfa);
            getchar();
            vdd = verificaAlfabeto(simbAlfa, alfabeto, simbolosDoAlfabeto);
        } while (!vdd);
        funcPrograma[funcProgramaCont-1].simboloFita = simbAlfa; 
        
        printf("Qual o simbolo que sera empilhado na pilha:\n");
        do{
            if (!vdd){
                printf("Esse simbolo nao existe, tente novamente:\n");
            }
            printf("Digite o simbolo do alfabeto de pilhas");
            scanf(" %c", &simbAlfa);
            getchar();
            vdd = verificaAlfabeto(simbAlfa, alfaPilha, simbolosDoAlfabeto); 
        } while (!vdd);
        funcPrograma[funcProgramaCont-1].simboloEmpilha = simbAlfa; 

        printf("Digite o estado que terminara essa acao:\n");
        do{
            if (!vdd){
                printf("Esse estado nao existe, tente novamente:\n");
            }
            
            printf("Digite o nome do estado final:\n");
            scanf(" %s", nomeEstado);
            vdd = verificaEstado(nomeEstado, estados, quantidadeEstados); 
        } while (!vdd);
        strcpy(funcPrograma[funcProgramaCont-1].estadoAtual.nome, nomeEstado);

        printf("Qual o simbolo que sera desenpilhado:\n");
        do{
            if (!vdd){
                printf("Esse simbolo nao existe, tente novamente:\n");
            }
            printf("Digite o simbolo do alfabeto de pilhas:\n");
            scanf(" %c", &simbAlfa);
            getchar();
            vdd = verificaAlfabeto(simbAlfa, alfaPilha, simbolosDoAlfabeto);
        } while (!vdd);
        funcPrograma[funcProgramaCont-1].simboloDesempilha = simbAlfa; 

        printf("Digite 0 para adicionar uma nova lei na funcao programa ou -1 para sair:\n");
    }
    
    // index = 0;
        // int tam = 0;
        
        // while (index != -1){
        //     char fita[100];
        //     printf("Digite a fita para testar o automato:\n");
        //     scanf(" %s", fita);
        //     tam = strlen(fita);
        //     char comp;
        //     for (int i = 0; i < tam; i++){
        //         comp = fita[i];

        //     }
            
        // }

}