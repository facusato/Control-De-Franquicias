#include "AdmArchivos.h"

using namespace std;

void cargarSucursales(ListaSucursal &listaSucursal,ListaProvincia &listaProvincia,ListaCasaMatriz &listaCasaMatriz){
    int idProvincia = 1;
    ifstream archivo("Sucursales.txt");
        if(archivo && archivo.is_open()){
            string linea;
            Sucursal sucursal; crearSucursal(sucursal);
            Provincia provincia; crearProvincia(provincia);
            CasaMatriz casaMatriz; crearCasaMatriz(casaMatriz);
            stringstream ss;

            while(archivo.good()){

                //Codigo de la Sucursal
                getline(archivo, linea, ';');
                ss.str(linea);
                setCodSucursal(sucursal, atoi(linea.c_str()));
                ss.clear();

                //Nombre de la Provincia
                getline(archivo, linea, ';');
                strcpy(sucursal.nombreProvincia,linea.c_str());
                strcpy(provincia.nombreProvincia,linea.c_str());
                ss.clear();

                //cantidad de articulos vendidos
                getline(archivo, linea, ';');
                ss.str(linea);
                setCantArticulosVendidos(sucursal, atoi(linea.c_str()));
                ss.clear();

                //Monto de facturacion
                getline(archivo, linea, ';');
                ss.str(linea);
                setMontoFacturacion(sucursal,atof(linea.c_str()));
                ss.clear();

                //m2
                getline(archivo, linea,';');
                ss.str(linea);
                setM2(sucursal, atoi(linea.c_str()));
                ss.clear();

                //casa matriz
                getline(archivo, linea);
                ss.str(linea);
                    if(atoi(linea.c_str())==0){
                        setCasaMatriz(sucursal,sucursal.codSucursal);
                        setIdCasaMatriz(casaMatriz,sucursal.codSucursal);
                    }
                    else{
                        setCasaMatriz(sucursal, atoi(linea.c_str()));
                        setIdCasaMatriz(casaMatriz,atoi(linea.c_str()));
                        ss.clear();
                    }


                setIdProvincia(provincia,idProvincia);
                if(listaVaciaProvincia(listaProvincia) == true){
                        adicionarFinalProvincia(listaProvincia, provincia);
                        idProvincia++;
                        adicionarFinalSucursal(listaSucursal,sucursal);
                    }else{
                        if(localizarDatoProvincia(listaProvincia,provincia) == NULL){
                            if(idProvincia < 24){
                                adicionarFinalProvincia(listaProvincia, provincia);
                                idProvincia++;
                                adicionarFinalSucursal(listaSucursal,sucursal);
                            }
                        }
                        else{
                            adicionarFinalSucursal(listaSucursal,sucursal);
                            }
                         }

                if(listaVaciaCasaMatriz(listaCasaMatriz) == true){
                        adicionarFinalCasaMatriz(listaCasaMatriz,casaMatriz);
                }else{
                    if(localizarDatoCasaMatriz(listaCasaMatriz,casaMatriz) == NULL){
                        adicionarFinalCasaMatriz(listaCasaMatriz, casaMatriz);
                    }
                }
            }
        archivo.close();
    }

}

