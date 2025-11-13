#include "arvores.h"
#define N 100


// ====================================================================================================
// =============================================VARIAVEIS GLOBAIS======================================
// ====================================================================================================

int rotacoesSplay = 0;  //variavel gobal que armazena o numero atual de rotacoes da splay
int comparacoesABP = 0; //variavel global que armazena o numero atual de comparacoes da ABP
int comparacoesSplay = 0;   //variavel global que armazena o numero atual de comparacoes da Splay
int ehBuscaSplay = 0;   //variavel global auxiliar para indicar se esta sendo feita uma busca em uma splay par incrementar as comparacoes
int nodos = 0;  //variavel global que armazena o numero de nodos inseridos
int rotacoesAVL = 0; // var global que armazena o numero atual de rotacoes da avl
int comparacoesAVL = 0; // var global que armazena o numero atual de comparacoes da avl

// ====================================================================================================
// ===========================================BASICO ARVORE============================================
// ====================================================================================================

//inicializa as arvores
Nodo *inicializa()
{
    return NULL;
}

//insere um nodo em uma ABP
Nodo* insere(Nodo* raiz, Jogo jogo)
{
    if(raiz == NULL)
    {
        raiz = (Nodo*)malloc(sizeof(Nodo));
        if(raiz == NULL)
            return NULL;

        raiz->jogo = jogo;
        raiz->esq = NULL;
        raiz->dir = NULL;
        return raiz;
    }
    if(strcmp(jogo.nome, raiz->jogo.nome) < 0)
        raiz->esq = insere(raiz->esq, jogo);

    else
        raiz->dir = insere(raiz->dir, jogo);

    return raiz;
}

//calcula recursivamente a altura de uma arvore
int altura(Nodo* raiz)
{
    int esq, dir;
    if(raiz == NULL)
        return 0;

    esq = 1 + altura(raiz->esq);
    dir = 1 + altura(raiz->dir);

    if(esq > dir)
        return esq;
    else
        return dir;
}


// ====================================================================================================
// ===========================================FUNCOES ABP/AVL==========================================
// ====================================================================================================

//realiza a procura de um jogo em uma ABP
Jogo consultaABP(Nodo* raiz, char jogo[])
{
    Jogo vazio = {"", 0.0};

    while(raiz != NULL)
    {
        comparacoesABP++;

        if(strcmp(jogo, raiz->jogo.nome) == 0)
            return raiz->jogo;

        else if(strcmp(jogo, raiz->jogo.nome) < 0)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;

    }
    return vazio;
}

//realiza a procura de um jogo em uma AVL
Jogo consultaAVL(Nodo* raiz, char jogo[])
{
    Jogo vazio = {"", 0.0};

    while(raiz != NULL)
    {
        comparacoesAVL++;

        if(strcmp(jogo, raiz->jogo.nome) == 0)
            return raiz->jogo;

        else if(strcmp(jogo, raiz->jogo.nome) < 0)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;

    }
    return vazio;
}

// ====================================================================================================
// ===========================================FUNCOES SPLAY============================================
// ====================================================================================================

//Realiza a operacao de splay em uma arvore dado item a ser procurado
Nodo* splay(Nodo* raiz, char jogo[])
{
    if (raiz == NULL)
        return NULL;

    int aux = strcmp(jogo, raiz->jogo.nome);

    //trecho de codigo responsavel por contabilizar o numero de comparacoes feitas na Splay
    if(ehBuscaSplay)
        comparacoesSplay++;

    // achou o jogo
    if (aux == 0)
        return raiz;

    // Caso 1: a subarvore esquerda
    if (aux < 0)
    {
        // se não existe sub esquerda, retorna o último visitado
        if (raiz->esq == NULL)
            return raiz;

        int aux2 = strcmp(jogo, raiz->esq->jogo.nome);

        // zig-zig
        if (aux2 < 0)
        {
            raiz->esq->esq = splay(raiz->esq->esq, jogo);
            raiz = zig(raiz);
        }
        //  zig-zag
        else if (aux2 > 0)
        {
            raiz->esq->dir = splay(raiz->esq->dir, jogo);
            if (raiz->esq->dir != NULL)
                raiz->esq = zag(raiz->esq);
        }

        // rotação final se ainda existe filho esquerdo
        if (raiz->esq == NULL)
            return raiz;
        else
            return zig(raiz);
    }

    //  Caso 2: subarvore direita
    else
    {
        // se não existe sub direita, retorna o ultimo
        if (raiz->dir == NULL)
            return raiz;

        int aux2 = strcmp(jogo, raiz->dir->jogo.nome);

        // zag-zig
        if (aux2 < 0)
        {
            raiz->dir->esq = splay(raiz->dir->esq, jogo);
            if (raiz->dir->esq != NULL)
                raiz->dir = zig(raiz->dir);
        }
        // zag-zag
        else if (aux2 > 0)
        {
            raiz->dir->dir = splay(raiz->dir->dir, jogo);
            raiz = zag(raiz);
        }

        // rotação final se ainda existe filho direito
        if (raiz->dir == NULL)
            return raiz;
        else
            return zag(raiz);
    }
}


