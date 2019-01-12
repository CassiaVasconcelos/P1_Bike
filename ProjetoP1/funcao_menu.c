#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

int menuPrincipal(int contBicicletas, int contEmprestimo, int contEspera, int contUtente, int bicicletasOcupadas, float distTotPecorrida, int quantAvariadas){
    int opcao;
 //   float top=0.;
    int bicicletasDisponiveis = MAXBICICLETA - bicicletasOcupadas;
    printf("\n\t   Welcome to UBike.\n\n");
    printf("\nNumero de bicicletas:%d",contBicicletas);
    printf("\nNumero de Utente:%d",contUtente);
    printf("\nNumero de emprestimos:%d",contEmprestimo);
    printf("\nQuantidade de pedidos na lista de espera:%d",contEspera);
    printf("\nDistancia total percorrida:%.2f",distTotPecorrida);
    printf("\nQuantidade de bicicletas avariadas:%d",quantAvariadas);
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

char menuEmprestimo(int bicicletasOcupadas){
    int bicicletasDisponiveis = MAXBICICLETA - bicicletasOcupadas;
    char opcoes[] = "RDCLV";
    char opcao;

    do{
        printf("\nNumero de bicicletas disponiveis:%d", bicicletasDisponiveis);
        printf("\n\n     (R)egistar\n");
        printf("     (D)evolucao\n");
        printf("     (C)onsultar\n");
        printf("     (L)istar\n");
        printf("     (V)oltar\n");
        printf("      Escolha uma opcao: ");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);

    }
    while (strchr(opcoes, opcao)==NULL);

    return opcao;
}

int menuCampus(){
        int opcao;

 //       printf("\n\nInsira o campus da bicicleta:");
        printf("\n1->Residencias");
        printf("\n2->Campus 1");
        printf("\n3->Campus 2");
        printf("\n4->Campus 5");
        opcao = lerInteiro("\nEscolhe uma opcao: ",1,4);

        return opcao;
}

int subMenuTipoUtente(){
        int opcao;

        printf("\n\nInsira o tipo do utente:");
        printf("\n1->Estudante");
        printf("\n2->Docente");
        printf("\n3->Tecnico Administrativo");
        printf("\n4->Convidado");
        opcao = lerInteiro("\nEscolhe uma opcao: ",1,4);

        return opcao;
}
/*
int menuEspera(int contadorEspera){
        int opcao;

        printf("\n\nInsira o tipo do utente:");
        printf("\n1->Estudante");
        printf("\n2->Docente");
        printf("\n3->Tecnico Administrativo");
        printf("\n4->Convidado");
        opcao = lerInteiro("\nEscolhe uma opcao: ",1,4);

        return opcao;
}
*/

char menuEspera(int numeroDeEsperas){
//    int bicicletasEspera = MAXBICICLETA - numeroDeEsperas;
    char opcoes[] = "AECLV";
    char opcao;

    do{
        printf("\nNumero de utentes em espera:%d", numeroDeEsperas);
 //       printf("\n\n     (R)egistar\n");
        printf("\n\n\t(A)lterar campus de destino\n");
        printf("\t(E)liminar da lista\n");
        printf("\t(C)onsultar\n");
        printf("\t(L)istar\n");
        printf("\t(V)oltar\n");
        printf("\tEscolha uma opcao: ");
        scanf(" %c", &opcao);
        limpaBufferStdin();
        opcao = toupper(opcao);

    }
    while (strchr(opcoes, opcao)==NULL);

    return opcao;
}
