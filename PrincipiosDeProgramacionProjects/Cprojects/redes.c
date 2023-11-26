#include <stdio.h>
#include <stdlib.h>

#define MAX_NODOS 100

// Estructura para representar la red no dirigida
struct RedNoDirigida {
    int matriz[MAX_NODOS][MAX_NODOS];
    int numNodos;
};

// Prototipos de funciones
void inicializarRed(struct RedNoDirigida *red);
void agregarConexion(struct RedNoDirigida *red, int nodo1, int nodo2);
void calcularYMostrarResultados(struct RedNoDirigida *red);
float calcularCoeficienteClustering(struct RedNoDirigida *red, int nodo);

int main() {
    struct RedNoDirigida red;
    inicializarRed(&red);

    printf("Ingrese las conexiones (ingrese -1 para finalizar):\n");

    while (1) {
        int nodo1, nodo2;
        printf("Conexión (nodo1 nodo2): ");
        scanf("%d", &nodo1);

        if (nodo1 == -1) {
            break;
        }

        scanf("%d", &nodo2);
        agregarConexion(&red, nodo1, nodo2);
    }

    calcularYMostrarResultados(&red);

    return 0;
}

// Inicializa la matriz de adyacencia de la red
void inicializarRed(struct RedNoDirigida *red) {
    red->numNodos = 0;

    for (int i = 0; i < MAX_NODOS; i++) {
        for (int j = 0; j < MAX_NODOS; j++) {
            red->matriz[i][j] = 0;
        }
    }
}

// Agrega una conexión entre nodos a la matriz de adyacencia
void agregarConexion(struct RedNoDirigida *red, int nodo1, int nodo2) {
    red->matriz[nodo1][nodo2] = 1;
    red->matriz[nodo2][nodo1] = 1;

    // Actualiza el número total de nodos si es necesario
    red->numNodos = (nodo1 > red->numNodos) ? nodo1 : red->numNodos;
    red->numNodos = (nodo2 > red->numNodos) ? nodo2 : red->numNodos;
}

// Calcula e imprime el grado y el coeficiente de clustering para cada nodo
void calcularYMostrarResultados(struct RedNoDirigida *red) {
    for (int nodo = 1; nodo <= red->numNodos; nodo++) {
        int grado = 0;

        for (int i = 1; i <= red->numNodos; i++) {
            grado += red->matriz[nodo][i];
        }

        float coeficiente = calcularCoeficienteClustering(red, nodo);

        printf("Nodo: %d, Grado: %d, Coeficiente de Clustering: %.2f\n", nodo, grado, coeficiente);
    }
}

// Calcula el coeficiente de clustering para un nodo específico
float calcularCoeficienteClustering(struct RedNoDirigida *red, int nodo) {
    int numVecinos = 0;
    int numConexiones = 0;

    for (int i = 1; i <= red->numNodos; i++) {
        if (red->matriz[nodo][i]) {
            numVecinos++;

            for (int j = i + 1; j <= red->numNodos; j++) {
                if (red->matriz[i][j] && red->matriz[nodo][j]) {
                    numConexiones++;
                }
            }
        }
    }

    float grado = numVecinos;
    return (grado > 1) ? (2.0 * numConexiones) / (grado * (grado - 1)) : 0.0;
}
