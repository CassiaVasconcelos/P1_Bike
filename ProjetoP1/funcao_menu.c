#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

int menuPrincipal(int contBicicletas, int contEmprestimo, int contEspera, int contUtente, int bicicletasOcupadas){
    int opcao,top2=0;
    float top=0.;
    int bicicletasDisponiveis = MAXBICICLETA - bicicletasOcupadas;
    printf("\n\t   Welcome to UBike.\n\n");
    printf("\nNumero de bicicletas:%d",contBicicletas);
    printf("\nNumero de Utente:%d",contUtente);
    printf("\nNumero de emprestimos:%d",contEmprestimo);
    printf("\nQuantidade de pedidos na lista de espera:%d",contEspera);
    printf("\nDistancia total percorrida:%.2f",top);
    printf("\nQuantidade de bicicletas avariadas:",top2);
    printf("\nNumero de bicicletas disponiveis:%d",bicicletasDisponiveis);
    printf("\n\n1->     Bicicletas\n");
    printf("2->     Utente\n");
    printf("3->     Espera\n");
    printf("4->     Emprestimo\n");
    printf("5->     Listar Utilizadores por numero decrescente de emprestimos\n");
    printf("6->     Estatistica\n");
    printf("7->     Listar os dados da ultima bicicleta utilizada por um determinado utente\n");
    printf("8->     Fechar e salvar programa\n");
    opcao = lerInteiro("\nEscolha uma opcao:",1,8);
    return opcao;
}

char menuBicicleta(int contBicicletas){
    char opcoes[] = "CLIRV";    //cada posicao tem uma letra
    char opcao;

    do{
        printf("\nNumero de Bicicletas:%d", contBicicletas);
        printf("\n\n     (I)nserir\n");
        printf("     (C)onsultar\n");
        printf("     (R)egistar avaria/devolucao\n");
        printf("     (L)istar\n");
        printf("     (V)oltar\n");
        printf("      Escolha uma opcao: ");
        scanf(" %c", &opcao);
        limpaBufferStdin();
        opcao = toupper(opcao);
    }
    while (strchr(opcoes, opcao)==NULL);    //se nao devolver nenhuma posicao(letra) devolve nulo

    return opcao;
}

char menuUtente(int contUtente){
    char opcoes[] = "IACLV";
    char opcao;

    do{
        printf("\nNumero de Utente:%d", contUtente);
        printf("\n\n     (I)nserir\n");
        printf("     (A)lterar\n");
        printf("     (C)onsultar\n");
        printf("     (L)istar\n");
        printf("     (V)oltar\n");
        printf("      Escolha uma opcao: ");
        scanf(" %c", &opcao);
        limpaBufferStdin();
        opcao = toupper(opcao);
    }
    while (strchr(opcoes, opcao)==NULL);

    return opcao;
}
