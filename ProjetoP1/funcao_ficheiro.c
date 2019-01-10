#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

void lerFicheiroBinBicicleta(tipoBicicleta bicicleta[MAXBICICLETA], int *contBicicletas)
{
    FILE *ficheiro;
    ficheiro=fopen("bicicletas.dat","rb");
    if (ficheiro == NULL)
    {
        printf ("Erro abrir ficheiro bike");
    }
    else
    {
        fread(contBicicletas,sizeof(int),1,ficheiro);
        fread(bicicleta,sizeof(tipoBicicleta),MAXBICICLETA,ficheiro);
    }
}

void escreverFicheiroBinBicicleta(tipoBicicleta bicicleta[MAXBICICLETA], int contBicicletas)
{
    if (contBicicletas==0)
    {
        printf("Nao existem bicicletas em registro\n");
    }
    FILE *ficheiro;

    ficheiro=fopen("bicicletas.dat","wb");
    if(ficheiro==NULL)
    {
        printf("Erro de abertura bike");
    }
    else
    {
        fwrite(&contBicicletas,sizeof(int),1,ficheiro);
        fwrite(bicicleta,sizeof(tipoBicicleta),MAXBICICLETA,ficheiro);

        fclose(ficheiro);
        printf("\nFicheiro bicicletas exportado com sucesso\n\n");
    }
}

void lerFicheiroBinUtente(tipoUtente utente[MAXUTENTE], int *contUtente)
{
    FILE *ficheiro;
    ficheiro=fopen("utentes.dat","rb");
    if (ficheiro == NULL)
    {
        printf ("Erro abrir ficheiro utente");
    }
    else
    {
        fread(contUtente,sizeof(int),1,ficheiro);
        fread(utente,sizeof(tipoUtente),MAXUTENTE,ficheiro);
    }
}

void escreverFicheiroBinUtente(tipoUtente utente[MAXUTENTE], int contUtente)
{
    if (contUtente==0)
    {
        printf("Nao existem utentes em registro\n");
    }
    FILE *ficheiro;

    ficheiro=fopen("utentes.dat","wb");
    if(ficheiro==NULL)
    {
        printf("Erro de abertura utente");
    }
    else
    {
        fwrite(&contUtente,sizeof(int),1,ficheiro);
        fwrite(utente,sizeof(tipoUtente),MAXUTENTE,ficheiro);

        fclose(ficheiro);
        printf("\nFicheiro utentes exportado com sucesso\n\n");
    }
}

tipoEmprestimo *lerFicheiroBinEmprestimo(tipoEmprestimo emprestimo[], int *contEmprestimo)
{
    FILE *ficheiro;
    tipoEmprestimo *aux;
    aux = NULL;
    ficheiro=fopen("emprestimos.dat","rb");
    if (ficheiro == NULL)
    {
        printf ("Erro abrir ficheiro emprestimo");
    }
    else
    {
        fread(contEmprestimo,sizeof(int),1,ficheiro);

        aux = realloc(aux,(*contEmprestimo)*sizeof(tipoEmprestimo));

        if(aux ==NULL && *contEmprestimo != 0)
        {
            printf("\nErro ao alocar memoria");
            *contEmprestimo =0;
        }
        else
        {
            fread(aux,sizeof(tipoEmprestimo),*contEmprestimo,ficheiro); //add
           // fread(emprestimo,sizeof(tipoEmprestimo),contEmprestimo,ficheiro);
        }

    }

    return aux;
}

void escreverFicheiroBinEmprestimo(tipoEmprestimo emprestimo[], int contEmprestimo)
{
    if (contEmprestimo==0)
    {
        printf("Nao existem emprestimos em registro\n");
    }
    FILE *ficheiro;

    ficheiro=fopen("emprestimos.dat","wb");
    if(ficheiro==NULL)
    {
        printf("Erro de abertura emprestimos");
    }
    else
    {
        fwrite(&contEmprestimo,sizeof(int),1,ficheiro);
        fwrite(emprestimo,sizeof(tipoEmprestimo),contEmprestimo,ficheiro);

        fclose(ficheiro);
        printf("\nFicheiro emprestimos exportado com sucesso\n\n");
    }
}
