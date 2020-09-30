/* TDA Lista
 * Implementación Simplemente Enlazada
 * Archivo : ListaCasaMatriz.cpp
 * Versión : 1.1
 */


#include "ListaCasaMatriz.h"

using namespace std;

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
ResultadoComparacionCasaMatriz compararDatoCasaMatrizPorId(DatoCasaMatriz dato1, DatoCasaMatriz dato2) {
    if (dato1.idCasaMatriz> dato2.idCasaMatriz) {
        return CMAYOR;
    }
    else if (dato1.idCasaMatriz < dato2.idCasaMatriz) {
        return CMENOR;
    }
    else {
        return CIGUAL;
    }
}


ResultadoComparacionCasaMatriz compararDatoCasaMatrizPorRendimiento(DatoCasaMatriz dato1, DatoCasaMatriz dato2) {
    if (dato1.rendimiento> dato2.rendimiento) {
        return CMAYOR;
    }
    else if (dato1.rendimiento < dato2.rendimiento) {
        return CMENOR;
    }
    else {
        return CIGUAL;
    }
}





/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearListaCasaMatriz(ListaCasaMatriz &listaCasaMatriz){
    listaCasaMatriz.primeroCasaMatriz=finCasaMatriz();
}

bool listaVaciaCasaMatriz(ListaCasaMatriz &listaCasaMatriz){
    return (primeroCasaMatriz(listaCasaMatriz) == finCasaMatriz());
}

PtrNodoListaCasaMatriz finCasaMatriz(){
    return NULL;
}

PtrNodoListaCasaMatriz primeroCasaMatriz(ListaCasaMatriz &listaCasaMatriz){
    return listaCasaMatriz.primeroCasaMatriz;
}

PtrNodoListaCasaMatriz siguienteCasaMatriz(ListaCasaMatriz &listaCasaMatriz, PtrNodoListaCasaMatriz ptrNodo){
/* verifica si la lista está vacia o si ptrNodo es el último */
    if ((! listaVaciaCasaMatriz(listaCasaMatriz)) && (ptrNodo != finCasaMatriz()))
        return ptrNodo->sgte;
    else
        return finCasaMatriz();
}


PtrNodoListaCasaMatriz anteriorCasaMatriz(ListaCasaMatriz &listaCasaMatriz, PtrNodoListaCasaMatriz ptrNodo){
    PtrNodoListaCasaMatriz ptrPrevio = finCasaMatriz();
    PtrNodoListaCasaMatriz ptrCursor = primeroCasaMatriz(listaCasaMatriz);
        while (( ptrCursor != finCasaMatriz()) && (ptrCursor != ptrNodo)) {
            ptrPrevio = ptrCursor;
            ptrCursor = siguienteCasaMatriz(listaCasaMatriz,ptrCursor);
        }
    return ptrPrevio;
}


PtrNodoListaCasaMatriz ultimoCasaMatriz(ListaCasaMatriz &listaCasaMatriz){
    /* el último nodo de la lista es el anterior al fin() */
    return anteriorCasaMatriz(listaCasaMatriz,finCasaMatriz());
}

PtrNodoListaCasaMatriz crearNodoLista(DatoCasaMatriz dato) {
    /* reserva memoria para el nodo y luego completa sus datos */
    PtrNodoListaCasaMatriz ptrAux = new NodoListaCasaMatriz;
    ptrAux->dato = dato;
    ptrAux->sgte = finCasaMatriz();
    return ptrAux;
}

PtrNodoListaCasaMatriz adicionarPrincipioCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato){
    /* crea el nodo */
    PtrNodoListaCasaMatriz ptrNuevoNodo = crearNodoLista(dato);
    /* lo incorpora al principio de la lista */
    ptrNuevoNodo->sgte = listaCasaMatriz.primeroCasaMatriz;
    listaCasaMatriz.primeroCasaMatriz = ptrNuevoNodo;
    return ptrNuevoNodo;
}


PtrNodoListaCasaMatriz adicionarDespuesCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato, PtrNodoListaCasaMatriz ptrNodo){
    PtrNodoListaCasaMatriz ptrNuevoNodo = finCasaMatriz();
    /* si la lista está vacia se adiciona la principio */
        if (listaVaciaCasaMatriz(listaCasaMatriz))
            ptrNuevoNodo = adicionarPrincipioCasaMatriz(listaCasaMatriz,dato);
        else {
            if (ptrNodo != finCasaMatriz()) {
                /* crea el nodo y lo intercala en la lista */
                ptrNuevoNodo = crearNodoLista(dato);
                ptrNuevoNodo->sgte = ptrNodo->sgte;
                ptrNodo->sgte = ptrNuevoNodo;
            }
        }
    return ptrNuevoNodo;
}

