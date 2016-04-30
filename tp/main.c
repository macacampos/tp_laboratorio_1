#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define TAM 20
/** tp laboratorio 1- programacion 1.
 *Agenda que recibe diferentes datos: nombre, dni y edad, permitiendo borrar a una persona si es necesario mediante el dni. Muestra tambien los nombres ordenados alfabeticamente y un grafico que agrupa las edades por diferentes criterios.
 * alumna: Macarena Campos division 1 E
 *
 */

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona agenda[20];
    int indiceL;
    Iniciar(agenda, TAM);

    while(seguir=='s')
    {
        fflush(stdin);
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        opcion=getInt();
        if(opcion!=0)
        {

        switch(opcion)
        {
            case 1:
                if(lugarLibre(agenda, TAM, &indiceL)==1)
                {
                    cargarPersona (agenda,indiceL);
                }
                else
                {
                    printf("NO HAY LUGAR LIBRE \n");
                    system("pause");
                }
                system("pause");
                break;
            case 2:
                if (borrarPersona(agenda, TAM)!=1)
                {
                        printf("ERORR \n");
                }
                 break;
            case 3:
                if(ordenar (agenda,TAM))
                {
                    printf("Se ordeno todo bien \n");
                }
                break;
            case 4:
                system("cls");
                CalcularRango(agenda);
                break;
            case 5:
                break;
            default:
                break;
        }
        }
    system("pause");
    }
    return 0;

}
