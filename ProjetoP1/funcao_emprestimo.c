#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

tipoEmprestimo *registarEmprestimo(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtente,int *contEmprestimo,int *idEmprestimo,int *bicicletasOcupadas, int *verPossibEmprestimo)
{
    int pos = -1;
    int i;
    int opcao;
    char campus[MAXSTRING];
    int codigo;
    tipoEmprestimo *aux;
    aux = emprestimos;  ///add
    int emprestimoRealizado=0,naoDisponivel=0;

    codigo = lerInteiro("\nIntroduza o numero de utente:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,codigo,contUtente);


    if(pos == -1)
    {
        printf("\nNao existe nenhum utente com este numero!");
    }
    else
    {

        for(i=0; i<*contEmprestimo; i++)    //verificar se ja possui emprestimo
        {
            //  printf("teste2:%d",emprestimos[i].codigoUtente);
            if(emprestimos[i].dataDevolucao.dia == 0 && utentes[pos].numero == emprestimos[i].codigoUtente)
            {
                emprestimoRealizado=1;
                //break;
            }
        }

        if(emprestimoRealizado==1)
        {
            printf("\n\nO utente ja possui um emprestimo realizado.");
        }
        else
        {
            printf("\nInsira o campus de origem que deseja:");
            opcao = menuCampus();

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

            for(i=0; i<contBicicleta; i++)
            {

                if(strcmp(bicicleta[i].campus,campus)==0)
                {

                    if(strcmp(bicicleta[i].estado,"disponivel")==0)  //ve se tem alguma bicicleta disponivel naquele campus
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


                            printf("\nInsira o campus de destino que deseja:");
                            opcao = menuCampus();   ///menu


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
                            printf("Mesmo campus de origem e destino, tente novamente inserindo locais diferentes para a bicicleta");
                        }
                        else
                        {
                            strcpy(aux[*contEmprestimo].campusDestino,campus);
                            //aux[*contEmprestimo].numeroRegisto = *idEmprestimo;
                            bicicleta[i].quantidadeEmprestimos++;
                            strcpy(bicicleta[i].estado,"emprestada");
                            utentes[pos].quantidadeEmprestimos++;
                            (*contEmprestimo)++;
                            (*idEmprestimo)++;
                            (*bicicletasOcupadas)++;
                            (*verPossibEmprestimo)=1;//foi possivel fazer o emprestimo

                            break;

                        }
                        //tipoData dataDevolucao;
                        //int distanciaPercorrida;
                    }
                    else
                    {
                        naoDisponivel=1;
                        (*verPossibEmprestimo)=0;

                    }
                }
                else
                {
                    naoDisponivel=1;
                }
            }

            if(naoDisponivel==1)
            {
                printf("\nNao ha bicicletas disponiveis no campus selecionado.");
                (*verPossibEmprestimo)=0;
            }
        }
    }


    return aux;//para atualizar a memoria dinamica
}

void consultarEmprestimo(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo)
{
    int numeroUtente;
    int pos = -1;
    int i;
    int j = 1;

    numeroUtente = lerInteiro("\nInsira o numero de utente que quer consultar os emprestimo:",1,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,numeroUtente,contUtentes);

    if(pos != -1)
    {
        for(i=0; i<contEmprestimo; i++)
        {
            if(emprestimos[i].codigoUtente == utentes[pos].numero)
            {
                printf("\nEmprestimo %d",j);
                printf("\n\nID do emprestimo:%d",emprestimos[i].numeroRegisto);
                printf("\nCodigo de utente:%d\t\tNome Utente:%s",emprestimos[i].codigoUtente,utentes[pos].nome);
                printf("\nID da bicicleta:%s",emprestimos[i].designacaoBicicleta);
                printf("\nCampus Origem:%s",emprestimos[i].campusOrigem);
                printf("\nCampus destino:%s",emprestimos[i].campusDestino);
                printf("\nData de emprestimo:%02d-%02d-%04d\t\t%02d:%02d",emprestimos[i].dataEmprestimo.dia,emprestimos[i].dataEmprestimo.mes,emprestimos[i].dataEmprestimo.ano,
                       emprestimos[i].dataEmprestimo.hora,emprestimos[i].dataEmprestimo.minuto);
                printf("\nData de devolucao:%02d-%02d-%04d\t\t%02d:%02d",emprestimos[i].dataDevolucao.dia,emprestimos[i].dataDevolucao.mes,emprestimos[i].dataDevolucao.ano,
                       emprestimos[i].dataDevolucao.hora,emprestimos[i].dataDevolucao.minuto);
                printf("\nDistancia percorrida:%.2f",emprestimos[i].distanciaPercorrida);
                j++;

            }
        }
    }
    else
    {
        printf("\nNao existe nenhum utente com o numero escolhido");
    }
}

