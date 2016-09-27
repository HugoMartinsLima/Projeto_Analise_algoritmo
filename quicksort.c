#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
#define SIZEOFVETOR 10000000
#define PERCENTAGEM 0
#define ISPRINT 0
void INSERIR_ELEMENTO(int *A) {
  int numero_randomico;
  srand(time(NULL));
  int repeticao = (SIZEOFVETOR*PERCENTAGEM);
  for(int i = 1; i <= SIZEOFVETOR; i++) {
    numero_randomico = (rand() % SIZEOFVETOR);
    if(i <= repeticao) {
        numero_randomico = 10;
    }
    A[i] = numero_randomico;
  }
}

void IMPRIMIR_VETOR(int *A) {
  printf("\n");
  printf("[");
  for(int i = 1; i <= SIZEOFVETOR; i++) {
    if (SIZEOFVETOR > i) {
      printf("%d, ", A[i]);
    }else if(SIZEOFVETOR == i) {
      printf("%d", A[i]);
    }  
  }
   printf("]");
   printf("\n");
}

void TROCAR(int i, int j, int *A) {
  int aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

int PARTITION(int *A, int p, int r) {
  int x, i;
  x = A[r];
  i = p-1;
  for(int j = p; j <= (r-1); j++) {
    if(A[j] <= x ) {
      i = i+1;
      TROCAR(i, j, A);  
    }
  }
  TROCAR((i+1), r, A);
  return i+1;
}

void QUICKSORT(int *A, int p, int r) {
  int q;
  if(p < r) {
    q = PARTITION(A, p, r);
    QUICKSORT(A, p, q-1);
    QUICKSORT(A, q+1, r);
  }
}

int main() {  
  int *A;
  time_t inicio, fim;
  inicio = time(NULL);
  A = (int*)calloc(SIZEOFVETOR, sizeof(int));
  INSERIR_ELEMENTO(A);
  if(ISPRINT ==1) {
    printf("\nVETOR ORIGINAL:");
    IMPRIMIR_VETOR(A);
  }
  QUICKSORT(A, 1, SIZEOFVETOR);
  if(ISPRINT == 1) {
    printf("\nVETOR PROCESSADO:");
    IMPRIMIR_VETOR(A);
  }
  fim = time(NULL);
  printf("\n\n %f \n\n ", difftime(fim, inicio) );
  return 1;
}
