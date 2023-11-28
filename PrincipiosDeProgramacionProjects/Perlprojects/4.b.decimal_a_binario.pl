#4.b.decimal_a_binario.pl
#
#Este programa lee un numero decimal y lo vuelve un numero binario
#paulinapglz.99@gmail.com

# Declaramos las variables
my $n;
my $i;
my @array = ();

# Leemos el número decimal
print "Ingrese el número decimal: \n";
chomp($n = <STDIN>);                   #el input

# Convertimos el decimal a binario

for (my $i = 0; $n > 0; $i++) {
    $array[$i] = $n % 2;        #asigna el modulo 2 al elemento actual del arreglo, lo que ira construyendo el numero binario
    $n = $n / 2;                #Esta linea de codigo divide el numero decimal por 2, y vuelve a entrar al for
}

# Imprimimos el número binario
print "El número binario es: ";
for (my $i = $i - 1; $i >= 0; $i--) {   #itera sobre el arreglo, empezando por el ultimo elemento, ya que las divisiones dejan el numero al reves
    print "$array[$i] ";
}
print "\n";

#listo