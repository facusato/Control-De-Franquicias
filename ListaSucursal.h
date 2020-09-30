#include "Sucursal.h"
#include "Provincia.h"
#ifndef LISTASUCURSAL_H_INCLUDED
#define LISTASUCURSAL_H_INCLUDED

#ifndef NULL
#define NULL      0
#endif

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/

/* tipo enumerado para realizar comparaciones */
enum ResultadoComparacionSucursal {
    MAYOR,
    IGUAL,
    MENOR
};
/* Tipo de Informacion que esta contenida en los Nodos de la
   Lista, identificada como DatoSucursal. */
typedef Sucursal DatoSucursal;

/* Tipo de Estructura de los Nodos de la Lista. */
struct NodoListaSucursal {
    DatoSucursal dato; // dato almacenado
    NodoListaSucursal* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Lista, el cual se usa para recorrer
   la Lista y acceder a sus Datos. */
typedef NodoListaSucursal* PtrNodoListaSucursal;


/* Tipo de Estructura de la Lista */
struct ListaSucursal{
    PtrNodoListaSucursal primeroSucursal;      // puntero al primer nodo de la lista
};


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/**
  PRE : La lista no debe haber sido creada.
  POST: Lista queda creada y preparada para ser usada.
  ATRIBUTOS:
  listaSucursal: Estructura de datos a ser creado.
*/
void crearListaSucursal(ListaSucursal &listaSucursal);

/*----------------------------------------------------------------------------*/
/**
  PRE : Lista Creada con crearLista().
  POST: Devuelve true si lista esta vacia, sino devuelve false.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
*/
bool listaVaciaSucursal(ListaSucursal &listaSucursal);

/*----------------------------------------------------------------------------*/
/**
  PRE : Lista Creada con crearLista().
  POST: Devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.
  RETORNO: Representación del fin de la lista.
*/
PtrNodoListaSucursal finSucursal();

/*----------------------------------------------------------------------------*/
/**
  PRE : Lista Creada con crearLista().
  POST: Devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia
  ATRIBUTOS:
  listaSucursal : Lista sobre la cual se invoca la primitiva.
  RETORNO: Puntero al primer nodo.
*/
PtrNodoListaSucursal primeroSucursal(ListaSucursal &listaSucursal);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista Creada con crearLista().
  POST: Devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
  prtNodo : Puntero al nodo a partir del cual se requiere el siguiente.
  RETURN puntero al nodo siguiente.
*/
PtrNodoListaSucursal siguienteSucursal(ListaSucursal &listaSucursal, PtrNodoListaSucursal ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE : Lista Creada con crearLista().
        ptrNodo es un puntero a un nodo de lista.
  POST: Devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        ptrNodo apuntaba al primero o si lista esta vacia.
  ATRIBUTOS:
  listaSucursal: lista sobre la cual se invoca la primitiva.
  prtNodo : Puntero al nodo a partir del cual se requiere el anterior.
  RETORNO : Puntero al nodo anterior.
*/
PtrNodoListaSucursal anteriorSucursal(ListaSucursal &listaSucursal, PtrNodoListaSucursal ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.
  ATRIBUTOS:
  listaSucursal : Lista sobre la cual se invoca la primitiva.
  RETORNO: Puntero al último nodo.
*/
PtrNodoListaSucursal ultimoSucursal(ListaSucursal &listaSucursal);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a adicionar al principio de la lista.
  RETORNO: Puntero al nodo adicionado.
*/
PtrNodoListaSucursal adicionarPrincipioSucursal(ListaSucursal &listaSucursal, DatoSucursal dato);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Agrega un nodo despues del apuntado por ptrNodo con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vacía agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a fin() no inserta
        nada y devuelve fin().
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a adicionar.
  ptrNodo: Puntero al nodo después del cual se quiere adicionar el dato.
  RETORNO: Puntero al nodo adicionado.
*/
PtrNodoListaSucursal adicionarDespuesSucursal(ListaSucursal &listaSucursal, DatoSucursal dato, PtrNodoListaSucursal ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.
  ATRIBUTOS:
  listaSucursal : Lista sobre la cual se invoca la primitiva.
  dato : Elemento a adicionar al final de la lista.
  RETORNO: Puntero al nodo adicionado.
*/
PtrNodoListaSucursal adicionarFinalSucursal(ListaSucursal &listaSucursal, DatoSucursal dato);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Agrega un nodo con el dato proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve fin(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a adicionar.
  ptrNodo: Puntero al nodo antes del cual se quiere adicionar el dato.
  RETORNO: Puntero al nodo adicionado.
*/
PtrNodoListaSucursal adicionarAntesSucursal(ListaSucursal &listaSucursal, DatoSucursal dato, PtrNodoListaSucursal ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista(), no vacia. ptrNodo es distinto de fin().
  POST: Coloca el dato proporcionado en el nodo apuntado por ptrNodo.
  ATRIBUTOS:
  listaSucursal : Lista sobre la cual se invoca la primitiva.
  dato: Elemento a colocar.
  ptrNodo : Puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDatoSucursal(ListaSucursal &listaSucursal, DatoSucursal &dato, PtrNodoListaSucursal ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista(), no vacia. ptrNodo es distinto de fin().
  POST: Devuelve el dato del nodo apuntado por ptrNodo.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
  dato: Elemento obtenido.
  ptrNodo: Puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDatoSucursal(ListaSucursal &listaSucursal, DatoSucursal &dato, PtrNodoListaSucursal ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a fin().
  ATRIBUTOS:
  listaSucursal : Lista sobre la cual se invoca la primitiva.
  ptrNodo: Puntero al nodo que se desea eliminar.
*/
void eliminarNodoSucursal(ListaSucursal &listaSucursal, PtrNodoListaSucursal ptrNodo);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Si la lista no esta vacia, elimina su nodo primero, sino no realiza
        accion alguna.
  ATRIBUTOS:
  listaSucursal : Lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimeroSucursal(ListaSucursal &listaSucursal);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Si la lista no esta vacia elimina su nodo ultimo,
        sino no realiza accion.
  ATRIBUTOS:
  listaSucursal : Lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimoSucursal(ListaSucursal &listaSucursal);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista creada con crearLista().
  POST: Elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
*/
void eliminarListaSucursal(ListaSucursal &listaSucursal);


/******************************************************************************/
/** Definición de Operaciones Adicionales */
/*---------------------------------------*/

/**
  PRE: Lista fue creada con crearLista().
  POST: Si el dato se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el dato no se encuentra en la lista devuelve fin().
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a localizar.
  RETORNO: Puntero al nodo localizado o fin().
*/
PtrNodoListaSucursal localizarDatoSucursal(ListaSucursal &listaSucursal ,DatoSucursal dato);

/*----------------------------------------------------------------------------*/
/**
  PRE: Lista fue creada con crearLista() y cargada con datos ordenados de
        menor a mayor respecto del sentido progresivo.
  POST: Agrega a la lista el dato manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a insertar.
  RETORNO: Puntero al nodo insertado.
*/
PtrNodoListaSucursal insertarDato1(ListaSucursal &listaSucursal, DatoSucursal dato);


/*----------------------------------------------------------------------------*/
/**
  PRE: Lista fue creada con crearLista() y cargada con datos ordenados de
        menor a mayor respecto del sentido progresivo.
  POST: Agrega a la lista el dato manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a insertar.
  RETORNO: Puntero al nodo insertado.
*/
PtrNodoListaSucursal insertarDato2(ListaSucursal &listaSucursal, DatoSucursal dato);

/*----------------------------------------------------------------------------*/
/**
  PRE: la lista fue creada con crearLista().
  POST: elimina el dato de la lista, si el mismo se encuentra.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a eliminar.
*/
void eliminarDato1(ListaSucursal &listaSucursal, DatoSucursal dato);

/*----------------------------------------------------------------------------*/
/**
  PRE: La lista fue creada con crearLista().
  POST: Elimina el dato de la lista, si el mismo se encuentra.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
  dato: Elemento a eliminar.
*/
void eliminarDato2(ListaSucursal &listaSucursal,DatoSucursal dato);
/*----------------------------------------------------------------------------*/
/**
  PRE: La lista fue creada con crearLista().
  POST: Reordena la lista por monto de facturacion de mayor a menor.
  ATRIBUTOS:
  listaSucursal : Lista sobre la cual se invoca la primitiva.
*/
void reordenarPorMonto(ListaSucursal &listaSucursal);

/**
  PRE: La lista fue creada con crearLista().
  POST: Reordena la lista por cantidad de articulos vendidos de mayor a menor.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
*/
void reordenarPorCantArticulos(ListaSucursal &listaSucursal);

/*----------------------------------------------------------------------------*/
/**
  PRE: La lista fue creada con crearLista().
  POST: Devuelve la cantidad de datos que tiene la lista.
  ATRIBUTOS:
  listaSucursal: Lista sobre la cual se invoca la primitiva.
*/
int longitudSucursal(ListaSucursal &listaSucursal);


#endif // LISTASUCURSAL_H_INCLUDED
