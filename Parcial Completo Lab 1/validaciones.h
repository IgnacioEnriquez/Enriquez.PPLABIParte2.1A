#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED




#include "trabajo.h"
#include "colores.h"
#include "bicicletas.h"
#include "servicios.h"
#include "tipos.h"
#endif // VALIDACIONES_H_INCLUDED

int menu();
int isFloat(char* pAux);
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);
int getFloat(float*pAux);
int isInt(char *pAux);
int getInt(int* pAux);
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);
int getCadena(char* pAux, int limit);
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);
