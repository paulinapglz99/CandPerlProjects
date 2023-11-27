#imprimirprimos.pl
#
#Este programa identifica y calcula los numeros primos que hay entre 0 y el numero que el usuario indique
#paulinapglz.99@gmail.com

#!/usr/bin/perl

use strict;   
use warnings;

#primero declaro la funcion, la logica reside en 
       #for my $divisor (2..$i-1) {
          #  if ($i % $divisor == 0) {

sub calcular_primos {
    my ($numero) = @_;

    for my $i (1..$numero) {
        my $es_primo = 1;
        for my $divisor (2..$i-1) {
            if ($i % $divisor == 0) {
                $es_primo = 0;        
                last;
            }
        }
        if ($es_primo) {    #solo imprimirlo si es primo
            print "$i\n";
        }
    }
}

#Mensaje de inicio
print "Este programa calcula los numeros primos que hay en antes del numero se indique\n";
#Pedir datos

print "Por favor, digite un numero entero positivo:";
my $numero = <STDIN>;
chomp $numero;

if ($numero <= 1) {     
    #Este if verifica que el numero sea positivo y mayor a 1
    print "Numero no valido, recuerde que el numero tiene que ser positivo y mayor a 1 para que haya primos\n";
} else {            
    #Si el numero cumple con los parametros, invoca a la funcion que encuentra los numeros primos
    calcular_primos($numero);
}