void menu(ListaSucursal &listaSucursal,ListaProvincia &listaProvincia,ListaCasaMatriz &listaCasaMatriz){

    int opcion;

    if( listaVaciaSucursal(listaSucursal) == false ){

        while(opcion!= 7){

            system("cls");

            cout << "--------------------BIENVENIDOS A LA APLICACION------------------------" << endl;
            cout << "--------------------UNIVERSIDAD NACIONAL DE LANUS----------------------" << endl;
            cout << "--------------------CATEDRA ALGORITMOS Y ESTRUCTURAS DE DATOS----------" << endl;
            cout << "--------------------TRABAJO PRACTICO CUATRIMESTRAL---------------------" << endl;
            cout << "------------------------------GRUPO 6 ---------------------------------" << endl;

            cout << "\n MENU DE REPORTES:\n" << endl;
            cout << "\t1. LISTADO DE SUCURSALES A ADMINISTRAR." << endl;
            cout << "\t2. LISTADO DE SUCURSALES QUE MAS FACTURARON A NIVEL NACIONAL." << endl;
            cout << "\t3. LISTADO DE SUCURSALES QUE MAS FACTURARON A NIVEL PROVINCIAL." << endl;
            cout << "\t4. LISTADO DE SUCURSALES QUE MAS ARTICULOS VENDIERON A NIVEL NACIONAL" << endl;
            cout << "\t5. LISTADO DE SUCURSALES QUE MAS ARTICULOS VENDIERON A NIVEL PROVINCIAL" << endl;
            cout << "\t6. LISTADO DE SUCURSALES POR RANKING DE RENDIMIENTO" << endl;
            cout << "\t7. SALIR DEL APLICATIVO." << endl;

            cout << "\n INGRESE LA OPCION DESEADA: ";
            cin >> opcion;

            switch(opcion){

               case 1:
                   obtenerSucursales(listaSucursal);
               break;
               case 2:
                   rankingNacionalPorMontoFacturacion(listaSucursal);
               break;
               case 3:
                   rankingProvincialPorMontoFacturacion(listaSucursal,listaProvincia);
               break;
               case 4:
                   rankingNacionalPorCantArticulosVendidos(listaSucursal);
               break;
               case 5:
                   rankingProvincialPorCantArticulosVendidos(listaSucursal,listaProvincia);
               break;
               case 6:
                   rankingRendimiento(listaSucursal,listaCasaMatriz);
               break;
               case 7:
                   system("cls");
                   cout << "-----------------------------------------------" << endl;
                   cout << "-- CATEDRA ALGORITMOS Y ESTRUCTURAS DE DATOS --" << endl;
                   cout << "-------- TRABAJO PRACTICO CUATRIMESTRAL -------" << endl;
                   cout << "-----------------------------------------------\n" << endl;
                   cout << "MUCHAS GRACIAS POR UTILIZAR LA APLICACION" << endl;
                   cout << "---------- GRUPO 6 ----------" << endl;
               break;
               default:
                   system("cls");
                   cout << "----------------------------------" << endl;
                   cout << "-- OPCION INGRESADA INEXISTENTE --" << endl;
                   cout << "----------------------------------\n" << endl;
                   cout << "MENSAJE: LA OPCION INGRESADA ES INEXISTENTE, INTENTE NUEVAMENTE.";
                   Sleep(3000);
               break;
            }
        }
    }
}



void obtenerSucursales(ListaSucursal &listaSucursal){
    PtrNodoListaSucursal ptrNodoLista;
    ptrNodoLista = primeroSucursal(listaSucursal);
    system("cls");
        cout << "\n" << setw(16) << " Codigo de Sucursal" << "\t|" << setw(18) << "Provincia" << "\t|" << setw(25) << "Cantidad de Articulos" << "\t|"<<setw(25) << "Monto de Facturacion" << "\t|"<<setw(12) <<"m^2"<< "\t|"<<setw(18) <<"Casa Matriz"<< endl;
        while(ptrNodoLista != NULL)
        {
            cout << "\n" << setw(20) <<ptrNodoLista->dato.codSucursal<< "\t|" << setw(18) <<ptrNodoLista->dato.nombreProvincia<< "\t|" << setw(25) <<ptrNodoLista->dato.cantArticulosVendidos<< "\t|"<<setw(25)<< fixed << setprecision(2) <<ptrNodoLista->dato.montoFacturacion<< "\t|"<<setw(12) <<ptrNodoLista->dato.m2<<"\t|"<<setw(12) <<ptrNodoLista->dato.casaMatriz<< endl;
            ptrNodoLista = siguienteSucursal(listaSucursal, ptrNodoLista);
        }
        cout<<"\n";
        system("pause");
}



void rankingNacionalPorMontoFacturacion(ListaSucursal &listaSucursal){
    reordenarPorMonto(listaSucursal);
    obtenerSucursales(listaSucursal);
}


void rankingProvincialPorMontoFacturacion(ListaSucursal &listaSucursal,ListaProvincia &listaProvincia){
    system("cls");
    facturacionTotalPorProvincia(listaSucursal,listaProvincia);
    reordenarPorMonto(listaSucursal);
    reordenarPorMontoTotalDeFacturacion(listaProvincia);
    obtenerListaProvinciaConTotalMontoFacturacion(listaSucursal,listaProvincia);
    cout<<"\n"<<endl;
    system("pause");
}


void rankingNacionalPorCantArticulosVendidos(ListaSucursal &listaSucursal){
    reordenarPorCantArticulos(listaSucursal);
    obtenerSucursales(listaSucursal);
}



void rankingProvincialPorCantArticulosVendidos(ListaSucursal &listaSucursal,ListaProvincia &listaProvincia){
    system("cls");
    articulosTotalesVendidosPorProvincia(listaSucursal,listaProvincia);
    reordenarPorCantArticulos(listaSucursal);
    reordenarPorcantArticulosVendidos(listaProvincia);
    obtenerListaProvinciaConTotalArticulosVendidos(listaSucursal,listaProvincia);
    cout<<"\n"<<endl;
    system("pause");
}


