#include "arvores.h"

int main(int argc, char *argv[])
{
    if (argc!=4)  //o numero de parametros esperado eh 3: nome do programa (argv[0]), nome do arq da steam(argv[1]), nome do arq da listaJogador(argv[2]) nome do arq de saida(argv[3])
    {
        printf ("Numero incorreto de parametros.\n Para chamar o programa digite: exemplo <arq_entrada1> <arq_entrada2> <arq_saida>\n");
        return 1;
    }
    else
    {
        Nodo* Splay;
        Nodo* ABP;
        Nodo* AVL;

        //inicializa as arvores
        Splay = inicializa();
        ABP = inicializa();
        AVL = inicializa();

        montaArvores(argv[1], &Splay, &ABP, &AVL);  //monta as arvores
        montaSaida(argv[2], argv[3], Splay, ABP, AVL);  //monta o arquivo de saida

    }
    return 0;
}
