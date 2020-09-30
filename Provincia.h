#ifndef PROVINCIA_H_INCLUDED

typedef struct{
    int idProvincia;
    char nombreProvincia[15];
    float montoTotal;
    int totalArticulosVendidos;
}Provincia;
#define PROVINCIA_H_INCLUDED

/**

DEFINICION DEL TIPO DE DATO PARA MANEJO DE ATRIBUTOS:

idProvincia
nombreProvincia
montoTotal
totalArticulosVendidos

AXIOMAS:

idProvincia > 0

**/

/**
PRE: La instancia TDA (Provincia) no debe haberse creado pero no debe estar destruida.
POST: Deja la instancia del TDA (Provincia) listo para ser usado.
ATRIBUTOS:
provincia: Instancia sobre la cual se aplica la primitiva.
RETORNO: No aplica.
*/
void crearProvincia(Provincia &provincia);
/**
PRE: La instancia  TDA (Provincia) debe haberse creado pero no debe estar destruida.
POST: Elimina la intancia del TDA y ya no podra ser utilizada.
ATRIBUTOS:
provincia: Instancia sobre la cual se aplica la primitiva.
RETORNO: No aplica.
*/
void eliminarProvincia(Provincia &provincia);
/**
PRE: La intancia TDA(Provincia) debe haberse creado pero no debe estar destruida.
POST: La provincia queda seteada con el nuevo identificador.
ATRIBUTOS:
provincia: Instancia sobre la cual se aplica la primitiva.
idProvincia: Valor del identificador a asignar a la provincia.
RETORNO: No aplica.
*/
void setIdProvincia(Provincia &provincia, int idProvincia);
/**
PRE: La intancia TDA(Provincia) debe haberse creado pero no debe estar destruida.
POST: Devuelve el identificador de provincia.
ATRIBUTOS: provincia: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve el identificador de provincia.
*/
int getIdProvincia(Provincia &provincia);
/**
PRE: La intancia TDA(Provincia) debe haberse creado pero no debe estar destruida.
POST: La provincia queda seteada con el nombreProvincia.
ATRIBUTOS:
provincia: Instancia sobre la cual se aplica la primitiva.
nombreProvincia: Nombre de la provincia asignado.
RETORNO: No aplica.
*/
void setNombreProvincia(Provincia &provincia, char* nombreProvincia);
/**
PRE: La intancia TDA(Provincia) debe haberse creado pero no debe estar destruida.
POST: Devuelve el nombre de la provincia.
ATRIBUTOS:
provincia: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve el nombre de la provincia.
*/
char* getNombreProvincia(Provincia &provincia);
/**
PRE: La intancia TDA(Provincia) debe haberse creado pero no debe estar destruida.
POST:
    La provincia queda seteada con el monto total de facturacion.
ATRIBUTOS:
provincia: Instancia sobre la cual se aplica la primitiva.
montoTotal: monto total de facturacion de la provincia asignado.
RETORNO:No aplica.
*/
void setMontoTotal(Provincia &provincia, float montoTotal);
/**
PRE: La intancia TDA(Provincia) debe haberse creado pero no debe estar destruida.
POST: Devuelve el monto total de facturacion de la provincia.
ATRIBUTOS:
provincia: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve el monto total de facturacion de la provincia.
*/
float getMontoTotal(Provincia &provincia);
/**
PRE: La intancia TDA(Provincia) debe haberse creado pero no debe estar destruida.
POST: La provincia queda seteada con el monto total de articulos vendidos.
ATRIBUTOS:
provincia: Instancia sobre la cual se aplica la primitiva.
totalArticulosVendidos: monto total de articulos vendidos de la provincia asignado.
RETORNO: No aplica.
*/
void setTotalArticulosVendidos(Provincia &provincia, int totalArticulosVendidos);

/**
PRE: La intancia TDA(Provincia) debe haberse creado pero no debe estar destruida.
POST: Devuelve el monto total de articulos vendidos de la provincia.
ATRIBUTOS:
provincia: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve el monto total de articulos vendidos de la provincia.
*/
float getTotalArticulosVendidos(Provincia &provincia);

#endif // PROVINCIA_H_INCLUDED
