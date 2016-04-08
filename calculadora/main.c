#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "miLibreria.h"
/**
 * TP laboratorio 1- programacion 1
 * calculadora: recibe dos operadores y calcula las diferentes operaciones( suma, resta, multiplicacion, division y factorial)
 * alumna: Macarena Campos division 1 E
 *
 *
 */


int main()
{

    int opcion=0;
    int op1=0;
    int op2=0;
    int resultado;
    int flag1=0;
    int flag2=0;




  do
    {
        system("cls");
        printf("\n");
        printf("................................................................................ \n");
        if (flag1)
        {
        printf("1- Ingresar 1er operando (A=%d)\n",op1);
        }
        else
        {
        printf("1- Ingresar 1er operando (A=no ingresado)\n");
        }
       if (flag2)
       {
           printf("2- Ingresar 2do operando (B=%d)\n",op2);
       }
       else
       {
           printf("2- Ingresar 2do operando (B=no ingresado)\n");
       }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la multiplicacion (A*B)\n");
        printf("6- Calcular la division (A/B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("................................................................................\n");

        printf("Ingrese numero entre 1 y 9 ");
        scanf("%d", &opcion);

        while (!(opcion>=1 && opcion<=9))
        {
            printf("Ingrese numero entre 1 y 9 ");
            scanf("%d", &opcion);

        }



        switch(opcion)
        {
        case 1:

            system("cls");
            printf("Ingrese primer operando: \n");
            scanf("%d", &op1);
            flag1=1;
            system("cls");

                break;
            case 2:

                system("cls");
                printf("Ingrese segundo operando: \n");
                scanf("%d", &op2);
                flag2=1;
                system("cls");
               break;
            case 3:

                system("cls");
                if (validaFlag(flag1,flag2))
                {
                resultado= sumar1(op1, op2);
                printf("El resultado de la suma es: %d \n", resultado);
                }
                else
                {
                    printf("faltan cargar operadores");

                }


                break;
            case 4:

                system("cls");
                if (validaFlag(flag1,flag2))
                {
                resultado=restar(op1,op2);
                printf("El resultado de la resta es: %d \n", resultado);

                }
                else{}

                break;
            case 5:

                system("cls");
                   if (validaFlag(flag1,flag2))
                {
                resultado=multiplicar(op1,op2);
                printf("El resultado de la multiplicacion es de: %d \n", resultado);
                }
                else
                {
                    printf("faltan cargar operadores");

                }


                break;
            case 6:

                system("cls");
                 if (validaFlag(flag1,flag2))
                 {
                while (op2==0)
                {
                    printf("Error! El denominador debe ser distinto de 0 para la division \n ingrese un numero correcto ");

                    scanf("%d", &op2);

                }
                printf("El resultado de la division es de: %.2f \n", dividir(op1,op2));

                 }
                 else
                 {
                     printf("faltan cargar operadores");
                 }



                break;
            case 7:

                system("cls");
                 if (validaFlag(flag1,flag1))
                 {
                 while (!(op1>=1))
                {
                 printf("el factorial debe ser mayor o igual a 1 \n, ingrese un numero correcto");
                 scanf("%d", &op1);
                }
                 resultado=factorial(op1);
                 printf("El resultado del factorial es de: %d \n", resultado);
                 }
                 else
                 {
                 printf("Faltan cargar operandos");
                 }

                break;
            case 8:
                system("cls");
                if (validaFlag(flag1,flag2))
                {
                while (op2==0)
                {
                    printf("error! El denominador debe ser distinto de 0 para la division \n ingrese un numero correcto \n");
                    scanf("%d", &op2);
                }
                while (!(op1>=1))
                {
                    printf("el factorial debe ser mayor o igual a 1 \n, ingrese un numero correcto \n");
                    scanf("%d", &op1);
                }
                resultado= sumar1(op1, op2);
                printf("El resultado de la suma es: %d \n", resultado);
                resultado=restar(op1,op2);
                printf("El resultado de la resta es: %d \n", resultado);
                resultado=multiplicar(op1,op2);
                printf("El resultado de la multiplicacion: %d \n", resultado);
                resultado=dividir(op1,op2);
                printf("El resultado de la division es de: %.2f \n",dividir(op1,op2) );
                resultado=factorial(op1);
                printf("El resultado del factorial es de: %d \n", resultado);
                resultado=factorial(op2);
                printf("El resultado del factorial es de: %d \n", resultado);
                }
                else
                {
                    printf("Falta cargar operadores");
                }

                break;
            case 9:
                break;
        }

    }while((ValidarSiNo()));
return 0;
}