PtrNodoListaCasaMatriz adicionarFinalCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato){
    /* adiciona el dato después del último nodo de la lista */
    return adicionarDespuesCasaMatriz(listaCasaMatriz,dato,ultimoCasaMatriz(listaCasaMatriz));
}

PtrNodoListaCasaMatriz adicionarAntesCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato, PtrNodoListaCasaMatriz ptrNodo){
    PtrNodoListaCasaMatriz ptrNuevoNodo = finCasaMatriz();
        if (! listaVaciaCasaMatriz(listaCasaMatriz)) {
            if (ptrNodo != primeroCasaMatriz(listaCasaMatriz))
                ptrNuevoNodo = adicionarDespuesCasaMatriz(listaCasaMatriz,dato,anteriorCasaMatriz(listaCasaMatriz,ptrNodo));
            else
                ptrNuevoNodo = adicionarPrincipioCasaMatriz(listaCasaMatriz,dato);
        }
    return ptrNuevoNodo;
}

void colocarDatoCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz &dato, PtrNodoListaCasaMatriz ptrNodo){
    if ( (! listaVaciaCasaMatriz(listaCasaMatriz)) && (ptrNodo != finCasaMatriz()))
        ptrNodo->dato = dato;
}


void obtenerDatoCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz &dato, PtrNodoListaCasaMatriz ptrNodo){
    if ((! listaVaciaCasaMatriz(listaCasaMatriz)) && (ptrNodo != finCasaMatriz()))
        dato = ptrNodo->dato;
}


void eliminarNodoCasaMatriz(ListaCasaMatriz &listaCasaMatriz, PtrNodoListaCasaMatriz ptrNodo){
    PtrNodoListaCasaMatriz ptrPrevio;
        /* verifica que la lista no esté vacia y que nodo no sea fin*/
        if ((! listaVaciaCasaMatriz(listaCasaMatriz)) && (ptrNodo != finCasaMatriz())) {
            if (ptrNodo == primeroCasaMatriz(listaCasaMatriz))
                listaCasaMatriz.primeroCasaMatriz= siguienteCasaMatriz(listaCasaMatriz,primeroCasaMatriz(listaCasaMatriz));

            else {
                ptrPrevio = anteriorCasaMatriz(listaCasaMatriz,ptrNodo);
                ptrPrevio->sgte = ptrNodo->sgte;
            }
            // Si el dato es un TDA, acá habría que llamar al destructor.
         delete ptrNodo;
        }
}

void eliminarNodoPrimeroCasaMatriz(ListaCasaMatriz &listaCasaMatriz){
    while (! listaVaciaCasaMatriz(listaCasaMatriz))
        eliminarNodoCasaMatriz(listaCasaMatriz,primeroCasaMatriz(listaCasaMatriz));
}


void eliminarNodoUltimoCasaMatriz(ListaCasaMatriz &listaCasaMatriz){
    while (! listaVaciaCasaMatriz(listaCasaMatriz))
        eliminarNodoCasaMatriz(listaCasaMatriz,ultimoCasaMatriz(listaCasaMatriz));
}


void eliminarListaCasaMatriz(ListaCasaMatriz &listaCasaMatriz){
/* retira uno a uno los nodos de la lista */
    while (! listaVaciaCasaMatriz(listaCasaMatriz))
        eliminarNodoCasaMatriz(listaCasaMatriz,primeroCasaMatriz(listaCasaMatriz));
}

PtrNodoListaCasaMatriz localizarDatoCasaMatriz(ListaCasaMatriz &listaCasaMatriz,DatoCasaMatriz dato){
    bool encontrado = false;
    DatoCasaMatriz datoCursor;
    PtrNodoListaCasaMatriz ptrCursor = primeroCasaMatriz(listaCasaMatriz);
        /* recorre los nodos hasta llegar al último o hasta
        encontrar el nodo buscado */
        while ((ptrCursor != finCasaMatriz()) && (! encontrado)) {
        /* obtiene el dato del nodo y lo compara */
            obtenerDatoCasaMatriz(listaCasaMatriz,datoCursor,ptrCursor);
                if (compararDatoCasaMatrizPorId(datoCursor,dato) == CIGUAL)
                    encontrado = true;
                else
                    ptrCursor = siguienteCasaMatriz(listaCasaMatriz,ptrCursor);
        }

        /* si no lo encontró devuelve fin */
        if (! encontrado)
                ptrCursor = finCasaMatriz();

    return ptrCursor;
}


