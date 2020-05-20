#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[20];


}eColor;
#include "trabajo.h"
#include "bicicletas.h"
#include "servicios.h"
#include "validaciones.h"
#include "tipos.h"
#include "clientes.h"



int menuColores();
void listarColores();
void elegirColor(int * id,int* validacion);
int cargarDescripColores(char descripcion[], int idColor,eColor colores[], int tamC);
void listarPorColor();
void mostrarPorColor(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL,int idColor);
void listarPorColor(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);
void colorMaximo(eBicicleta* bicicletas,int tamB);
void contarColorYTipo(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);

#endif // COLORES_H_INCLUDED

