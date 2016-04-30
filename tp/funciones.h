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
void grafico(int x, int y, int z);
int calcularMayor(int x,int y,int z);
void CalcularRango(EPersona rango[]);
void Iniciar(EPersona* agenda, int cantidad);
int lugarLibre (EPersona agendaA[], int cantidad,int *indice);
int lugarLibreDNI (EPersona agendaA[], int cantidad);
void cargarPersona (EPersona agenda[],int indice);
int soloSonLetras (char string[]);
int validaNumero(char string[]);
int borrarPersona(EPersona agenda[], int cantidad);
int ordenar (EPersona agenda[],int cantidad);
int getInt (void);
