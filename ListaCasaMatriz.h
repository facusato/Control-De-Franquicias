#include "CasaMatriz.h"
#include "ListaSucursal.h"
#include <iomanip>
#include <cstring>
#include <iostream>

#ifndef LISTACASAMATRIZ_H_INCLUDED
#define LISTACASAMATRIZ_H_INCLUDED

/******************************************************************************/
/** Definiciones de Tipos de Datos */
/*--------------------------------*/

/** tipo enumerado para realizar comparaciones */
enum ResultadoComparacionCasaMatriz {
    CMAYOR,
    CIGUAL,
    CMENOR
};
/** Tipo de Informacion que esta contenida en los Nodos de la
   Lista, identificada como Dato. */
typedef CasaMatriz DatoCasaMatriz;

/** Tipo de Estructura de los Nodos de la Lista. */
struct NodoListaCasaMatriz {
    DatoCasaMatriz dato; // dato almacenado
    NodoListaCasaMatriz* sgte; // puntero al siguiente
};

/** Tipo de Puntero a los Nodos de la Lista, el cual se usa para recorrer
   la Lista y acceder a sus Datos. */
typedef NodoListaCasaMatriz* PtrNodoListaCasaMatriz;


/** Tipo de Estructura de la Lista */
struct ListaCasaMatriz{
    PtrNodoListaCasaMatriz primeroCasaMatriz;      // puntero al primer nodo de la lista
};


/******************************************************************************/
/** Definicion de Primitivas */
/*--------------------------*/

/**
  PRE: La lista no debe haber sido creada.
  POST: Lista queda creada y preparada para ser usada.
  ATRIBUTOS:
  listaCasaMatriz: Estructura de datos a ser creado.
*/
void crearListaCasaMatriz(ListaCasaMatriz &listaCasaMatriz);

/*----------------------------------------------------------------------------*/
/**
  PRE : Lista Creada con crearLista().
  POST: Devuelve true si lista esta vacia, sino devuelve false.
  ATRIBUTOS:
  listaCasaMatriz : Lista sobre la cual se invoca la primitiva.
*/
bool listaVaciaCasaMatriz(ListaCasaMatriz &listaCasaMatriz);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista Creada con crearLista().
  POST: Devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  RETORNO: Representación del fin de la lista.
*/
PtrNodoListaCasaMatriz finCasaMatriz();

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista Creada con crearLista().
  POST: Devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  RETORNO: Puntero al primer nodo.
*/
PtrNodoListaCasaMatriz primeroCasaMatriz(ListaCasaMatriz &listaCasaMatriz);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista Creada con crearLista().
  POST: Devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  prtNodo: Puntero al nodo a partir del cual se requiere el siguiente.
  RETORNO: Puntero al nodo siguiente.