PtrNodoListaCasaMatriz localizarDatoCasaMatriz2(ListaCasaMatriz &listaCasaMatriz,DatoCasaMatriz dato){
    bool encontrado = false;
    DatoCasaMatriz datoCursor;
    PtrNodoListaCasaMatriz ptrCursor = primeroCasaMatriz(listaCasaMatriz);
        /* recorre los nodos hasta llegar al último o hasta
        encontrar el nodo buscado */
        while ((ptrCursor != finCasaMatriz()) && (! encontrado)) {
        /* obtiene el dato del nodo y lo compara */
            obtenerDatoCasaMatriz(listaCasaMatriz,datoCursor,ptrCursor);
                if (compararDatoCasaMatrizPorRendimiento(datoCursor,dato) == CIGUAL)
                    encontrado = true;
                else
                    ptrCursor = siguienteCasaMatriz(listaCasaMatriz,ptrCursor);
        }

        /* si no lo encontró devuelve fin */
        if (! encontrado)
                ptrCursor = finCasaMatriz();

    return ptrCursor;
}

PtrNodoListaCasaMatriz insertarDatoCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato){
    PtrNodoListaCasaMatriz ptrPrevio = primeroCasaMatriz(listaCasaMatriz);
    PtrNodoListaCasaMatriz ptrCursor = primeroCasaMatriz(listaCasaMatriz);
    PtrNodoListaCasaMatriz ptrNuevoNodo;
    DatoCasaMatriz datoCursor;
    bool ubicado = false;
  /* recorre la lista buscando el lugar de la inserción */
        while ((ptrCursor != finCasaMatriz()) && (! ubicado)) {
            obtenerDatoCasaMatriz(listaCasaMatriz,datoCursor,ptrCursor);
            // si cambio menor por mayor ordena de menor a mayor
                if (compararDatoCasaMatrizPorId(datoCursor,dato) == CMENOR)
                    ubicado = true;

                else {
                    ptrPrevio = ptrCursor;
                    ptrCursor = siguienteCasaMatriz(listaCasaMatriz,ptrCursor);
                }
        }

        if (ptrCursor == primeroCasaMatriz(listaCasaMatriz))
            ptrNuevoNodo = adicionarPrincipioCasaMatriz(listaCasaMatriz,dato);
        else
            ptrNuevoNodo = adicionarDespuesCasaMatriz(listaCasaMatriz,dato,ptrPrevio);

    return ptrNuevoNodo;
}


PtrNodoListaCasaMatriz insertarDatoCasaMatriz2(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato){
    PtrNodoListaCasaMatriz ptrPrevio = primeroCasaMatriz(listaCasaMatriz);
    PtrNodoListaCasaMatriz ptrCursor = primeroCasaMatriz(listaCasaMatriz);
    PtrNodoListaCasaMatriz ptrNuevoNodo;
    DatoCasaMatriz datoCursor;
    bool ubicado = false;
  /* recorre la lista buscando el lugar de la inserción */
        while ((ptrCursor != finCasaMatriz()) && (! ubicado)) {
            obtenerDatoCasaMatriz(listaCasaMatriz,datoCursor,ptrCursor);
            // si cambio menor por mayor ordena de menor a mayor
                if (compararDatoCasaMatrizPorRendimiento(datoCursor,dato) == CMENOR)
                    ubicado = true;

                else {
                    ptrPrevio = ptrCursor;
                    ptrCursor = siguienteCasaMatriz(listaCasaMatriz,ptrCursor);
                }
        }

        if (ptrCursor == primeroCasaMatriz(listaCasaMatriz))
            ptrNuevoNodo = adicionarPrincipioCasaMatriz(listaCasaMatriz,dato);
        else
            ptrNuevoNodo = adicionarDespuesCasaMatriz(listaCasaMatriz,dato,ptrPrevio);

    return ptrNuevoNodo;
}

void eliminarDatoCasaMatriz(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato){
 /* localiza el dato y luego lo elimina */
    PtrNodoListaCasaMatriz ptrNodo = localizarDatoCasaMatriz(listaCasaMatriz,dato);
        if (ptrNodo != finCasaMatriz())
            eliminarNodoCasaMatriz(listaCasaMatriz,ptrNodo);
}

