#include "Sucursal.h"
#include "Provincia.h"
#include "CasaMatriz.h"
#include "ListaSucursal.h"
#include "ListaProvincia.h"
#include "ListaCasaMatriz.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iomanip>
#ifndef ADMARCHIVOS_H_INCLUDED
#define ADMARCHIVOS_H_INCLUDED

#ifndef NULL
#define NULL      0
#endif

/**
PRE: Las listas de sucursal, provincia y casaMatriz deben haber sido creadas.
POST: Las listas quedan cargadas con los datos leidos del archivo de texto.
ATRIBUTOS:
listaSucursal: Lista sobre la cual se invoca la primitiva.
ListaProvincia: Lista sobre la cual se invoca la primitiva.
listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
RETORNO: No aplica.
*/
void cargarSucursales(ListaSucursal &listaSucursal,ListaProvincia &listaProvincia,ListaCasaMatriz &listaCasaMatriz);
/**
PRE: Las listas de sucursal, provincia y casaMatriz deben haber sido creadas.
POST: Menu interactivo de opciones para consultas a realizar por el usuario.
ATRIBUTOS:
listaSucursal: Lista sobre la cual se invoca la primitiva.
ListaProvincia: Lista sobre la cual se invoca la primitiva.
listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
RETORNO: No aplica.
*/
void menu(ListaSucursal &listaSucursal,ListaProvincia &listaProvincia,ListaCasaMatriz &listaCasaMatriz);
/**
PRE: La lista sucursal debe haber sido creada y cargada con cargarSucursales().
POST: Se obtiene la lista de sucursales cargadas en el sistema en el orden en que fueron leidas desde el archivo.
ATRIBUTOS:
listaSucursal: Lista sobre la cual se invoca la primitiva.
RETORNO: No aplica
*/
void obtenerSucursales(ListaSucursal &listaSucursal);
/**
PRE: La lista sucursal debe haber sido creada y cargada con cargarSucursales().
POST: Se obtiene el reporte  del ranking nacional de sucursales ordenadas por monto de facturacion.
ATRIBUTOS:
listaSucursal: Lista sobre la cual se invoca la primitiva.
RETORNO: No aplica.
*/
void rankingNacionalPorMontoFacturacion(ListaSucursal &listaSucursal);
/**
PRE: La lista sucursal y provincia deben haber sido creadas y cargadas con cargarSucursales().
POST: Se obtiene el reporte del ranking provincial de sucursales ordenadas por monto de facturacion total por provincia.
ATRIBUTOS:
listaSucursal: Lista sobre la cual se aplica la primitiva.
listaProvincia: Lista sobre la cual se aplica la primitiva.
RETORNO: No aplica.
*/
void rankingProvincialPorMontoFacturacion(ListaSucursal &listaSucursal,ListaProvincia &listaProvincia);
/**
PRE: La lista sucursal debe haber sido creada y cargada con cargarSucursales().
POST: Se obtiene el reporte del ranking nacional de sucursales ordenadas por cantidad total de articulos vendidos.
ATRIBUTOS:
listaSucursal: Lista sobre la cual se aplica la primitiva.
RETORNO: No aplica.
*/
void rankingNacionalPorCantArticulosVendidos(ListaSucursal &listaSucursal);
/**
PRE: La lista sucursal y provincia deben haber sido creadas y cargadas con cargarSucursales().
POST: Se obtiene el reporte del ranking provincial de sucursales ordenadas por cantidad total de articulos vendidos por provincia.
ATRIBUTOS:
listaSucursal: Lista sobre la cual se aplica la primitiva.
listaProvincia: Lista sobre la cual se aplica la primitiva.
RETORNO: No aplica.
*/
void rankingProvincialPorCantArticulosVendidos(ListaSucursal &listaSucursal, ListaProvincia &listaProvincia);
/**
PRE: La lista sucursal y casaMatriz deben haber sido creadas y cargadas con cargarSucursales().
POST: Se obtiene el ranking de surcusales ordenadas por rendimiento de cada casaMatriz(montoFacturacion/m2)
ATRIBUTOS:
listaSucursal: Lista sobre la cual se aplica la primitiva.
listaCasaMatriz: Lista sobre la cual se aplica la primitiva.
RETORNO: No aplica.
*/
void rankingRendimiento(ListaSucursal &listaSucursal,ListaCasaMatriz &listaCasaMatriz);
/**
PRE: La lista sucursal y provincia deben haber sido creadas y cargadas con cargarSucursales().
POST: Se setean los campos del monto de facturacion total  por cada provincia.
ATRIBUTOS:
listaSucursal: Lista sobre la cual se aplica la primitiva.
listaProvincia: Lista sobre la cual se aplica la primitiva.
RETORNO: No aplica
*/
void facturacionTotalPorProvincia(ListaSucursal &listaSucursal, ListaProvincia &listaProvincia);
/**
PRE: La lista sucursal y provincia deben haber sido creadas y cargadas con cargarSucursales().
POST: Se setean los campos de la cantidad total de articulos vendidos por cada provincia.
ATRIBUTOS:
listaSucursal: Lista sobre la cual se aplica la primitiva.
listaProvincia: Lista sobre la cual se aplica la primitiva.
RETORNO: No aplica
*/
void articulosTotalesVendidosPorProvincia(ListaSucursal &listaSucursal, ListaProvincia &listaProvincia);
/**
PRE: La lista sucursal y casaMatriz deben haber sido creadas y cargadas con cargarSucursales().
POST: Se setea los campos del rendimiento total por cada casa matriz.
ATRIBUTOS:
listaSucursal: Lista sobre la cual se aplica la primitiva.
listaCasaMatriz: Lista sobre la cual se aplica la primitiva.
RETORNO: No aplica.
*/
void rendimientoTotalPorCasaMatriz(ListaSucursal &listaSucursal, ListaCasaMatriz &listaCasaMatriz);
#endif // ADMARCHIVOS_H_INCLUDED
