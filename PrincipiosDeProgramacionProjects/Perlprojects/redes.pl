#!/usr/bin/perl

use strict;
use warnings;

# Lee las conexiones desde la entrada estándar y crea la matriz de adyacencia
sub crear_matriz_adyacencia {
    my %matriz;

    while (1) {
        print "Ingrese la conexión (o presione Enter para terminar): ";
        my $linea = <STDIN>;
        chomp $linea;

        last if $linea eq ''; # Termina la entrada al presionar Enter

        my ($nodo1, $nodo2) = split /\s+/, $linea;
        
        # Marca la conexión en ambas direcciones (la red es no dirigida)
        $matriz{$nodo1}{$nodo2} = 1;
        $matriz{$nodo2}{$nodo1} = 1;
    }

    return \%matriz;
}

# Calcula e imprime el grado y el coeficiente de clustering para cada nodo
sub calcular_y_mostrar_resultados {
    my ($matriz) = @_;

    for my $nodo (sort keys %$matriz) {
        my $grado = scalar keys %{ $matriz->{$nodo} };
        my $coeficiente = calcular_coeficiente_clustering($matriz, $nodo);

        printf "Nodo: %s, Grado: %d, Coeficiente de Clustering: %.2f\n", $nodo, $grado, $coeficiente;
    }
}

# Calcula el coeficiente de clustering para un nodo específico
sub calcular_coeficiente_clustering {
    my ($matriz, $nodo) = @_;

    my @vecinos = keys %{ $matriz->{$nodo} };
    my $num_conexiones = 0;
    
    for my $vecino1 (@vecinos) {
        for my $vecino2 (@vecinos) {
            next if $vecino1 eq $vecino2;

            # Incrementa el número de conexiones si hay una conexión entre los vecinos
            $num_conexiones++ if $matriz->{$vecino1}{$vecino2};
        }
    }

    my $grado = scalar @vecinos;
    return $grado > 1 ? 2 * $num_conexiones / ($grado * ($grado - 1)) : 0;
}

# Programa principal
sub main {
    my $matriz = crear_matriz_adyacencia();
    calcular_y_mostrar_resultados($matriz);
}

main(); # Llama al programa principal