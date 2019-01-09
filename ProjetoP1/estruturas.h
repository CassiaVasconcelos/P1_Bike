#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include "constantes.h"
#include "declaracoes_funcoes.h"

typedef struct{
    char designacao[MAXSTRING];///ID inserido pelo usuario
    char modelo[MAXSTRING];
    char estado[MAXESTADO];  ///disponivel, emprestada, avariada
    char campus[MAXSTRING];  ///residencias, campus 1, campus 2, campus 5
    int quantidadeEmprestimos;
    int quantidadeAvarias;
    float distanciaTotal;
}tipoBicicleta;

typedef struct{
    int numero;
    char nome[MAXSTRING];
    int telemovel;
    char tipo[MAXSTRING]; ///estudante docente tecnico administrativo convidado
    int quantidadeEmprestimos;
    float distanciaPercorrida;
}tipoUtente;

#endif // ESTRUTURAS_H_INCLUDED
