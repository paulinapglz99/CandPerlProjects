#include <stdio.h>

int busqueda_binaria(int *A, int N, int inicio, int fin) {
  if (inicio > fin) {
    return -1;
  }

  int medio = (inicio + fin) / 2;

  if (A[medio] == N) {
    return medio;
  } else if (A[medio] < N) {
    return busqueda_binaria(A, N, medio + 1, fin);
  } else {
    return busqueda_binaria(A, N, inicio, medio - 1);
  }
}

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
  int posicion = busqueda_binaria(A, N, 0, M - 1);

  // Si N se encontró en A
  if (posicion != -1) {
    printf("N se encuentra en la posición %d de A.\n", posicion);
  } else {
    printf("N no se encuentra en A.\n");
  }

  return 0;
}