//operacao de rotacao zig
Nodo* zig(Nodo* raiz)
{
    Nodo* aux;

    aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;

    //incrementa o numero de rotacoes
    rotacoesSplay++;

    return aux;
}

//operacao de rotacao zag
Nodo* zag(Nodo* raiz)
{
    Nodo* aux;

    aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;

    //incrementa o numero de rotacoes
    rotacoesSplay++;

    return aux;
}

//funcao que realiza a insercao em uma Splay
Nodo* insereSplay(Nodo *raiz, Jogo jogo)
{
    raiz = insere(raiz, jogo);  //insere igual a uma ABP
    raiz = splay(raiz, jogo.nome);  //Realiza Splay para trazer o nodo inserida para a raiz
    return raiz;
}

//funcao que realiza a consulta em uma Splay
Jogo consultaSplay(Nodo** raiz, char jogo[])
{
    //realiza Splay do nodo procurado, trazendo-o para a raiz
    *raiz = splay(*raiz, jogo);
    return (*raiz)->jogo;
}

// ====================================================================================================
// ===========================================FUNCOES AVL==============================================
// ====================================================================================================

Nodo* rotacao_direita(Nodo* p)
{
    rotacoesAVL++;
    Nodo *u;

    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->FB = 0;
    p = u;

    return p;
}

Nodo* rotacao_esquerda(Nodo *p)
{
    rotacoesAVL++;
    Nodo *z;

    z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->FB = 0;
    p = z;

    return p;
}



Nodo* rotacao_dupla_direita (Nodo* p)
{
    rotacoesAVL++;
    Nodo *u, *v;

    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;

    if (v->FB == 1)
        p->FB = -1;
    else
        p->FB = 0;

    if (v->FB == -1)
        u->FB = 1;
    else
        u->FB = 0;

    p = v;
    return p;
}


Nodo* rotacao_dupla_esquerda (Nodo *p)
{
    rotacoesAVL++;
    Nodo *z, *y;

    z = p->dir;
    y = z->esq;
    z->esq = y->dir;
    y->dir = z;
    p->dir = y->esq;
    y->esq = p;

    if (y->FB == -1)
        p->FB = 1;
    else
        p->FB = 0;

    if (y->FB == 1)
        z->FB = -1;
    else
        z->FB = 0;

    p = y;
    return p;
}

// insere --> AVL
//fiz a mudanca de utilizar a ordem alfabetica da tabela ascii por meio do strcmp
Nodo* insereAVL (Nodo *a, char *nome, float x, int *ok)
{
    /* Insere nodo em uma árvore AVL, onde A representa a raiz da árvore,
     x, a chave a ser inserida e h a altura da árvore */
    if (a == NULL)
    {
        a = (Nodo*) malloc(sizeof(Nodo));
        a->jogo.horas = x;

        //fiz assim para evitar estouro na hora de copiar o nome
        strncpy(a->jogo.nome, nome, sizeof(a->jogo.nome)-1);
        a->jogo.nome[sizeof(a->jogo.nome)-1] = '\0';

        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        *ok = 1;
    }
    else if (strcmp(nome, a->jogo.nome) < 0)
    {
        a->esq = insereAVL(a->esq,nome,x,ok);
        if (*ok)
        {
            switch (a->FB)
            {
            case -1:
                a->FB = 0;
                *ok = 0;
                break;
            case 0:
                a->FB = 1;
                break;
            case 1:
                a=Caso1(a,ok);
                break;
            }
        }
    }
    else
    {
        a->dir = insereAVL(a->dir,nome,x,ok);
        if (*ok)
        {
            switch (a->FB)
            {
            case 1:
                a->FB = 0;
                *ok = 0;
                break;
            case 0:
                a->FB = -1;
                break;
            case -1:
                a = Caso2(a,ok);
                break;
            }
        }
    }

    return a;
}

Nodo* Caso1 (Nodo *a, int *ok)
{
    Nodo *z;

    z = a->esq;
    if (z->FB == 1)
        a = rotacao_direita(a);
    else
        a = rotacao_dupla_direita(a);

    a->FB = 0;
    *ok = 0;
    return a;
}

Nodo* Caso2 (Nodo *a, int *ok)
{
    Nodo *z;

    z = a->dir;
    if (z->FB == -1)
        a = rotacao_esquerda(a);
    else
        a = rotacao_dupla_esquerda(a);

    a->FB = 0;
    *ok = 0;
    return a;
}


// ====================================================================================================
// ========================================GESTAO DOS ARQUIVOS=========================================
// ====================================================================================================