*/
PtrNodoListaCasaMatriz siguienteCasaMatriz(ListaCasaMatriz &listaCasaMatriz, PtrNodoListaCasaMatriz ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista Creada con crearLista().
        ptrNodo es un puntero a un nodo de lista.
  POST: Devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        ptrNodo apuntaba al primero o si lista esta vacia.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  prtNodo: Puntero al nodo a partir del cual se requiere el anterior.
  RETORNO: Puntero al nodo anterior.
*/
PtrNodoListaCasaMatriz anteriorCasaMatriz(ListaCasaMatriz &listaCasaMatriz, PtrNodoListaCasaMatriz ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.
  ATRIBUTOS:
  listaCasaMatriz : Lista sobre la cual se invoca la primitiva.
  RETORNO: Puntero al último nodo.
*/
PtrNodoListaCasaMatriz ultimoCasaMatriz(ListaCasaMatriz &listaCasaMatriz);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.
  ATRIBUTOS:
  listaCasaMatriz : Lista sobre la cual se invoca la primitiva.
  dato : Elemento a adicionar al principio de la lista.
  RETORNO: Puntero al nodo adicionado.
*/
PtrNodoListaCasaMatriz adicionarPrincipioCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Agrega un nodo despues del apuntado por ptrNodo con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vacía agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a fin() no inserta
        nada y devuelve fin().
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a adicionar.
  ptrNodo : Puntero al nodo después del cual se quiere adicionar el dato.
  RETORNO: Puntero al nodo adicionado.
*/
PtrNodoListaCasaMatriz adicionarDespuesCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato, PtrNodoListaCasaMatriz ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a adicionar al final de la lista.
  RETORNO: Puntero al nodo adicionado.
*/
PtrNodoListaCasaMatriz adicionarFinalCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  post: Agrega un nodo con el dato proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve fin(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a adicionar.
  ptrNodo: Puntero al nodo antes del cual se quiere adicionar el dato.
  RETORNO: Puntero al nodo adicionado.
*/
PtrNodoListaCasaMatriz adicionarAntesCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato, PtrNodoListaCasaMatriz ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista(), no vacia. ptrNodo es distinto de fin().
  POST: Coloca el dato proporcionado en el nodo apuntado por ptrNodo.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  dato : elemento a colocar.
  ptrNodo : Puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDatoCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz &dato, PtrNodoListaCasaMatriz ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE : Lista creada con crearLista(), no vacia. ptrNodo es distinto de fin().
  POST: Devuelve el dato del nodo apuntado por ptrNodo.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  dato: Elemento obtenido.
  ptrNodo: Puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDatoCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz &dato, PtrNodoListaCasaMatriz ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a fin().
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  ptrNodo: Puntero al nodo que se desea eliminar.
*/
void eliminarNodoCasaMatriz(ListaCasaMatriz &listaCasaMatriz, PtrNodoListaCasaMatriz ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Si la lista no esta vacia, elimina su nodo primero, sino no realiza
        accion alguna.
  ATRIBUTOS:
  listaCasaMatriz : Lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimeroCasaMatriz(ListaCasaMatriz &listaCasaMatriz);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Si la lista no esta vacia elimina su nodo ultimo,
        sino no realiza accion.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimoCasaMatriz(ListaCasaMatriz &listaCasaMatriz);

/*----------------------------------------------------------------------------*/
/**
  PRE: lista creada con crearLista().
  POST: Elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  listaCasaMatriz : Lista sobre la cual se invoca la primitiva.
*/
void eliminarListaCasaMatriz(ListaCasaMatriz &listaCasaMatriz);


/******************************************************************************/
/** Definición de Operaciones Adicionales */
/*---------------------------------------*/

/**
  PRE: Lista fue creada con crearLista().
  POST: Si el dato se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el dato no se encuentra en la lista devuelve fin().
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a localizar.
  RETORNO: Puntero al nodo localizado o fin().
*/
PtrNodoListaCasaMatriz localizarDatoCasaMatriz(ListaCasaMatriz &listaCasaMatriz,DatoCasaMatriz dato);
/**
  PRE: Lista fue creada con crearLista().
  POST: Si el dato se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el dato no se encuentra en la lista devuelve fin().
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a localizar.
  RETORNO: Puntero al nodo localizado o fin().
*/
PtrNodoListaCasaMatriz localizarDatoCasaMatriz2(ListaCasaMatriz &listaCasaMatriz,DatoCasaMatriz dato);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista fue creada con crearLista() y cargada con datos ordenados de
        menor a mayor respecto del sentido progresivo.
  POST: agrega a la lista el dato manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  dato : Elemento a insertar.
  RETORNO: Puntero al nodo insertado.
*/
PtrNodoListaCasaMatriz insertarDatoCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato);
/**
  PRE: Lista fue creada con crearLista() y cargada con datos ordenados de
        menor a mayor respecto del sentido progresivo.
  POST: Agrega a la lista el dato manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a insertar.
  RETORNO: Puntero al nodo insertado.
*/
PtrNodoListaCasaMatriz insertarDatoCasaMatriz2(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato);

/*----------------------------------------------------------------------------*/
/**
  PRE: La lista fue creada con crearLista().
  POST: Elimina el dato de la lista, si el mismo se encuentra.

  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a eliminar.
*/
void eliminarDatoCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato);

/*----------------------------------------------------------------------------*/
/**
  PRE: La lista fue creada con crearLista().
  POST: Elimina el dato de la lista, si el mismo se encuentra.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a eliminar.
*/
void eliminarDatoCasaMatriz2(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato);

/*----------------------------------------------------------------------------*/
/**
  PRE: La lista fue creada con crearLista().
  POST: Reordena la lista por idCasaMatriz de mayor a menor.
  ATRIBUTOS:
  listaCasaMatriz : Lista sobre la cual se invoca la primitiva.
*/
void reordenarPorId(ListaCasaMatriz &listaCasaMatriz);
/*----------------------------------------------------------------------------*/
/**
  PRE: La lista fue creada con crearLista().
  POST: Reordena la lista por rendimiento total de mayor a menor.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
*/
void reordenarPorRendimiento(ListaCasaMatriz &listaCasaMatriz);

/*----------------------------------------------------------------------------*/
/**
  PRE: La lista fue creada con crearLista().
  POST: Devuelve la cantidad de datos que tiene la lista.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
*/
int longitud(ListaCasaMatriz &listaCasaMatriz);
/*----------------------------------------------------------------------------*/
/**
  PRE: La lista fue creada con crearLista().
  POST: Devuelve la lista de las provincias.
  ATRIBUTOS:
  listaCasaMatriz: Lista sobre la cual se invoca la primitiva.
*/
void obtenerListaCasaMatriz(ListaSucursal &listaSucursal,ListaCasaMatriz &listaCasaMatriz);

#endif // LISTACASAMATRIZ_H_INCLUDED
