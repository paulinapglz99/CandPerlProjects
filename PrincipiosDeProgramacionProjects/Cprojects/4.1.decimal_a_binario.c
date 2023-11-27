//binario_a_decimal.c
//17 de noviembre de 2023
//
//Este programa lee un numero binario posicion a posicion (ceros y unos)  
// e imprime su numero decimal 
//paulinapglz.99@gmail.com

//NOTA: Para convertir un número decimal a binario basta realizar divisiones sucesivas entre 2 y 
//escribir los residuos obtenidos en cada división en orden inverso al que han sido obtenidos.


#include <stdio.h>

//Primero defino la funcion

void decimalABinario(int num, int arreglo[]) {
    for (int i = 0; i < 16; ++i) {   //lo mismo que para el otro 
        arreglo[i] = num & 1;       //operación AND a nivel de bits entre el número num y el valor 1. Es 1 si el último bit de num es 1, y  0 si el último bit es 0.
        num = num >> 1;      //corrimiento a la derecha, equivalente a dividir num por 2. 
}
}


int main() {
    int decimal;
    int arreglo[16];

    printf("Este programa convierte un numero decimal a su correspondiente numero binario \n");
    printf("Ingresa un número decimal: \n");
    scanf("%d", &decimal);

    decimalABinario(decimal, arreglo);

    printf("El número binario equivalente es: \n");
    for (int i = 15; i >= 0; --i) {
        printf("%d", arreglo[i]);
    }

    return 0;
}
