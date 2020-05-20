#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "colores.h"
#include "bicicletas.h"
#include "servicios.h"
#include "validaciones.h"
#include "tipos.h"
#include "string.h"
#include "clientes.h"

int buscarClienteLibre(eCliente* list,int tam)
{
    int indice = -1;

    for(int i = 0; i <tam; i++)
    {
        if( list[i].isEmpty == 1)
        {
            indice = i;
            break;

        }
    }

    return indice;

}
int iniciarClientes(eCliente* list, int len)
{
    int retorno = -1;


    if(list != NULL)
    {

        for(int i = 0; i < len ; i++)
        {

            list[i].isEmpty = 1;

        }

        retorno = 0;

    }

    return retorno;
}
void mostrarCliente(eCliente x)
{

    printf("\n  %d         %10s        %c \n",x.id,x.nombre,x.sexo);

}
void mostrarClientes(eCliente* clientes,int tamC)
{
    system("cls");
    printf("-------------- Lista de Clientes Actuales --------------\n");
    printf("IDCLIENTE      NOMBRE       SEXO");
    for(int i = 0;i<tamC;i++)
    {
       if(clientes[i].isEmpty == 0)
       {
           mostrarCliente(clientes[i]);

       }

    }

}
int buscarIDClientes(eCliente* list,int tam,int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            break;

        }
    }

    return indice;

}
int cargarDescripClientes(char nombre[],char*  sexo, int idCliente,eCliente clientes[],int tamC)
{
    int isOk = 0;

    for(int i = 0; i < tamC; i++)
    {
        if(clientes[i].id == idCliente) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
        {
            strcpy(nombre, clientes[i].nombre);
            *sexo = clientes[i].sexo; //copio a descripcion la descripcion que tengo en ese sector
            isOk = 1; //exito
            break;
        }
    }

    return isOk;
}
