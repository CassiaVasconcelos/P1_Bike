#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

void lerFicheiroBinBicicleta(tipoBicicleta bicicleta[MAXBICICLETA], int *contBicicletas){
    FILE *ficheiro;
    ficheiro=fopen("bicicletas.dat","rb");
    if (ficheiro == NULL) {
        printf ("Erro abrir ficheiro");
    }else{
    fread(contBicicletas,sizeof(int),1,ficheiro);
    fread(bicicleta,sizeof(tipoBicicleta),MAXBICICLETA,ficheiro);
    }
}

void escreverFicheiroBinBicicleta(tipoBicicleta bicicleta[MAXBICICLETA], int contBicicletas){
    if (contBicicletas==0)
    {
        printf("Nao existem bicicletas em registro\n");
    }
    FILE *ficheiro;

    ficheiro=fopen("bicicletas.dat","wb");
        if(ficheiro==NULL){
            printf("Erro de abertura");
        }
        else{
            fwrite(&contBicicletas,sizeof(int),1,ficheiro);
            fwrite(bicicleta,sizeof(tipoBicicleta),MAXBICICLETA,ficheiro);

            fclose(ficheiro);
            printf("\n\nFicheiro 1 Exportado com Sucesso\n\n");
        }
}

void lerFicheiroBinUtente(tipoUtente utente[MAXUTENTE], int *contUtente){
    FILE *ficheiro;
    ficheiro=fopen("utentes.dat","rb");
    if (ficheiro == NULL) {
        printf ("Erro abrir ficheiro");
    }else{
    fread(contUtente,sizeof(int),1,ficheiro);
    fread(utente,sizeof(tipoUtente),MAXUTENTE,ficheiro);
    }
}

void escreverFicheiroBinUtente(tipoUtente utente[MAXUTENTE], int contUtente){
    if (contUtente==0)
    {
        printf("Nao existem utentes em registro\n");
    }
    FILE *ficheiro;

    ficheiro=fopen("utentes.dat","wb");
        if(ficheiro==NULL){
            printf("Erro de abertura");
        }
        else{
            fwrite(&contUtente,sizeof(int),1,ficheiro);
            fwrite(utente,sizeof(tipoUtente),MAXUTENTE,ficheiro);

            fclose(ficheiro);
            printf("\n\nFicheiro 2 Exportado com Sucesso\n\n");
        }
}
