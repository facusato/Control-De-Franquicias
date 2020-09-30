/* TDA Lista
 * Implementación Simplemente Enlazada
 * Archivo : ListaProvincia.cpp
 * Versión : 1.1
 */


#include "ListaProvincia.h"

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
ResultadoComparacionProvincia compararDatoProvincia(DatoProvincia dato1, DatoProvincia dato2) {
    if (dato1.totalArticulosVendidos> dato2.totalArticulosVendidos) {
        return PMAYOR;
    }
    else if (dato1.totalArticulosVendidos < dato2.totalArticulosVendidos) {
        return PMENOR;
    }
    else {
        return PIGUAL;
    }
}

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

ResultadoComparacionProvincia compararDatoProvincia2(DatoProvincia dato1, DatoProvincia dato2) {
    if (dato1.montoTotal> dato2.montoTotal) {
        return PMAYOR;
    }
    else if (dato1.montoTotal < dato2.montoTotal) {
        return PMENOR;
    }
    else {
        return PIGUAL;
    }
}




/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/


void crearListaProvincia(ListaProvincia &listaProvincia) {
    listaProvincia.primeroProvincia= finProvincia();
}


bool listaVaciaProvincia(ListaProvincia &listaProvincia) {
    return (primeroProvincia(listaProvincia) == finProvincia());
}


PtrNodoListaProvincia finProvincia() {
    return NULL;
}


PtrNodoListaProvincia primeroProvincia(ListaProvincia &listaProvincia) {
    return listaProvincia.primeroProvincia;
}


PtrNodoListaProvincia siguienteProvincia(ListaProvincia &listaProvincia, PtrNodoListaProvincia ptrNodo) {
    /* verifica si la lista está vacia o si ptrNodo es el último */
    if ((! listaVaciaProvincia(listaProvincia)) && (ptrNodo != finProvincia()))
        return ptrNodo->sgte;
    else
        return finProvincia();
}


PtrNodoListaProvincia anteriorProvincia(ListaProvincia &listaProvincia, PtrNodoListaProvincia ptrNodo) {
    PtrNodoListaProvincia ptrPrevio = finProvincia();
    PtrNodoListaProvincia ptrCursor = primeroProvincia(listaProvincia);
        while (( ptrCursor != finProvincia()) && (ptrCursor != ptrNodo)) {
            ptrPrevio = ptrCursor;
            ptrCursor = siguienteProvincia(listaProvincia,ptrCursor);
        }
    return ptrPrevio;
}


PtrNodoListaProvincia ultimoProvincia(ListaProvincia &listaProvincia) {
    /* el último nodo de la lista es el anterior al fin() */
    return anteriorProvincia(listaProvincia,finProvincia());
}


PtrNodoListaProvincia crearNodoLista(DatoProvincia dato) {
    /* reserva memoria para el nodo y luego completa sus datos */
    PtrNodoListaProvincia ptrAux = new NodoListaProvincia;
    ptrAux->dato = dato;
    ptrAux->sgte = finProvincia();
    return ptrAux;
}


PtrNodoListaProvincia adicionarPrincipioProvincia(ListaProvincia &listaProvincia, DatoProvincia dato) {
    /* crea el nodo */
    PtrNodoListaProvincia ptrNuevoNodo = crearNodoLista(dato);
    /* lo incorpora al principio de la lista */
    ptrNuevoNodo->sgte = listaProvincia.primeroProvincia;
    listaProvincia.primeroProvincia = ptrNuevoNodo;
    return ptrNuevoNodo;
}


PtrNodoListaProvincia adicionarDespuesProvincia(ListaProvincia &listaProvincia, DatoProvincia dato, PtrNodoListaProvincia ptrNodo) {
    PtrNodoListaProvincia ptrNuevoNodo = finProvincia();
    /* si la lista está vacia se adiciona la principio */
        if (listaVaciaProvincia(listaProvincia))
            ptrNuevoNodo = adicionarPrincipioProvincia(listaProvincia,dato);
        else {
            if (ptrNodo != finProvincia()) {
                /* crea el nodo y lo intercala en la lista */
                ptrNuevoNodo = crearNodoLista(dato);
                ptrNuevoNodo->sgte = ptrNodo->sgte;
                ptrNodo->sgte = ptrNuevoNodo;
            }
        }
    return ptrNuevoNodo;
}



