#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

int main()
{
    int opcao,contBicicletas=0,contEmprestimo=0,contEspera=0,contUtente=0,bicicletasOcupadas=0;
    char opcaoBicicleta,opcUtente;

    tipoBicicleta bicicleta[MAXBICICLETA];
    tipoUtente utente[MAXUTENTE];

    lerFicheiroBinBicicleta(bicicleta,&contBicicletas);
    lerFicheiroBinUtente(utente,&contUtente);

    do
    {
        opcao = menuPrincipal(contBicicletas, contEmprestimo, contEspera, contUtente, bicicletasOcupadas);
        switch(opcao)
        {
            case 1:
                opcaoBicicleta = menuBicicleta(contBicicletas);
                switch(opcaoBicicleta)
                {
                case 'I':
                    if(contBicicletas == MAXBICICLETA){
                            printf("\nJa atingiu o numero maximo de bicicletas");
                        }else{
                            inserirBicicleta(bicicleta,&contBicicletas);
                        }
                break;
                case 'C':
                    consultarBicicleta(bicicleta,contBicicletas);
                break;
                case 'L':
                    listarBicicletas(bicicleta,contBicicletas);
                break;
                case 'R':
                break;
                }
            break;
            case 2:
                opcUtente = menuUtente(contUtente);
                switch(opcUtente)
                {
                case 'I':
                    if(contUtente == MAXUTENTE){
                            printf("\nJa atingiu o numero maximo de utentes");
                        }else{
                            inserirUtente(utente,&contUtente);
                        }
                break;
                case 'C':
                    consultarUtente(utente,contUtente);
                break;
                case 'L':
                    listarUtente(utente,contUtente);
                break;
                case 'A':
                    alterarUtente(utente,contUtente);
                break;
                }
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
        }
    }while(opcao!=8);

    escreverFicheiroBinBicicleta(bicicleta,contBicicletas);//salvar
    escreverFicheiroBinUtente(utente,contUtente);//salvar

    return 0;
}
