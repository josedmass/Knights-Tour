# Passeio-do-Cavalo
Este é um projeto desenvolvido como trabalho prático da disciplina de Matemática Discreta da UFMG, realizado em 2022/02

## Autor
- José Eduardo Duarte Massucato

## Descrição
O Passeio do Cavalo é um problema clássico de matemática e ciência da computação, no qual o objetivo é mover um cavalo em um tabuleiro de xadrez de dimensões específicas, visitando cada casa uma única vez. Este projeto implementa uma solução para o Passeio do Cavalo, a partir de uma posição específica do tabuleiro, utilizando a linguagem C.

## Funcionalidades
- Geração de um possível Passeio do Cavalo em um arquivo de saída.
- Apresentação de quantos movimentos de ida e quantos movimentos de volta (backtracking) o algoritmo precisou realizar para resolver o problema.

OBS: Os detalhes da implementação, bem como as estruturas de dados utilizadas e o paradigma abordado, encontram-se em "Documentacao.pdf"

## Como usar
1. Compile o código-fonte utilizando um compilador C compatível.
2. Execute o programa gerado, seguindo as instruções de entrada e saída.
3. Digite as posições de linha e coluna, respectivamente, que o cavalo deve começar seu passeio.
4. Um arquivo chamado saida.txt será gerado com a solução do algoritmo.

OBS: as linhas e colunas que o usuário digita __devem__ variar de 1 a 8.

## Exemplo de uso
1. Gerando o executável pela linha de comando do terminal Ubuntu: 
```bash
gcc ./src/main.c -o meu_programa
```
2. Executando o programa:
```bash
./meu_programa
```