# Trabalho Árvores-ED

-> Foco Principal: Comparação entre Árvores Binárias de Pesquisa(ABP), Árvores AVL(AVL) e Árvores Splay(Splay) no Armazenamento e Consulta de Dados.

## Introdução

O objetivo deste trabalho é implementar um código que utilize três formas diferentes de árvore binária, sendo ABP, AVL e Splay, e comparar o desempenho das três em armazenamento e em consulta de informações de jogos da Steam. O programa lê dois arquivos: um contendo uma lista de jogos e seus tempos médios de jogatina(.csv), e outro contendo a lista de jogos de um usuário(.txt). Com isso, ele cria um arquivo de saída(.txt) com o tempo total dos jogos que o usuário escolheu junto com informações sobre as árvores utilizadas para fazer essa busca.

-------------------------------------

PENDENTE: Colocar explicações do código

-------------------------------------

## Como chamar no Ubuntu(Linux)

  1. Local dos arquivos:
    cd /mnt/c/Users/LocalDosArquivos

  2. Criar o executavel:
    gcc -o main main.c arvores.c arvores.h

  3. Executar o programa e suas entradas:
    ./main dataset.csv lista_jogador1.txt saida1.txt
