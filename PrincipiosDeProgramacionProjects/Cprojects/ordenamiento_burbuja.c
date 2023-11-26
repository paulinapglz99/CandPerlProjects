//
//20 de noviembre de 2023
//
//Este programa hace el ordenamiento burbuja de un arreglo de caracteres
#define TAMANIO 10000
#include<stdio.h>
void ordenamiento_burbuja(int numero[], int control);
int main (void)
{
    //Declarar variables
    int numero[TAMANIO]={0};
    int control;
    //Mensaje de inicio
    printf("Este programa ordena los numeros que usted ingrese de mayor a menor en un rango de -20,000 a 20,000\n");
    //Pedir datos
    printf("Por favor, digame cuantos numeros desea ingresar(no mayor a 10,000):");
    scanf("%d", &control);

    if (control>TAMANIO||control<2)
    {
        printf("El limite de numeros que puede ingresar es de 2 a %d, por favor vuelva a intentar", TAMANIO);
        return 0;       
    }
    

    for (int i = 0; i < control; i++)
    {
        printf("Por favor, digame el numero %d:", i+1);
        scanf("%d", &numero[i]);
        if(numero[i]>20000||numero[i]<-20000){
            printf("Numero fuera del rango, por favor vuelva a intentar");
            return 0;
        }
    }
    ordenamiento_burbuja(numero,control);
    return 0;
}

void ordenamiento_burbuja(int numero[],int control){
    int auxiliar;
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