void listarEmprestimos(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo)
{
    int i, j = 1;

    for(i=0; i<contEmprestimo; i++)
    {
        printf("\n\nEmprestimo %d",j);
        printf("\nID do emprestimo:%d",emprestimos[i].numeroRegisto);
        printf("\nCodigo de utente:%d",emprestimos[i].codigoUtente);
        printf("\nID da bicicleta:%s",emprestimos[i].designacaoBicicleta);
        printf("\nCampus Origem:%s",emprestimos[i].campusOrigem);
        printf("\nCampus destino:%s",emprestimos[i].campusDestino);
        printf("\nData de emprestimo:%02d-%02d-%04d\t\t%02d:%02d",emprestimos[i].dataEmprestimo.dia,emprestimos[i].dataEmprestimo.mes,emprestimos[i].dataEmprestimo.ano,
               emprestimos[i].dataEmprestimo.hora,emprestimos[i].dataEmprestimo.minuto);
        printf("\nData de devolucao:%02d-%02d-%04d\t\t%02d:%02d",emprestimos[i].dataDevolucao.dia,emprestimos[i].dataDevolucao.mes,emprestimos[i].dataDevolucao.ano,
               emprestimos[i].dataDevolucao.hora,emprestimos[i].dataDevolucao.minuto);
        printf("\nDistancia percorrida:%.2f",emprestimos[i].distanciaPercorrida);
        j++;

    }
}

