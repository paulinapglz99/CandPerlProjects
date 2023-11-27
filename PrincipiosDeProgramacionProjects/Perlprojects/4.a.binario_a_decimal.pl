#binario_a_decimal.pl
#
#Este programa lee un numero binario posicion a posicion (ceros y unos)  
#e imprime su numero decimal 
#paulinapglz.99@gmail.com

# Declaramos las variables
my @array = ();
my $i;
my $sum = 0;

#Damos instrucciones al usuarie

print"Este programa lee un numero binario posicion a posicion (ceros y unos) e imprime su numero decimal \n";
print"Deberas ingresar unicamente 1 o 0 y luego dar enter \n";


# Leemos el arreglo binario

for (my $i = 0; $i < 16; $i++) {        #Para tener un arreglo de 16 bits
    print "Ingrese el elemento $i: ";   #y ps le pedimos numero a numero
    chomp($array[$i] = <STDIN>);        #el input
}

# Convertimos el binario a decimal
#esta es pa parte divertida

for (my $i = 15; $i >= 0; $i--) {    #vamos de atras para adelante en este caso, es mas conveniente para ir teniendo los bits mas significativos
    if ($array[$i] == 1) {           #easy, si i es igual a 1, le vas sumando dos
        $sum += 2 ** $i;
    }
}

# Imprimimos el número decimal
print "El número decimal es: $sum\n";  
