#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

///se nao houver bike disponivel, vai pra lista de espera
//entrar, sair e editar(campo de destino)

tipoEspera *registrarEspera(tipoEspera espera[],tipoUtente utente[],int *contEspera,int contUtente)
{
    int pos = -1;
    int i;
    int opcao;
    char campus[MAXSTRING];
    int codigo;
    tipoEspera *aux;
    aux = espera;  ///add
    int esperaRealizada=0,naoDisponivel=0;
    int flag = 1;

    codigo = lerInteiro("\nIntroduza o numero de utente:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utente,codigo,contUtente);


    if(pos == -1)
    {
        printf("\nNao existe nenhum utente com esse numero");
    }
    else
    {
        for(i=0 ; i<*contEspera ; i++)
        {
            if(codigo == espera[i].codigoUtente)
            {
                //    printf("\nO utente ja se encontra na lista de espera, aguarde sua vez! ");
                flag = 0;
            }
            else
            {
                flag=1;
            }
        }

        if(flag == 0)
        {
            printf("\nO utente ja se encontra na lista de espera, aguarde sua vez! ");
        }
        else
        {
            aux = realloc(aux,(*contEspera+1)*sizeof(tipoEspera));

            if(aux == NULL)
            {
                printf("\nImpossivel alocar memoria.");
            }
            else
            {

                printf("\nInsira o campus de origem que deseja:");
                opcao = menuCampus();

                switch(opcao)
                {
                case 1:
                    strcpy(aux[*contEspera].campusOrigem,"residencias");
                    break;
                case 2:
                    strcpy(aux[*contEspera].campusOrigem,"campus 1");
                    break;
                case 3:
                    strcpy(aux[*contEspera].campusOrigem,"campus 2");
                    break;
                case 4:
                    strcpy(aux[*contEspera].campusOrigem,"campus 5");
                    break;
                }
                printf("Insira a data e horario previsto para emprestimo:");
                aux[*contEspera].dataRegistro = lerData();
                aux[*contEspera].codigoUtente = codigo;


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

            if(strcmp(aux[*contEspera].campusOrigem,campus)==0)
            {
                printf("\nMesmo local de origem e destino. Tente novamente mais tarde.");
            }
            else
            {
                strcpy(aux[*contEspera].campusDestino,campus);
                printf("\nParabens! Voce foi adicionada a lista de espera, aguarde sua vez!");
                (*contEspera)++;
            }
        }
    }
    return aux;
}

void consultarEspera(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEspera espera[],int contBicicleta,int contUtentes,int contEspera)
{
    int numeroUtente;
    int pos = -1;
    int i;
    int j = 1;

    numeroUtente = lerInteiro("\nInsira o numero de utente que quer consultar na lista de espera:",1,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,numeroUtente,contUtentes);

    if(pos != -1)
    {
        for(i=0; i<contEspera; i++)
        {
            if(espera[i].codigoUtente == utentes[pos].numero)
            {
                printf("\nEspera %d",j);
                printf("\nCodigo de utente:%d\t\tNome Utente:%s",espera[i].codigoUtente,utentes[pos].nome);
                printf("\nCampus Origem:%s",espera[i].campusOrigem);
                printf("\nCampus destino:%s",espera[i].campusDestino);
                printf("\nData do pedido de emprestimo:%02d-%02d-%04d\t\t%02d:%02d",espera[i].dataRegistro.dia,espera[i].dataRegistro.mes,espera[i].dataRegistro.ano,
                       espera[i].dataRegistro.hora,espera[i].dataRegistro.minuto);
                j++;

            }
        }
    }
    else
    {
        printf("\nNao existe nenhum utente com o numero escolhido");
    }
}

void listarEspera(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEspera espera[],int contBicicleta,int contUtentes,int contEspera)
{
    int i, j = 1;

    for(i=0; i<contEspera; i++)
    {
        printf("\nEspera %d",j);
        printf("\nCodigo de utente:%d",espera[i].codigoUtente);
        printf("\nCampus Origem:%s",espera[i].campusOrigem);
        printf("\nCampus destino:%s",espera[i].campusDestino);
        printf("\nData prevista para emprestimo:%02d-%02d-%04d\t\t%02d:%02d",espera[i].dataRegistro.dia,espera[i].dataRegistro.mes,espera[i].dataRegistro.ano,
               espera[i].dataRegistro.hora,espera[i].dataRegistro.minuto);
        j++;
    }
}

void alterarCampusDestinoEspera(tipoEspera espera[],  int contEspera)
{
    int codigo,opcao;
    int i;
    int utenteExiste =1;
    char campus[MAXSTRING];

    codigo = lerInteiro("\nIntroduza o numero de utente que pretende alterar:",0,MAXNUMEROUTENTE);

    for(i=0 ; i<contEspera ; i++)
    {
        if(espera[i].codigoUtente==codigo)
        {
            printf("\nO campus de destino selecionado anteriormente foi: %s",espera[i].campusDestino);
            printf("\nInsira o novo campus de destino que deseja:");

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

            if(strcmp(espera[i].campusOrigem,campus)==0)
            {
                printf("Mesmo campus de origem e destino, tente novamente inserindo locais diferentes para a bicicleta");
            }
            else
            {
                if(strcmp(espera[i].campusDestino,campus)==0)
                {
                    printf("Voce nao mudou o campus de destino, tente novamente inserindo locais diferentes para a bicicleta");
                }
                else
                {
                    strcpy(espera[i].campusDestino,campus);
                    printf("\nDestino alterado com sucesso");
                }
            }
        }
        else
        {
            utenteExiste = 0;
        }
    }
    if(utenteExiste==0)
    {
        printf("\nNao ha cadastro desse utente na lista de espera.");
    }
}

tipoEspera *eliminarEspera(tipoUtente utentes[],tipoEspera espera[],int contUtentes,int *contEspera)
{
    int i;
    tipoEspera *aux;
    aux = espera;
    int j=1;
    int codigo;
    int pos = -1;
    int posApagar=-1;
    tipoEspera auxiliar;

    codigo = lerInteiro("\nInsira o numero de utente que quer efectuar o emprestimo:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,codigo,contUtentes);

    if(pos == -1)
    {
        printf("\nO utente nao existe");
    }
    else
    {
        for(i=0; i<*contEspera; i++)
        {
            if(espera[i].codigoUtente == utentes[pos].numero)
            {
                posApagar = i;
                //         break;
            }
        }
        if(posApagar == -1)
        {
            printf("\nO utente nao esta na lista de espera.");
        }
        else
        {
            for(i=posApagar; i<*contEspera-1; i++)
            {
                j=i+1;  //substitiu a posicao posterior a posicao eliminada

                auxiliar.codigoUtente = aux[j].codigoUtente;//salvando no auxiliar a posicao a frente
                strcpy(auxiliar.campusDestino,aux[j].campusDestino);
                strcpy(auxiliar.campusOrigem,aux[j].campusOrigem);
                auxiliar.dataRegistro = aux[j].dataRegistro;

                aux[i].codigoUtente = auxiliar.codigoUtente;
                strcpy(aux[i].campusDestino,auxiliar.campusDestino);
                strcpy(aux[i].campusOrigem,auxiliar.campusOrigem);
                aux[i].dataRegistro = auxiliar.dataRegistro;

            }

            aux = realloc(aux,(*contEspera-1)*sizeof(tipoEspera));
            (*contEspera)--;
            printf("\nO utente foi eliminado da lista de espera");
        }
    }

    return aux;
}
