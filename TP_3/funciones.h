#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#define TAM 4

typedef struct
{
    char titulo[51];
    char genero[20];
    int duracion;
    char descripcion[100000];
    int puntaje;
    char linkImagen[100000];
    int estado;
} EMovie;

void iniciar(EMovie* peliculas, int cantidad);
int lugarLibre (EMovie peliculas[], int cantidad, int *indice);
void cargar(EMovie peliculas[], int indice);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int getInt (void);
int borrar(EMovie peliculas[], int cantidad);
int modificar (EMovie* peliculas, int cantidad);
unsigned int ValidaSeguirSoN(char mensajeError[]);
void LeerBinario(EMovie *peliculas, int cantidad);
void GuardarBinario(EMovie *peliculas, int cantidad);
void generarPagina(EMovie peliculas[], int cantidad);
void precargada(EMovie peliculas[]);

