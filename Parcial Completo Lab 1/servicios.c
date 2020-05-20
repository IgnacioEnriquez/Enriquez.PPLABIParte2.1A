#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "colores.h"
#include "bicicletas.h"
#include "servicios.h"
#include "validaciones.h"
#include "tipos.h"

void listarServicios()
{
    system("cls");
    printf("--------------  Menu de Servicios -------------- \n");
    printf(" 1 - Limpieza 250$\n");
    printf(" 2 - Parche 300$\n");
    printf(" 3 - Centrado 400$\n");
    printf(" 4 - Cadena 350$\n");
    printf("------------------------------------------ \n\n");
    system("pause");

}

int menuServicios()
{
    int opcion;

    system("cls");
    printf("--------------  Menu de Servicios --------------\n");
    printf(" 1 - Limpieza 250$\n");
    printf(" 2 - Parche 300$\n");
    printf(" 3 - Centrado 400$\n");
    printf(" 4 - Cadena 350$\n");
    printf("------------------------------------------------\n\n");
    printf("Elija el servicio que desea asigar : ");
    scanf("%d",&opcion);

    return opcion;

}
void elegirServicios(int* idServicio,int* validacion)
{
    switch(menuServicios())
    {
    case 1:
        *idServicio = 20000;
        *validacion = 0;
        break;

    case 2:
        *idServicio = 20001;
        *validacion = 0;
        break;

    case 3:
        *idServicio = 20002;
        *validacion = 0;
        break;

    case 4:
        *idServicio = 20003;
        *validacion = 0;
        break;

    default:
        system("cls");
        printf("--------------------------------------------------\n");
        printf("La opcion elegida es incorrecta,reingrese datos\n");
        printf("--------------------------------------------------\n");
        system("pause");
        *validacion = -1;
        break;



    }




}
