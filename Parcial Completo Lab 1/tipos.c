#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "trabajo.h"
#include "colores.h"
#include "bicicletas.h"
#include "servicios.h"
#include "validaciones.h"
#include "tipos.h"

int menuTipos()
{
    int opcion;

    printf("-------------- Menu de Tipos --------------\n\n");
    printf("             1 - Rutera \n\n");
    printf("             2 - Carrera\n\n");
    printf("             3 - Mountain\n\n");
    printf("             4 - BMX\n\n");
    printf("-------------------------------------------\n\n");
    printf("Ingresa el tipo que desea  : ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
void listarTipos()
{
    system("cls");
    printf("-------------- Lista de Tipos --------------\n");
    printf(" 1 - Rutera \n");
    printf(" 2 - Carrera\n");
    printf(" 3 - Mountain\n");
    printf(" 4 - BMX\n");
    printf("--------------------------------------------\n\n");
    system("pause");

}
void elegirTipo(int* idTipo,int* validacion)
{
                   system("cls");
                    switch(menuTipos())
                    {
                    case 1:
                        *idTipo = 1000;
                        *validacion = 0;
                        break;
                    case 2:
                        *idTipo = 1001;
                        *validacion = 0;
                        break;

                    case 3:
                        *idTipo = 1002;
                        *validacion = 0;
                        break;
                    case 4:
                        *idTipo = 1003;
                        *validacion = 0;
                        break;
                    default:
                        system("cls");
                        printf("--------------------------------------------------\n");
                        printf("Error,el tipo de bicicleta es incorrecto,reingrese datos\n");
                        printf("--------------------------------------------------\n");
                        system("pause");
                        *validacion = -1;
                        break;

                    }
}
int cargarDescripTipos(char descripcion[], int idTipo, eTipo tipos[], int tamT)
{
    int isOk = 0;

    for(int i = 0; i < tamT; i++)
    {
        if(tipos[i].id == idTipo) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
        {
            strcpy(descripcion, tipos[i].descripcion); //copio a descripcion la descripcion que tengo en ese sector
            isOk = 1; //exito
            break;
        }
    }

    return isOk;
}
void listarPorTipo(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{
    int validacion;
    int idTipo;

    elegirTipo(&idTipo,&validacion);
    if(validacion != -1)
    {
        mostrarPorTipo(list,tam,tipos,tamT,colores,tamC,clientes,tamCL,idTipo);
    }

}
void mostrarPorTipo(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL,int idTipo)
{
    system("cls");
    int flag = 0;
    printf("-------------- Lista de Bicicletas Actuales --------------\n");

    for(int i = 0;i < tam;i++)
    {
       if(list[i].isEmpty == 0 && list[i].idTipo == idTipo)
       {
           mostrarBicicleta(list[i],tipos,tamT,colores,tamC,clientes,tamCL);
           flag = 1;

       }

    }
    if(flag == 0)
    {
        printf("------------------------------------------\n");
        printf("No hay bicicletas que contengan ese tipo\n");
        printf("------------------------------------------\n");
    }

    system("pause");
}
void mostrarSoloBMW(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{
    int flag = 0;
    system("cls");
    printf("------------ Bicicletas BMW -------------\n");
    for(int i = 0; i<tam; i++)
    {
        if(list[i].isEmpty == 0 && list[i].idTipo == 1003)
        {
         mostrarBicicleta(list[i],tipos,tamT,colores,tamC,clientes,tamCL);
         flag = 1;
        }



    }

    if(flag == 0)
    {
        printf("------------------------------------------\n");
        printf("No hay bicicletas que contengan ese tipo\n");
        printf("------------------------------------------\n");

    }

    system("pause");
}
void mostrarSoloMountain(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{
    int flag = 0;
    printf("------------ Bicicletas Mountain -------------\n");
    for(int i = 0; i<tam; i++)
    {
        if(list[i].isEmpty == 0 && list[i].idTipo == 1002)
        {
         mostrarBicicleta(list[i],tipos,tamT,colores,tamC,clientes,tamCL);
         flag = 1;
        }



    }

    if(flag == 0)
    {
        printf("------------------------------------------\n");
        printf("No hay bicicletas que contengan ese tipo\n");
        printf("------------------------------------------\n");

    }

    system("pause");

}
void mostrarSoloCarrera(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{
    int flag = 0;
    printf("------------ Bicicletas Carrera -------------\n");
    for(int i = 0; i<tam; i++)
    {
        if(list[i].isEmpty == 0 && list[i].idTipo == 1001)
        {
         mostrarBicicleta(list[i],tipos,tamT,colores,tamC,clientes,tamCL);
         flag = 1;
        }



    }

    if(flag == 0)
    {
        printf("------------------------------------------\n");
        printf("No hay bicicletas que contengan ese tipo\n");
        printf("------------------------------------------\n");

    }

    system("pause");

}
void mostrarSoloRutera(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{
    int flag = 0;
    printf("------------ Bicicletas Rutera -------------\n");
    for(int i = 0; i<tam; i++)
    {
        if(list[i].isEmpty == 0 && list[i].idTipo == 1000)
        {
         mostrarBicicleta(list[i],tipos,tamT,colores,tamC,clientes,tamCL);
         flag = 1;
        }



    }

    if(flag == 0)
    {
        printf("------------------------------------------\n");
        printf("No hay bicicletas que contengan ese tipo\n");
        printf("------------------------------------------\n");

    }

    system("pause");

}
