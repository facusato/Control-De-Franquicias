#ifndef SUCURSAL_H_INCLUDED

typedef struct{
    int codSucursal;
    char nombreProvincia[20];
    int cantArticulosVendidos;
    float montoFacturacion;
    int m2;
    int casaMatriz;
}Sucursal;

#define SUCURSAL_H_INCLUDED

/**
PRE: La instancia del TDA (Sucursal) no debe haberse creado (crear) ni destruido (destruir) con anterioridad.
POST: Deja la instancia del TDA (Sucursal) listo para ser usado.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
RETORNO: No aplica.
*/
void crearSucursal(Sucursal &sucursal);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (destruir).
POST: Destruye la instancia del TDA y ya no podrá ser utilizada.
ATRIBUTOS: Sucursal: instancia sobre la cual se aplica la primitiva.
RETORNO: No aplica.
*/
void eliminarSucursal(Sucursal &sucursal);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: La Sucursal queda seteada con el codigo de sucursal.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
codSucursal: Valor del codigo de sucursal a asignar a la sucursal.
RETORNO: No aplica.
*/
void setCodSucursal(Sucursal &sucursal,int codSucursal);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: Devuelve el codigo de sucursal de la sucursal.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve el codigo de la sucursal.
*/
int getCodSucursal(Sucursal &sucursal);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: La Sucursal queda seteada con la provincia.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
nombreProvincia: Nombre de la provincia a asignar en la sucursal.
RETORNO:No aplica.
*/

void setNombreProvincia(Sucursal &sucursal,char* nombreProvincia);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: Devuelve la provincia de la sucursal.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve el nombre de la provincia de la sucursal.
*/
char* getNombreProvincia(Sucursal &sucursal);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: La Sucursal queda seteada con la cantidad de articulos vendidos.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
cantArticulosVendidos: Cantidad de articulos vendidos a asignar en la sucursal.
RETORNO: No aplica.
*/
void setCantArticulosVendidos(Sucursal &sucursal,int cantArticulosVendidos);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: Devuelve la cantidad de articulos vendidos de la sucursal.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve la cantidad de articulos vendidos de la sucursal.
*/
int getCantArticulosVendidos(Sucursal &sucursal);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: La Sucursal queda seteada con el monto de facturacion.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
montoFacturacion: Monto de facturacion a asignar en la sucursal.
RETORNO: No aplica.
*/
void setMontoFacturacion(Sucursal &sucursal,float montoFacturacion);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: Devuelve el monto de facturacion de la sucursal.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve el monto de facturacion de la sucursal.
*/
float getMontoFacturacion(Sucursal &sucursal);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: La Sucursal queda seteada con la casa matriz a la que pertenece.
ATRIBUTOS:
Sucursal: instancia sobre la cual se aplica la primitiva.
casaMatriz: Casa matriz a asignar en la sucursal.
RETORNO: No aplica.
*/
void setCasaMatriz(Sucursal &sucursal,int casaMatriz);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: Devuelve la casa matriz de la sucursal.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve la casa matriz de la sucursal.
*/
int getCasaMatriz(Sucursal &sucursal);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: La Sucursal queda seteada con los metros cuadrados que posee.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
m2: Metros cuadrados a asignar en la sucursal.
RETORNO: No aplica.
*/
void setM2(Sucursal &sucursal,int cm2);
/**
PRE: La instancia del TDA (Sucursal) debe haberse creado (crear) pero no debe estar destruida (eliminar).
POST: Devuelve la cantidad de m2 de la sucursal.
ATRIBUTOS:
Sucursal: Instancia sobre la cual se aplica la primitiva.
RETORNO: Devuelve la cantidad de m2 de la sucursal.
*/
int getM2(Sucursal &sucursal);


#endif // SUCURSAL_H_INCLUDED
