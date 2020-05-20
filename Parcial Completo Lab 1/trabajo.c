#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "trabajo.h"
#include "colores.h"
#include "bicicletas.h"
#include "servicios.h"
#include "validaciones.h"
#include "tipos.h"


int altaTrabajo(int* id,eBicicleta* list,int tamB,eTrabajo* trabajos,int tamTR,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{
    int retorno = -1;
    int validacion;
    int indice;
    int indiceT;
    char opcion;
    eTrabajo aux;


    indiceT = buscarLibreTrabajo(trabajos,tamTR);
    validacion = mostrarBicicletas(list,tamB,tipos,tamT,colores,tamC,clientes,tamCL);

    if(validacion != -1)
    {
        printf("--------------------------------------------------\n");
        validacion = utn_getEntero(&aux.idBicicleta,0,"Ingrese ID de la Bicicleta que desea asignar un trabajo : ","Error,El ID debe ser entero,reingrese datos\n",1,100000);

        if(validacion != -1)
        {
            indice = buscarIDBicicletas(list,tamB,aux.idBicicleta);

            if(indice != -1)
            {
                system("cls");
                printf("---------------------------------------");
                mostrarBicicleta(list[indice],tipos,tamT,colores,tamC,clientes,tamCL);
                printf("---------------------------------------\n");

                printf("Desea asigar un trabajo a esta Bicicleta? : ");
                scanf("%c",&opcion);

                if(opcion == 's' || opcion == 'S')
                {
                    elegirServicios(&aux.idServicio,&validacion);

                    if(validacion == 0)
                    {

                        validacion = ingresarFechaTrabajo(&aux.fecha.dia,&aux.fecha.mes,&aux.fecha.anio);

                        if(validacion == 0)
                        {
                            aux.id = *id;
                            *id =aux.id +1 ;
                            trabajos[indiceT] = aux;
                            trabajos[indiceT].isEmpty = 0;
                            system("cls");
                            printf("--------------------------------------------------\n");
                            printf("El trabajo fue correctamente asignado\n");
                            printf("--------------------------------------------------\n");
                            system("pause");



                        }


                    }





                }
                else if(opcion == 'n'||opcion == 'N')
                {

                    system("cls");
                    printf("--------------------------------------------------\n");
                    printf("No se le asignara un trabajo a esta Bicicleta\n") ;
                    printf("--------------------------------------------------\n");
                    system("pause");

                }
                else
                {

                    system("cls");
                    printf("--------------------------------------------------\n");
                    printf("Opcion incorrecta,reingrese datos\n") ;
                    printf("--------------------------------------------------\n");
                    system("pause");

                }



            }
            else
            {
                system("cls");
                printf("--------------------------------------------------\n");
                printf("No se encuentra una Bicicleta con ese ID\n") ;
                printf("--------------------------------------------------\n");
                system("pause");

            }


        }


    }
    else
    {
        printf("-------------------------------------------------------------");
        printf("\nEs necesario ingresar una Bicicleta para asignar un trabajo\n");
        printf("-------------------------------------------------------------\n");
        system("pause");


    }










    return retorno;
}
int buscarLibreTrabajo(eTrabajo* list,int tam)
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
int iniciarTrabajos(eTrabajo* list, int len)
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
int ingresarFechaTrabajo(int* dia,int *mes,int* anio)
{
    int validacion;
    int retorno = -1;
    int auxDia;
    int auxMes;
    int auxAnio;

    validacion = utn_getEntero(&auxDia,0,"Ingrese dia que se solicito el servicio : ","Error,dato mal ingresado,reingrese datos",1,31);

    if(validacion != -1)
    {
        validacion = utn_getEntero(&auxMes,0,"Ingrese mes que se solicito el servicio : ","Error,dato mal ingresado,regrese datos",1,12);


        if(validacion != -1)
        {
            validacion = utn_getEntero(&auxAnio,0,"Ingrese Anio que se solicito el servicio : ","Error,dato mal ingresado,regrese datos",1900,2020);

            if(validacion != -1)
            {
                *dia = auxDia;
                *mes = auxMes;
                *anio = auxAnio;
                retorno = 0;


            }
        }





    }

    return retorno;
}
void mostrarTrabajo(eTrabajo trabajo,eBicicleta* bicicletas,int tamB,eTipo* tipos,int tamT,eColor* colores,int tamC, eServicio servicios[], int tamS)
{
    char descripcionTipo[20];
    char descripcionColor[20];
    char descripcionServicio[20];
    int precioServicio;
    int indice;

    indice = buscarIDBicicletas(bicicletas,tamB,trabajo.idBicicleta);

    cargarDescripServicio(descripcionServicio,trabajo.idServicio,servicios,tamS);
    cargarPrecioServicio(&precioServicio,trabajo.idServicio,servicios,tamS);
    cargarDescripTipos(descripcionTipo,bicicletas[indice].idTipo,tipos,tamT);
    cargarDescripColores(descripcionColor,bicicletas[indice].idColor,colores,tamC);


    printf("\n  %d %s %.0d/%.0d/%4d %d$ %d %s %s %s\n",trabajo.id,descripcionServicio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio,precioServicio,bicicletas[indice].id,bicicletas[indice].marca,descripcionTipo,descripcionColor);

}
int cargarDescripServicio(char descripcion[],int idServicio, eServicio servicios[], int tamS)
{
    int isOk = 0;

    for(int i = 0; i < tamS; i++)
    {
        if(servicios[i].id == idServicio) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
        {
            strcpy(descripcion, servicios[i].descripcion); //copio a descripcion la descripcion que tengo en ese sector
            isOk = 1; //exito
            break;
        }
    }

    return isOk;
}
int cargarPrecioServicio(int* precio,int idServicio, eServicio servicios[], int tamS)
{
    int isOk = 0;

    for(int i = 0; i < tamS; i++)
    {
        if(servicios[i].id == idServicio) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
        {
            *precio = servicios[i].precio; //copio a descripcion la descripcion que tengo en ese sector
            isOk = 1; //exito
            break;
        }
    }

    return isOk;

}
void mostrarTrabajos(eTrabajo* trabajos,int tamTR,eBicicleta* bicicletas,int tamB,eTipo* tipos,int tamT,eColor* colores,int tamC, eServicio servicios[], int tamS)
{
    int flag = 0;

    system("cls");
    printf("\n********** Lista de Trabajos************\n");
    for(int i = 0; i < tamTR ; i++)
    {

        if(trabajos[i].isEmpty == 0 && bicicletas[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i],bicicletas,tamB,tipos,tamT,colores,tamC,servicios,tamS);
            flag = 1;
        }

    }

    if(flag == 0)
    {
        printf("\nNo hay Trabajos para Mostrar\n\n");
    }

}
void eliminarTrabajo(eTrabajo* trabajos,int tamTR,eBicicleta* bicicletas,int idBicicleta)
{
    for(int i = 0; i < tamTR; i++ )
    {
        if(trabajos[i].idBicicleta == idBicicleta)
        {
            trabajos[i].isEmpty = 1;


        }
    }

}