void eliminarDatoCasaMatriz2(ListaCasaMatriz &listaCasaMatriz, DatoCasaMatriz dato){
 /* localiza el dato y luego lo elimina */
    PtrNodoListaCasaMatriz ptrNodo = localizarDatoCasaMatriz2(listaCasaMatriz,dato);
        if (ptrNodo != finCasaMatriz())
            eliminarNodoCasaMatriz(listaCasaMatriz,ptrNodo);
}

void reordenarPorId(ListaCasaMatriz &listaCasaMatriz){
    ListaCasaMatriz temp = listaCasaMatriz;
    PtrNodoListaCasaMatriz ptrCursor = primeroCasaMatriz(temp);
    crearListaCasaMatriz(listaCasaMatriz);
        while ( ptrCursor != finCasaMatriz() ) {
            DatoCasaMatriz dato;
            obtenerDatoCasaMatriz( temp, dato, ptrCursor);
            insertarDatoCasaMatriz( listaCasaMatriz, dato );
            eliminarNodoCasaMatriz( temp, ptrCursor );
            ptrCursor = primeroCasaMatriz(temp);
        }
    eliminarListaCasaMatriz( temp );
}


void reordenarPorRendimiento(ListaCasaMatriz &listaCasaMatriz){
    ListaCasaMatriz temp = listaCasaMatriz;
    PtrNodoListaCasaMatriz ptrCursor = primeroCasaMatriz(temp);
    crearListaCasaMatriz(listaCasaMatriz);
        while ( ptrCursor != finCasaMatriz() ) {
            DatoCasaMatriz dato;
            obtenerDatoCasaMatriz( temp, dato, ptrCursor);
            insertarDatoCasaMatriz2( listaCasaMatriz, dato );
            eliminarNodoCasaMatriz( temp, ptrCursor );
            ptrCursor = primeroCasaMatriz(temp);
        }
    eliminarListaCasaMatriz( temp );
}


int longitud(ListaCasaMatriz &listaCasaMatriz){
    PtrNodoListaCasaMatriz ptrCursor = primeroCasaMatriz(listaCasaMatriz);
    int longitud = 0;
        while ( ptrCursor != finCasaMatriz() ) {
            longitud++;
            ptrCursor = siguienteCasaMatriz(listaCasaMatriz,ptrCursor);
        }
    return longitud;
}

void obtenerListaCasaMatriz(ListaSucursal &listaSucursal,ListaCasaMatriz &listaCasaMatriz){
    PtrNodoListaCasaMatriz ptrNodoCasaMatriz = primeroCasaMatriz(listaCasaMatriz);
        while( (!listaVaciaCasaMatriz(listaCasaMatriz)) && (ptrNodoCasaMatriz != finCasaMatriz()) ){
                cout << "\n> CASA MATRIZ: " << ptrNodoCasaMatriz->dato.idCasaMatriz << " - RENDIMIENTO: " << ptrNodoCasaMatriz->dato.rendimiento<<"\n" << endl;
                cout << "\n" << setw(16) << " Codigo de Sucursal" << "\t|" << setw(18) << "Provincia" << "\t|" << setw(25) << "Cantidad de Articulos" << "\t|"<<setw(25) << fixed << setprecision(2) << "Monto de Facturacion" << "\t|"<<setw(12) <<"m^2"<< "\t|"<<setw(18) <<"Casa Matriz"<< endl;
                PtrNodoListaSucursal ptrNodoSucursal = primeroSucursal(listaSucursal);
                    while( (!listaVaciaSucursal(listaSucursal)) && (ptrNodoSucursal != finSucursal()) ){
                        if( getIdCasaMatriz(ptrNodoCasaMatriz->dato)==getCasaMatriz(ptrNodoSucursal->dato)){
                          cout << "\n" << setw(20) <<ptrNodoSucursal->dato.codSucursal<< "\t|" << setw(18) <<ptrNodoSucursal->dato.nombreProvincia<< "\t|" << setw(25) <<ptrNodoSucursal->dato.cantArticulosVendidos<< "\t|"<<setw(25)<<ptrNodoSucursal->dato.montoFacturacion<< "\t|"<<setw(12) <<ptrNodoSucursal->dato.m2<<"\t|"<<setw(12) <<ptrNodoSucursal->dato.casaMatriz<< endl;
                        }
                        ptrNodoSucursal = siguienteSucursal(listaSucursal,ptrNodoSucursal);
                    }
            ptrNodoCasaMatriz = ptrNodoCasaMatriz->sgte;
        }
}
