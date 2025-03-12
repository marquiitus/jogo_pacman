typedef struct Mapa {
  char **matriz;  //'ponteiro para ponteiro'
  int linhas;
  int colunas;
} TMapa;  //'Tipo Mapa'

void lerMapa(TMapa *m);
void imprimeMapa(TMapa *m);
void liberaMapa(TMapa *m);
void alocaMapa(TMapa *m);

typedef struct Posicao {
  int x;
  int y;
} TPosicao;

void encontrarMapa(TMapa *m, TPosicao *p, char c);