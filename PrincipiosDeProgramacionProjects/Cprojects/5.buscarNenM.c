//5.buscarNenM.c
//23 de noviembre de 2023
//
//Este programa lee un numero N de un conjunto de M numeros enteros (M <= 10,000 en el rango de -20,000 hasta 20,000)
//

#include <stdio.h>

int main() {
  int N, M;  //numeros enteros N y M
  int A[10000];  //un array A donde puedo almacenar hasta 10,000 numeros

  //Dar las instrucciones al usuario

  printf("Este programa te indica en que posicion esta el numero (N) en una serie de numeros que dara el usuario")
  printf("NOTA: El usuario debera ingresar los numeros de la lista donde se buscara manera ordenada y ascendente")

  // Leer N
  printf("Ingrese un número a buscar (N): ");
  scanf("%d", &N);

  // Leer M
  printf("Ingrese la cantidad de números que tendra la lista en la que buscaremos el numero N: ");
  scanf("%d", &M);

  // Leer A
  printf("Escriba uno a uno y de manera ordenada los "%d" numeros de la lista", &M)
  for (int i = 0; i < M; i++) {              //Un for para ir solicitando los numeros de la lista a buscar
    printf("Ingrese el número [%d]: ", i);
    scanf("%d", &A[i]);                      // Leer iterativamente 
  }

  // Buscar N en el array A

  int i = 0;                    //Inicializo mi variable
  while (i < M && A[i] < N) {   //mientras i sea menor a M y el valor iesimo de A sea menor a N sigue buscando
    i++;
  }

  // Si N se encontró en A
  if (i < M && A[i] == N) {      //Si el indice es menor al numero de numeros y el valor del iesimo numero de A es igual a N
    printf("N se encuentra en la posición %d de A.\n", i); //Imprimimos donde lo entontro
  } else {
    printf("N no se encuentra en A.\n");
  }

  return 0;
}