#ifndef CASAMATRIZ_H_INCLUDED

typedef struct{
  int idCasaMatriz;
  float rendimiento;
}CasaMatriz;


#define CASAMATRIZ_H_INCLUDED
/**

DEFINICION DEL TIPO DE DATO PARA MANEJO DE ATRIBUTOS:

idCasaMatriz
rendimiento

AXIOMAS:

idCasaMatriz > 0

**/

/**
PRE: La instancia TDA (CasaMatriz) no debe haberse creado pero no debe estar destruida.
POST: Deja la instancia del TDA (CasaMatriz) listo para ser usado.
ATRIBUTOS:
casaMatriz: Instancia sobre la cual se aplica la primitiva.
RETORNO: No aplica.
*/
void crearCasaMatriz(CasaMatriz &casaMatriz);
/**
PRE: La instancia  TDA (CasaMatriz) debe haberse creado pero no debe estar destruida.
POST: Elimina la intancia del TDA y ya no podra ser utilizada.
ATRIBUTOS:
provincia: Instancia sobre la cual se aplica la primitiva.
RETORNO: No aplica.
*/
void eliminarCasaMatriz(CasaMatriz &casaMatriz);
/**
PRE: La intancia TDA(CasaMatriz) debe haberse creado pero no debe estar destruida.
POST: La casaMatriz queda seteada con el nuevo identificador.
ATRIBUTOS:
casaMatriz: Instancia sobre la cual se aplica la primitiva.
idCasaMatriz: Valor del identificador a asignar a la casaMatriz.
RETORNO: No aplica.
*/
void setIdCasaMatriz(CasaMatriz &casaMatriz, int idCasaMatriz);
/**
PRE: La intancia TDA(CasaMatriz) debe haberse creado pero no debe estar destruida.
POST: Devuelve el identificador de casaMatriz.
ATRIBUTOS:
casaMatriz: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve el identificador de casaMatriz.
*/
int getIdCasaMatriz(CasaMatriz &casaMatriz);
/**
PRE: La intancia TDA(CasaMatriz) debe haberse creado pero no debe estar destruida.
POST: La casa matriz queda seteada con el rendimiento.
ATRIBUTOS:
casaMatriz: Instancia sobre la cual se aplica la primitiva.
rendimiento: Rendimiento de la casaMatriz asignado.
RETORNO: No aplica.
*/
void setRendimiento(CasaMatriz &casaMatriz,float rendimiento);

/**
PRE: La intancia TDA(CasaMatriz) debe haberse creado pero no debe estar destruida.
POST: Devuelve el rendimiento de la casaMatriz.
ATRIBUTOS:
casaMatriz: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve el rendimiento de la casaMatriz.
*/
float getRendimiento(CasaMatriz &casaMatriz);







#endif // CASAMATRIZ_H_INCLUDED
