//
//20 de noviembre de 2023
//
//Este programa imprime en letra los numeros que el usuario le indique

#include<stdio.h>
void imprimir_numero(int numero);
int main (void)
{
    //Declarar variables
    int numero;
    //Mensaje de inicio
    printf("Este programa imprime en letra el numero que usted indique de maximo tre cifras\n");
    //Pedir datos
    printf("Por favor, digite el numero a leer:");
    scanf("%d", &numero);

    if (numero>=1000||numero<=0){//Con este if verificamos que el numero sea positivo y no mayor a tres cifras
        printf("Numero no valido, recuerde que el numero tiene que ser positivo y de maximo tres cifras\n");
        return 0;
    }
    else //Si el numero cumple con los parametros, invocamos la funcion que los imprime
      imprimir_numero(numero);
    return 0;
}
void imprimir_numero(int numero){  
   //Declarar variables
   int centecimas,decimas,unidades;
   centecimas=numero/100; //Con esta operación sabemos las centecmas que tiene nuestro numero
   decimas=(numero-(centecimas*100))/10; //Multiplicamos las centecimas por 100 y se le resta al numero, luego se divide por 10 para asi saber las unidades
   unidades=numero-((centecimas*100)+(decimas*10));//Aqui restamos las centecimas y las decimas para saber las unidades

    switch (centecimas){//Con un switch vamos imrpimiendo segun las centecimas que tengamos
    case 9:
       printf("Novecientos");
        break;
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
        printf("Cien");         
    default:
        break;
    }  

    if (decimas&&centecimas>0)
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
        if (unidades!=0)
         printf("veinti");  //En el caso de las unidades de 20, como no se pueden escribir vete y uno se cambia el sunfijo veinte por veinti
        else
            printf("veinte");  
        break;
     case 1:
        if (unidades==0) //Si no hay unidades, imprime el diez
        printf("diez");  
        else if (unidades>5)
        {
        printf("dieci");     //Si las unidades que hay son mayores a 5, se pone el subfijo dieci      
        }
         
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
    unidades=0;   
        }      
    default:
        break;
    }  

    if (unidades>0&&decimas>2)   //imprime el y solo si existen unidades y si las decimas son mayores a dos (por el dieci y el veinti)
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
