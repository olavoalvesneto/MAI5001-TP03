#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h"

int main(void) {
    //abrir arquivo
    FILE *file;
    //retorna ponteiro do arquivo para o ponteiro file
    file = fopen("dados.txt", "r");

    //validando se o arquivo foi aberto
    if (file == NULL)  {
       // printf("Não foi possivel abrir o arquivo\n");
        return 0;
    }

    char frase[100];
    char pai[30], filhoEsquerda[30], filhoDireita[30];
    int qtdeSaida=0;
    int linha = 0;
    
    ArvBin* raiz = cria_ArvBin();

    //percorre linha do arquivo texto adicionando a trinca de elementos na arvore binária de Elementos
     while(fgets(frase, 100, file) != NULL) {
        sscanf(frase," %[^,] , %[^,] ,%s", pai, filhoEsquerda, filhoDireita);        
        if(strcmp(pai,"X")!=0 ) {
            if(!adiciona_ArvBin(raiz, pai, filhoEsquerda, filhoDireita, linha)){
                printf("retornando como erro ao adicionar PAI: %s, FE:%s, FD:%s\n", pai, filhoEsquerda, filhoDireita);
            }
        }  
       linha++;
    }

    preOrdem_ArvBin(raiz);
    printf("TNv %d\n", altura_ArvBin(raiz));
    if (totalSaida_ArvBin(raiz,&qtdeSaida)>0) {
        printf("TSd %d\n", qtdeSaida);
    }else {
        printf("\nErro ao percorrer a arvore procurando a qtde de saída");
    }
    printf("TNd %d\n", totalNO_ArvBin(raiz));


    fclose(file);
    libera_ArvBin(raiz);

    return 0;
}
