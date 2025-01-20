# Projeto Unidade 3 - Introdução às Técnicas de Programação
## Desenvolvedores
1. Francisco Paiva da Silva Neto
2. Gabriel Souto Lozano Barbosa

## Conteúdo
#### Este repositório contém os códigos referentes ao projeto da terceira unidade com uma breve explicação do funcionamento dos algoritmos.

## Funcionamento dos códigos
### Jogo de Damas
#### O código foi compartimentado em funções para facilitar o desenvolvimento e execução do projeto, sendo elas:
1. posicaoSegura(): Verifica se a dama pode ser colocadada na posição especificada;
2. resolverNQueens(): Usa backtracking para resolver o problema proposto no desafio chamando a função 'posicaoSegura()' e verificando seu retorno;
3. definirNQueens(): Inicia e imprime o tabuleiro com a solução definida;
4. main(): Agrupa as funções criadas permitindo a execução e interação do usuário com o programa;

### Jogo da Velha
#### De mesmo modo, o jogo da velha também foi compartimentado em funções, sendo elas:
1. geraTabuleiro(): Exibe o estado atual do tabuleiro o imprimindo na tela;
2. jogadaJogador(): Registra a jogada feita pelo jogador da vez por meio de uma poisçao alfanumérica inserida no seu turno do jogo;
3. jogadaComputador(): Registra a jogada do computador, que nesse caso é feita de forma aleatória por um número sorteado dentro os campos possíveis de jogo;
4. verificaVencedor(): Responsável por determinar o vencedor da partida verificando as condições de vitória do jogo;
5. tabuleiroCompleto(): Verifica se o tabuleiro foi completamente preenchido, fazendo com que seja possível determinar se "deu velha";
6. main(): Agrupa as funções criadas permitindo a execução e interação do usuário com o programa;
