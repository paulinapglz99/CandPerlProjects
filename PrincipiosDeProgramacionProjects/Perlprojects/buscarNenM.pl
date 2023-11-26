#!/usr/bin/perl

use strict;
use warnings;

my $N;
my $M;
my @A;

# Leer N
print "Ingrese un número N: ";
chomp($N = <STDIN>);

# Leer M
print "Ingrese la cantidad de números M: ";
chomp($M = <STDIN>);

# Leer A
for (my $i = 0; $i < $M; $i++) {
  print "Ingrese el número A[$i]: ";
  chomp($A[$i] = <STDIN>);
}

# Buscar N en A
my $i = 0;
while ($i < $M && $A[$i] < $N) {
  $i++;
}

# Si N se encontró en A
if ($i < $M && $A[$i] == $N) {
  print "N se encuentra en la posición $i de A.\n";
} else {
  print "N no se encuentra en A.\n";
}
