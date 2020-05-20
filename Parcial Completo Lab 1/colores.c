#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "trabajo.h"
#include "colores.h"
#include "bicicletas.h"
#include "servicios.h"
#include "validaciones.h"
#include "tipos.h"

int menuColores()
{
    int opcion;

    printf("-------------- Menu de Colores --------------\n\n");
    printf("               1 - Gris\n\n");
    printf("               2 - Negro\n\n");
    printf("               3 - Blanco\n\n");
    printf("               4 - Azul\n\n");
    printf("               5 - Rojo\n\n");
    printf("--------------------------------------------\n\n");
    printf("Ingresa una opcion : ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
void listarColores()
{
    system("cls");
    printf("--------------  Menu de Tipos --------------\n");
    printf(" 1 - Gris\n");
    printf(" 2 - Negro\n");
    printf(" 3 - Blanco\n");
    printf(" 4 - Azul\n");
    printf(" 5 - Rojo\n");
    printf("--------------------------------------------\n\n");
    system("pause");
}
void elegirColor(int* id,int* validacion)
{
    system("cls");
    switch(menuColores())
    {
    case 1:
        *id = 5000;
        *validacion= 0;
        break;
    case 2:
        *id = 5001;
        *validacion= 0;
        break;

    case 3:
        *id = 5002;
        *validacion= 0;
        break;
    case 4:
        *id = 5003;
        *validacion= 0;
        break;
    case 5:
        *id = 5004;
        *validacion= 0;
        break;

    default:
        printf("--------------------------------------------------------\n");
        printf("Error,el Color de bicicleta es incorrecto,reingrese datos\n");
        printf("--------------------------------------------------------\n");
        system("pause");
        *validacion= -1;
        break;
    }
}
int cargarDescripColores(char descripcion[], int idColor,eColor colores[], int tamC)
{
    int isOk = 0;

    for(int i = 0; i < tamC; i++)
    {
        if(colores[i].id == idColor) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
        {
            strcpy(descripcion, colores[i].descripcion); //copio a descripcion la descripcion que tengo en ese sector
            isOk = 1; //exito
            break;
        }
    }

    return isOk;
}
void listarPorColor(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{
    int validacion;
    int idColor;

    elegirColor(&idColor,&validacion);
    if(validacion != -1)
    {
        mostrarPorColor(list,tam,tipos,tamT,colores,tamC,clientes,tamCL,idColor);
    }

}
void mostrarPorColor(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL,int idColor)
{
    system("cls");
    int flag = 0;
    printf("-------------- Lista de Bicicletas Actuales --------------\n");

    for(int i = 0;i < tam;i++)
    {
       if(list[i].isEmpty == 0 && list[i].idColor == idColor)
       {
           mostrarBicicleta(list[i],tipos,tamT,colores,tamC,clientes,tamCL);
           flag = 1;

       }

    }
    if(flag == 0)
    {
        printf("------------------------------------------\n");
        printf("No hay bicicletas que contengan ese color\n");
        printf("------------------------------------------\n");
    }

    system("pause");
}
void contarColorYTipo(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{
    int idColor;
    int validacionColor;
    int idTipo;
    int ValidacionTipo;
    int contadorTipoYColor = 0;
    system("cls");
    elegirColor(&idColor,&validacionColor);
    elegirTipo(&idTipo,&ValidacionTipo);

    if(validacionColor != -1 && ValidacionTipo != -1)
    {
        system("cls");
        for(int i = 0; i<tam ;i++)
        {

            if(list[i].isEmpty == 0)
            {
                if(list[i].idColor == idColor && list[i].idTipo == idTipo)
                {
                    mostrarBicicleta(list[i],tipos,tamT,colores,tamC,clientes,tamCL);
                    contadorTipoYColor++;


                }

            }

        }


        printf("\nLa cantidad de bicicletas con el mismo color y tipo es %d\n",contadorTipoYColor);

    }



}
void colorMaximo(eBicicleta* bicicletas,int tamB)
{
    int contadorRojo = 0;
    int contadorGris = 0;
    int contadorAzul = 0;
    int contadorBlanco = 0;
    int contadorNegro = 0;



    for(int i = 0 ;i<tamB ;i++)
    {
        if(bicicletas[i].isEmpty == 0)
        {

            if(bicicletas[i].idColor == 5004)
            {
                contadorRojo++;
            }
            else if(bicicletas[i].idColor == 5000)
            {
                contadorGris++;
            }
            else if(bicicletas[i].idColor == 5001)
            {
                contadorNegro++;
            }
            else if(bicicletas[i].idColor == 5002)
            {
                contadorBlanco++;
            }
            else if(bicicletas[i].idColor == 5003)
            {
                contadorAzul++;
            }

        }
    }

    system("cls");
    if(contadorRojo >= contadorAzul && contadorRojo >= contadorBlanco && contadorRojo >= contadorGris && contadorRojo >= contadorNegro)
    {
        printf("-------------------------------------------------------------------------\n");
        printf("El color mas elegido por los clientes es el Rojo con %d de Bicicleta\n",contadorRojo);
        printf("-------------------------------------------------------------------------\n\n");
    }
    if(contadorAzul >= contadorRojo && contadorAzul >= contadorBlanco && contadorAzul >= contadorGris && contadorAzul >= contadorNegro)
    {
        printf("-------------------------------------------------------------------------\n");
        printf("El color mas elegido por los clientes es el Azul con %d de Bicicleta\n\n",contadorAzul);
        printf("-------------------------------------------------------------------------\n\n");

    }
    if(contadorBlanco >= contadorRojo && contadorBlanco >= contadorAzul && contadorBlanco >= contadorGris && contadorBlanco >= contadorNegro)
    {
        printf("-------------------------------------------------------------------------\n");
        printf("El color mas elegido por los clientes es el Blanco con %d de Bicicleta\n\n",contadorBlanco);
        printf("-------------------------------------------------------------------------\n\n");

    }
    if(contadorNegro >= contadorRojo  && contadorNegro >= contadorAzul && contadorNegro >= contadorGris && contadorNegro >= contadorBlanco)
    {
        printf("-------------------------------------------------------------------------\n");
        printf("El color mas elegido por los clientes es el Negro con %d de Bicicleta\n\n",contadorNegro);
        printf("-------------------------------------------------------------------------\n\n");

    }
    if(contadorGris >= contadorRojo  && contadorGris >= contadorAzul && contadorGris >= contadorNegro && contadorGris >= contadorBlanco)
    {
        printf("-------------------------------------------------------------------------\n");
        printf("El color mas elegido por los clientes es el Gris con %d de Bicicleta\n\n",contadorGris);
        printf("-------------------------------------------------------------------------\n\n");

    }

}
