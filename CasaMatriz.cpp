#include "CasaMatriz.h"



void crearCasaMatriz(CasaMatriz &casaMatriz){
    casaMatriz.idCasaMatriz=0;
    casaMatriz.rendimiento=0;
}

void eliminarCasaMatriz(CasaMatriz &casaMatriz){
    casaMatriz.idCasaMatriz=0;
    casaMatriz.rendimiento=0;
}

void setIdCasaMatriz(CasaMatriz &casaMatriz, int idCasaMatriz){
    casaMatriz.idCasaMatriz=idCasaMatriz;
}

int getIdCasaMatriz(CasaMatriz &casaMatriz){
    return casaMatriz.idCasaMatriz;
}

void setRendimiento(CasaMatriz &casaMatriz,float rendimiento){
   casaMatriz.rendimiento=rendimiento;
}


float getRendimiento(CasaMatriz &casaMatriz){
    return casaMatriz.rendimiento;
}
