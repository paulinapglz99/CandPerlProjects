# buscarNenM_recursivo.pl
#
#Este programa busca en que posicion se encuentra un numero N dentro de un arreglo de M numeros, con un enfoque recursivo
#paulinapglz.99@gmail.com

use strict;
use warnings;

# tenemos q asignar una funcion recursiva para realizar la busqueda binaria

sub buscar_binario {
    my ($N, $A, $inicio, $fin) = @_;   #nota para mi: @_ es una variable especial para desempaquetae las variables anteriores

    # Si el inicio es mayor que el final, significa que no se encontro el número
    return -1 if $inicio > $fin;

    my $medio = int(($inicio + $fin) / 2);  # calcula el indice medio entre dos valores, (el valor que esta entre los dos valores)

    #Asi, si el numero en la posición media es igual a N, se encontro el numero
    
    return $medio             #si la condicin despues del if es verdadera, la subrut para y te da el valor de $medio
     if $A->[$medio] == $N;   #verificando si el elemento en la posición indicada por $medio en el arreglo @A es igual al num que estamos buscando ($N)

    # Si el número en la posición media es menor que N, buscar en la mitad derecha
    if ($A->[$medio] < $N) {
        return buscar_binario($N, $A, $medio + 1, $fin);
    }
    # Si el número en la posición media es mayor que N, buscar en la mitad izquierda
    else {
        return buscar_binario($N, $A, $inicio, $medio - 1);
    }
}

# Declaramos variables para la funcion principal 

my $N;
my $M;
my @A;

# Leer N
print "Ingrese un numero (N) que el programa buscara en un conjunto de numeros: ";
chomp($N = <STDIN>);

# Leer M
print "Ingrese la cantidad de números (M) de la lista en la que vamos a buscar: ";
chomp($M = <STDIN>);

# Leer A
for (my $i = 0; $i < $M; $i++) {
    print "Ingrese el número A[$i]: ";
    chomp($A[$i] = <STDIN>);
}

# Llamar a la función de búsqueda binaria
my $posicion = buscar_binario($N, \@A, 0, $M - 1);  #pongo -1 se debe pq en Perl los indices comienzan en 0

# Mostrar el resultado
if ($posicion != -1) {
    print "N se encuentra en la posición $posicion de A.\n";
} else {
    print "N no se encuentra en A.\n";
}

#:(