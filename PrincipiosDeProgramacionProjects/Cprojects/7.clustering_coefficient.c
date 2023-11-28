//clustering_coefficient.c
//27 de noviembre de 2023
//
//Este programa realiza la busqueda binaria de un conjunto de numeros
//paulinapglz.99@gmail.com


#include <stdio.h>

#define MAX_NODOS 100  //desde ahora puedo decir que mi maximo de nodos sea 100

int main() {
    int matrix[MAX_NODOS][MAX_NODOS] = {0}; // Inicializar matriz de adyacencia con ceros
    int degrees[MAX_NODOS] = {0}; // Inicializar arreglo de grados de nodos con ceros, esto para contar el degree de cada nodo
    float clustering_coefficient[MAX_NODOS] = {0}; // Inicializar arreglo de coeficientes de agrupamiento con ceros, float pa tener decimales
    
    int num_nodos, num_edges;

//Dar instrucciones al usuarie
        printf("Hola, este es un programa al que le puedes indicar el numero de nodos y conexiones que tiene tu red, \n");
        printf("Posteriormente generara una matriz de adyaciencia y calculara el coeficiente de clustering para cada nodo \n");
        printf("Te recomiendo que sea una red sencilla y que la dibujes para tener claro el numero de conexiones que tiene \n \n \n");

//Pedir el numero de nodos

    printf("Ingrese el número de nodos que tiene la red: ");
    scanf("%d", &num_nodos);

//Pedir el edgelist
    
    printf("Ingrese el número de conexiones que tiene la red (edges): \n");
    scanf("%d", &num_edges);
    
    printf("Ingrese las conexiones en el formato \"nodo1 nodo2\":\n");

    //

    int nodo1, nodo2;
    for (int i = 0; i < num_edges; i++) {   //iteramos en cada conexión en la red (de 0 a num_edges veces)
        scanf("%d %d", &nodo1, &nodo2);    
        matrix[nodo1][nodo2] = 1;           //incializamos la matriz en 1, esto 
        matrix[nodo2][nodo1] = 1;           //incializamos la matriz en 1
        degrees[nodo1]++;                   //esto es para ir identificando con cuantos nodos se pega el nodo 1
        degrees[nodo2]++;                  //y calcular su degree
    
    //Finalmente imprimimos el resultado
        //aqui esta la magia negra

    printf("Nodo\tGrado\tCoeficiente de agrupamiento\n");  

    //la logica esta en este bloque de codigo

    for (int i = 0; i < num_nodos; i++) {                             //de 1 a numero de nodos uno en uno
        float num_edges_posibles = (degrees[i] * (degrees[i] - 1)) / 2.0;   //calcular el numero de edges posibles y dividirlo entre 2 pq es no dirigida
        int num_edges_actual = 0;                                           //inicializamos la variable en 0
        
        for (int j = 0; j < num_nodos; j++) {                                        //recorre la matriz en j
            for (int k = j + 1; k < num_nodos; k++) {                                 //recorre la matriz en k
                if (matrix[i][j] == 1 && matrix[i][k] == 1 && matrix[j][k] == 1) {    //si todos son 1, si hace la suma, si no nel
                    num_edges_actual++;
                }
            }
        }
        
        clustering_coefficient[i] = (num_edges_actual / num_edges_posibles);   //usa la funcion para iterar sobre los indices i y calcular el clustering coeff pa todos los nodos
        printf("%d\t%d\t%f\n", i, degrees[i], clustering_coefficient[i]);  //lo imprimimos
    }
    
    return 0;
}
}

//the fin