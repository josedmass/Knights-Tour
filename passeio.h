#include <stdio.h>
#include <stdlib.h>

// Funções que realizam um dos 8 possíveis movimentos, e seus respectivos "inversos", do cavalo
void movimento (int n, int* l, int* c);
void antimovimento (int, int*, int*);

// Checa se um movimento é possível
int movimento_possivel(int, int, int tab[][8]);

// Função que retorna o movimento que levará o cavalo para uma posição onde ele terá poucos movimentos possíveis.
int MenorQuantidade (int l, int c, int tab[][8], int r[][8][8], int x, int y);

void passeio (int x, int y) {
    int l = x-1, c = y-1;
    int cont=1, tabuleiro[8][8] = {0}; 
    int salvamov[64]; 
    int contIdas = 0, contVoltas = 0;
    int restricao[8][8][8], p = 0;

    for(int i=0; i<64; i++) {
        salvamov[i] = 1;
    }
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++){
            for(int k=0; k<8; k++) {
                restricao[i][j][k] = 0;
            }
        }
    }

    for(cont = 1; cont<=64; cont++) {
        p=0;

        // Se o movimento é possível (salvamov[cont-1] > 0), ele o faz
        if(salvamov[cont-1] > 0) {
            tabuleiro[l][c] = cont;
            contIdas++;
        }
        
        // Backtracking
        else {
            // A restrição de movimento das casas posteriores devem ser zeradas, uma vez que elas mudarão.
            // A casa atual é então zerada e o cavalo volta.
            for(int i=0; i<8; i++) restricao[l][c][i] = 0;
            tabuleiro[l][c] = 0; 
            cont--;
            antimovimento(salvamov[cont-1], &l, &c); 
            contVoltas++;
            
            // Esse laço for é pro caso de já haver alguma restrição naquela casa
            for(int i=0; i<8; i++) {
                if(restricao[l][c][i] != 0) p++;
            }
            // Impõe a restrição de que o cavalo não deve fazer, a partir de uma posição, um movimento
            // que o levou a utilizar do backtracking.
            restricao[l][c][p] = salvamov[cont-1];
            cont--;
        }
        salvamov[cont] = MenorQuantidade(l, c, tabuleiro, restricao, l, c);
        movimento(salvamov[cont], &l, &c);
    }    
    
    // Imprimindo o tabuleiro resultante no arquivo
    FILE *f;
    f = fopen("saida.txt", "w");
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            fprintf(f, "%d\t", tabuleiro[i][j]);
        }
        fprintf(f, "\n");
    }
    fprintf(f, "Quantidade de idas: %d\nQuantidade de voltas (backtracking): %d\n", contIdas, contVoltas);
    fclose(f);
    f = NULL;
}

int movimento_possivel(int l, int c, int tab[][8]) {
    if(l>=0 && l<8 && c>=0 && c<8) {
        if(tab[l][c]==0) return 1;
    }
    return -1;
}

void movimento (int n, int* l, int* c) { 
    if(n == 1) {
        *l+=2;
        *c+=1;
    }
    if(n == 2) {
        *l+=1;
        *c+=2;
    }
    if(n == 3) {
        *l-=1;
        *c+=2;
    }
    if(n == 4) {
        *l-=2;
        *c+=1;
    }
    if(n == 5) {
        *l-=2;
        *c-=1;
    }
    if(n == 6) {
        *l-=1;
        *c-=2;
    }
    if(n == 7) {
        *l+=1;
        *c-=2;
    }
    if(n == 8) {
        *l+=2;
        *c-=1;
    }
}

void antimovimento (int n, int *l, int *c) {
    if(n == 1) {
        *l-=2;
        *c-=1;
    }
    if(n == 2) {
        *l-=1;
        *c-=2;
    }
    if(n == 3) {
        *l+=1;
        *c-=2;
    }
    if(n == 4) {
        *l+=2;
        *c-=1;
    }
    if(n == 5) {
        *l+=2;
        *c+=1;
    }
    if(n == 6) {
        *l+=1;
        *c+=2;
    }
    if(n == 7) {
        *l-=1;
        *c+=2;
    }
    if(n == 8) {
        *l-=2;
        *c+=1;
    }
}

int MenorQuantidade (int l, int c, int tab[][8], int r[][8][8], int x, int y) {
    int menor = 9;
    int cont = 0;
    int menormov = -1;
    
    for(int i=1; i<=8; i++) {
        cont = 0;
        movimento(i, &l, &c);
        if(movimento_possivel(l, c, tab) == 1) {
            if(r[x][y][0] != i && r[x][y][1] != i && r[x][y][2] != i && r[x][y][3] != i && r[x][y][4] != i && r[x][y][5] != i && r[x][y][6] != i && r[x][y][7] != i) {
                for(int j = 1; j <= 8; j++) {
                    movimento(j, &l, &c);
                    if(movimento_possivel(l, c, tab) == 1) cont++;
                    antimovimento(j, &l, &c);
                }
                if(cont < menor) {
                    menor = cont;
                    menormov = i;
            }
            }
        }
        antimovimento(i, &l, &c);
    }
    // O fato de a variável "menor" não ter sido alterada implica que não existem movimentos que simultaneamente
    // sejam possíveis e superem as restrições para aquela posição.
    if(menor == 9) return -1;

    // Retorna o movimento que leva o cavalo para um posição onde haja poucas possibilidades de movimento
    return menormov;
}