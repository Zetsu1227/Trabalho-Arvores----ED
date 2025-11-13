#ifndef ARVORES_H_INCLUDED
#define ARVORES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 70

//STRUCT JOGO
typedef struct{
    char nome[TAM];
    float horas;
}Jogo;

//STRUCT NODO
typedef struct str_nodo Nodo;

struct str_nodo{
    Jogo jogo;
    Nodo *esq;
    Nodo *dir;

    //Para AVLs
    int FB;
};

//Arvores
Nodo *inicializa();
Nodo *insere(Nodo*, Jogo);
int altura(Nodo*);

//ABP e AVL --> é a mesma função so muda qual comparacao ta somando
Jogo consultaABP(Nodo*, char[]);
Jogo consultaAVL(Nodo* raiz, char jogo[]);

//Splay
Nodo *splay(Nodo*, char[]);
Nodo *insereSplay(Nodo*, Jogo);
Jogo consultaSplay(Nodo**, char[]);
Nodo *zig(Nodo*);
Nodo *zag(Nodo*);

//AVL
Nodo* rotacao_direita(Nodo* p); //rotaciona a direita a arvore
Nodo* rotacao_esquerda(Nodo *p); //rotaciona a esquerda a arvore
Nodo* rotacao_dupla_direita (Nodo* p); //rotaciona duas vezes a direita
Nodo* rotacao_dupla_esquerda (Nodo *p); //rotaciona duas vezes a esquerda
Nodo* insereAVL (Nodo *a, char *nome ,float x, int *ok); //insere em avl
Nodo* Caso1 (Nodo *a, int *ok); //caso de inclusao avl na direita
Nodo* Caso2 (Nodo *a, int *ok); // caso de inclusao avl na esquerda


//Manejo dos arquivos
void montaArvores(char[], Nodo**, Nodo**, Nodo**);
void montaSaida(char[], char[], Nodo*, Nodo*, Nodo*);


#endif // ARVORES_H_INCLUDED
