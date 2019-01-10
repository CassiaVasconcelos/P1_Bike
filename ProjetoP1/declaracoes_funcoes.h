#ifndef DECLARACOES_FUNCOES_H_INCLUDED
#define DECLARACOES_FUNCOES_H_INCLUDED

#include "constantes.h"
#include "estruturas.h"
//auxiliares
int lerInteiro(char mensagem[MAXSTRING], int minimo, int maximo);
float lerFloat(char mensagem[MAXSTRING], float minimo, float maximo);
void lerString(char mensagem[MAXSTRING], char vetorCaracteres[MAXSTRING], int maximoCaracteres);
void limpaBufferStdin(void);
tipoData lerData(void);
//menus
int menuPrincipal(int contBicicletas, int contEmprestimo, int contEspera, int contUtente, int bicicletasOcupadas, float distTotPecorrida);
char menuBicicleta(int contBicicletas);
char menuUtente(int contUtente);
int menuCampus();
int subMenuTipoUtente();
//bicicletas
void inserirBicicleta(tipoBicicleta bicicletas[],int *contBicicletas);
void consultarBicicleta(tipoBicicleta bicicletas[],int contBicicletas);
void listarBicicletas(tipoBicicleta bicicletas[],int contBicicletas);
int procurarBicicleta(tipoBicicleta bicicletas[],char designacao[],int contBicicletas);
int bicicletasDisponiveis(tipoBicicleta bicicletas[], int *contBicicletas);
//emprestimos
tipoEmprestimo *registarEmprestimo(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int *contEmprestimo,int *idEmprestimo,int *bicicletasOcupadas);
void listarEmprestimos(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo);
void consultarEmprestimo(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo);
void devolverBicicleta(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo,int *bicicletasOcupadas);
//ficheiro
void lerFicheiroBinBicicleta(tipoBicicleta bicicleta[MAXBICICLETA], int *contBicicletas);
void escreverFicheiroBinBicicleta(tipoBicicleta bicicleta[MAXBICICLETA], int contBicicletas);
void lerFicheiroBinUtente(tipoUtente utente[MAXUTENTE], int *contUtente);
void escreverFicheiroBinUtente(tipoUtente utente[MAXUTENTE], int contUtente);
tipoEmprestimo *lerFicheiroBinEmprestimo(tipoEmprestimo emprestimo[], int *contEmprestimo);
void escreverFicheiroBinEmprestimo(tipoEmprestimo emprestimo[], int contEmprestimo);
//utentes
void inserirUtente(tipoUtente Utente[],int *contUtente);
int procurarUtente(tipoUtente Utente[],int codigo,int contUtente);
void alterarUtente(tipoUtente Utente[],int contUtente);
void consultarUtente(tipoUtente Utente[],int contUtente);
void listarUtente(tipoUtente Utente[],int contUtente);


#endif // DECLARACOES_FUNCOES_H_INCLUDED
