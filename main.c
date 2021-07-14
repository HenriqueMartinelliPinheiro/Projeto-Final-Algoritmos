#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct{
  float posX;
  float posY;
  char dentro;
} Pontos;

//proto

int carregarTamanho();
int verificarDentro(Pontos**,int,int);
int carregarRaio();
void erros(int);
float calcularPI(int,int);
Pontos * carregarPontos(int);
Pontos **alocaVetorPontos(int);
Pontos *alocaPonto();

void verificarErros(Pontos**);
void imprimirPontos(Pontos*,int);
void desalocarMemoria(Pontos**,int);
void imprimirVetorPontos(Pontos**,int);
void carregarVetorPontos(Pontos**,float,int);
void imprimirPI(float);

int main(void){
  int r;
  int tam;
  float pi;
  Pontos **pontos;
  int contDentro;

  tam = carregarTamanho();
  r = carregarRaio();
  pontos = alocaVetorPontos(tam);
  verificarErros(pontos);
  carregarVetorPontos(pontos,r,tam);
  contDentro = verificarDentro(pontos, r,tam);
  pi = calcularPI(contDentro,tam);
  imprimirVetorPontos(pontos,tam);
  imprimirPI(pi);
  desalocarMemoria(pontos,tam);

  return 0;
}

//alocar e desalocar memória

Pontos *alocaPonto(){
  return (Pontos*) malloc(sizeof(Pontos));
}

Pontos **alocaVetorPontos(int tam){
  Pontos **pontos;
  pontos = (Pontos**) malloc(sizeof(Pontos*)*tam);

  return pontos;
}

void desalocarMemoria(Pontos** pontos,int tam){
  int i;
  for(i=0;i<tam;i++){
    free(pontos[i]);
  }
  free(pontos);
}

//entrada de Dados
void carregarVetorPontos(Pontos **pontos,float r,int tam){
  int i;
  for(i=0;i<tam;i++){
    pontos[i] = carregarPontos(r);
  }
}

Pontos* carregarPontos(int r){
  Pontos* p;
  int rr = 2*r;
  p = alocaPonto();

  if(p!=NULL){
    p->posX = (rand() % rr)-r;
    p->posY = (rand() % rr)-r;
  }
  return p;
}

int carregarRaio(){
  int raio;
  printf("Digite o raio do círculo: \n");
  scanf("%i",&raio);
  return raio;
}

int carregarTamanho(){
  int tam;
  printf("Digite a quantidade de pontos que deseja ter: \n");
  scanf("%i",&tam);
  return tam;
}

//processamento

int verificarDentro(Pontos** pontos,int r,int tam){
  int i;
  int contDentro=0;
  float x = 0;
  float y = 0;
  for(i=0;i<tam;i++){
    if(sqrt(pow(pontos[i]->posX,2)  + pow(pontos[i]->posY,2)) <= r){
      contDentro++;
      pontos[i]->dentro = 's';
    }
    else{
      pontos[i]->dentro = 'n';
    }
  }
  return contDentro;
}

float calcularPI(int contDentro,int tam){
  float pi=0;
  float dentro;
  dentro = contDentro;
  pi = 4 * dentro/tam;
  return pi;
}

//saída de Dados
void imprimirPontos(Pontos *pontos,int i){

    printf("\n\nA posicao X do ponto %i é %f\n",i+1,pontos->posX);
    printf("A posicao Y do ponto %i é %f\n",i+1,pontos->posY);
    printf("O ponto %i está dentro(s-sim,n-nao): %c\n",i+1,pontos->dentro);
}

void imprimirVetorPontos(Pontos** pontos,int tam){
  int i;
  for(i=0;i<tam; i++){
    imprimirPontos(pontos[i],i);
  }
}

void imprimirPI(float pi){
  printf("O valor de PI é %f \n",pi);
}

//tratamento de Erros

void erros(int erro){
  printf("Sistema retornou com o erro %i!\n", erro);
}

void verificarErros(Pontos** pontos){
  if(pontos == NULL){
    erros(-1);
  }
}

