
#include "funciones.h"

/** \brief inicia el array, y le asigna -1 al campo vacio
 *
 * \param agenda EPersona* estructura donde estan los parametros
 * \param cantidad int cantidad de veces que va a iterar
 * \return void
 *
 */

void Iniciar(EPersona* agenda, int cantidad)
{
    int i;

    for(i=0;i < cantidad;i++)
    {
        agenda[i].estado=-1;
    }
}


/** \brief busca un lugar libre para cargarle datos
 *
 * \param cantidad int cantidad de veces a iterar
 * \param indice int
 * \return retorna 1 si salio todo bien
 *
 */

int lugarLibre (EPersona agenda[], int cantidad, int *indice)
{
    int retorno=0;
    int i;
    for(i=0;i < cantidad;i++)
    {
        if(agenda[i].estado==-1)
        {
            *indice=i;
            retorno=1;
            break;
        }
    }
    return retorno;
}
/** \brief busca lugares libres en el campo dni
 *
 * \param cantidad int las veces que va a iterar
 * \param EPersona agendaA[] estructura donde se encuentra el campo dni
 * \return i si esta vacio, 0 si esta lleno
 *
 */
void inicializarDNI(EPersona agenda[],int cantidad,int valor)
{
    int i;
    for(i=0;i < cantidad; i++)
    {
        agenda[i].dni = valor;
    }
}

int buscarDNI(EPersona agenda[],int cantidad,int valor)
{
    int i;
    for(i=0;i < cantidad; i++)
    {
        if(agenda[i].dni == valor)
        {
            return i;
        }
    }
    return -1;
}

/** \brief carga los datos
 *
 * \param EPersona agenda[] estructura donde se escuentran los campos a cargar
 * \param int indice
 * \return void
 */

void cargarPersona (EPersona agenda[],int indice)
{
    char auxiliar[255];
    char nombre[20];
    int edad;
    int dni;
    int flagUno=0;
    int flagDos=0;
    int flagTres=0;

    printf("Ingrese dni: ");
    gets(auxiliar);

    if(validaNumero(auxiliar)==1 && (buscarDNI(agenda,TAM,atoi(auxiliar))== -1) && atoi(auxiliar)>0 && atoi(auxiliar)<=99999999)
        {
             flagUno=1;
             dni=atoi(auxiliar);
        }
    else
        {
            printf("Ingreso mal el dni o ya esta ocupado por otro usuario \n");
        }
    if(flagUno)
    {
    fflush(stdin);
    printf("Ingrese nombre: ");
    gets(auxiliar);

        if(soloSonLetras(auxiliar)==1)
        {
        flagDos=1;
        strcpy(nombre,auxiliar);
        }
    }

    if(flagDos)
    {
        printf("Ingrese edad: ");
        gets(auxiliar);
        if(validaNumero(auxiliar)&& atoi(auxiliar)>=0 && atoi(auxiliar)<=99)
        {
            flagTres=1;
            edad=atoi(auxiliar);
        }
    }



    if(flagDos==1 && flagTres==1 && flagUno==1)
    {
        strcpy(agenda[indice].nombre,nombre);
        agenda[indice].dni=dni;
        agenda[indice].edad=edad;
        agenda[indice].estado=1;

    }
}
/** \brief verifica que solo se ingresen letras
 *
 * \param char string[] para validar
 * \return retorna 1 si esta todo bien
 *
 */

int soloSonLetras (char string[])
{
    int cant;
    cant=strlen(string);
    for (int i=0;i < cant;i++)
    {
        if(!(isalpha(string[i])))
        {
            return 0;
        }

    }
    return 1;
}
/** \brief valida que se ingrese solo un numero.
 *
 * \param string[] char para validar
 * \return int 1 si esta todo bien
 *
 */

int validaNumero(char string[])
{
   int i=0;
   while(string[i] != '\0')
   {
       if(string[i] < '0' || string[i] > '9')
       {
           return 0;
       }

       i++;
   }
   return 1;
}

/** \brief borra una persona por dni
 *
 * \param agenda[] EPersona estructura donde se encuentra el campo a analizar
 * \param cantidad int
 * \return int 1 si lo borro, 0 si no lo borro
 *
 */

int borrarPersona(EPersona agenda[], int cantidad)
{
    fflush(stdin);
    char aux[20];
    int i;
    printf("ingrese dmi a borrar: ");
    gets(aux);

    if (validaNumero(aux))
    {
        for (i=0;i < cantidad;i++)
        {
            if(agenda[i].dni==atoi(aux) && agenda[i].estado==1)
            {
                agenda[i].estado=-1;
                return 1;
            }
        }
    }
    return 0;

}
/** \brief ordena los nombres alfabeticamente
 *
 * \param EPersona agenda[] estructura donde se encuentran los campos
 * \param int cantidad, las veces que va a iterar el for
 * \return 1 si salio todo bien
 *
 */

