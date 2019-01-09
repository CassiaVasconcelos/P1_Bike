#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

tipoEmprestimo *registarEmprestimo(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtente,int *contEmprestimo,int *idEmprestimo,int *bicicletasOcupadas){
    int numeroUtente;
    int pos = -1;
    int i;
    int dia,mes,ano;
    int dataValida = -1;
    int opcao;
    char campus[MAXSTRING];
    int codigo;
    tipoEmprestimo *aux;
    aux = emprestimos;
    int incremento;

    codigo = lerInteiro("\nIntroduza o numero de utente:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,codigo,contUtente);

    if(pos == -1){
        printf("\nNao existe nenhum utente com esse numero");
    }else{
        printf("\n\nInsira o campus onde deseja efectuar o emprestimo:");
        printf("\n1->Residencias");
        printf("\n2->Campus 1");
        printf("\n3->Campus 2");
        printf("\n4->Campus 5");
        opcao = lerInteiro("\nEscolhe uma opcao: ",1,4);

        switch(opcao){
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

        for(i=0;i<contBicicleta;++i){
            if(strcmp(bicicleta[i].campus,campus)==0){
               if(strcmp(bicicleta[i].estado,"disponivel")==0){ //ve se tem alguma bike disponivel naquele campus
                    aux = realloc(aux,(*contEmprestimo+1)*sizeof(tipoEmprestimo));

                    if(aux == NULL){
                        printf("\nImpossivel alocar memoria.");
                    }else{
                        //printf("teste:%d",*contEmprestimo);
                        aux[*contEmprestimo].numeroRegisto = *idEmprestimo;
                        printf("teste2");
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

                        switch(opcao){
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
                    if(strcmp(aux[*contEmprestimo].campusOrigem,campus)==0){
                        printf("Insira outro local para deixar a bike");
                    } else{
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

        return aux;//para atualizar a memoria dinamica
    }
}