PtrNodoListaProvincia adicionarFinalProvincia(ListaProvincia &listaProvincia, DatoProvincia dato) {
    /* adiciona el dato después del último nodo de la lista */
    return adicionarDespuesProvincia(listaProvincia,dato,ultimoProvincia(listaProvincia));
}

PtrNodoListaProvincia adicionarAntesProvincia(ListaProvincia &listaProvincia,DatoProvincia dato,PtrNodoListaProvincia ptrNodo) {
    PtrNodoListaProvincia ptrNuevoNodo = finProvincia();
        if (! listaVaciaProvincia(listaProvincia)) {
            if (ptrNodo != primeroProvincia(listaProvincia))
                ptrNuevoNodo = adicionarDespuesProvincia(listaProvincia,dato,anteriorProvincia(listaProvincia,ptrNodo));
            else
                ptrNuevoNodo = adicionarPrincipioProvincia(listaProvincia,dato);
        }
    return ptrNuevoNodo;
}


void colocarDatoProvincia(ListaProvincia &listaProvincia, DatoProvincia &dato, PtrNodoListaProvincia ptrNodo) {
    if ( (! listaVaciaProvincia(listaProvincia)) && (ptrNodo != finProvincia()))
        ptrNodo->dato = dato;
}


void obtenerDatoProvincia(ListaProvincia &listaProvincia,DatoProvincia &dato, PtrNodoListaProvincia ptrNodo) {
    if ((! listaVaciaProvincia(listaProvincia)) && (ptrNodo != finProvincia()))
        dato = ptrNodo->dato;
}


void eliminarNodoProvincia(ListaProvincia &listaProvincia, PtrNodoListaProvincia ptrNodo) {
    PtrNodoListaProvincia ptrPrevio;
        /* verifica que la lista no esté vacia y que nodo no sea fin*/
        if ((! listaVaciaProvincia(listaProvincia)) && (ptrNodo != finProvincia())) {
            if (ptrNodo == primeroProvincia(listaProvincia))
                listaProvincia.primeroProvincia= siguienteProvincia(listaProvincia,primeroProvincia(listaProvincia));

            else {
                ptrPrevio = anteriorProvincia(listaProvincia,ptrNodo);
                ptrPrevio->sgte = ptrNodo->sgte;
            }
            // Si el dato es un TDA, acá habría que llamar al destructor.
         delete ptrNodo;
        }
}


void eliminarNodoPrimeroProvincia(ListaProvincia &listaProvincia) {
    if (! listaVaciaProvincia(listaProvincia))
        eliminarNodoProvincia(listaProvincia,primeroProvincia(listaProvincia));
}


void eliminarNodoUltimoProvincia(ListaProvincia &listaProvincia) {
    if (! listaVaciaProvincia(listaProvincia))
        eliminarNodoProvincia(listaProvincia,ultimoProvincia(listaProvincia));
}


void eliminarListaProvincia(ListaProvincia &listaProvincia) {
    /* retira uno a uno los nodos de la lista */
    while (! listaVaciaProvincia(listaProvincia))
        eliminarNodoProvincia(listaProvincia,primeroProvincia(listaProvincia));
}

PtrNodoListaProvincia localizarDatoProvincia(ListaProvincia &listaProvincia ,DatoProvincia dato){
   bool encontrado = false;
   DatoProvincia datoCursor;
   PtrNodoListaProvincia ptrCursor = primeroProvincia(listaProvincia);

        /* recorre los nodos hasta llegar al último o hasta
        encontrar el nodo buscado */
        while ((ptrCursor != finProvincia()) && (! encontrado)) {
        /* obtiene el dato del nodo y lo compara */
            obtenerDatoProvincia(listaProvincia,datoCursor,ptrCursor);
                if (strcmp(datoCursor.nombreProvincia, dato.nombreProvincia) == 0)
                    encontrado = true;
                else
                    ptrCursor = siguienteProvincia(listaProvincia,ptrCursor);
        }

        /* si no lo encontró devuelve fin */
        if (! encontrado)
            ptrCursor = finProvincia();

    return ptrCursor;

}



