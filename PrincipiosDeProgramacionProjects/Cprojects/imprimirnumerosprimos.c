//
//20 de noviembre de 2023
//
//Este programa identifica y calcula los numeros primos que hay entre 0 y el numero que el usuario indique
//paulinapglz.99@gmail.com

// Recordatorio de que podemos definir un numero primo como un 
           // Número entero que solamente es divisible por él mismo y por la unidad, then si 
           //Si el número dado es divisible por el número de control, entonces el número dado no es primo.
            //si numero%2 == 0 , if (1) entonces es divisible entre 2, y no es primo 
                               

#include<stdio.h>
void calcular_primos(int numero);

//Declaro la funcion que buscar numeros primos, usando un for



void calcular_primos(int numero){  
    for (;numero>0;numero--){       //Este for es el que va a ir imprimiendo los numeros primos que encuentre
     //Este for busca los numeros primos      
        for (int control=2;control!=numero;control++)  //Tomamos como control el 2, se incicializa ahi.
        {  
            if (numero%control==0){   // El modular de un número primo y 1 siempre será 1.
            numero--;   //va 1 por 1 hacia 0. Si se encuentra un divisor que no sea el mismo numero, se descarta ese numero como primo
            control=2;  //Se reestablece control para que vuelva a empezar en 2
            }
        }
        printf("%d\n", numero);     //Los numeros que se imprimen son los que unicamente fueron divisibles por si mismos y por lo tanto, primos
    }  
}

//La funcion principal

int main (void)
{
    //Declarar variables
    int numero;
    //Mensaje de inicio
    printf("Hellou, este programa calcula los numeros primos que hay en antes del numero que usted indique\n");
    //Pedir datos
    printf("Por favor, digite un numero entero positivo que no sea 1:");
    scanf("%d", &numero);

    if (numero<=1){     //Si el numero es menor o igual a 1, te dice que no. Este if verifica que el numero sea positivo.
        printf("Numero no valido, recuerde que el numero tiene que ser positivo y mayor a 1 para que haya primos\n");
        return 0;
    }
    else            //Si el numero si es mayor a 1, cumple con los parametros, e invoca a la funcion que encuentra los numeros primos
    calcular_primos(numero);
    return 0;
}