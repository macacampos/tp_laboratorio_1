#include "funciones.h"
/** \brief inicia el array, y le asigna -1 al campo vacio
 *
 * \param estructura donde estan los parametros
 * \param cantidad int cantidad de veces que va a iterar
 * \return void
 *
 */
void iniciar(EMovie* peliculas, int cantidad)
{
    if(peliculas!= NULL )
    {
        for (int i=0; i < cantidad; i++)
        {
            peliculas[i].estado=-1;
        }
    }
}

/** \brief busca un lugar libre para cargarle datos
 *
 * \param cantidad int cantidad de veces a iterar
 * \param indice int
 * \return retorna 1 si salio todo bien
 *
 */
int lugarLibre (EMovie peliculas[], int cantidad, int *indice)
{
    int retorno=0;
    int i;

    if(peliculas!= NULL)
    {
        for(i=0; i < cantidad; i++)
        {
            if(peliculas[i].estado==-1)
            {
                *indice=i;
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
/** \brief carga los datos a los campos de la estructura
 *
 * \param peliculas[] EMovie estructura
 * \param indice int
 * \return void
 *
 */
void cargar(EMovie peliculas[], int indice)
{
    char aux[1000];
    int flagtitulo=0;
    int flagGenero=0;
    int flagduracion=0;
    int flagdescripcion=0;
    int flagpuntaje=0;

    printf("Ingrese titulo de la pelicula: ");
    gets(aux);
    flagtitulo=1;
    strcpy(peliculas[indice].titulo,aux);

    if(flagtitulo==1)
    {
        fflush(stdin);
        printf("ingrese genero de la pelicula: ");
        gets(aux);

        if (esSoloLetras(aux)==1)
        {
             flagGenero=1;
            strcpy(peliculas[indice].genero,aux);

        }
        else
        {
            printf("error ingrese solo letras\n");
        }

    }

    if (flagGenero==1)
    {

        printf("ingrese la duracion de la pelicula: \n");
        gets(aux);

        if (esNumerico(aux)==1)
        {
            flagduracion=1;
            peliculas[indice].duracion=atoi(aux);

        }
        else
        {
            printf("error debe ingresar solo numeros\n");
        }
    }

    if (flagduracion==1)
    {
        fflush(stdin);
        printf("ingrese descripcion de la pelicula: \n");
        gets(aux);
        flagdescripcion=1;
        strcpy(peliculas[indice].descripcion,aux);

    }

    if(flagdescripcion==1)
    {
        fflush(stdin);
        printf("ingrese puntaje de la pelicula: \n");
        gets(aux);
        if (esNumerico(aux)==1)
        {
            flagpuntaje=1;
            peliculas[indice].puntaje=atoi(aux);

        }
        else
        {
            printf("debe ser solo numerico ");
        }
    }
    if(flagpuntaje==1)
    {
        fflush(stdin);
        printf("ingrese link de la imagen:");
        gets(aux);

        strcpy(peliculas[indice].linkImagen,aux);
        peliculas[indice].estado=1;
    }

}


/** \brief valida que se ingrese solo un numero.
 *
 * \param string[] char para validar
 * \return int 1 si esta todo bien
 *
 */
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
/** \brief verifica que solo se ingresen letras
 *
 * \param char string[] para validar
 * \return retorna 1 si esta todo bien
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
/** \brief Valida el ingreso de un char de respuesta, para admitir solo 's' 'S' como "SI", y 'n', o 'N' como "NO".
 *
 * \param mensajeError[] char el mensaje a mostrar en caso de error
 * \return unsigned int  (O) Si el usuario ingreso 'n' o 'N'; (1) si el usuario ingresó 'S' o 's'.
 *
 */
unsigned int ValidaSeguirSoN(char mensajeError[])
{
    char rta;

    printf("\n\n  s : para seguir   -   n : para salir\n\n");
    rta=toupper(getche());
    while(!((rta=='S')||(rta=='N')))
    {
        puts(mensajeError);
        rta=toupper(getche());
    }
    return (rta=='S');
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
    if(cantChar==1 && opcion<=8 && opcion>=1)
    {
        return opcion;
    }
    else
    {
        printf("ERROR\n");
        return 0;
    }
}
/** \brief borra una persona
 *
 * \param estructura donde se encuentra el campo a analizar
 * \param cantidad int cantidad de veces a iterar
 * \return int 1 si lo borro, 0 si no lo borro
 *
 */
int borrar(EMovie peliculas[], int cantidad)
{
    fflush(stdin);
    char aux[255];
    int i;
    printf("ingrese titulo de la pelicula a borrar: ");
    gets(aux);

    for (i=0; i < cantidad; i++)
    {
        if(strcmp(aux,peliculas[i].titulo)==0)
        {
            peliculas[i].estado=-1;
            return 1;
        }
    }

    return 0;
}
/** \brief  modifica los datos de los campos de la estructura
 *
 * \param estructura
 * \param cantidad de veces a iterar
 * \return 0 salio todo ok
 *
 */
int modificar (EMovie* peliculas, int cantidad)
{
    int opcion;
    char auxiliar[1000];
    int flag;
    int i, indiceMod=-1;
    char seguir='s';
    printf("Ingrese la pelicula a modificar: ");
    gets(auxiliar);
    for(i=0; i<cantidad; i++)
    {
        if(strcmp(auxiliar,peliculas[i].titulo)==0)
        {
            indiceMod=i;
            break;
        }
    }
    if(indiceMod!=-1)
    {

        do
        {

            {

                printf("MODIFICAR\n");
                printf("1.Titulo\n2.Genero\n3.Duracion\n4.Descripcion\n5.Puntaje\n6.Link de imagen\n");

                opcion=getInt();
                if(opcion!=-1)
                {
                    switch(opcion)
                    {
                    case 1:

                        system("cls");
                        printf("1.Titulo\n2.Genero\n3.Duracion\n4.Descripcion\n5.Puntaje\n6.Link de imagen\n");
                        flag=0;
                        while(flag==0)
                        {
                            printf("Ingrese nuevo titulo: ");
                            gets(auxiliar);
                            flag=1;
                            strcpy(peliculas[i].titulo,auxiliar);

                        }
                        break;
                    case 2:
                        system("cls");
                        printf("1.Titulo\n2.Genero\n3.Duracion\n4.Descripcion\n5.Puntaje\n6.Link de imagen\n");
                        flag=0;
                        while(flag==0)
                        {
                            printf("Ingrese el nuevo genero: ");
                            gets(auxiliar);
                            if(esSoloLetras(auxiliar)==1)
                            {
                                flag=1;
                                strcpy(peliculas[i].genero,auxiliar);
                            }
                            else
                                printf("Error, debe ingresar solo letras");
                        }
                        break;
                    case 3:
                        system("cls");
                        printf("1.Titulo\n2.Genero\n3.Duracion\n4.Descripcion\n5.Puntaje\n6.Link de imagen\n");
                        flag=0;
                        while(flag==0)
                        {
                            printf("Ingrese la nueva duracion: ");
                            gets(auxiliar);
                            if(esNumerico(auxiliar)==1)
                            {
                                flag=1;
                                peliculas[i].duracion=atoi(auxiliar);
                            }
                            else
                                printf("Error, debe ser numerico");
                        }
                        break;
                    case 4:
                        system("cls");
                        printf("1.Titulo\n2.Genero\n3.Duracion\n4.Descripcion\n5.Puntaje\n6.Link de imagen\n");
                        flag=0;
                        while(flag==0)
                        {
                            printf("Ingrese la nueva descripcion: ");
                            gets(auxiliar);
                            if(esSoloLetras(auxiliar)==1)
                            {
                                flag=1;
                                strcpy(peliculas[i].descripcion,auxiliar);
                            }
                            else
                                printf("Error, deben ser solo letras");
                        }
                        break;
                    case 5:
                        system("cls");
                        printf("1.Titulo\n2.Genero\n3.Duracion\n4.Descripcion\n5.Puntaje\n6.Link de imagen\n");
                        flag=0;
                        while(flag==0)
                        {
                            printf("Ingrese el nuevo puntaje: ");
                            gets(auxiliar);
                            if(esNumerico(auxiliar)==1)
                            {
                                flag=1;
                                peliculas[i].puntaje=atoi(auxiliar);
                            }
                            else
                                printf("Error, debe ser numerico");
                        }
                        break;
                    case 6:
                        system("cls");
                        printf("1.Titulo\n2.Genero\n3.Duracion\n4.Descripcion\n5.Puntaje\n6.Link de imagen\n");
                        flag=0;
                        while(flag==0)
                        {
                            printf("Ingrese el nuevo link de la imagen: ");
                            gets(auxiliar);
                            flag=1;
                            strcpy(peliculas[i].linkImagen,auxiliar);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }

        }
        while((seguir=ValidaSeguirSoN("Error, ingrese correctamente: s o n")));
    }
    else
    {
        printf("\nnombre erroneo\n");
        system("pause");
    }

    return 0;

}

/** \brief
 *
 * \param peliculas EMovie*
 * \param cantidad int cantidad de veces a iterar
 * \return void
 *
 */
void GuardarBinario(EMovie *peliculas, int cantidad)
{
    FILE *f;
    f = fopen("bin.dat", "wb");
    if(f == NULL)
    {
        printf("No se pudo abrir el fichero");
        exit(1);
    }

    fwrite(peliculas, sizeof(EMovie), cantidad, f);

    printf("\nFichero guardado con exito\n");

    fclose(f);
}
/** \brief
 *
 * \param peliculas EMovie*
 * \param cantidad int
 * \return void
 *
 */
void LeerBinario(EMovie *peliculas, int cantidad)
{
    FILE *f;
    f = fopen("bin.dat", "rb");
    if(f == NULL)
    {
        f = fopen("bin.dat", "wb");

    }
    if(f == NULL)
    {
        printf("No se pudo abrir el fichero");
        exit(1);
    }
    fread(peliculas, sizeof(EMovie), cantidad, f);

    printf("\nFichero cargado con exito\n\n");

    system("pause");

    fclose(f);
}

/** \brief genera un html con las peliculas cargadas
 *
 * \param peliculas[] EMovie estructura
 * \param cantidad int de veces a iterar
 * \return void
 *
 */
void generarPagina(EMovie peliculas[], int cantidad)
{
    int i;

     FILE *f;

    f=fopen("pagina.html", "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }
    fprintf(f,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");

  for(i=0;i<cantidad;i++)
    {
        if(peliculas[i].estado==1)
        {
         fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>", peliculas[i].linkImagen);
         fprintf(f,"</a><h3><a href='#'>%s</a></h3><ul>",peliculas[i].titulo);
         fprintf(f,"<li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul>", peliculas[i].genero, peliculas[i].puntaje,peliculas[i].duracion);
         fprintf(f,"<p>%s</p></article>",peliculas[i].descripcion);
        }
    }
    fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(f);
    printf("\n\n archivo escrito con exito\n\n");

}
/** \brief peliculas ya cargadas en el html
 *
 * \param peliculas[] EMovie
 * \return void
 *
 */
void precargada(EMovie peliculas[])
{
    strcpy(peliculas[0].titulo, "\nLos juegos del hambre\n");
    strcpy(peliculas[0].genero, "\nCiencia ficcion\n");
    peliculas[0].duracion=142;
    strcpy(peliculas[0].descripcion, "La nacion de Panem salio de las ruinas de lo que una vez fue conocido como Norte America. <br> Hace 74 anios, los distritos afectados por la pobreza en Panem se rebelaron en contra de la riqueza que controla el Capitolio. <br> Despues de su aplastante victoria, el Capitolio ideo  Cada anio,cada distrito debe llevar a cabo una rifa (conocida como la cosecha) <br> para elegir un hombre y una mujer (con edades desde los 12 hasta los 18 anios) para participar en Los Juegos del Hambre, <br> una competicion en la que cada uno de los 24 participantes (conocidos como tributos) pelearan a muerte en una arena televisada hasta que solo uno quede vivo.<br> Sin embargo esto es simplemente un recordatorio anual a los doce distritos de su autoridad y como castigo por la rebelion hecha hace 74 anios.");
    peliculas[0].puntaje=10;
    strcpy(peliculas[0].linkImagen,"http://ia.media-imdb.com/images/M/MV5BMjA4NDg3NzYxMF5BMl5BanBnXkFtZTcwNTgyNzkyNw@@._V1_UX182_CR0,0,182,268_AL_.jpg");
    peliculas[0].estado=1;
    strcpy(peliculas[1].titulo,"\nThe mazze runner\n");
    strcpy(peliculas[1].genero, "\nCiencia ficcion\n");
    peliculas[1].duracion=113;
    strcpy(peliculas[1].descripcion, "Un dia Thomas despierta sin ningun recuerdo, atrapado en un extranio lugar; un lugar donde <br>hay mas jovenes como el que se encuentran en la misma condicion: no recuerdan nada y solo tienen una pista: la organizacion CRUEL. <br>En dicho lugar, hay un gran laberinto, por el que podrian escapar antes de que sus puertas se cierren y acabe con sus vidas, <br>para lograr huir tendran que ir juntando las pistas que hay en ese laberinto. Thomas y los demas chicos, tiene la esperanza de <br>descubrir lo que hay detras de ese enigma y quien los ha puesto ahi, con que motivo. Escapar y descubrirlo, no sera nada facil.");
    peliculas[1].puntaje=10;
    strcpy(peliculas[1].linkImagen, "http://ia.media-imdb.com/images/M/MV5BMjUyNTA3MTAyM15BMl5BanBnXkFtZTgwOTEyMTkyMjE@._V1_UX182_CR0,0,182,268_AL_.jpg");
    peliculas[1].estado=1;
}