PtrNodoListaProvincia insertarDatoProvincia(ListaProvincia &listaProvincia, DatoProvincia dato){
    PtrNodoListaProvincia ptrPrevio = primeroProvincia(listaProvincia);
    PtrNodoListaProvincia ptrCursor = primeroProvincia(listaProvincia);
    PtrNodoListaProvincia ptrNuevoNodo;
    DatoProvincia datoCursor;
    bool ubicado = false;
  /* recorre la lista buscando el lugar de la inserción */
        while ((ptrCursor != finProvincia()) && (! ubicado)) {
            obtenerDatoProvincia(listaProvincia,datoCursor,ptrCursor);
            // si cambio menor por mayor ordena de menor a mayor
                if (compararDatoProvincia(datoCursor,dato) == PMENOR)
                    ubicado = true;

                else {
                    ptrPrevio = ptrCursor;
                    ptrCursor = siguienteProvincia(listaProvincia,ptrCursor);
                }
        }

        if (ptrCursor == primeroProvincia(listaProvincia))
            ptrNuevoNodo = adicionarPrincipioProvincia(listaProvincia,dato);
        else
            ptrNuevoNodo = adicionarDespuesProvincia(listaProvincia,dato,ptrPrevio);

    return ptrNuevoNodo;

}


PtrNodoListaProvincia insertarDatoProvincia2(ListaProvincia &listaProvincia, DatoProvincia dato){
    PtrNodoListaProvincia ptrPrevio = primeroProvincia(listaProvincia);
    PtrNodoListaProvincia ptrCursor = primeroProvincia(listaProvincia);
    PtrNodoListaProvincia ptrNuevoNodo;
    DatoProvincia datoCursor;
    bool ubicado = false;
  /* recorre la lista buscando el lugar de la inserción */
        while ((ptrCursor != finProvincia()) && (! ubicado)) {
            obtenerDatoProvincia(listaProvincia,datoCursor,ptrCursor);
            // si cambio menor por mayor ordena de menor a mayor
                if (compararDatoProvincia2(datoCursor,dato) == PMENOR)
                    ubicado = true;

                else {
                    ptrPrevio = ptrCursor;
                    ptrCursor = siguienteProvincia(listaProvincia,ptrCursor);
                }
        }

        if (ptrCursor == primeroProvincia(listaProvincia))
            ptrNuevoNodo = adicionarPrincipioProvincia(listaProvincia,dato);
        else
            ptrNuevoNodo = adicionarDespuesProvincia(listaProvincia,dato,ptrPrevio);

    return ptrNuevoNodo;

}


void eliminarDatoProvincia(ListaProvincia &listaProvincia, DatoProvincia dato){
    /* localiza el dato y luego lo elimina */
    PtrNodoListaProvincia ptrNodo = localizarDatoProvincia(listaProvincia,dato);
        if (ptrNodo != finProvincia())
            eliminarNodoProvincia(listaProvincia,ptrNodo);
}



void reordenarPorcantArticulosVendidos(ListaProvincia &listaProvincia){
    ListaProvincia temp = listaProvincia;
    PtrNodoListaProvincia ptrCursor = primeroProvincia(temp);
    crearListaProvincia(listaProvincia);
        while ( ptrCursor != finProvincia() ) {
            DatoProvincia dato;
            obtenerDatoProvincia( temp, dato, ptrCursor);
            insertarDatoProvincia( listaProvincia, dato );
            eliminarNodoProvincia( temp, ptrCursor );
            ptrCursor = primeroProvincia(temp);
        }
    eliminarListaProvincia( temp );
}

void reordenarPorMontoTotalDeFacturacion(ListaProvincia &listaProvincia){
    ListaProvincia temp = listaProvincia;
    PtrNodoListaProvincia ptrCursor = primeroProvincia(temp);
    crearListaProvincia(listaProvincia);
        while ( ptrCursor != finProvincia() ) {
            DatoProvincia dato;
            obtenerDatoProvincia( temp, dato, ptrCursor);
            insertarDatoProvincia2( listaProvincia, dato );
            eliminarNodoProvincia( temp, ptrCursor );
            ptrCursor = primeroProvincia(temp);
        }
    eliminarListaProvincia( temp );
}


int longitud(ListaProvincia &listaProvincia){
    PtrNodoListaProvincia ptrCursor = primeroProvincia(listaProvincia);
    int longitud = 0;
        while ( ptrCursor != finProvincia() ) {
            longitud++;
            ptrCursor = siguienteProvincia(listaProvincia,ptrCursor);
        }
    return longitud;
}