//insere os jogos de uma lista de jogos em uma arvore Splay e uma arvore ABP
void montaArvores(char nomeArq[], Nodo** Splay, Nodo** ABP, Nodo** AVL)
{
    FILE* arq;
    char strAux[N];
    char *pchar;
    Jogo jogoAux;

    int ok; //pra chamar a função de insereAVL

    //abre o arquivo para leitura
    arq = fopen(nomeArq, "r");
    if(arq != NULL)
    {
        //enquanto o arquivo nao chegar ao fim
        while(!feof(arq))
        {
            //se conseguir realizara a leitura
            if(fgets(strAux, N, arq) !=0)
            {
                //quebra a linha atual em duas partes no separador indicado pela virgula
                pchar = strtok(strAux, ",");
                strcpy(jogoAux.nome, pchar);    //copia o nome do jogo para uma variavel de jogo auxiliar

                //tranforma o caractere numerico ascii para float
                //e guarda na variavel de jogo auxiliar
                pchar = strtok(NULL, "\n");
                jogoAux.horas = atof(pchar);

                *Splay = insereSplay(*Splay, jogoAux);  //insere na Splay
                *ABP = insere(*ABP, jogoAux);           //insere na ABP
                *AVL = insereAVL(*AVL, jogoAux.nome, jogoAux.horas, &ok);     //insere na AVL

                nodos++;    //incrementa a contagem de nodos inseridos
            }
        }
        fclose(arq);    //fecha o arquivo
    }
}

void montaSaida(char listaJogos[], char saida[], Nodo* Splay, Nodo* ABP, Nodo* AVL)
{
    FILE* arqJogos;
    FILE* arqSaida;
    char strAux[N];
    char nomeJogo[TAM];
    Jogo jogoAux;
    float horas = 0;
    int alturaABP;
    int alturaAVL;
    int alturaSplayAntes;
    int alturaSplayDepois;
    int rotacoesSplayAntes;

    alturaABP = altura(ABP);    //realiza a contagem da altura da ABP
    alturaSplayAntes = altura(Splay);   //realiza a contagem da Splay antes das buscas
    alturaAVL = altura(AVL);

    arqJogos = fopen(listaJogos, "r");  //abre o arquivo da lista de jogos para leitura
    if(arqJogos != NULL)
    {
        arqSaida = fopen(saida, "w");   //abre o arquivo de saida para escrita
        if(arqSaida != NULL)
        {
            ehBuscaSplay = 1;   //muda para 1, indicando que sera realizada busca, liberando a contagem de comparacoes na funcao Splay
            rotacoesSplayAntes = rotacoesSplay; //armazena o numero de rotacoes da Splay antes das buscas

            //enquanto o arquivo nao acabar
            while(!feof(arqJogos))
            {
                //se conseguir realizar a leitura
                if(fgets(strAux, N, arqJogos) !=0)
                {
                    //copia o nome do jogo na lista para uma variave auxiliar
                    strAux[strlen(strAux)-1] = '\0';
                    strcpy(nomeJogo, strAux);

                    //procura o jogo na ABP
                    jogoAux = consultaABP(ABP, nomeJogo);

                    //incrementa o numero de horas correspondente ao jogo procurado
                    horas += jogoAux.horas;

                    //procura o jogo na Splay
                    jogoAux = consultaSplay(&Splay, nomeJogo);

                    //procura o jogo na avl
                    jogoAux = consultaAVL(AVL, nomeJogo);
                }
            }
            alturaSplayDepois = altura(Splay);//realiza a contagem da altura da splay apos a busca

            //horas totais
            fprintf(arqSaida, "Tempo total estimado: %.2f\n\n", horas);

            //ABP
            fprintf(arqSaida, "======== ESTATÍSTICAS ABP ============\n");
            fprintf(arqSaida, "Número de Nodos: %d\nAltura: %d\nRotações: 0\nComparações: %d\n\n", nodos, alturaABP, comparacoesABP);

            //SPLAY
            fprintf(arqSaida, "======== ESTATÍSTICAS SPLAY ============\n");
            fprintf(arqSaida, "Número de Nodos: %d\nAltura antes da busca: %d\n", nodos, alturaSplayAntes);
            fprintf(arqSaida, "Altura depois da busca: %d\nRotações antes da busca: %d\n", alturaSplayDepois, rotacoesSplayAntes);
            fprintf(arqSaida, "Rotações depois da busca: %d\nComparações: %d\n\n",  rotacoesSplay, comparacoesSplay);

            //AVL
            fprintf(arqSaida, "======== ESTATÍSTICAS AVL ============\n");
            fprintf(arqSaida, "Número de Nodos: %d\nAltura: %d\n", nodos, alturaAVL);
            fprintf(arqSaida, "Rotações: %d\nComparações: %d\n\n",  rotacoesAVL, comparacoesAVL);

            fclose(arqSaida);//fecha o arquivo de saida
        }
        fclose(arqJogos);//fecha o arquivo da lista de jogos
    }
}

