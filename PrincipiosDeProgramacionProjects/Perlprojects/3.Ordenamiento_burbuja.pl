#
#21 de noviembre de 2023
#
#Este programa hace el ordenamiento burbuja de un arreglo de caracteres, es decir, ordena numeros de mayor a menor
# El método de ordenamiento burbuja funciona iterando sobre el arreglo dos veces, comparando cada par de números adyacentes.
# Si el primer número es menor que el segundo número, los números se intercambian.
#paulinapglz.99@gmail.com


# Declaramos las variables
my @array = ();  # Arreglo que almacenara los numeros leidos del teclado
my $n; #Numero de elementos del arreglo.

# Leemos el nmero de numeros a ingresar
print "Ingrese el número de elementos: ";
chomp($n = <STDIN>);

# Leemos los elementos del arreglo

for (my $i = 0; $i < $n; $i++) {        #desde indice 0 a menor q n, uno en uno
    print "Ingrese el elemento $i: ";   
    chomp($array[$i] = <STDIN>);        #leyending
}

# Ordenamos el arreglo con metodo bubble (como la chica superpoderosa)

for (my $i = 0; $i < $n - 1; $i++) {            #dos for anidados, uno para que lea los numeros 
    for (my $j = 0; $j < $n - $i - 1; $j++) {   #y otro para que los compare 
        if ($array[$j] > $array[$j + 1]) {      #checamos condicion
            # Intercambiamos los elementos
            ($array[$j], $array[$j + 1]) = ($array[$j + 1], $array[$j]);    #y los ordena
        }
    }
}

# Imprimimos el arreglo ordenado

print "El arreglo ordenado es: ";
foreach my $item (@array) {
    print "$item ";
}
print "\n";

#listou