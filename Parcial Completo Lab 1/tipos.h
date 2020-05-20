#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eTipo;

#include "trabajo.h"
#include "colores.h"
#include "bicicletas.h"
#include "servicios.h"
#include "validaciones.h"
#include "clientes.h"



int menuTipos();
void listarTipos();
void elegirTipo(int* idTipo,int* validacion);
int cargarDescripTipos(char descripcion[], int idTipo, eTipo tipos[], int tamT);
void listarPorTipo(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);
void mostrarPorTipo(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL,int idTipo);
void mostrarSoloBMW(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);
void mostrarSoloMountain(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);
void mostrarSoloCarrera(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);
void mostrarSoloRutera(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);







#endif // TIPOS_H_INCLUDED


