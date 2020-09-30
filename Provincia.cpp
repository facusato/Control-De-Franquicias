#include "Provincia.h"
#include <iostream>
#include <string.h>

void crearProvincia(Provincia &provincia){
    provincia.idProvincia=0;
    strcpy(provincia.nombreProvincia,"");
    provincia.montoTotal=0;
    provincia.totalArticulosVendidos=0;
}

void eliminarProvincia(Provincia &provincia){
    provincia.idProvincia=0;
    strcpy(provincia.nombreProvincia,"");
    provincia.montoTotal=0;
    provincia.totalArticulosVendidos=0;
}

void setIdProvincia(Provincia &provincia, int idProvincia){
    provincia.idProvincia=idProvincia;
}

int getIdProvincia(Provincia &provincia){
    return provincia.idProvincia;
}

void setNombreProvincia(Provincia &provincia, char* nombreProvincia){
    strcpy(provincia.nombreProvincia,nombreProvincia);
}

char* getNombreProvincia(Provincia &provincia){
    return provincia.nombreProvincia;
}

void setMontoTotal(Provincia &provincia,float montoTotal){
    provincia.montoTotal=montoTotal;
}

float getMontoTotal(Provincia &provincia){
    return provincia.montoTotal;
}

void setTotalArticulosVendidos(Provincia &provincia, int totalArticulosVendidos){
    provincia.totalArticulosVendidos=totalArticulosVendidos;
}


float getTotalArticulosVendidos(Provincia &provincia){
    return provincia.totalArticulosVendidos;
}


