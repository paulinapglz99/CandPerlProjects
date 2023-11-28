#imprimirnmumeros.pl
#
#Este programa identifica y calcula los numeros primos que hay entre 0 y el numero que el usuario indique
#paulinapglz.99@gmail.com
#este script me hizo sudar sangre :D

#!/usr/bin/perl

use strict;
use warnings;

#definimos variables de unidades 
my @unidades = ("cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve");
#variables de decenas (especiales)
my @decenas = ("diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve");
#variables de decenas (con terminacion 0)
my @decenas2 = ("", "", "veinti", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa");
#variables de centenas
my @centenas = ("", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos");

#declaramos una subrutina 

sub convertir_a_palabras {
    my $numero = shift;        #"shift" se utiliza para eliminar y devolver el primer elemento de una lista
    if ($numero < 10) {                   #para numeros que son del 0 al 9
        return $unidades[$numero];
    } elsif ($numero < 20) {              #para numeros mayores a 20
        return $decenas[$numero - 10];
    } elsif ($numero < 100) {             #para numeros mayores a 100 
        my $unidad = $numero % 10;        #la unidad debe de ser el numero modulo 10
        my $decena = int($numero / 10);   #la decena es el integer (sin decimal), solamente pq estamos escribiendo num del 0 al 999
        my $texto = $decenas2[$decena];   
        if ($unidad > 0) {           
            $texto .= " y $unidades[$unidad]";     #poner un y en medio
        }
        return $texto;
    } else {
        my $unidad = $numero % 10;
        my $decena = int(($numero % 100) / 10);
        my $centena = int($numero / 100);
        my $texto = $centenas[$centena];
        if ($decena == 1) {
            $texto .= " " . $decenas[$unidad];
        } else {
            $texto .= " " . $decenas2[$decena];
            if ($unidad > 0) {
                $texto .= " y $unidades[$unidad]";
            }
        }
        return $texto;
    }
}

#finalmente, le pedimos al usuario que agregue el numero

print "Este programa traduce un número en palabras \n ";

print "Ingrese un número: \n";
my $numero = <STDIN>; 
chomp $numero;

if ($numero >= 0 && $numero < 1000) {                       #verificamos que sea menor de 1000 
    my $palabras = convertir_a_palabras($numero);
    print "El número $numero en palabras es: $palabras\n";
} else {
    print "El número debe ser entre 0 y 999.\n";
}
