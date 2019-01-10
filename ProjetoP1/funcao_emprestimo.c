#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

tipoEmprestimo *registarEmprestimo(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtente,int *contEmprestimo,int *idEmprestimo,int *bicicletasOcupadas)
{
    int pos = -1;
    int i;
    int opcao;
    char campus[MAXSTRING];
    int codigo;
    tipoEmprestimo *aux;
    int emprestimoRealizado=0;

    codigo = lerInteiro("\nIntroduza o numero de utente:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,codigo,contUtente);


    if(pos == -1)
    {
        printf("\nNao existe nenhum utente com esse numero");
    }
    else
    {

        for(i=0; i<*contEmprestimo; ++i)    //verificar se ja possui emprestimo
        {
            printf("teste2:%d",emprestimos[i].codigoUtente);
            if(emprestimos[i].dataDevolucao.dia == 0 && utentes[pos].numero == emprestimos[i].codigoUtente)
            {
                //printf("teste2");
                emprestimoRealizado=1;
                break;

            }
        }

        if(emprestimoRealizado==1)
        {
            printf("\n\nO utente ja possui um emprestimo realizado.");
        }
        else
        {
            printf("\n\nInsira o campus onde deseja efectuar o emprestimo:");
            printf("\n1->Residencias");
            printf("\n2->Campus 1");
            printf("\n3->Campus 2");
            printf("\n4->Campus 5");
            opcao = lerInteiro("\nEscolhe uma opcao: ",1,4);

            switch(opcao)
            {
            case 1:
                strcpy(campus,"residencias");
                break;
            case 2:
                strcpy(campus,"campus 1");
                break;
            case 3:
                strcpy(campus,"campus 2");
                break;
            case 4:
                strcpy(campus,"campus 5");
                break;
            }

            for(i=0; i<contBicicleta; ++i)
            {
                if(strcmp(bicicleta[i].campus,campus)==0)
                {
                    if(strcmp(bicicleta[i].estado,"disponivel")==0)  //ve se tem alguma bike disponivel naquele campus
                    {
                        aux = realloc(aux,(*contEmprestimo+1)*sizeof(tipoEmprestimo));

                        if(aux == NULL)
                        {
                            printf("\nImpossivel alocar memoria.");
                        }
                        else
                        {
                            aux[*contEmprestimo].numeroRegisto = *idEmprestimo;
                            aux[*contEmprestimo].codigoUtente = codigo;
                            strcpy(aux[*contEmprestimo].designacaoBicicleta,bicicleta[i].designacao);
                            aux[*contEmprestimo].dataEmprestimo = lerData();
                            strcpy(aux[*contEmprestimo].campusOrigem,campus);

                            printf("\n\nInsira o campus de destino:");
                            printf("\n1->Residencias");
                            printf("\n2->Campus 1");
                            printf("\n3->Campus 2");
                            printf("\n4->Campus 5");
                            opcao = lerInteiro("\nEscolhe uma opcao: ",1,4);

                            switch(opcao)
                            {
                            case 1:
                                strcpy(campus,"residencias");
                                break;
                            case 2:
                                strcpy(campus,"campus 1");
                                break;
                            case 3:
                                strcpy(campus,"campus 2");
                                break;
                            case 4:
                                strcpy(campus,"campus 5");
                                break;
                            }
                        }
                        if(strcmp(aux[*contEmprestimo].campusOrigem,campus)==0)
                        {
                            printf("Insira outro local para deixar a bike");
                        }
                        else
                        {
                            strcpy(aux[*contEmprestimo].campusDestino,campus);
                            bicicleta[i].quantidadeEmprestimos++;
                            strcpy(bicicleta[i].estado,"emprestada");
                            utentes[pos].quantidadeEmprestimos++;
                            (*contEmprestimo)++;
                            (*idEmprestimo)++;
                            (*bicicletasOcupadas)++;

                            break;

                        }
                        //tipoData dataDevolucao;
                        //int distanciaPercorrida;


                    }

                }
            }

        }
    }


    return aux;//para atualizar a memoria dinamica
}

void consultarEmprestimo(tipoBicicleta bicicletas[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo)
{
    int numeroUtente;
    int pos = -1;
    int i;
    int j = 1;

    numeroUtente = lerInteiro("\nInsira o numero de utente que quer consultar os emprestimo:",1,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,numeroUtente,contUtentes);

    if(pos != -1)
    {
        for(i=0; i<contEmprestimo; ++i)
        {
            if(emprestimos[i].codigoUtente == utentes[pos].numero)
            {
                printf("\nEmprestimo %d",j);
                printf("\nNumero de registo:%d",emprestimos[i].numeroRegisto);
                printf("\nCodigo de utente:%d\t\tNome Utente:%s",emprestimos[i].codigoUtente,utentes[pos].nome);
                printf("\nDesignacao da bicicleta:%s",emprestimos[i].designacaoBicicleta);
                printf("\nCampus Origem:%s",emprestimos[i].campusOrigem);
                printf("\nCampus destino:%s",emprestimos[i].campusDestino);
                printf("\nData de emprestimo:%d-%d-%d\t\t%d:%d",emprestimos[i].dataEmprestimo.dia,emprestimos[i].dataEmprestimo.mes,emprestimos[i].dataEmprestimo.ano,
                       emprestimos[i].dataEmprestimo.hora,emprestimos[i].dataEmprestimo.minuto);
                printf("\nData de devolucao:%d-%d-%d\t\t%d:%d",emprestimos[i].dataDevolucao.dia,emprestimos[i].dataDevolucao.mes,emprestimos[i].dataDevolucao.ano,
                       emprestimos[i].dataDevolucao.hora,emprestimos[i].dataDevolucao.minuto);
                printf("\nDistancia percorrida:%d",emprestimos[i].distanciaPercorrida);
                j++;

            }
        }
    }
    else
    {
        printf("\nNao existe nenhum utente com o numero escolhido");
    }
}

void listarEmprestimos(tipoBicicleta bicicletas[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo)
{
    int numeroUtente;
    int pos = -1;
    int i;
    int j = 1;


    for(i=0; i<contEmprestimo; ++i)
    {
        printf("\nEmprestimo %d",j);
        printf("\nNumero de registo:%d",emprestimos[i].numeroRegisto);
        printf("\nCodigo de utente:%d",emprestimos[i].codigoUtente);
        printf("\nDesignacao da bicicleta:%s",emprestimos[i].designacaoBicicleta);
        printf("\nCampus Origem:%s",emprestimos[i].campusOrigem);
        printf("\nCampus destino:%s",emprestimos[i].campusDestino);
        printf("\nData de emprestimo:%d-%d-%d\t\t%d:%d",emprestimos[i].dataEmprestimo.dia,emprestimos[i].dataEmprestimo.mes,emprestimos[i].dataEmprestimo.ano,
               emprestimos[i].dataEmprestimo.hora,emprestimos[i].dataEmprestimo.minuto);
        printf("\nData de devolucao:%d-%d-%d\t\t%d:%d",emprestimos[i].dataDevolucao.dia,emprestimos[i].dataDevolucao.mes,emprestimos[i].dataDevolucao.ano,
               emprestimos[i].dataDevolucao.hora,emprestimos[i].dataDevolucao.minuto);
        printf("\nDistancia percorrida:%d",emprestimos[i].distanciaPercorrida);
        j++;

    }
}

void devolverBicicleta(tipoBicicleta bicicletas[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo,int *bicicletasOcupadas)
{
    int numeroUtente;
    int pos = -1;
    int i;
    int j;
    char designacao[MAXSTRING];
    int opcao;
    int dia,mes,ano;
    int dataValida = -1;
    float distancia;

    numeroUtente = lerInteiro("\nInsira o numero de utente que quer devolver uma bicicleta:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,numeroUtente,contUtentes);

    if(pos != -1)
    {
        for(i=0 ; i<contEmprestimo; ++i)
        {
            if(emprestimos[i].codigoUtente == utentes[pos].numero)
            {
                for(j=0; j<contBicicleta; ++j)
                {
                    if(strcmp(bicicletas[j].designacao,emprestimos[i].designacaoBicicleta)==0 && strcmp(bicicletas[j].estado,"emprestada")==0)
                    {
                        strcpy(bicicletas[j].estado,"disponivel");

                        emprestimos[i].dataDevolucao = lerData();
                        distancia= lerFloat("\nIntroduza a distancia percorrida:",MIN,MAXDISTANCIA);
                        bicicletas[j].distanciaTotal= bicicletas[j].distanciaTotal + distancia;
                        emprestimos[i].distanciaPercorrida = distancia;
                        (*bicicletasOcupadas)--;

                    }
                }
            }
        }
    }
    else
    {
        printf("\nNao existe nenhum utente com o numero escolhido");

    }
}
