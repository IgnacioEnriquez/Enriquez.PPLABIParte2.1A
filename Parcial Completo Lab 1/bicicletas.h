#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED


typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodados;
    int isEmpty;
    int idCliente;


} eBicicleta;

#include "tipos.h"
#include "trabajo.h"
#include "clientes.h"







int iniciarBicicletas(eBicicleta* list, int len);
int altaBicicleta(eCliente* clientes,int tamC,eBicicleta* list,int tam,int* contador);
int buscarLibre(eBicicleta* list,int tam);
int buscarIDBicicletas(eBicicleta* list,int tam,int id);
int menuRodados();
int mostrarBicicletas(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);
void mostrarBicicleta(eBicicleta x,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);
void elegirRodado (float* id,int* validacion);
int bajaBicicleta(eTrabajo* trabajos,int tamTR,eBicicleta* list,int tamB,eTipo* tipos,int tamT,eColor* colores,int tamC,int* contador,eCliente* clientes,int tamCL);
int menuModificacion();
int modificarBicicleta(eBicicleta* list,int tamB,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);
int ordenarBicicletas(eBicicleta* list, int tam);
void mostrarMenorRodado(eBicicleta* list, int tam,eTipo* tipos,int tamT,eColor* colores,int tamC,eCliente* clientes,int tamCL);

#endif // BICICLETAS_H_INCLUDED


