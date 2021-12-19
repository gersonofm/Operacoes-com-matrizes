// Autores: Daniel Caetano de Souza Ferreira
//          Gerson Otávio Fernandes Moreira
//
//          Goiania, 01 de dezembro de 2021
//          Vetor e Matriz Aleatória

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void gera_numero_aleatorio(float *numeroAleatorio) {
  *numeroAleatorio = rand() % 11;
  *numeroAleatorio = *numeroAleatorio / 10.0;
}
void imprimir_matriz(float matriz[2][2]) {

  for (int i = 0; i < 2; i++) {
    printf("** ");
    for (int j = 0; j < 2; j++) {
      printf("|%.2f|", matriz[i][j]);
    }
    printf("                  **\n");
  }
}
void calcula_matriz_A_B(float matriz[2][2], float matrizA[2][2],
                        float matrizB[2][2], float vetor[2]) {

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrizA[i][j] = vetor[0] * matriz[i][j];
      matrizB[i][j] = vetor[1] * matriz[i][j];
    }
  }
}
void gera_matriz_aleatoria(float matriz[2][2]) {
  float numeroAleatorio;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      gera_numero_aleatorio(&numeroAleatorio);
      matriz[i][j] = numeroAleatorio;
    }
  }
}
void gera_vetor_aleatorio(float vetor[2]) {
  float numeroAleatorio;
  gera_numero_aleatorio(&numeroAleatorio);
  vetor[0] = numeroAleatorio;
  gera_numero_aleatorio(&numeroAleatorio);
  vetor[1] = numeroAleatorio;
}
int main() {

  srand(time(0));

  float numeroAleatorio;
  float vetor[2];
  float matriz[2][2];
  float matrizA[2][2];
  float matrizB[2][2];

  printf("\n***********************************\n");
  printf("**    Operacoes com Matrizes     **");
  printf("\n**                               **");
  printf("\n***********************************\n");
  printf("**                               **");
  printf("\n**  Vetor Aleatorio              **\n");
  printf("** ---------------               **");
  gera_vetor_aleatorio(vetor);
  printf("\n** |Vetor[1]|%.2f|               **\n** |Vetor[2]|%.2f|            "
         "   **\n",
         vetor[0], vetor[1]);
  printf("** ---------------               **\n");
  gera_matriz_aleatoria(matriz);
  printf("**                               **");
  printf("\n**  Matriz Aleatoria             **\n");
  printf("** ------------                  **\n");
  imprimir_matriz(matriz);
  printf("** ------------                  **\n");

  calcula_matriz_A_B(matriz, matrizA, matrizB, vetor);
  printf("**                               **");
  printf("\n**  Matriz A (Matriz * vetor[1]) **\n");
  printf("** ------------                  **\n");
  imprimir_matriz(matrizA);
  printf("** ------------                  **\n");
  printf("**                               **");
  printf("\n**  Matriz B (Matriz * vetor[2]) **\n");
  printf("** ------------                  **\n");
  imprimir_matriz(matrizB);
  printf("** ------------                  **\n");
  printf("**                               **");
  printf("\n***********************************\n");
}