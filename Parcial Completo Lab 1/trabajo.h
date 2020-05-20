#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED


typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
 int id;
 int idBicicleta;
 int idServicio;
 eFecha fecha;
 int isEmpty;


}eTrabajo;
#include "colores.h"
#include "servicios.h"
#include "validaciones.h"
#include "tipos.h"


int altaTrabajo(int* id,eBicicleta* list,int tamB,eTrabajo* trabajos,int tamTR,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);
int iniciarTrabajos(eTrabajo* list, int len);
int buscarLibreTrabajo(eTrabajo* list,int tam);
int ingresarFechaTrabajo(int* dia,int *mes,int* anio);
int cargarDescripServicio(char descripcion[],int idServicio, eServicio servicios[], int tamS);
int cargarDescripServicio(char descripcion[],int idServicio, eServicio servicios[], int tamS);
void mostrarTrabajo(eTrabajo trabajo,eBicicleta* bicicletas,int tamB,eTipo* tipos,int tamT,eColor* colores,int tamC, eServicio servicios[], int tamS);
void mostrarTrabajos(eTrabajo* trabajos,int tamTR,eBicicleta* bicicletas,int tamB,eTipo* tipos,int tamT,eColor* colores,int tamC, eServicio servicios[], int tamS);
int cargarPrecioServicio(int* precio,int idServicio, eServicio servicios[], int tamS);
void eliminarTrabajo(eTrabajo* trabajos,int tamTR,eBicicleta* bicicletas,int idBicicleta);
#endif // TRABAJO_H_INCLUDED



