# 🌳 Trabalho Árvores-ED

**-> Foco Principal**: Comparação entre Árvores Binárias de Pesquisa(ABP), Árvores AVL(AVL) e Árvores Splay(Splay) no Armazenamento e Consulta de Dados.

## 💡 Introdução

O objetivo deste trabalho é implementar um código que utilize três formas diferentes de árvore binária, sendo ABP, AVL e Splay, e comparar o desempenho das três em armazenamento e em consulta de informações de jogos da Steam. O programa lê dois arquivos: um contendo uma lista de jogos e seus tempos médios de jogatina(.csv), e outro contendo a lista de jogos de um usuário(.txt). Com isso, ele cria um arquivo de saída(.txt) com o tempo total dos jogos que o usuário escolheu junto com informações sobre as árvores utilizadas para fazer essa busca.

-------------------------------------

## 💻 Implementação  

- `arvores.c` - arquivo que contém o código de implementação dos 3 tipos de árvores.
- `arvores.h` - arquivo que contém o protótipos das funções presentes em arvores.c, assim como estruturas utilizadas para facilitar a compreensão do código.
- `main.c` - arquivo principal, responsável por chamar todas as funções utilizadas no código.

-------------------------------------

## 🧠 Complexidades

**-> ABP**:  
- Inserção: a função insere vai para esquerda ou direita de acordo com o valor da chave. No entanto, para casos de inserção ordenada a ABP tende a criar uma lista. Deste modo uma única inserção será O(n), pois será necessário percorrer toda a lista. Contudo, serão inseridos n nodos, portanto, a complexidade final da inserção será O(n²).

- Busca: mesma lógica da inserção. Deste modo, o pior caso forma uma lista; consequentemente, a busca tende a ter que percorrer os n elementos da lista. Logo a busca em uma ABP terá a complexidade O(n).

 **-> AVL**:  
 - Inserção: de maneira semelhante à função de inserção em ABP, percorre a árvore à esquerda ou à direita. Contudo, na inserção são feitas rotações que possuem complexidade constante (O(1)), que fazem um balanceamento da árvore, impedindo que se formem listas. Desta forma, a inserção de uma única chave terá o custo O(log n), pois a árvore estará sempre balanceada e as rotações não interferem na complexidade por terem custo constante. Portanto, o custo de inserção total de n nodos será O(nlog n).

 - Busca: como a AVL é uma árvore balanceada, a cada chave que percorremos, cortamos as opções pela metade, deste modo, a complexidade de uma busca na AVL será O(log n).

**-> Splay**:  
  - Inserção: utilizamos a mesma função de inserção em uma ABP, porém realizando a função Splay com o nodo inserido. Assim como a ABP, se inserirmos chaves cada vez maior ou cada vez menor que a anterior a àrvore tomará um formato de lista, ou seja, a inserção de um único nodo terá o custo O(n). Portanto, para realizar a inserção dos n nodos teremos a complexidade total O(n²) no pior dos casos.  

- Busca: como no pior dos casos teremos uma lista, o custo de uma busca em uma SPLAY será O(n). No entanto, vale a pena ressaltar que a busca em uma Splay realiza a função Splay no nodo buscado, trazendo-o para a raíz da árvore. Assim caso sejam procuradas várias chaves com valores similares teremos um número menor de comparações; nesse sentido, esta complexidade não reflete o custo real de uma Splay aplicada no contexto correto.

-------------------------------------

## 📉 Resultados

  No contexto desse nosso programa, a AVL apresentou o melhor desempenho global por causa das buscas rápidas e consistentes ao longo da execução. A Splay não é vantajosa, porque o usuário só vai consultar uma vez, ou seja, a frequência não faz parte do problema.
  Enquanto que a ABP é a mais suscetível a quedas de performance quando a entrada não é suficientemente aleatória e acaba virando uma lista. Logo, é possível afirmar que a importância do balanceamento e da adaptação estrutural das árvores é essencial para assegurar boa 
  performance em aplicações reais, especialmente em sistemas que precisam lidar com grandes listas de dados e múltiplas consultas.

-------------------------------------

## 🐧🐧 Como chamar no Ubuntu(Linux) 🐧🐧

  1. Local dos arquivos:
    cd /mnt/c/Users/LocalDosArquivos

  2. Criar o executavel:
    gcc -o main main.c arvores.c arvores.h

  3. Executar o programa e suas entradas:
    ./main dataset.csv lista_jogador1.txt saida1.txt