int ordenar (EPersona agenda[],int cantidad)
{
    EPersona auxiliar;
    int i;
    int j;

    for (i=0;i < cantidad-1;i++)
    {
        if(agenda[i].estado==-1)
        {
            continue;
        }
        for(j=i+1;j < cantidad;j++)
        {
            if(agenda[i].estado==-1)
            {
                continue;
            }
            if(strcmp(agenda[i].nombre,agenda[j].nombre)>0)
            {
                    auxiliar=agenda[i];
                    agenda[i]=agenda[j];
                    agenda[j]=auxiliar;
            }
        }
    }

    for (i=0;i < cantidad;i++)
    {
        if(agenda[i].estado==1)
        {
            printf("nombre ---- edad ---- dni  \n");
            printf("%s          %d        %d\n", agenda[i].nombre, agenda[i].edad, agenda[i].dni);
        }
    }

    return 1;

}
/** \brief valida que se ingrese una opcion correcta
 *
 * \param void
 * \return
 *
 */
int getInt (void)
{
    fflush(stdin);
    char aux[255];
    int opcion;
    int cantChar;
    printf("Ingresa una opcion: ");
    gets(aux);
    opcion=atoi(aux);
    cantChar=strlen(aux);
    if(cantChar==1 && opcion<=5 && opcion>=1)
    {
        return opcion;
    }
    else
    {
        printf("ERROR");
        return 0;
    }
}

/** \brief Calcula una estadistica entre 3 rango de edades.
 *
 * \param  x es el primer rango.
 * \param  y es el segundo rango.
 * \param  z es el tercer rango.
 * \return No retorna nada.
 *
 */
/*void grafico(int x, int y, int z)
{
    int i,j;
    int mayor= calcularMaximo(x,y, z);
    int graf[]={x,y,z};
    char matriz[mayor][3];
    for(j=0;j < mayor;j++)
    {
        for(i=0;i < 3;i++)
        {
            if(graf[i]>j)
            {
                matriz[j][i]='*';
            }
            else
            {
                matriz[j][i]=' ';
            }
        }
    }
    for(j=mayor-1;j>=0;j--)
    {
        printf("  %c     %c     %c \n",matriz[j][0],matriz[j][1],matriz[j][2]);
    }
        printf("|...............\n");
        printf("<18   19-35  >35\n");
}


/** \brief Calcula el rango de edades para mostrarlas con grafico
 *
 * \param  rango recibe un vector de tipo EPersona
 * \return No retorna nada.
 *
 */
/*void Rangos(EPersona agenda[])
{
    int i;
    int x=0;
    int y=0;
    int z=0;

    for(i=0;i <=20 && agenda[i].estado==1;i++)
    {
        fflush(stdin);
        if(agenda[i].edad<18)
        {
            x++;
        }

        if(agenda[i].edad>18 && agenda[i].edad<=35)
        {
            y++;
        }

        if(agenda[i].edad>35)
        {
            z++;
        }
    }
        grafico(x,y,z);
}


/** \brief Recibe 3 numeros y calcula el mayor
 *
 * \param  int x numero a evaluar
 * \param  int y numero a evaluar
 * \param  int z numero a evaluar
 * \return retorna el mayor.
 *
 */
/*int calcularMaximo(int x,int y,int z)
{
    int Maximo;
    if(x>y && x>z)
    {
        Maximo=x;
    }
    else
    {
        if(y>x && y>=z)
        {
            Maximo=y;
        }
        else
        {
            Maximo=z;
        }
    }
    return Maximo;
}*/
void graficoEdades(EPersona* agenda)
{

    int contMayor=0;
    int contMenores18=0;
    int contDe19a35=0;
    int contMayoresDe35=0;
    int i;
    int flag=0;

    for (i=0;i<TAM;i++){
        if(agenda[i].estado!=-1){
            if(agenda[i].edad<18){
                contMenores18++;
            }else if(agenda[i].edad>18&&agenda[i].edad<35){
                contDe19a35++;
            }else {
                contMayoresDe35++;
            }
        }
    }

    if(contMenores18>contDe19a35&&contMenores18>contMayoresDe35){
        contMayor=contMenores18;
    }else if(contDe19a35>contMenores18&&contDe19a35>contMayoresDe35){
        contMayor=contDe19a35;
    }else{
        contMayor=contMayoresDe35;
    }

    for(i=contMayor; i>0; i--){
        if(i<= contMenores18){
            printf("*");
        }
        if(i<= contDe19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= contMayoresDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
        printf("\n");
    }
    printf("--------------------");
    printf("\n <18 | 19-35 | >35");

}
