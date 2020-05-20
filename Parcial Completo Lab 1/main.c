#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "colores.h"
#include "bicicletas.h"
#include "servicios.h"
#include "validaciones.h"
#include "tipos.h"
#include "clientes.h"

#define TAMC 5
#define TAMB 5
#define TAMT 5

int main()
{
    eCliente clientes[TAMC] = {{01,"Roberto",'M',0},{02,"Juan",'M',0},{03,"Norma",'F',0},{04,"Adrian",'M',0},{05,"Josefina",'F',0}};
    eTipo tipos[4] = {{1000,"Rutera"},{1001,"Carrera"},{1002,"Mountain"},{1003,"BMX"}};
    eColor colores[5] = {{5000,"Gris"},{5001,"Negro"},{5002,"Blanco"},{5003,"Azul"},{5004,"Rojo"}};
    eServicio servicios[4] = {{20000,"Limpieza",250},{20001,"Parche",300},{20002,"Centrado",400},{20003,"Cadena",350}};
    eBicicleta bicicletas[TAMB];
    //eBicicleta bicicletas[TAMB] = {{1111,"Razor",5004,20,0,01},{2222,"Sese",5004,20,0,01},{3333,"fafa",5001,20,0,03},{4444,"Nene",5003,20,0,04}}
    eTrabajo trabajos [TAMT];

    char seguir = 's';
    int idTrabajo = 1;
    int contadorBicicleta = 0;

    iniciarBicicletas(bicicletas,TAMB);
    iniciarTrabajos(trabajos,TAMT);
    //iniciarClientes(clientes,TAMC); = Se inicializa en caso de querer utilizar alta cliente

    do
    {
        system("cls");
        switch(menu())
        {
        case 'A':
            altaBicicleta(clientes,TAMC,bicicletas,TAMB,&contadorBicicleta);
            break;
        case 'B':
            if(contadorBicicleta != 0)
            {
                modificarBicicleta(bicicletas,TAMB,tipos,TAMT,colores,5,clientes,TAMC);
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");
            }
            break;
        case 'C':
            if(contadorBicicleta != 0)
            {
                bajaBicicleta(trabajos,TAMT,bicicletas,TAMB,tipos,TAMT,colores,5,&contadorBicicleta,clientes,TAMC);
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");
            }
            break;
        case 'D':
            if(contadorBicicleta != 0)
            {
                ordenarBicicletas(bicicletas,TAMB);
                mostrarBicicletas(bicicletas,TAMB,tipos,TAMT,colores,5,clientes,TAMC);
                system("pause");
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");
            }
            break;
        case 'E':
            listarTipos();
            break;
        case 'F':
            listarColores();
            break;
        case 'G':
            listarServicios();
            break;
        case 'H':
            if(contadorBicicleta != 0)
            {
                altaTrabajo(&idTrabajo,bicicletas,TAMB,trabajos,TAMT,tipos,4,colores,5,clientes,TAMC);
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");

            }
            break;
        case 'I':
            if(contadorBicicleta != 0)
            {
                mostrarTrabajos(trabajos,TAMT,bicicletas,TAMB,tipos,4,colores,5,servicios,4);
                system("pause");
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");

            }
            break;
        case 'J':

              mostrarClientes(clientes,TAMC);
              system("pause");
              break;
        case 'K':
            if(contadorBicicleta != 0)
            {
            listarPorColor(bicicletas,TAMB,tipos,4,colores,5,clientes,TAMC);
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");

            }
            break;
        case 'L':
            if(contadorBicicleta != 0)
            {
            listarPorTipo(bicicletas,TAMB,tipos,4,colores,5,clientes,TAMC);
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");

            }
            break;

        case 'M':
            if(contadorBicicleta != 0)
            {
            mostrarMenorRodado(bicicletas,TAMB,tipos,4,colores,5,clientes,TAMC);
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");

            }
            break;
        case 'N':
            if(contadorBicicleta != 0)
            {
            mostrarSoloBMW(bicicletas,TAMB,tipos,4,colores,5,clientes,TAMC);
            mostrarSoloMountain(bicicletas,TAMB,tipos,4,colores,5,clientes,TAMC);
            mostrarSoloRutera(bicicletas,TAMB,tipos,4,colores,5,clientes,TAMC);
            mostrarSoloCarrera(bicicletas,TAMB,tipos,4,colores,5,clientes,TAMC);
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");

            }
            break;
        case 'O':
            if(contadorBicicleta != 0)
            {
            contarColorYTipo(bicicletas,TAMB,tipos,4,colores,5,clientes,TAMC);
            system("pause");
            break;
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");

            }
            break;
        case 'P':
            if(contadorBicicleta != 0)
            {
            colorMaximo(bicicletas,TAMB);
            system("pause");
            break;
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");

            }
            break;
        case 'Q':
            if(contadorBicicleta != 0)
            {
            seguir = 'n';
            printf("Gracias Vuelva Pronto!\n");
            system("pause");
            break;
            }
            else
            {
                printf("--------------------------------------------------------\n");
                printf("Debes dar de alta una Bicicleta para utilizar esta opcion\n");
                printf("--------------------------------------------------------\n");
                system("pause");

            }
            break;

        default:
            printf("Opcion elegida incorrecta,recuerde elegir en Mayuscula");
            system("pause");
            break;



        }











    }
    while(seguir == 's');





}
