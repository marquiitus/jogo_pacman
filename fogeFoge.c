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
  encontrarMapa(&m, &heroi, '@');  //encontra a posição do herói

  do {

    imprimeMapa(&m);

    char comando;
    scanf(" %c", &comando);
    
    move(comando);

  } while(!acabou());

  liberaMapa(&m);

  return 0;
}

//*************** FUNÇÕES ***************
void move(char direcao) {

  //começando a validar a entrada do usuário
  if(direcao!='a' && direcao!='w' &&
     direcao!='d' && direcao!='s')
     return; 

  int proximoX = heroi.x;
  int proximoY = heroi.y;

  switch (direcao) {

    case 'a':
      proximoY--;
      break;
    case 'w':
      proximoX--;
      break;
    case 's':
      proximoX++;
      break;
    case 'd':
      proximoY++;
      break;
  }

  if(proximoX>=m.linhas||  //se for além do número de linhas e colunas do programa
     proximoY>=m.colunas)
  return;

  if(m.matriz[proximoX][proximoY] != '.')
    return;
  
  m.matriz[proximoX][proximoY] = '@';
  m.matriz[heroi.x][heroi.y] = '.';
  heroi.x = proximoX;
  heroi.y = proximoY;
}

int acabou() {
  return 0;
}