#define ESQUERDA 'a'
#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'

void move(char direcao);
int acabou();
int validarDirecao(char direcao);
void fantasmas();
int praOndeFantasmaVai(int xOrigem, int yOrigem, int *xDestino, int *yDestino);