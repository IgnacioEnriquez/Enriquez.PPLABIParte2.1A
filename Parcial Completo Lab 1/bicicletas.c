#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "colores.h"
#include "bicicletas.h"
#include "servicios.h"
#include "validaciones.h"
#include "tipos.h"
#include "clientes.h"
#include "string.h"

int altaBicicleta(eCliente* clientes,int tamC,eBicicleta* list,int tam,int* contador)
{
    int retorno = -1;
    int indice;
    int indiceC;
    int validacion;
    eBicicleta aux;
    eCliente auxC;

    mostrarClientes(clientes,tamC);

    validacion = utn_getEntero(&auxC.id,0,"Ingrese ID del cliente que le quiere asignar una Bicicleta : ","Error,debe ingresar ID entero,reingrese datos\n",1,10000);

    if(validacion != -1)
    {

        indiceC = buscarIDClientes(clientes,tamC,auxC.id); //Valido que el cliente exista

        if(indiceC != -1)
        {

            indice = buscarLibre(list,tam); //Busca espacio libre
            system("cls");

            if(indice == -1)
            {
                printf("----------------------------------\n");
                printf("El sistema esta completo\n");
                printf("----------------------------------\n");
                system("pause");


            }
            else
            {
                printf("----------------------------------\n");
                validacion = utn_getEntero(&aux.id,0,"Ingrese ID de la nueva bicicleta : ","Error,debe ingresar un ID entero,reingrese datos\n",1,100000); //validacion que sea int

                if(validacion == 0)
                {

                    validacion = buscarIDBicicletas(list,tam,aux.id); //verifico que el id no exista ya

                    if(validacion == -1)
                    {
                        printf("----------------------------------\n");
                        validacion = utn_getCadena(aux.marca,20,0,"Ingrese Marca de la nueva bicicleta : ","Error,debe ingresar una Marca Correcta,reingrese datos\n"); //valido que sea un

                        if(validacion == 0)
                        {

                            elegirTipo(&aux.idTipo,&validacion);

                        }

                        if(validacion == 0)
                        {
                            elegirColor(&aux.idColor,&validacion);


                            if(validacion == 0)
                            {
                                elegirRodado (&aux.rodados,&validacion);


                                if(validacion == 0)
                                {
                                    list[indice] = aux;
                                    list[indice].isEmpty = 0;
                                    list[indice].idCliente = auxC.id;
                                    retorno = 0;
                                    *contador = *contador + 1;
                                    system("cls");
                                    printf("-------------------------------------\n");
                                    printf("Bicicleta ingresada correctamente\n");
                                    printf("-------------------------------------\n\n");
                                    system("pause");

                                }


                            }

                        }

                    }
                    else
                    {
                        printf("Error : Ya existe una bicicleta con ese ID,Reingrese datos\n\n");
                        system("pause");

                    }
                }

            }
        }
        else
        {

          printf("Error : No existe un cliente con ese ID,Reingrese datos\n\n");
          system("pause");



        }
    }

    return retorno;
}
int iniciarBicicletas(eBicicleta* list, int len)
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
int buscarLibre(eBicicleta* list,int tam)
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
int buscarIDBicicletas(eBicicleta* list,int tam,int id)
{
    int indice = -1;

    for(int i = 0; i <tam; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            break;

        }
    }

    return indice;

}
int menuRodados()
{
    int opcion;

    printf("-------------- Menu de Rodados --------------\n\n");
    printf("              1 - 20\n\n");
    printf("              2 - 26\n\n");
    printf("              3 - 27,5\n\n");
    printf("              4 - 29\n\n");
    printf("---------------------------------------------\n\n");
    printf("Ingresa una opcion : ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
void mostrarBicicleta(eBicicleta x,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{
    char descripcionTipo[20];
    char descripcionColor[20];
    char nombreCliente[20];
    char sexoCliente;

    cargarDescripTipos(descripcionTipo,x.idTipo,tipos,tamT);
    cargarDescripColores(descripcionColor,x.idColor,colores,tamC);
    cargarDescripClientes(nombreCliente,&sexoCliente,x.idCliente,clientes,tamCL);

    printf("\n%d          %10s   %c     %d    %6s      %5s      %.2f    %s \n",x.idCliente,nombreCliente,sexoCliente,x.id,descripcionColor,x.marca,x.rodados,descripcionTipo);

}

int mostrarBicicletas(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{

    int flag = 0;
    int retorno = -1;

    system("cls");
    printf("\n-------------- Lista de Bicicletas --------------\n");
    printf("IDCLIENTE      NOMBRE      SEXO     COLOR       MARCA      RODADO     TIPO\n");
    for(int i = 0; i < tam ; i++)
    {

        if(list[i].isEmpty == 0)
        {
            mostrarBicicleta(list[i],tipos,tamT,colores,tamC,clientes,tamCL);
            retorno = 0;
            flag = 1;
        }

    }

    if(flag == 0)
    {
        printf("----------------------------------\n");
        printf("\nNo hay Bicicletas para Mostrar\n\n");
        printf("----------------------------------\n");
    }

    return retorno;

}
void elegirRodado (float* id,int* validacion)
{
    system("cls");
    switch(menuRodados())
    {
    case 1:
        *id = 20;
        *validacion = 0;
        break;
    case 2:
        *id = 26;
        *validacion = 0;
        break;

    case 3:
        *id = 27.5;
        *validacion = 0;
        break;
    case 4:
        *id = 29;
        *validacion = 0;
        break;

    default:
        system("cls");
        printf("--------------------------------------------------\n");
        printf("Error,el rodado de bicicleta es incorrecto,reingrese datos\n");
        printf("--------------------------------------------------\n");
        system("pause");
        *validacion = -1;
        break;


    }
}
int bajaBicicleta(eTrabajo* trabajos,int tamTR,eBicicleta* list,int tamB,eTipo* tipos,int tamT,eColor* colores,int tamC,int* contador,eCliente* clientes,int tamCL)
{
    int retorno = -1;
    int validacion;
    int indice;
    char opcion;
    eBicicleta aux;
    mostrarBicicletas(list,tamB,tipos,tamT,colores,5,clientes,tamCL);


    printf("--------------------------------------------------\n");
    validacion = utn_getEntero(&aux.id,0,"Ingrese ID de la Bicicleta que desea eliminar : ","Error,debe ingresar un ID entero,reingrese datos\n",0,100000);

    if(validacion != -1)
    {

        indice = buscarIDBicicletas(list,tamB,aux.id);

        if(indice != -1)
        {
            system("cls");
            printf("--------------------------------------------------");
            mostrarBicicleta(list[indice],tipos,tamT,colores,tamC,clientes,tamCL);
            printf("--------------------------------------------------\n");
            printf("Desea eliminar esta Bicicleta? : ");
            scanf("%c",&opcion);

            if(opcion == 's' || opcion == 'S')
            {


                list[indice].isEmpty = 1;
                *contador = *contador - 1;
                eliminarTrabajo(trabajos,tamTR,list,list[indice].id);
                system("cls");
                printf("--------------------------------------------------\n");
                printf("La bicicleta fue eliminada correctamente\n");
                printf("--------------------------------------------------\n");
                system("pause");

            }
            else if(opcion == 'n' || opcion == 'N')
            {

                system("cls");
                printf("--------------------------------------------------\n");
                printf("La bicicleta no fue eliminada\n");
                printf("--------------------------------------------------\n");
                system("pause");


            }
            else
            {
                system("cls");
                printf("--------------------------------------------------\n");
                printf("Opcion elegida incorrecta,reingrese datos\n");
                printf("--------------------------------------------------\n");
                system("pause");
            }

        }
        else
        {
            system("cls");
            printf("--------------------------------------------------\n");
            printf("Ninguna Bicicleta tiene el ID ingresado\n");
            printf("--------------------------------------------------\n");
            system("pause");

        }


    }

    return retorno;
}
int modificarBicicleta(eBicicleta* list,int tamB,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{
    int retorno = -1;
    int validacion;
    int indice;
    char opcion;
    char seguir = 's';
    eBicicleta aux;

    system("cls");
    mostrarBicicletas(list,tamB,tipos,tamT,colores,5,clientes,tamCL);

    printf("--------------------------------------------------\n");
    validacion = utn_getEntero(&aux.id,0,"Ingrese ID de la Bicicleta que desea modificar : ","Error,debe ingresar un ID entero,reingrese datos\n",0,100000);

    if(validacion != -1)
    {


        indice = buscarIDBicicletas(list,tamB,aux.id);

        if(indice != -1)
        {
            system("cls");
            printf("--------------------------------------------------");
            mostrarBicicleta(list[indice],tipos,tamT,colores,tamC,clientes,tamCL);
            printf("--------------------------------------------------\n");
            printf("Desea modificar  esta Bicicleta? S/N : ");
            scanf("%c",&opcion);

            if(opcion == 's' || opcion == 'S')
            {
                system("cls");
                do
                {
                    system("cls");
                    switch(menuModificacion())
                    {
                    case 1:
                        elegirTipo(&aux.idTipo,&validacion);

                        if(validacion != -1)
                        {

                            list[indice].idTipo = aux.idTipo;
                            system("cls");
                            printf("--------------------------------------------------\n");
                            printf("Tipo de Bicicleta cambiado correctamente\n");
                            printf("--------------------------------------------------\n");
                            system("pause");

                            break;

                        }

                        break;
                    case 2:

                        elegirRodado(&aux.rodados,&validacion);

                        if(validacion != -1)
                        {

                            list[indice].rodados = aux.rodados;
                            system("cls");
                            printf("--------------------------------------------------\n");
                            printf("Tipo de Rodado cambiado correctamente");
                            printf("--------------------------------------------------\n");
                            system("pause");
                            break;

                        }
                        break;

                    case 3:
                        seguir = 'n';
                        break;
                    default:
                        break;







                    }
                }
                while(seguir == 's');








            }
            else if(opcion == 'n' || opcion == 'N')
            {

                system("cls");
                printf("--------------------------------------------------\n");
                printf("La bicicleta no fue modificada\n");
                printf("--------------------------------------------------\n");
                system("pause");


            }
            else
            {
                system("cls");
                printf("--------------------------------------------------\n");
                printf("Opcion elegida incorrecta,reingrese datos\n");
                printf("--------------------------------------------------\n");
                system("pause");
            }

        }
        else
        {
            system("cls");
            printf("--------------------------------------------------\n");
            printf("Ninguna Bicicleta tiene el ID ingresado\n");
            printf("--------------------------------------------------\n");
            system("pause");

        }




    }

    return retorno;
}
int menuModificacion()
{
    int opcion;

    printf("---------------- Menu de Modificaciones ----------------\n\n");
    printf("              1 - Modificar Tipo \n\n");
    printf("              2 - Modificar Rodado\n\n");
    printf("              3 - Salir \n\n");
    printf("--------------------------------------------------------\n\n");
    printf("Ingresa una opcion : ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
int ordenarBicicletas(eBicicleta* list, int tam)
{
    eBicicleta aux;
    int retorno = -1;

    if(list != NULL)
    {

        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i+1; j < tam ; j++)
            {
                if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {

                    if(list[i].idTipo > list[j].idTipo)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;

                    }
                    if(list[i].idTipo == list[j].idTipo && list[i].rodados > list[j].rodados )
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }


            }
        }

        retorno = 0;
    }

    return retorno;

}
void mostrarMenorRodado(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL)
{
    float menorRodado;
    int flag = 0;

    system("cls");
    printf("------------- Bicicletas con Menor Rodado -------------\n");
    for(int i = 0;i < tam;i++)
    {
        if(list[i].isEmpty == 0)
        {
        if(list[i].rodados <= menorRodado || flag == 0)
        {
          menorRodado = list[i].rodados;
          flag = 1;
        }

        }

    }
    for(int i = 0;i <tam;i++)
    {
        if(list[i].rodados == menorRodado)
        {
            mostrarBicicleta(list[i],tipos,tamT,colores,tamC,clientes,tamCL);

        }


    }


    system("pause");

}
