//
//20 de noviembre de 2023
//
//Este programa hace el ordenamiento burbuja de un arreglo de caracteres, es decir, ordena numeros de mayor a menor
// El método de ordenamiento burbuja funciona iterando sobre el arreglo dos veces, comparando cada par de números adyacentes.
// Si el primer número es menor que el segundo número, los números se intercambian.
//paulinapglz.99@gmail.com


#define TAMANIO 10000 //constante simbolica en diezmil
#include<stdio.h>
void ordenamiento_burbuja(int numero[], int control);  //numero[] es un arreglo 

//Declaro la funcion primero

void ordenamiento_burbuja(int numero[],int control){ 
    int auxiliar;                           // La variable auxiliar se utiliza para almacenar el valor del número que se va a intercambiar.
    for (int l=0;l<control;l++){
        for (int k=0;k<control-1; k++){     //el control-1 es para evitar que tome los valores 0 que estan fuera de la cadena
            if (numero[k]<numero[k+1]){			
               auxiliar=numero[k+1];        //auxiliar es la variable que nos va a ayudar a organizar nuestro arreglo, guardando la posicion siguiente    
               numero[k+1]=numero[k];       //como el valor siguiente es mayor, este a tomar la posición del anterior
                numero[k]=auxiliar;         //el valor en la posicion k, toma la posicion siguiente  
        }
            }
    }
    for (int i = 0; i < control; i++)       //imprime los valores ya acomodados
         printf("%d\n", numero[i]);  
}

//Funcion principal

int main (void)
{
    //Declarar variables
    int numero[TAMANIO]={0};  //inicializamos la variable
    int control;              //el control es el num contra el que se va a comparar
    //Mensaje de inicio
    printf("Este programa ordena de mayor a menor los numeros (rango de -20,000 a 20,000) que usted ingrese. \n");
    //Pedir datos
    printf("Cuantos numeros deseas ordenar? (no mayor a 10,000):");
    scanf("%d", &control);

    if (control>TAMANIO||control<2)
    {
        printf("El limite de numeros que puede ingresar es de 2 a %d, por favor vuelva a intentar", TAMANIO); //definimos tamanio como 10000
        return 0;       
    }
    
//Finalmente el bloque de impresion

    for (int i = 0; i < control; i++) //El bucle for se ejecuta "control" veces, una vez por cada número del arreglo.
    {
        printf("Por favor, digame el numero %d:", i+1); //va aumentando el numero que va pidiento
        scanf("%d", &numero[i]);  //leer un arreglo
        if(numero[i]>20000||numero[i]<-20000){  // para tener el rando deseado
            printf("Numero fuera del rango, por favor vuelva a intentar");
            return 0;
        }
    }
    ordenamiento_burbuja(numero,control);  //echamos a andar la funcion 
    return 0;
}
