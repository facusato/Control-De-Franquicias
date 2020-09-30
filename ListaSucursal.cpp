/* TDA Lista
 * Implementación Simplemente Enlazada
 * Archivo : ListaSucursal.cpp
 * Versión : 1.1
 */


#include "ListaSucursal.h"

/******************************************************************************/
/* Definición de Tipos de Datos para manejo interno */
/*--------------------------------------------------*/


/******************************************************************************/
/* Funciones Adicionales */
/*-----------------------*/

/*
  pre : ninguna.
  post: compara ambos dato1 y dato2, devuelve
          mayor si dato1 es mayor que dato2,
          igual si dato1 es igual a dato2,
          menor si dato1 es menor que dato2.

  dato1 : dato a comparar.
  dato2 : dato a comparar.
  return resultado de comparar dato1 respecto de dato2.
*/
ResultadoComparacionSucursal compararDatoMonto(DatoSucursal dato1, DatoSucursal dato2) {
    if (dato1.montoFacturacion > dato2.montoFacturacion) {
        return MAYOR;
    }
    else if (dato1.montoFacturacion < dato2.montoFacturacion) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}


ResultadoComparacionSucursal compararDatoCantArticulos(DatoSucursal dato1, DatoSucursal dato2) {
    if (dato1.cantArticulosVendidos > dato2.cantArticulosVendidos) {
        return MAYOR;
    }
    else if (dato1.cantArticulosVendidos  < dato2.cantArticulosVendidos ) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/


void crearListaSucursal(ListaSucursal &listaSucursal) {
    listaSucursal.primeroSucursal = finSucursal();
}


bool listaVaciaSucursal(ListaSucursal &listaSucursal) {
    return (primeroSucursal(listaSucursal) == finSucursal());
}


PtrNodoListaSucursal finSucursal() {
    return NULL;
}


PtrNodoListaSucursal primeroSucursal(ListaSucursal &listaSucursal) {
    return listaSucursal.primeroSucursal;
}


PtrNodoListaSucursal siguienteSucursal(ListaSucursal &listaSucursal, PtrNodoListaSucursal ptrNodo) {
    /* verifica si la lista está vacia o si ptrNodo es el último */
    if ((! listaVaciaSucursal(listaSucursal)) && (ptrNodo != finSucursal()))
        return ptrNodo->sgte;
    else
        return finSucursal();
}


PtrNodoListaSucursal anteriorSucursal(ListaSucursal &listaSucursal, PtrNodoListaSucursal ptrNodo) {
    PtrNodoListaSucursal ptrPrevio = finSucursal();
    PtrNodoListaSucursal ptrCursor = primeroSucursal(listaSucursal);
        while (( ptrCursor != finSucursal()) && (ptrCursor != ptrNodo)) {
            ptrPrevio = ptrCursor;
            ptrCursor = siguienteSucursal(listaSucursal,ptrCursor);
        }
    return ptrPrevio;
}


PtrNodoListaSucursal ultimoSucursal(ListaSucursal &listaSucursal) {
    /* el último nodo de la lista es el anterior al fin() */
    return anteriorSucursal(listaSucursal,finSucursal());
}


PtrNodoListaSucursal crearNodoLista(DatoSucursal dato) {
    /* reserva memoria para el nodo y luego completa sus datos */
    PtrNodoListaSucursal ptrAux = new NodoListaSucursal;
    ptrAux->dato = dato;
    ptrAux->sgte = finSucursal();
    return ptrAux;
}


PtrNodoListaSucursal adicionarPrincipioSucursal(ListaSucursal &listaSucursal, DatoSucursal dato) {
    /* crea el nodo */
    PtrNodoListaSucursal ptrNuevoNodo = crearNodoLista(dato);
    /* lo incorpora al principio de la lista */
    ptrNuevoNodo->sgte = listaSucursal.primeroSucursal;
    listaSucursal.primeroSucursal = ptrNuevoNodo;
    return ptrNuevoNodo;
}


PtrNodoListaSucursal adicionarDespuesSucursal(ListaSucursal &listaSucursal, DatoSucursal dato, PtrNodoListaSucursal ptrNodo) {
    PtrNodoListaSucursal ptrNuevoNodo = finSucursal();
    /* si la lista está vacia se adiciona la principio */
        if (listaVaciaSucursal(listaSucursal))
            ptrNuevoNodo = adicionarPrincipioSucursal(listaSucursal,dato);
        else {
            if (ptrNodo != finSucursal()) {
                /* crea el nodo y lo intercala en la lista */
                ptrNuevoNodo = crearNodoLista(dato);
                ptrNuevoNodo->sgte = ptrNodo->sgte;
                ptrNodo->sgte = ptrNuevoNodo;
            }
        }
    return ptrNuevoNodo;
}



PtrNodoListaSucursal adicionarFinalSucursal(ListaSucursal &listaSucursal, DatoSucursal dato) {
    /* adiciona el dato después del último nodo de la lista */
    return adicionarDespuesSucursal(listaSucursal,dato,ultimoSucursal(listaSucursal));
}

PtrNodoListaSucursal adicionarAntesSucursal(ListaSucursal &listaSucursal,DatoSucursal dato,PtrNodoListaSucursal ptrNodo) {
    PtrNodoListaSucursal ptrNuevoNodo = finSucursal();
        if (! listaVaciaSucursal(listaSucursal)) {
            if (ptrNodo != primeroSucursal(listaSucursal))
                ptrNuevoNodo = adicionarDespuesSucursal(listaSucursal,dato,anteriorSucursal(listaSucursal,ptrNodo));
            else
                ptrNuevoNodo = adicionarPrincipioSucursal(listaSucursal,dato);
        }
    return ptrNuevoNodo;
}


void colocarDatoSucursal(ListaSucursal &listaSucursal, DatoSucursal &dato, PtrNodoListaSucursal ptrNodo) {
    if ( (! listaVaciaSucursal(listaSucursal)) && (ptrNodo != finSucursal()))
        ptrNodo->dato = dato;
}


void obtenerDatoSucursal(ListaSucursal &listaSucursal,DatoSucursal &dato, PtrNodoListaSucursal ptrNodo) {
    if ((! listaVaciaSucursal(listaSucursal)) && (ptrNodo != finSucursal()))
        dato = ptrNodo->dato;
}


void eliminarNodoSucursal(ListaSucursal &listaSucursal, PtrNodoListaSucursal ptrNodo) {
    PtrNodoListaSucursal ptrPrevio;
        /* verifica que la lista no esté vacia y que nodo no sea fin*/
        if ((! listaVaciaSucursal(listaSucursal)) && (ptrNodo != finSucursal())) {
            if (ptrNodo == primeroSucursal(listaSucursal))
                listaSucursal.primeroSucursal = siguienteSucursal(listaSucursal,primeroSucursal(listaSucursal));

            else {
                ptrPrevio = anteriorSucursal(listaSucursal,ptrNodo);
                ptrPrevio->sgte = ptrNodo->sgte;
            }
            // Si el dato es un TDA, acá habría que llamar al destructor.
         delete ptrNodo;
        }
}


void eliminarNodoPrimeroSucursal(ListaSucursal &listaSucursal) {
    if (! listaVaciaSucursal(listaSucursal))
        eliminarNodoSucursal(listaSucursal,primeroSucursal(listaSucursal));
}


void eliminarNodoUltimoSucursal(ListaSucursal &listaSucursal) {
    if (! listaVaciaSucursal(listaSucursal))
        eliminarNodoSucursal(listaSucursal,ultimoSucursal(listaSucursal));
}


void eliminarListaSucursal(ListaSucursal &listaSucursal) {
    /* retira uno a uno los nodos de la lista */
    while (! listaVaciaSucursal(listaSucursal))
        eliminarNodoSucursal(listaSucursal,primeroSucursal(listaSucursal));
}


PtrNodoListaSucursal localizarDato1(ListaSucursal &listaSucursal,DatoSucursal dato) {

   bool encontrado = false;
   DatoSucursal datoCursor;
   PtrNodoListaSucursal ptrCursor = primeroSucursal(listaSucursal);
        /* recorre los nodos hasta llegar al último o hasta
        encontrar el nodo buscado */
        while ((ptrCursor != finSucursal()) && (! encontrado)) {
        /* obtiene el dato del nodo y lo compara */
            obtenerDatoSucursal(listaSucursal,datoCursor,ptrCursor);
                if (compararDatoMonto(datoCursor,dato) == IGUAL)
                    encontrado = true;
                else
                    ptrCursor = siguienteSucursal(listaSucursal,ptrCursor);
        }

        /* si no lo encontró devuelve fin */
        if (! encontrado)
                ptrCursor = finSucursal();

    return ptrCursor;
}



PtrNodoListaSucursal localizarDato2(ListaSucursal &listaSucursal,DatoSucursal dato) {

   bool encontrado = false;
   DatoSucursal datoCursor;
   PtrNodoListaSucursal ptrCursor = primeroSucursal(listaSucursal);

        /* recorre los nodos hasta llegar al último o hasta
        encontrar el nodo buscado */
        while ((ptrCursor != finSucursal()) && (! encontrado)) {
        /* obtiene el dato del nodo y lo compara */
            obtenerDatoSucursal(listaSucursal,datoCursor,ptrCursor);
                if (compararDatoCantArticulos(datoCursor,dato) == IGUAL)
                    encontrado = true;
                else
                    ptrCursor = siguienteSucursal(listaSucursal,ptrCursor);
        }

        /* si no lo encontró devuelve fin */
        if (! encontrado)
            ptrCursor = finSucursal();

    return ptrCursor;
}


void eliminarDato1(ListaSucursal &listaSucursal,DatoSucursal dato) {
  /* localiza el dato y luego lo elimina */
    PtrNodoListaSucursal ptrNodo = localizarDato1(listaSucursal,dato);
        if (ptrNodo != finSucursal())
            eliminarNodoSucursal(listaSucursal,ptrNodo);
}


void eliminarDato2(ListaSucursal &listaSucursal,DatoSucursal dato) {
    /* localiza el dato y luego lo elimina */
    PtrNodoListaSucursal ptrNodo = localizarDato2(listaSucursal,dato);
        if (ptrNodo != finSucursal())
            eliminarNodoSucursal(listaSucursal,ptrNodo);
}


PtrNodoListaSucursal insertarDato1(ListaSucursal &listaSucursal,DatoSucursal dato) {
    PtrNodoListaSucursal ptrPrevio = primeroSucursal(listaSucursal);
    PtrNodoListaSucursal ptrCursor = primeroSucursal(listaSucursal);
    PtrNodoListaSucursal ptrNuevoNodo;
    DatoSucursal datoCursor;
    bool ubicado = false;
    /* recorre la lista buscando el lugar de la inserción */
        while ((ptrCursor != finSucursal()) && (! ubicado)) {
            obtenerDatoSucursal(listaSucursal,datoCursor,ptrCursor);
            // si cambio menor por mayor ordena de menor a mayor
                if (compararDatoMonto(datoCursor,dato) == MENOR)
                    ubicado = true;
                else {
                    ptrPrevio = ptrCursor;
                    ptrCursor = siguienteSucursal(listaSucursal,ptrCursor);
                }
        }
        if (ptrCursor == primeroSucursal(listaSucursal))
                ptrNuevoNodo = adicionarPrincipioSucursal(listaSucursal,dato);
        else
                ptrNuevoNodo = adicionarDespuesSucursal(listaSucursal,dato,ptrPrevio);

    return ptrNuevoNodo;
}


PtrNodoListaSucursal insertarDato2(ListaSucursal &listaSucursal,DatoSucursal dato) {
    PtrNodoListaSucursal ptrPrevio = primeroSucursal(listaSucursal);
    PtrNodoListaSucursal ptrCursor = primeroSucursal(listaSucursal);
    PtrNodoListaSucursal ptrNuevoNodo;
    DatoSucursal datoCursor;
    bool ubicado = false;
  /* recorre la lista buscando el lugar de la inserción */
        while ((ptrCursor != finSucursal()) && (! ubicado)) {
            obtenerDatoSucursal(listaSucursal,datoCursor,ptrCursor);
            // si cambio menor por mayor ordena de menor a mayor
                if (compararDatoCantArticulos(datoCursor,dato) == MENOR)
                    ubicado = true;

                else {
                    ptrPrevio = ptrCursor;
                    ptrCursor = siguienteSucursal(listaSucursal,ptrCursor);
                }
        }

        if (ptrCursor == primeroSucursal(listaSucursal))
            ptrNuevoNodo = adicionarPrincipioSucursal(listaSucursal,dato);
        else
            ptrNuevoNodo = adicionarDespuesSucursal(listaSucursal,dato,ptrPrevio);

    return ptrNuevoNodo;
}



void reordenarPorMonto(ListaSucursal &listaSucursal) {
    ListaSucursal temp = listaSucursal;
    PtrNodoListaSucursal ptrCursor = primeroSucursal(temp);
    crearListaSucursal(listaSucursal);
        while ( ptrCursor != finSucursal() ) {
            DatoSucursal dato;
            obtenerDatoSucursal( temp, dato, ptrCursor);
            insertarDato1( listaSucursal, dato );
            eliminarNodoSucursal( temp, ptrCursor );
            ptrCursor = primeroSucursal(temp);
        }
    eliminarListaSucursal( temp );
}

void reordenarPorCantArticulos(ListaSucursal &listaSucursal) {
    ListaSucursal temp = listaSucursal;
    PtrNodoListaSucursal ptrCursor = primeroSucursal(temp);
    crearListaSucursal(listaSucursal);
        while ( ptrCursor != finSucursal() ) {
            DatoSucursal dato;
            obtenerDatoSucursal( temp, dato, ptrCursor);
            insertarDato2( listaSucursal, dato );
            eliminarNodoSucursal( temp, ptrCursor );
            ptrCursor = primeroSucursal(temp);
        }
    eliminarListaSucursal( temp );
}



int longitudSucursal(ListaSucursal &listaSucursal){
    PtrNodoListaSucursal ptrCursor = primeroSucursal(listaSucursal);
    int longitud = 0;
        while ( ptrCursor != finSucursal() ) {
            longitud++;
            ptrCursor = siguienteSucursal(listaSucursal,ptrCursor);
        }
    return longitud;
}

