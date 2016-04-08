#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>





/** \brief suma de los dos operadores
 *
 * \param x recibe primer operador
 * \param y recibe segundo operador
 * \return suma de los dos operadores
 *
 */

int sumar1(int x,int y)

{
    int suma;
    suma=x+y;


    return suma;

}
/** \brief resta los dos operadores
 *
 * \param recibe primer operador
 * \param recibe segundo operador
 * \return resta de los dos operadores
 *
 */

int restar (int x, int y)
{
    int resta;
    resta=x-y;

    return resta;
}
/** \brief multiplicacion de los dos operadores
 *
 * \param recibe primero operando
 * \param recibe segundo operando
 * \return multiplicacion de los dos operadores
 *
 */

int multiplicar (int x, int y)
{
    int multiplicacion;
    multiplicacion=x*y;

    return multiplicacion;
}
/** \brief division de los operandos
 *
 * \param recibe primer operador
 * \param recibe segundo operador
 * \return la division de los dos operadores
 *
 */

float dividir (float x, float y)
{
    float division;
    division=x/y;


    return division;
}
/** \brief valida si se ingresa s o n
 *
 * \return retorna la respuesta correcta para seguir
 *
 */


int ValidarSiNo (void)
{
 char rta;
 printf(" s: para seguir / n: para salir \n");
 rta=tolower(getche());
 while (!((rta=='s')||(rta=='n')))
 {
     printf("error! ingrese una respuesta correcta");
     rta=tolower(getche());

 }
 return (rta=='s');
}
/** \brief calcula el factorial
 *
 * \param recibe el primer operando
 * \param
 * \return el resultado del factorial
 *
 */

int factorial (int op1)
{
    int factorial=1;
    int i;
    for ( i=1; i<=op1; i++)
    {
        factorial=factorial*i;
    }
    return factorial;

}
/** \brief valida que se ingresen los operandos
 *
 * \param valida el primer operando
 * \param valida el segundo operando
 * \return los operandos validados
 *
 */

int validaFlag(int x, int y)

{

    int aux=0;
    if (x==1 && y==1)
    {
        aux=1;
    }
    return aux;
}
