#5.buscarNenM.pl
#
#Este programa busca en que posicion se encuentra un numero N dentro de un arreglo de M numeros
#paulinapglz.99@gmail.com

#!/usr/bin/perl

use strict;
use warnings;

#Declaramos variables

my $N;    
my $M;
my @A;    #este es el arreglo donde se van a guardar los M numeros

# Leer N
print "Ingrese un numero N que el programa buscara en un conjunto de numeros: ";
chomp($N = <STDIN>);

# Leer M
print "Ingrese la cantidad de números (M) de la lista en la que vamos a buscar: ";
chomp($M = <STDIN>);

# Leer A

for (my $i = 0; $i < $M; $i++) {              #desde 0 hasta menor que el numero de numeros
  print "Ingrese el número A[$i]: ";          #ingresar uno a uno
  chomp($A[$i] = <STDIN>);                    #para el input
}

# Buscar N en A
my $i = 0;                                   #inicializo la variable para empezar a buscar
while ($i < $M && $A[$i] < $N) {             #mientras i sea menor que M y el iesimo numero sea menor a N
  $i++;                                      #sigue buscando
}

#mensaje de exito o fracaso :C (como yo haciendo el de redes)

if ($i < $M && $A[$i] == $N) {                           # Si N se encontró en A
  print "N se encuentra en la posición $i de A.\n";      #se imprime
} else {
  print "N no se encuentra en A.\n";                     #o
}


#done