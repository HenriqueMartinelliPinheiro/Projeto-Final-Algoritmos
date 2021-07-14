#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TAML 1000
typedef struct{
  float posX;
  float posY;
  char dentro;
} Pontos;

//proto
Pontos carregarPontos(int);
void carregarVetorPontos(Pontos[],float r);
int verificarDentro(Pontos[],int);
float calcularPI(int);
void imprimir(Pontos[],float);
int carregarRaio();

int main(void) {
  int r;
  float pi;
  Pontos pontos[TAML];
  int contDentro;

  r = carregarRaio();
  carregarVetorPontos(pontos,r);
  contDentro = verificarDentro(pontos,r);
  pi = calcularPI(contDentro);
  imprimir(pontos,pi);
  return 0;
}

Pontos carregarPontos(int r){
  Pontos p;
  int rr = 2*r;
  p.posX = (rand() % rr)-r;
  p.posY = (rand() % rr)-r;

  return p;
}

void carregarVetorPontos(Pontos pontos[],float r){
  int i;
  for(i=0;i<TAML;i++){
    pontos[i] = carregarPontos(r);
  }
}

int verificarDentro(Pontos pontos[],int r){
  int i;
  int contDentro=0;
  float x = 0;
  float y = 0;
  for(i=0;i<TAML;i++){
    if(sqrt(pow(pontos[i].posX,2)  + pow(pontos[i].posY,2)) <= r){
      contDentro++;
      pontos[i].dentro = 's';
    }
    else{
      pontos[i].dentro = 'n';
    }
  }
  return contDentro;
}

float calcularPI(int contDentro){
  float pi=0;
  float dentro;
  dentro = contDentro;
  pi = 4 * dentro/TAML;
  return pi;
}

void imprimir(Pontos pontos[],float pi){
int i;
  for(i=0;i<TAML; i++){
    printf("\n\nA posicao X do ponto %i é %f\n",i+1,pontos[i].posX);
    printf("A posicao Y do ponto %i é %f\n",i+1,pontos[i].posY);
    printf("O ponto %i está dentro(s-sim,n-nao): %c\n",i+1,pontos[i].dentro);
  }

  printf("\n\n\n\nO valor de PI é: %f",pi);
}

int carregarRaio(){
  int raio=0;
  printf("Digite o valor do raio: \n");
  scanf("%i",&raio);
  return raio;
}