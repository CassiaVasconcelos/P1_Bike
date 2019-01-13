#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

void listarUtentesPorNumeroDecrescenteDeEmprestimos(tipoUtente utentes[],tipoEmprestimo emprestimos[],int contUtentes,int contEmprestimo)
{
    int i, j, aux;
    tipoUtente auxiliar[MAXUTENTE];
    tipoUtente ut;
    ///para nao alterar diretamente o vetor utentes, fizemos a copia para o auxiliar
    for(i=0; i<contUtentes; ++i) //so para fazer a copia
    {
        strcpy(auxiliar[i].nome,utentes[i].nome);
        auxiliar[i].numero = utentes[i].numero;
        auxiliar[i].telemovel = utentes[i].telemovel;
        strcpy(auxiliar[i].tipo,utentes[i].tipo);
        auxiliar[i].distanciaPercorrida = utentes[i].distanciaPercorrida;
        auxiliar[i].quantidadeEmprestimos = utentes[i].quantidadeEmprestimos;
    }

    for(i=0; i < contUtentes-1; i++)           //troca direta
    {
        for (j= i+1; j < contUtentes; j++)
        {
            if(utentes[j].quantidadeEmprestimos > utentes[i].quantidadeEmprestimos)     //> para descrescente
            {
                strcpy(ut.nome,utentes[j].nome);
                ut.numero = utentes[j].numero;
                ut.telemovel = utentes[j].telemovel;
                strcpy(ut.tipo,utentes[j].tipo);
                ut.distanciaPercorrida = utentes[j].distanciaPercorrida;
                ut.quantidadeEmprestimos = utentes[j].quantidadeEmprestimos;

                strcpy(auxiliar[i].nome,ut.nome);
                auxiliar[i].numero = ut.numero;
                auxiliar[i].telemovel = ut.telemovel;
                strcpy(auxiliar[i].tipo,ut.tipo);
                auxiliar[i].distanciaPercorrida = ut.distanciaPercorrida;
                auxiliar[i].quantidadeEmprestimos = ut.quantidadeEmprestimos;

                strcpy(auxiliar[j].nome,utentes[i].nome);
                auxiliar[j].numero = utentes[i].numero;
                auxiliar[j].telemovel = utentes[i].telemovel;
                strcpy(auxiliar[j].tipo,utentes[i].tipo);
                auxiliar[j].distanciaPercorrida = utentes[i].distanciaPercorrida;
                auxiliar[j].quantidadeEmprestimos = utentes[i].quantidadeEmprestimos;
            }
        }
    }

    j=1;

    for(i=0; i<contUtentes; ++i)
    {
        printf("\n\nUtente %d",j);
        printf("\nNome Utente:%s",auxiliar[i].nome);
        printf("\nNumero Utente:%d",auxiliar[i].numero);
        printf("\nTelemovel Utente:%d",auxiliar[i].telemovel);
        printf("\nTipo de Utente:%s",auxiliar[i].tipo);
        printf("\nDistancia percorrida pelo Utente:%f",auxiliar[i].distanciaPercorrida);
        printf("\nQuantidade de emprestimo efectuadas pelo Utente:%d",auxiliar[i].quantidadeEmprestimos);
        j++;
    }
}

void listarDadosEmprestimoUtente(tipoBicicleta bicicletas[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo)
{
    int pos = -1;
    int codigo;
    int i;
    int opcao;
    int j = 1;
    int posUltimaBicicleta = -1;

    codigo = lerInteiro("\nInsira o numero de utente que saber os dados:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,codigo,contUtentes);

    if(pos == -1)
    {
        printf("\nO utente nao existe");
    }
    else
    {
        printf("\n\t\tHistorico emprestimo do utente com a designacao selecionada");

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
                printf("\nDistancia percorrida:%f",emprestimos[i].distanciaPercorrida);
                j++;
            }
        }

            for(i=0; i<contEmprestimo; ++i)
            {
                if(emprestimos[i].codigoUtente==codigo)
                {
           /*         if(emprestimos[i].dataEmprestimo){

                    }*/
                }
            }

            printf("\n\nDados da ultima bicicleta emprestado ao utilizador com a designacao selecionada\n");
            printf("\nDesignacao:%s",bicicletas[posUltimaBicicleta].designacao);
            printf("\nCampus:%s",bicicletas[posUltimaBicicleta].campus);
            printf("\nModelo:%s",bicicletas[posUltimaBicicleta].modelo);
            printf("\nEstado:%s",bicicletas[posUltimaBicicleta].estado);
            printf("\nQuantidade Avarias:%d",bicicletas[posUltimaBicicleta].quantidadeAvarias);
            printf("\nQuantidade Emprestimo:%d",bicicletas[posUltimaBicicleta].quantidadeEmprestimos);
            printf("\nDistancia percorrida:%f",bicicletas[posUltimaBicicleta].distanciaTotal);

        }


}