void obtenerListaProvinciaConTotalMontoFacturacion(ListaSucursal &listaSucursal,ListaProvincia &listaProvincia){
	 PtrNodoListaProvincia ptrNodoProvincia = primeroProvincia(listaProvincia);
        while( (!listaVaciaProvincia(listaProvincia)) && (ptrNodoProvincia != finProvincia()) ){
                cout << "\n> PROVINCIA: " << ptrNodoProvincia->dato.idProvincia << " - NOMBRE PROVINCIA: " << ptrNodoProvincia->dato.nombreProvincia <<  " - MONTO TOTAL DE FACTURACION: " <<ptrNodoProvincia->dato.montoTotal<<"\n" << endl;
                cout << "\n" << setw(16) << " Codigo de Sucursal" << "\t|" << setw(18) << "Provincia" << "\t|" << setw(25) << "Cantidad de Articulos" << "\t|"<<setw(25) << "Monto de Facturacion" << "\t|"<<setw(12) <<"m^2"<< "\t|"<<setw(18) <<"Casa Matriz"<< endl;
                PtrNodoListaSucursal ptrNodoSucursal = primeroSucursal(listaSucursal);
                    while( (!listaVaciaSucursal(listaSucursal)) && (ptrNodoSucursal != finSucursal()) ){
                        if( strcmp(getNombreProvincia(ptrNodoProvincia->dato), getNombreProvincia(ptrNodoSucursal->dato)) == 0 ){
                          cout << "\n" << setw(20) <<ptrNodoSucursal->dato.codSucursal<< "\t|" << setw(18) <<ptrNodoSucursal->dato.nombreProvincia<< "\t|" << setw(25) <<ptrNodoSucursal->dato.cantArticulosVendidos<< "\t|"<<setw(25)<<ptrNodoSucursal->dato.montoFacturacion<< "\t|"<<setw(12) <<ptrNodoSucursal->dato.m2<<"\t|"<<setw(12) <<ptrNodoSucursal->dato.casaMatriz<< endl;
                        }
                        ptrNodoSucursal = siguienteSucursal(listaSucursal,ptrNodoSucursal);
                    }
            cout << "\n"<<endl;
            ptrNodoProvincia = ptrNodoProvincia->sgte;
        }
}

void obtenerListaProvinciaConTotalArticulosVendidos(ListaSucursal &listaSucursal,ListaProvincia &listaProvincia){
    PtrNodoListaProvincia ptrNodoProvincia = primeroProvincia(listaProvincia);
        while( (!listaVaciaProvincia(listaProvincia)) && (ptrNodoProvincia != finProvincia()) ){
                cout << "\n> PROVINCIA: " << ptrNodoProvincia->dato.idProvincia << " - NOMBRE PROVINCIA: " << ptrNodoProvincia->dato.nombreProvincia <<  " - TOTAL ARTICULOS VENDIDOS: " <<ptrNodoProvincia->dato.totalArticulosVendidos<<"\n" << endl;
                cout << "\n" << setw(16) << " Codigo de Sucursal" << "\t|" << setw(18) << "Provincia" << "\t|" << setw(25) << "Cantidad de Articulos" << "\t|"<<setw(25) << fixed << setprecision(2) << "Monto de Facturacion" << "\t|"<<setw(12) <<"m^2"<< "\t|"<<setw(18) <<"Casa Matriz"<< endl;
                PtrNodoListaSucursal ptrNodoSucursal = primeroSucursal(listaSucursal);
                    while( (!listaVaciaSucursal(listaSucursal)) && (ptrNodoSucursal != finSucursal()) ){
                        if( strcmp(getNombreProvincia(ptrNodoProvincia->dato), getNombreProvincia(ptrNodoSucursal->dato)) == 0 ){
                          cout << "\n" << setw(20) <<ptrNodoSucursal->dato.codSucursal<< "\t|" << setw(18) <<ptrNodoSucursal->dato.nombreProvincia<< "\t|" << setw(25) <<ptrNodoSucursal->dato.cantArticulosVendidos<< "\t|"<<setw(25)<<ptrNodoSucursal->dato.montoFacturacion<< "\t|"<<setw(12) <<ptrNodoSucursal->dato.m2<<"\t|"<<setw(12) <<ptrNodoSucursal->dato.casaMatriz<< endl;
                        }
                        ptrNodoSucursal = siguienteSucursal(listaSucursal,ptrNodoSucursal);
                    }
            cout << "\n"<<endl;
            ptrNodoProvincia = ptrNodoProvincia->sgte;
        }
}

