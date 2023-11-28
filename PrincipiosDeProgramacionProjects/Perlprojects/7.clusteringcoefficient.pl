#clustering_coefficient.c
#27 de noviembre de 2023

#Este programa lee una red por teclado, hace su matriz de adyacencia y calcula el clustering coefficient 
#paulinapglz.99@gmail.com

use strict;
use warnings;

# primero me gustaria obtener el numero de nodos y conexiones

print "Ingrese el número de nodos: ";
my $num_nodos = <STDIN>;
chomp $num_nodos;

print "Ingrese el número de conexiones: ";
my $num_conexiones = <STDIN>;
chomp $num_conexiones;

# Inicializar la matriz de adyacencia

my @matriz_adyacencia;                         #declaro un array que es la matriz de ady
for (my $i = 0; $i < $num_nodos; $i++) {         #la construyo con un for en i
    for (my $j = 0; $j < $num_nodos; $j++) {     #y en j
        $matriz_adyacencia[$i][$j] = 0;          #la lleno de 0's
    }
}

# Leer las conexiones
for (my $k = 0; $k < $num_conexiones; $k++) {                         
    print "Ingrese la conexión $k (en el formato 'nodo1 nodo2'): ";
    my $conexion = <STDIN>;
    chomp $conexion;
    my ($nodo1, $nodo2) = split(' ', $conexion);     #la magia esta en split, que corta la cadena segun un espacio

    # Actualizar la matriz de adyacencia
    $matriz_adyacencia[$nodo1][$nodo2] = 1;  #inicializamos en 1 pero en el for se va actualizando para tener la matriz 
    $matriz_adyacencia[$nodo2][$nodo1] = 1;
}

# Calcular los grados de los nodos y los coeficientes de agrupamiento
my @grados;
my @coeficientes;


#3 for anidados para leer los nodos e i
#for para leer los nodos en m 
for (my $m = 0; $m < $num_nodos; $m++) {
    my $grado = 0;
    my $coeficiente = 0;
#y en n
    for (my $n = 0; $n < $num_nodos; $n++) {
        if ($matriz_adyacencia[$m][$n] == 1) {
            $grado++;
        }
#leemos los vecinos que tiene
        my $vecinos = 0;
        for (my $p = 0; $p < $num_nodos; $p++) {
            if ($matriz_adyacencia[$n][$p] == 1 && $matriz_adyacencia[$m][$p] == 1) {  #aqui usamos la funcion para hacer la matriz 
                $vecinos++;
            }
        }

        if ($grado > 1) {
            $coeficiente += ($vecinos / ($grado * ($grado - 1))); #en esta parte se calcula el clustering coefficient 
        }
    }

    push @grados, $grado;
    push @coeficientes, $coeficiente;
}

# Imprimir los resultados
print "Nodo\tGrado\tCoeficiente\n";
for (my $q = 0; $q < $num_nodos; $q++) {
    print "$q\t$grados[$q]\t$coeficientes[$q]\n";
}

#fin?