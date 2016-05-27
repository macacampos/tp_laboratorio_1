#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>
#include <string.h>
#include <conio.h>
#define TAM 4

/** \brief programa que genera un html con peliculas guardadas
 *
 * Macarena Campos 1e
 *
 */
int main()
{
    char seguir='s';
    int opcion=0;
    EMovie peliculas[TAM];
    int indice;

    iniciar(peliculas,TAM);
    LeerBinario(peliculas,TAM);
    precargada(peliculas);

    do
    {
        fflush(stdin);
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        opcion=getInt();
        if(opcion!=0)
        {
            switch(opcion)
            {
            case 1:
                if(lugarLibre (peliculas,TAM,&indice)==1)
                {
                    cargar(peliculas,indice);
                }
                else
                {
                    printf("NO HAY LUGAR LIBRE \n");
                    system("pause");
                }
                system("pause");
                break;
            case 2:
                if(peliculas[indice].estado==1)
                {
                    borrar(peliculas,TAM);
                    printf("pelicula borrada\n");
                    system("pause");
                }
                else
                {
                    printf("error, no hay peliculas cargadas\n");
                    system("pause");
                }
                break;
            case 3:
                if(peliculas[indice].estado==1)
                {
                    modificar (peliculas,TAM);
                }
                else
                {
                    printf("error, no hay peliculas cargadas\n");
                    system("pause");
                }

                break;
            case 4:
                generarPagina( peliculas,TAM);
                system("pause");
                break;
            case 5:
                GuardarBinario(peliculas, TAM);
                seguir = 'n';
                break;
            }
        }
    }
    while(seguir=='s');

    return 0;
}
