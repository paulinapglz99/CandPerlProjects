#!/usr/bin/perl

use strict;
use warnings;

sub imprimir_numero {
    my $numero = shift;

    # Validar que el número esté en el rango adecuado
    if ($numero < 0 || $numero > 999) {
        print "Número no válido. Debe estar entre 0 y 999.\n";
        return;
    }

    # Switch para centenas
    if ($numero >= 100) {
        my $centenas = int($numero / 100);
        if ($centenas == 1) {
            print "Cien";
        } else {
            print convertir_unidades($centenas) . "cientos";
        }
        $numero %= 100;
        print " " if $numero > 0;
    }

    # Switch para decenas
    if ($numero >= 10 && $numero <= 99) {
        print convertir_decenas($numero);
        $numero %= 10;
        print " " if $numero > 0;
    }

    # Switch para unidades
    if ($numero > 0) {
        print convertir_unidades($numero);
    }

    print "\n";
}

sub convertir_decenas {
    my $numero = shift;

    if ($numero >= 90) {
        return "noventa";
    } elsif ($numero >= 80) {
        return "ochenta";
    } elsif ($numero >= 70) {
        return "setenta";
    } elsif ($numero >= 60) {
        return "sesenta";
    } elsif ($numero >= 50) {
        return "cincuenta";
    } elsif ($numero >= 40) {
        return "cuarenta";
    } elsif ($numero >= 30) {
        return "treinta";
    } elsif ($numero >= 20) {
        return "veinti" . convertir_unidades($numero % 10);
    } elsif ($numero == 10) {
        return "diez";
    } else {
        return convertir_unidades($numero);
    }
}

sub convertir_unidades {
    my $numero = shift;

    if ($numero == 9) {
        return "nueve";
    } elsif ($numero == 8) {
        return "ocho";
    } elsif ($numero == 7) {
        return "siete";
    } elsif ($numero == 6) {
        return "seis";
    } elsif ($numero == 5) {
        return "cinco";
    } elsif ($numero == 4) {
        return "cuatro";
    } elsif ($numero == 3) {
        return "tres";
    } elsif ($numero == 2) {
        return "dos";
    } elsif ($numero == 1) {
        return "uno";
    }
}

# Programa principal
print "Ingrese un número del 0 al 999: ";
my $numero = <STDIN>;
chomp($numero);

imprimir_numero($numero);
