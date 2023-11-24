#!/usr/bin/perl

#este aun no esta listo

use strict;
use warnings;

no warnings 'void';  # Suprime advertencias sobre uso inútil de valores en contexto de tipo void

sub imprimir_numero {
    my $numero = shift;

    my $centecimas = int($numero / 100);
    my $decimas    = int(($numero - ($centecimas * 100)) / 10);
    my $unidades   = $numero - ($centecimas * 100) - ($decimas * 10);

    # Switch para centecimas
    if ($centecimas == 9) {
        print "Novecientos";
    } elsif ($centecimas == 8) {
        print "Ochocientos";
    } elsif ($centecimas == 7) {
        print "Setecientos";
    } elsif ($centecimas == 6) {
        print "Seiscientos";
    } elsif ($centecimas == 5) {
        print "Quinientos";
    } elsif ($centecimas == 4) {
        print "Cuatrocientos";
    } elsif ($centecimas == 3) {
        print "Trescientos";
    } elsif ($centecimas == 2) {
        print "Doscientos";
    } elsif ($centecimas == 1) {
        print "Cien";
    }

    # Imprimir espacio si hay más números aparte de las centecimas
    print " " if ($decimas && $centecimas > 0);

    # Switch para decimas
    if ($decimas == 9) {
        print "noventa";
    } elsif ($decimas == 8) {
        print "ochenta";
    } elsif ($decimas == 7) {
        print "setenta";
    } elsif ($decimas == 6) {
        print "sesenta";
    } elsif ($decimas == 5) {
        print "cincuenta";
    } elsif ($decimas == 4) {
        print "cuarenta";
    } elsif ($decimas == 3) {
        print "treinta";
    } elsif ($decimas == 2) {
        print($unidades != 0) ? "veinti" : "veinte";
    } elsif ($decimas == 1) {
        print($unidades == 0) ? "diez" : "dieci";
    }

    # Switch para unidades
    if ($unidades == 9) {
        print "nueve";
    } elsif ($unidades == 8) {
        print "ocho";
    } elsif ($unidades == 7) {
        print "siete";
    } elsif ($unidades == 6) {
        print "seis";
    } elsif ($unidades == 5) {
        print "cinco";
    } elsif ($unidades == 4) {
        print "cuatro";
    } elsif ($unidades == 3) {
        print "tres";
    } elsif ($unidades == 2) {
        print "dos";
    } elsif ($unidades == 1) {
        print "uno";
    }
}

# Programa principal
print "Este programa imprime en letra el numero que usted indique de maximo tres cifras\n";
print "Por favor, digite el numero a leer:";
my $numero = <STDIN>;
chomp($numero);

if ($numero >= 1000 || $numero <= 0) {
    print "Numero no valido, recuerde que el numero tiene que ser positivo y de maximo tres cifras\n";
} else {
    imprimir_numero($numero);
}
