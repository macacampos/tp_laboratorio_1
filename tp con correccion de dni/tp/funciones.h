#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 20
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;
void graficoEdades(EPersona* agenda);
int calcularMaximo(int x,int y,int z);
void Iniciar(EPersona* agenda, int cantidad);
void inicializarDNI(EPersona agenda[],int cantidad,int valor);
int lugarLibre (EPersona agenda[], int cantidad,int *indice);
int buscarDNI(EPersona agenda[],int cantidad,int valor);
void cargarPersona (EPersona agenda[],int indice);
int soloSonLetras (char string[]);
int validaNumero(char string[]);
int borrarPersona(EPersona agenda[], int cantidad);
int ordenar (EPersona agenda[],int cantidad);
int getInt (void);

