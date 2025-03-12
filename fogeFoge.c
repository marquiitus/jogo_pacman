//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "fogeFoge.h"
#include "mapa.c"

//definição de variáveis globais
TMapa m;
TPosicao heroi;

int main() {

  lerMapa(&m);
  encontrarMapa(&m, &heroi, '@');

  do {

    imprimeMapa(&m);

    char comando;
    scanf(" %c", &comando);  //não esquecer do espaço antes do %c
    
    move(comando);

  } while(!acabou());

  liberaMapa(&m);

  return 0;
}

//Funções
void move(char direcao) {

  m.matriz[heroi.x][heroi.y] = '.';

  switch (direcao) {  //dependendo da direção escolhida, o herói irá andar

    case 'a':
      m.matriz[heroi.x][heroi.y-1] = '@';
      heroi.y--;
      break;
    case 'w':
      m.matriz[heroi.x-1][heroi.y] = '@';
      heroi.x--;
      break;
    case 's':
      m.matriz[heroi.x+1][heroi.y] = '@';
      heroi.x++;
      break;
    case 'd':
      m.matriz[heroi.x][heroi.y+1] = '@';
      heroi.y++;
      break;
  }
}

int acabou() {
  
  return 0;
}