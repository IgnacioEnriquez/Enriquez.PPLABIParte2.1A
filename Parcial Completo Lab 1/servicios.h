#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED


typedef struct
{
  int id;
  char descripcion[25];
  int precio;


} eServicio;
#include "trabajo.h"
#include "colores.h"
#include "bicicletas.h"
#include "validaciones.h"
#include "tipos.h"
#endif // SERVICIOS_H_INCLUDED

void listarServicios();
int menuServicios();
void elegirServicios(int* idServicio,int* validacion);
