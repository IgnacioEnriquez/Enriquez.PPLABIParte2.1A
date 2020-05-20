#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "trabajo.h"
#include "bicicletas.h"
#include "servicios.h"
#include "validaciones.h"
#include "tipos.h"
#include "colores.h"

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;

}eCliente;



#endif // CLIENTES_H_INCLUDED

int buscarClienteLibre(eCliente* list,int tam);
int iniciarClientes(eCliente* list, int len);
void mostrarCliente(eCliente x);
void mostrarClientes(eCliente* clientes,int tamC);
int buscarIDClientes(eCliente* list,int tam,int id);
int cargarDescripClientes(char nombre[],char*  sexo, int idCliente,eCliente clientes[],int tamC);
