#include <stdio.h>
#include <stdlib.h>
#include "fogeFoge.h"
#include "mapa.c"

//definição de variáveis globais
TMapa m;
TPosicao heroi;

int main(void) {

  leMapa(&m);
  encontraMapa(&m, &heroi, HEROI);  //encontra a posição do herói

  do {

    imprimeMapa(&m);

    char comando;
    scanf(" %c", &comando);
    
    move(comando);
    fantasmas();

  } while(!acabou());

  liberaMapa(&m);
}

//*************** FUNÇÕES ***************
int validarDirecao(char direcao) {

  return (direcao==ESQUERDA || direcao==CIMA || direcao==BAIXO || direcao==DIREITA); 
}

void move(char direcao) {

  int proximoX = heroi.x;
  int proximoY = heroi.y;

  //começando a validar a entrada do usuário
  if(!validarDirecao(direcao)) 
    return;

  switch (direcao) {

    case ESQUERDA:
      proximoY--;
      break;
    case CIMA:
      proximoX--;
      break;
    case BAIXO:
      proximoX++;
      break;
    case DIREITA:
      proximoY++;
      break;
  }

  if(!validaMapa(&m, proximoX, proximoY))
    return;

  if(!validaPosicao(&m, proximoX, proximoY))
    return;
  
  andaNoMapa(&m, heroi.x, heroi.y, proximoX, proximoY);
  heroi.x = proximoX;
  heroi.y = proximoY;
}

void fantasmas() {

  TMapa copia;
  copiaMapa(&m, &copia);

  for(int i=0; i<m.linhas; i++) {
    for(int j=0; j<m.colunas; j++) {

      if(copia.matriz[i][j] == FANTASMA) {
      
        if(validaMapa(&m, i, j+1) && validaPosicao(&m, i, j+1))
          andaNoMapa(&m, i, j, i, j+1);
      }
    }
  }

  liberaMapa(&copia);
}

int acabou() {
  return 0;
}