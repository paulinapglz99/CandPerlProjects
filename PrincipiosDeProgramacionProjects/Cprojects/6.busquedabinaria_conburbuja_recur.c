//busqueda_binaria.c
//24 de noviembre de 2023
//
//Este programa realiza la busqueda binaria de un conjunto de numeros
//paulinapglz.99@gmail.com

#include <stdio.h>
#define TAMANIO 10000   //Definimos el tamanio de nuestro array en 10,000
#define RANGO 20000     //Nuestro rango hasta 2000

// Declarando funciones

void ordenamiento_burbuja(int numero[], int control);  //para que lo ordene solito
int buscar(int elementos[], int buscado, int ini, int fin);  

int main(void) {
    //Declarar variables
    int elementos[TAMANIO] = {0};  //incializo la var
    int fin;
    int num_elementos, encontrar;

    //Mensaje de inicio
    printf("Este programa localiza la posicion un numero en un conjunto de maximo %d elementos.\n", TAMANIO);

    //Pedir datos
    printf("Por favor, ingrese el numero de elementos del conjunto de numeros donde se buscara:");
    scanf("%d", &num_elementos);
    fin=num_elementos;   //indicar cuando termina

//Este if se usa si el usuario intenta ingresar mas elementos de los que tiene el arreglo

    if (num_elementos>TAMANIO||num_elementos<=0){   
                printf("Numero de elementos no valido, deben ser numeros positivos y no mayor a %d", TAMANIO);
        return 0;
    }

    for (int i =0;i<num_elementos;i++){
        printf("Por favor, ingrese el numero %d del conjunto:", i+1);
        scanf("%d", &elementos[i]);   
        if (elementos[i]>RANGO||elementos[i]<-RANGO)    //Este if es por si el usuario intenta ingresar elementos fuera del rango establecido
        {
            printf("El rango para el numero a buscar es desde -%d hasta %d, por favor intente de nuevo", RANGO, RANGO);
            return 0;
        }     
    }
    printf("Por favor, ingrese el elemento a buscar:");
    scanf("%d", &encontrar);
    if (encontrar>RANGO||encontrar<-RANGO)    //Este if es por si el usuario intenta ingresar elementos fuera del rango establecido
        {
            printf("El rango para el elemento a buscar es desde -%d hasta %d, por favor intente de nuevo", RANGO, RANGO);
            return 0;
        }    

    ordenamiento_burbuja(elementos,num_elementos);    //Llamamos a la funcion para acomodar los elementos del arreglo

    printf("El conjunto ordenado es:\n");
    for (int i=0; i<fin;i++)
    {
        printf("%d\n",elementos[i]);
    }

    if (buscar(elementos,encontrar,0,fin-1)!=-1)
        printf("El numero que usted busca esta en la posicion %d del conjunto ordenado", buscar(elementos,encontrar,0,fin-1)+1);//Se agrega el +1 recordando que la posicion inicial del arreglo es 0
    else 
        printf("El elemento que usted busca no esta en el conjunto");

    return 0;
}

//Funcion para el ordenamiento, burbuja

void ordenamiento_burbuja(int numero[],int control){
    int auxiliar;
    for (int l=0;l<control;l++){
        for (int k=0;k<control-1; k++){     //el control-1 es para evitar que tome los valores 0 que estan fuera de la cadena
            if (numero[k]>numero[k+1]){			
               auxiliar=numero[k+1];        //auxiliar es la variable que nos va a ayudar a organizar nuestro arreglo, guardando la posicion siguiente    
               numero[k+1]=numero[k];       //como el valor siguiente es mayor, este a tomar la posición del anterior
                numero[k]=auxiliar;         //el valor en la posicion k, toma la posicion siguiente  
        }
            }
    }
}

//Finalmente, funcion de busqueda binaria
// Se repite este proceso de manera recursiva hasta encontrar el elemento o determinar que no está en el arreglo.

int buscar(int elementos[], int buscado, int ini, int fin){
    int posicion=-1; //Declaramos a pos en -1 que sirve de centinela por si no se encuentra el elemento
    int mitad;
    if (ini<=fin) { 
        mitad=(ini+fin)/2;//Partimos el arreglo a la mitad y a partir de ahi empezamos a buscar
        if (buscado==elementos[mitad]) //Si el elemento de encuentra en el punto de la division, regresemos esa posicion
            posicion=mitad;

        else if (buscado<elementos[mitad]) //Si el elemento buscado es menor que la mitad de donde partimos, aplicamos la recursividad a esa parte menor
            posicion=buscar(elementos, buscado, ini, mitad - 1);
    
        else 
            posicion=buscar(elementos, buscado, mitad + 1, fin);//Si el elemento buscado es mayor que la mitad de donde partimos, aplicamos la recursividad a esa parte mayor
    }

    return posicion;
}