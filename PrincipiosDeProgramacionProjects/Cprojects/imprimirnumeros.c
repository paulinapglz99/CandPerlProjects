//
//20 de noviembre de 2023
//
//Este programa lee un numero (positivo, entero, máximo tres cifras)  
// y lo imprime en palabras. Intente documentarlo lo mas posible con fines didacticos y de mi yo futura.

//paulinapglz.99@gmail.com

#include<stdio.h> //cargar libreria base


void imprimir_numero(int numero);
int main (void)
{
    //Declarar variables, integers
    int numero;
    //Mensaje de inicio
    printf("Este programa imprime en letra el numero que usted indique. Debe ser positivo y maximo de tres cifras\n");
    //Pedir datos
    printf("Por favor, escribe el numero a leer:");
    scanf("%d", &numero); //decimal

    if (numero>=1000||numero<=0){//Con este if verificamos que el numero sea positivo y no mayor a tres cifras
        printf("Número no válido. El número debe ser positivo y de máximo tres cifras.\n");
        return 0;
    }
    else //Si el numero cumple con los parametros, invocamos la funcion que los imprime
      imprimir_numero(numero);
    return 0;
}

//Declaro una funcion que divide el número en sus tres componentes: centenas, decenas y  unidades.

void imprimir_numero(int numero){  
   //Declarar variables
   int centecimas,decimas,unidades;
   centecimas=numero/100; //Asi sabemos las centenas que tiene nuestro numero, como es int solo sacara el numero
   decimas=(numero-(centecimas*100))/10; //Multiplicamos las centecimas por 100 y se le resta al numero, luego se divide por 10 para asi saber las unidades
   unidades=(numero-((centecimas*100)+(decimas*10)));//Aqui restamos las centecimas y las decimas para saber las unidades

    switch (centecimas){//Con un switch vamos imprimiendo segun las centecimas que tengamos
    case 9:  //si mis centecimas son igual a 9,
       printf("Novecientos"); //entonces imprime Novecientos
        break; //y terminamos
     case 8:
        printf("Ochocientos");
        break;
     case 7:
        printf("Setecientos");
        break;
    case 6:
        printf("Seiscientos");
        break;
     case 5:
        printf("Quinientos");
        break;
     case 4:
        printf("Cuatrocientos");
        break;
        case 3:
       printf("Trescientos");
        break;
     case 2:
        printf("Doscientos");
        break;
        case 1:
  if (unidades == 0)
    printf("cien");
  else 
  {
    printf("Ciento");
  }
  break;
    default:
        break;
    }  


//Para algunos numeros necesitamos espacio

    if (decimas&&centecimas>0) //Si decimas o centecimas es true, es decir...
         printf(" "); //Si hay mas numeros aparte de las centecimas, se imprime un espacio para que no se sobrepongan los numeros

   switch (decimas)
    {
    case 9:
       printf("noventa");
        break;
     case 8:
        printf("ochenta");
        break;
     case 7:
        printf("setenta");
        break;
    case 6:
        printf("sesenta");
        break;
     case 5:
        printf("cincuenta");
        break;
     case 4:
        printf("cuarenta");
        break;
      case 3:
       printf("treinta");
        break;
     case 2:
        if (unidades!=0) //Si unidades es diferente a 0
         printf("veinti");  //Puedes imprimir veinti
        else
            printf("veinte");  //Si son iguales a 0, nomas escribe 20
        break;
     case 1:
        if (unidades&&centecimas==0) //Si unidades y centecimas es igual a 0, imprime el diez
        printf("diez");  
        else if (unidades>5)
        {
        printf("dieci");     //Si las unidades que hay son mayores a 5, se pone el subfijo dieci      
        }

        //esta parte fue la que me costo mas

        else{ 
            switch(unidades)  //si las unidades son menores o iguales a 5, se imprimen individualmente y a unidades se le asigna el valor 0 para que no entre en el siguiente switch
             {
            case 5:
                printf("quince");
               break;
            case 4:
               printf("catorce");
               break;
            case 3:
               printf("trece");
               break;
            case 2:
            printf("doce");
            break;
            case 1:
            printf("once");         
    } 

    unidades=0;   //Esto se hace para evitar que la variable unidades entre en el siguiente switch, que se usa para imprimir las decenas.
        }

    default:
        break;
    }  //aqui termina el switch de decenas  


//en el caso de los 20's y 10's

    if (unidades>0&&decimas>2)   //si unidades es mayor a 0 t decimas es mayor a 2, imprime el "y" de los 20's (por el dieci y el veinti)
        printf(" y ");
    switch (unidades)
    {
    case 9:
       printf("nueve");
        break;
     case 8:
        printf("ocho");
        break;
     case 7:
        printf("siete");
        break;
    case 6:
        printf("seis");
        break;
     case 5:
        printf("cinco");
        break;
     case 4:
        printf("cuatro");
        break;
        case 3:
       printf("tres");
        break;
     case 2:
        printf("dos");
        break;
     case 1:
        printf("uno");         
    default:
        break;
    }  

}

//FIN
