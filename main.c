#include <stdio.h>
#include <stdlib.h>



int main(){
  int linhaA, colunaA, linhaB, colunaB;
  while(1){
    printf("Digite as dimensões da primera matriz: ");
    scanf("%d %d", &linhaA, &colunaA);
    printf("Digite as dimensões da segunda matriz: ");
    scanf("%d %d", &linhaB, &colunaB);
    if(colunaB == linhaA)
      break;
    else{
      printf("Dimensoes invalidas, digite novamente!\n");
    }
  }

  float **A = (float**) malloc(linhaA*sizeof(float*));
  for(int i = 0; i < linhaA; i++){
    A[i] = (float*) malloc(colunaA*sizeof(float));
    for(int j = 0; j < colunaA; j++){
      printf("Digite o valor da posicao A[%d][%d]: ", i+1, j+1);
      scanf("%f", &A[i][j]);
    }
  }

  float **B = (float**) malloc(linhaB*sizeof(float*));
  for(int i = 0; i < linhaB; i++){
    B[i] = (float*) malloc(colunaB*sizeof(float));
    for(int j = 0; j < colunaB; j++){
      printf("Digite o valor da posicao B[%d][%d]: ", i+1, j+1);
      scanf("%f", &B[i][j]);
    }
  }

  float **C = (float**) malloc(linhaA*sizeof(float*));
  for(int i = 0; i < linhaA; i++){
    C[i] = (float*) malloc(colunaB*sizeof(float));
    for(int j = 0; j < colunaB; j++){
      int soma = 0;
      for(int k = 0; k < linhaB; k++){
        soma += A[i][k] + B[k][j];
      }
      C[i][j] = soma;
    }
  }

  printf("\nMatriz A:\n");
  for(int i = 0; i < linhaA; i++){
    for(int j = 0; j < colunaA; j++){
      printf("%f ", A[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz B:\n");
  for(int i = 0; i < linhaB; i++){
    for(int j = 0; j < colunaB; j++){
      printf("%f ", B[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz C:\n");
  for(int i = 0; i < linhaA; i++){
    for(int j = 0; j < colunaB; j++){
      printf("%f ", C[i][j]);
    }
    printf("\n");
  }

  for(int i =0; i < linhaA; i++)
    free(A[i]);
  free(A);
  for(int i =0; i < linhaB; i++)
    free(B[i]);
  free(B);
  for(int i =0; i < linhaA; i++)
    free(C[i]);
  free(C);

  return 0;
}
