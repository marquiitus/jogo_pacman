//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void encontrarMapa(TMapa *m, TPosicao *p, char c) {

  //sempre tenho que percorrer a matriz inteira pra encontrar o herói, como melhorar isso?
  for(int i=0; i < m->linhas; i++) {

    for(int j=0; j < m->colunas; j++) {

      if(m->matriz[i][j] == c) {  //guardando a posição do PacMan

        p->x = i;
        p->y = j;
        break;
      }
    }
  }
}

void liberaMapa(TMapa *m) {

  for(int i=0; i < m->linhas; i++) {

    free(m->matriz[i]);
  }

  free(m->matriz);
}

void alocaMapa(TMapa *m) {

  m->matriz = malloc(sizeof(char*) * m->linhas);  //malloc: memory allocation

  for(int i=0; i < m->linhas; i++) {

    m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);  // Aloca colunas (+1 para '\0')
  }
}

void lerMapa(TMapa *m) {

  FILE *f; //variável para manipular arquivos
  f = fopen("C:\\Users\\marco\\OneDrive\\Desktop\\Marcos\\alura\\C\\pacMan\\mapa.txt", "r");
  
  if(!f) {  //verifica se o arquivo foi aberto corretamente

    printf("\n\nErro na leitura do mapa");
    exit(1);
  }

  fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
  alocaMapa(m);

  for(int i=0; i < m->linhas; i++) {

    fscanf(f, "%s", m->matriz[i]);
  }

  fclose(f);
}

void imprimeMapa(TMapa *m) {
  
  for(int i=0; i < m->linhas; i++) {

    printf("%s\n", m->matriz[i]);
  }
}