void rankingRendimiento(ListaSucursal &listaSucursal,ListaCasaMatriz &listaCasaMatriz){
    system("cls");
    rendimientoTotalPorCasaMatriz(listaSucursal,listaCasaMatriz);
    reordenarPorMonto(listaSucursal);
    reordenarPorRendimiento(listaCasaMatriz);
    obtenerListaCasaMatriz(listaSucursal,listaCasaMatriz);
    cout<<"\n"<<endl;
    system("pause");
}


void facturacionTotalPorProvincia(ListaSucursal &listaSucursal, ListaProvincia &listaProvincia){
    float sumaMontoProvincia = 0;
    PtrNodoListaProvincia ptrNodoProvincia = primeroProvincia(listaProvincia);

        while( (!listaVaciaProvincia(listaProvincia)) && (ptrNodoProvincia != finProvincia()) ){

            PtrNodoListaSucursal ptrNodoSucursal = primeroSucursal(listaSucursal);

                while( (!listaVaciaSucursal(listaSucursal)) && (ptrNodoSucursal != finSucursal()) ){

                    if( strcmp(getNombreProvincia(ptrNodoProvincia->dato), getNombreProvincia(ptrNodoSucursal->dato)) == 0 ){
                        sumaMontoProvincia += getMontoFacturacion(ptrNodoSucursal->dato);
                    }
                  ptrNodoSucursal = ptrNodoSucursal->sgte;
                }
            setMontoTotal(ptrNodoProvincia->dato,sumaMontoProvincia);
            sumaMontoProvincia=0;
            ptrNodoProvincia = ptrNodoProvincia->sgte;
        }
}




void articulosTotalesVendidosPorProvincia(ListaSucursal &listaSucursal, ListaProvincia &listaProvincia){
    float sumaArticulosProvincia = 0;
    PtrNodoListaProvincia ptrNodoProvincia = primeroProvincia(listaProvincia);

        while( (!listaVaciaProvincia(listaProvincia)) && (ptrNodoProvincia != finProvincia()) ){

            PtrNodoListaSucursal ptrNodoSucursal = primeroSucursal(listaSucursal);

                while( (!listaVaciaSucursal(listaSucursal)) && (ptrNodoSucursal != finSucursal()) ){

                    if( strcmp(getNombreProvincia(ptrNodoProvincia->dato), getNombreProvincia(ptrNodoSucursal->dato)) == 0 ){
                        sumaArticulosProvincia += getCantArticulosVendidos(ptrNodoSucursal->dato);
                    }
                  ptrNodoSucursal = ptrNodoSucursal->sgte;
                }
            setTotalArticulosVendidos(ptrNodoProvincia->dato,sumaArticulosProvincia);
            sumaArticulosProvincia=0;
            ptrNodoProvincia = ptrNodoProvincia->sgte;
        }
}


void rendimientoTotalPorCasaMatriz(ListaSucursal &listaSucursal, ListaCasaMatriz &listaCasaMatriz){
    float sumaM2Sucursal = 0;
    float sumaMontoFacturacion=0;
    float rendimientoTotal=0;
    PtrNodoListaCasaMatriz ptrNodoCasaMatriz = primeroCasaMatriz(listaCasaMatriz);

        while( (!listaVaciaCasaMatriz(listaCasaMatriz)) && (ptrNodoCasaMatriz != finCasaMatriz()) ){

            PtrNodoListaSucursal ptrNodoSucursal = primeroSucursal(listaSucursal);

                while( (!listaVaciaSucursal(listaSucursal)) && (ptrNodoSucursal != finSucursal()) ){

                    if(getIdCasaMatriz(ptrNodoCasaMatriz->dato)==getCasaMatriz(ptrNodoSucursal->dato)){
                        sumaM2Sucursal += getM2(ptrNodoSucursal->dato);
                        sumaMontoFacturacion += getMontoFacturacion(ptrNodoSucursal->dato);
                    }
                  ptrNodoSucursal = ptrNodoSucursal->sgte;
                }
            rendimientoTotal=sumaMontoFacturacion/sumaM2Sucursal;
            setRendimiento(ptrNodoCasaMatriz->dato,rendimientoTotal);
            sumaM2Sucursal=0;
            sumaMontoFacturacion=0;
            rendimientoTotal=0;
            ptrNodoCasaMatriz = ptrNodoCasaMatriz->sgte;
        }
}


