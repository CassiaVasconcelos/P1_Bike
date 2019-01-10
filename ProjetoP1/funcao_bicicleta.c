#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

void inserirBicicleta(tipoBicicleta bicicletas[],int *contBicicletas){
    char designacao[MAXSTRING];
    int pos = -1;
    int opcao;

    printf("\n\nInserir Bicicleta   \n");
    printf("\nInserir designacao da bicicleta:");
    scanf("%s",&designacao);
    limpaBufferStdin();

    pos = procurarBicicleta(bicicletas,designacao,*contBicicletas);

    if(pos != -1){
        printf("\n\nJa existe uma bicicleta com essa designacao");
    }else{
        ///copia string origem para o vetor destino (incluindo \0)
        strcpy(bicicletas[*contBicicletas].designacao,designacao); //salva a designacao da bike no vetor
        strcpy(bicicletas[*contBicicletas].estado,"disponivel");    //"automaticamente" passa a estar disponivel

       opcao = menuCampus();

        switch(opcao){
            case 1:
                strcpy(bicicletas[*contBicicletas].campus,"residencias");
            break;
            case 2:
                strcpy(bicicletas[*contBicicletas].campus,"campus 1");
            break;
            case 3:
                strcpy(bicicletas[*contBicicletas].campus,"campus 2");
            break;
            case 4:
                strcpy(bicicletas[*contBicicletas].campus,"campus 5");
            break;
        }

        lerString("\n\nInsira o modelo da bicicleta:",bicicletas[*contBicicletas].modelo,MAXSTRING);
        bicicletas[*contBicicletas].quantidadeAvarias = 0;
        bicicletas[*contBicicletas].quantidadeEmprestimos = 0;
        bicicletas[*contBicicletas].distanciaTotal = 0;
        (*contBicicletas)++;
        printf("\nBicicleta criada com sucesso");

    }
}

void consultarBicicleta(tipoBicicleta bicicletas[],int contBicicleta){
    char designacao[MAXSTRING];
    int pos = -1;

    printf("\nInserir designacao da bicicleta:");
    scanf("%s",&designacao);

    pos = procurarBicicleta(bicicletas,designacao,contBicicleta);

    if(pos != -1){
        printf("\n\nBicicleta Encontrada");
        printf("\nDesignacao:%s",bicicletas[pos].designacao);
        printf("\nCampus:%s",bicicletas[pos].campus);
        printf("\nModelo:%s",bicicletas[pos].modelo);
        printf("\nEstado:%s",bicicletas[pos].estado);
        printf("\nQuantidade Avarias:%d",bicicletas[pos].quantidadeAvarias);
        printf("\nQuantidade Emprestimo:%d",bicicletas[pos].quantidadeEmprestimos);
        printf("\nDistancia percorrida:%d\n\n",bicicletas[pos].distanciaTotal);
    }else{
        printf("\n\nNao existe nenhuma bicicleta com essa designacao\n");
    }

}

void listarBicicletas(tipoBicicleta bicicletas[],int contBicicleta){
    int i,j = 1;

    for(i = 0;i<contBicicleta;++i){
        printf("\n\nBicicleta:%d",j);
        printf("\nDesignacao:%s",bicicletas[i].designacao);
        printf("\nCampus:%s",bicicletas[i].campus);
        printf("\nModelo:%s",bicicletas[i].modelo);
        printf("\nEstado:%s",bicicletas[i].estado);
        printf("\nQuantidade Avarias:%d",bicicletas[i].quantidadeAvarias);
        printf("\nQuantidade Emprestimo:%d",bicicletas[i].quantidadeEmprestimos);
        printf("\nDistancia percorrida:%d",bicicletas[i].distanciaTotal);
        j++;
    }
}

int procurarBicicleta(tipoBicicleta bicicletas[],char designacao[],int contBicicleta){
    int pos = -1;
    int i;

    for(i=0;i<contBicicleta;++i){
    ///compara alfabeticamente strings destino e origem, devolve 0 se iguais
        if(strcmp(bicicletas[i].designacao,designacao)==0){//se forem iguais devolve 0, ja existe
            pos = i;
            break;  ///
        }
    }
    return pos;
}


int bicicletasDisponiveis(tipoBicicleta bicicletas[], int *contBicicleta){
    int ocupadas=0, i=0;

        for(i=0;i<*contBicicleta;++i){
    ///compara alfabeticamente strings destino e origem, devolve 0 se iguais
        if(strcmp(bicicletas[i].estado,"disponivel")!=0){//se forem iguais devolve 0, ja existe
            ocupadas++;
        }
    }

    return ocupadas;
}