void devolverBicicleta(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo,int *bicicletasOcupadas)
{
    int numeroUtente;
    int pos = -1;
    int i;
    int j;
    char designacao[MAXSTRING];
    int opcao;
    int dia,mes,ano;
    float distancia;
    int possuiBicicleta=0;
    tipoData verificar;
    int dataValida= 0;

    numeroUtente = lerInteiro("\nInsira o numero de utente que quer devolver uma bicicleta:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,numeroUtente,contUtentes);

    if(pos != -1)
    {
        for(i=0 ; i<contEmprestimo; i++)
        {
            //se data de devolução<data de empréstimo, exibir erro.
            if(emprestimos[i].dataDevolucao.dia == 0 && utentes[pos].numero == emprestimos[i].codigoUtente)
            {
                for(j=0; j<contBicicleta; ++j)
                {
                    if(strcmp(bicicleta[j].designacao,emprestimos[i].designacaoBicicleta)==0 && strcmp(bicicleta[j].estado,"emprestada")==0)
                    {
                        verificar= lerData();
                        dataValida = verificarData(verificar,emprestimos[i].dataEmprestimo);
                        if(dataValida==-1)
                        {
                            ///data invalida
                            printf("\nA data de devolucao tem de ser superior a data de emprestimo. ");
                        }
                        else
                        {
                            strcpy(bicicleta[j].estado,"disponivel");
                            strcpy(bicicleta[j].campus, emprestimos[i].campusDestino);
                            emprestimos[i].dataDevolucao=verificar;
                            distancia= lerFloat("\nIntroduza a distancia percorrida:",MIN,MAXDISTANCIA);
                            bicicleta[j].distanciaTotal= bicicleta[j].distanciaTotal + distancia;
                            emprestimos[i].distanciaPercorrida = distancia;
                            (*bicicletasOcupadas)--;
                        }
                    }
                    else
                    {
                        possuiBicicleta=1;
                    }
                    break;
                }

            }
            else
            {
                printf("Este utente nao possui uma bicicleta para ser devolvida.");
            }
            break;
        }
//        if(possuiBicicleta==1)
//        {
//            printf("Este utente nao possui uma bicicleta para ser devolvida.");
//        }
    }
    else
    {
        printf("\nNao existe nenhum utente com o numero escolhido");

    }
}/*
void devolverBicicleta(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo,int *bicicletasOcupadas)
{
    int numeroUtente;
    int pos = -1;
    int i;
    int j;
    char designacao[MAXSTRING];
    int opcao;
    int dia,mes,ano;
    float distancia;
    int possuiBicicleta=0;
    tipoData verificar;
    int dataValida= 0;

    numeroUtente = lerInteiro("\nInsira o numero de utente que quer devolver uma bicicleta:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,numeroUtente,contUtentes);

    if(pos != -1){
        for(i=0 ; i<contEmprestimo; i++){
            if(emprestimos[i].dataDevolucao.dia == 0 && utentes[pos].numero == emprestimos[i].codigoUtente){
                possuiBicicleta = 1;
            }
        }

        if(possuiBicicleta == 1){
            ///devolver
            for(j=0; j<contBicicleta; ++j){
                if(strcmp(bicicleta[j].designacao,emprestimos[i].designacaoBicicleta)==0 && strcmp(bicicleta[j].estado,"emprestada")==0){
                    verificar= lerData();
                    dataValida = verificarData(verificar,emprestimos[i].dataEmprestimo);

                    if(dataValida==-1)
                    {
                        printf("\nA data de devolucao tem de ser superior a data de emprestimo. ");
                    }else{
                        strcpy(bicicleta[j].estado,"disponivel");
                        strcpy(bicicleta[j].campus, emprestimos[i].campusDestino);
                        emprestimos[i].dataDevolucao=verificar;
                        distancia= lerFloat("\nIntroduza a distancia percorrida:",MIN,MAXDISTANCIA);
                        bicicleta[j].distanciaTotal= bicicleta[j].distanciaTotal + distancia;
                        emprestimos[i].distanciaPercorrida = distancia;
                        (*bicicletasOcupadas)--;
                    }
                }
                break;
        }

    }else{
        printf("Este utente nao possui uma bicicleta para ser devolvida.");
    }

    }else
    {
        printf("\nNao existe nenhum utente com o numero escolhido");

    }
}
*/

int quantidadeEmprestimos(tipoEmprestimo emprestimos[], int *contEmprestimo)
{
    int quantidade=0, i=0;

    for(i=0; i<*contEmprestimo; i++)
    {
        quantidade++;
    }

    return quantidade;
}

int verificarData(tipoData verificar,tipoData dataEmprestimo)
{
    int dataValida=0;

    if(dataEmprestimo.ano < verificar.ano)
    {
        dataValida=1;
    }
    else
    {
        if(dataEmprestimo.ano > verificar.ano)
        {
            dataValida=-1;
        }
        else
        {
            ///anos iguais
            if(dataEmprestimo.mes < verificar.mes)
            {
                dataValida=1;
            }
            else
            {
                if(dataEmprestimo.mes > verificar.mes)
                {
                    dataValida=-1;
                }
                else
                {
                    ///meses iguais
                    if(dataEmprestimo.dia < verificar.dia)
                    {
                        dataValida = 1;
                    }
                    else
                    {
                        if(dataEmprestimo.dia > verificar.dia)
                        {
                            dataValida = -1;
                        }
                        else
                        {
                            ///dias iguais

                            if(dataEmprestimo.hora < verificar.hora)
                            {
                                dataValida=1;
                            }
                            else
                            {
                                if(dataEmprestimo.hora > verificar.hora)
                                {
                                    dataValida=-1;
                                }
                                else
                                {
                                    ///horas iguais

                                    if(dataEmprestimo.minuto < verificar.minuto)
                                    {
                                        dataValida=1;
                                    }
                                    else
                                    {
                                        if(dataEmprestimo.minuto > verificar.minuto)
                                        {
                                            dataValida=-1;
                                        }
                                        else
                                        {
                                            ///minutos iguais
                                            dataValida=-1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
    }
    return dataValida;
}
