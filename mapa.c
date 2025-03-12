//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void encontrarMapa(TMapa *m, TPosicao *p, char c) {

  //acha a posição do foge foge (tem como melhorar isso?)
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

  free(m->matriz);  //liberando memória usando 'free'
}

void alocaMapa(TMapa *m) {

  m->matriz = malloc(sizeof(char*) * m->linhas);  //malloc: memory allocation

  for(int i=0; i < m->linhas; i++) {

    m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);  
  }
}

void lerMapa(TMapa *m) {

  FILE *f; //variável para manipular arquivos

  f = fopen("C:\\Users\\Tommy Marques\\Desktop\\Marcos\\alura\\C\\pacMan.c\\mapa.txt", "r");
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