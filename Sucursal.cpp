#include "Sucursal.h"
#include <cctype>
#include <string.h>


void crearSucursal(Sucursal &sucursal){
    sucursal.codSucursal=0;
    strncpy(sucursal.nombreProvincia, "", 15);
    sucursal.cantArticulosVendidos=0;
    sucursal.montoFacturacion=0;
    sucursal.m2=0;
    sucursal.casaMatriz=0;

}

void eliminarSucursal(Sucursal &sucursal){
    sucursal.codSucursal=0;
    strncpy(sucursal.nombreProvincia, "", 15);
    sucursal.cantArticulosVendidos=0;
    sucursal.montoFacturacion=0;
    sucursal.m2=0;
    sucursal.casaMatriz=0;
}

void setCodSucursal(Sucursal &sucursal,int codSucursal){
    sucursal.codSucursal=codSucursal;
}

int getCodSucursal(Sucursal &sucursal){
    return sucursal.codSucursal;
}

void setNombreProvincia(Sucursal &sucursal,char* nombreProvincia){
    strcpy(sucursal.nombreProvincia,nombreProvincia);
}

char* getNombreProvincia(Sucursal &sucursal){
    return sucursal.nombreProvincia;
}

void setCantArticulosVendidos(Sucursal &sucursal,int cantArticulosVendidos){
    sucursal.cantArticulosVendidos=cantArticulosVendidos;
}

int getCantArticulosVendidos(Sucursal &sucursal){
    return sucursal.cantArticulosVendidos;
}

void setMontoFacturacion(Sucursal &sucursal,float montoFacturacion){
    sucursal.montoFacturacion=montoFacturacion;
}

float getMontoFacturacion(Sucursal &sucursal){
    return sucursal.montoFacturacion;
}

void setCasaMatriz(Sucursal &sucursal,int casaMatriz){
    sucursal.casaMatriz=casaMatriz;
}

int getCasaMatriz(Sucursal &sucursal){
    return sucursal.casaMatriz;
}

void setM2(Sucursal &sucursal,int m2){
    sucursal.m2=m2;
}

int getM2(Sucursal &sucursal){
    return sucursal.m2;
}
