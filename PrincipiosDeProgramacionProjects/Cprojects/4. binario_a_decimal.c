//binario_a_decimal.c
//19 de noviembre de 2023
//
//Este programa lee un numero binario posicion a posicion (ceros y unos)  
// e imprime su numero decimal 
//paulinapglz.99@gmail.com

#include <stdio.h>

int main() {
  // Declarar variables
  int arreglo[16];   //para que sea un byte 
  int i, j, suma;

  //Dar las instrucciones al usuario

  printf("Este programa convierte un numero binario de 16bits en decimal \n");
  printf("Solo deberas insertar 0 y 1 \n");

  // Leer el arreglo ingresado
  for (i = 0; i < 16; i++) {                           //El usuario debe agregar el numero de 1 en 1 
    printf("Ingrese el elemento %d del byte: ", i);
    scanf("%d", &arreglo[i]);                          //Lee uno a uno y los ingresa en el arreglo
  }

//Aqui esta la magia

  // Convertir el arreglo a decimal
  suma = 0;                          //inicializamos la variable, almacenara el resultado de la conversion
  for (i = 0; i < 16; i++) {         // iniciamos de 0 a 16
    suma += arreglo[i] << (15 - i);  //Corazon de la logica, usamos un corrimiento a la izquierda
    //En cada iteración del bucle, se calcula la potencia de 2 correspondiente al índice del elemento del arreglo
    //Haciendo el corrimiento iterativo de 1 en 1 bit :) 
    }

  // Imprimir el número decimal
  printf("El número binario es %d en decimal.\n", suma);

  return 0;
}
