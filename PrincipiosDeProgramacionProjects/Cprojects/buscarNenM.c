#include <stdio.h>

int main() {
  int N, M;
  int A[10000];

  // Leer N
  printf("Ingrese un número N: ");
  scanf("%d", &N);

  // Leer M
  printf("Ingrese la cantidad de números M: ");
  scanf("%d", &M);

  // Leer A
  for (int i = 0; i < M; i++) {
    printf("Ingrese el número A[%d]: ", i);
    scanf("%d", &A[i]);
  }

  // Buscar N en A
  int i = 0;
  while (i < M && A[i] < N) {
    i++;
  }

  // Si N se encontró en A
  if (i < M && A[i] == N) {
    printf("N se encuentra en la posición %d de A.\n", i);
  } else {
    printf("N no se encuentra en A.\n");
  }

  return 0;
}
