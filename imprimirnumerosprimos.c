//
//20 de noviembre de 2023
//
//Este programa calcula los numeros primos que hay entre 0 y el numero que el usuario indique

#include<stdio.h>
void calcular_primos(int numero);
int main (void)
{
    //Declarar variables
    int numero;
    //Mensaje de inicio
    printf("Este programa calcula los numeros positivos que hay en antes del numero que usted indique\n");
    //Pedir datos
    printf("Por favor, digite un numero entero positivo:");
    scanf("%d", &numero);

    if (numero<=1){     //Este if verifica que el numero sea positivo y mayor a 1
        printf("Numero no valido, recuerde que el numero tiene que ser positivo y mayor a 1 para que haya primos\n");
        return 0;
    }
    else            //Si el numero cumple con los parametros, invoca a la funcion que encuentra los numeros primos
    calcular_primos(numero);
    return 0;
}
void calcular_primos(int numero){  
    for (;numero>0;numero--){       //Este for es el que va a ir imprimiendo los numeros primos que encuentre
        for (int control=2;control!=numero;control++)//este for va ir buscando los numeros primos
        {//Se inicializa en dos porque sabemos que el modular de un cualquier numero y 1 va a dar 0
            if (numero%control==0){ 
            numero--;   //Si se encuentra un divisor que no sea el mismo numero, se descarta ese numero como primo
            control=2;  //Se reestablece control para que vuelva a empezar en 2
            }
        }
        printf("%d\n", numero);     //Los numeros que se imprimen son los que unicamente fueron divisibles por si mismos y por lo tanto, primos
    }  
}