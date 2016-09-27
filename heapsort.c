#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
#define SIZEOFVETOR 10000000
#define PERCENTAGEM 0
#define ISPRINT 0

void imprime_vetor(int *A) {
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


void insere_valor(int *A) {
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



int LEFT(int i) {
 //printf("\n\n[INFO] INICIO DO MÉTODO LEFT");
  return i*2;
}

int RIGHT(int i) {
  //printf("\n\n[INFO] INICIO DO MÉTODO RIGHT");
  return (i*2) + 1;
}

void TROCAR(int i, int m, int *A) {
  //printf("\n\n[INFO] INICIO DO MÉTODO TROCAR");
  int aux;
  aux=A[i];
  A[i] = A[m];
  A[m] = aux;
}


void  HEAPFY(int *A, int i, int tam_heap) {
  //printf("\n\n[INFO] INICIO DO MÉTODO HEAPFY");
  int l, r, m;
  l = LEFT(i); //  2i       ==8
  r = RIGHT(i); // 2i + 1   ==9
  m = i;
  if((l <= tam_heap) && (A[l] > A[i])) {
  	m = l;
  }
  if((r <= tam_heap) && (A[r] > A[m])) {
	m = r;
  }
  if(m != i) {
  	TROCAR(i, m, A);
  	HEAPFY(A, m, tam_heap);
  }
}

void BUILD_HEAP(int *A) {
  //printf("\n\n[INFO] INICIO DO MÉTODO BUILD_HEAP");
  for(int i = (SIZEOFVETOR/2); i >= 1; i--) {
	 HEAPFY(A, i, SIZEOFVETOR);
  }	
}

void HEAPSORT(int *A) {
  //printf("\n\n[INFO] INICIO DO MÉTODO HEAPSORT\n\n");
  int TAM_HEAP = SIZEOFVETOR;
  BUILD_HEAP(A);
 for(int i = SIZEOFVETOR; i >= 2; i--) {
    TROCAR(1, i, A);
    TAM_HEAP = (TAM_HEAP - 1);
    HEAPFY(A, 1, TAM_HEAP);
  }
  //printf("\n\n[INFO] ************************FIM DO MÉTODO HEAPSORT");
}

int main() {
  int *A;
  time_t inicio, fim;
  
  inicio = time(NULL);
  A = (int*)calloc(SIZEOFVETOR, sizeof(int));
  insere_valor(A);
  if(ISPRINT == 1) {	
    printf("\nVETOR ORIGINAL:  ");
    imprime_vetor(A);
  }

  HEAPSORT(A);
  if(ISPRINT == 1) {	
    printf("\nVETOR PROCESSADO:  ");
    imprime_vetor(A);
  }
  fim = time(NULL);
  printf("\n\n %f \n\n ", difftime(fim, inicio) );	
  return 1;	
}
