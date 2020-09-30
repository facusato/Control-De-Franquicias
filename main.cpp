#include <iostream>

#include "AdmArchivos.h"


using namespace std;

int main()
{
    system("color 0E");
    ListaSucursal listaSucursal;
    ListaProvincia listaProvincia;
    ListaCasaMatriz listaCasaMatriz;
    crearListaSucursal(listaSucursal);
    crearListaProvincia(listaProvincia);
    crearListaCasaMatriz(listaCasaMatriz);
    cargarSucursales(listaSucursal,listaProvincia,listaCasaMatriz);
    menu(listaSucursal,listaProvincia,listaCasaMatriz);
    eliminarListaProvincia(listaProvincia);
    eliminarListaCasaMatriz(listaCasaMatriz);
    eliminarListaSucursal(listaSucursal);
    return 0;
}
