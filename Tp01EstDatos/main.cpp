/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: milto
 *
 * Created on 31 de agosto de 2018, 12:38
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: milto
 *
 * Created on 29 de agosto de 2018, 17:54
 */
#include<iostream>
#include <stdio.h>




using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
    int dato;
    pnodo sig;
};

void iniciarLista(pnodo &lista);
void crear(pnodo &nuevo) ;
void agregarInicio(pnodo &lista, pnodo nuevo);
void agregarFinal(pnodo &lista, pnodo nuevo) ;
void agregarEmOrden(pnodo &lista, pnodo nuevo) ;
pnodo quitarInicio(pnodo &lista) ;
pnodo quitarFinal(pnodo &lista) ;
pnodo quitarNodoX(pnodo &lista, int valor) ;
void mostrar(pnodo lista);
bool buscarNodo(pnodo lista, int valor);
void menu(int &opc);




int main(){
    pnodo lista, nuevo, eliminado;
    int opcion, valor;
    bool encontrado;
    do{
        menu(opcion);
        switch(opcion){
            case 1 : 
                iniciarLista(lista);
                break;
            case 2 : 
                crear(nuevo);
                agregarInicio(lista,nuevo);
                break;
            case 3 : 
                crear(nuevo);
                agregarFinal(lista,nuevo);
                break;    
            case 4 : 
                crear(nuevo);
                agregarEmOrden(lista,nuevo);
                break;
            case 5 : 
                eliminado = quitarInicio(lista);
                if (eliminado!=NULL) {
                    cout << "Se extrajo: "<< eliminado->dato << endl;
                } else {
                    cout << "No se pudo eliminar." << endl;
                }
                break;
            case 6 : 
                eliminado = quitarFinal(lista);
                if (eliminado = NULL) {
                    cout << "Se extrajo: " << eliminado->dato << endl;
                } else {
                    cout << "No se pudo eliminar. " << endl;
                }
                break;    
            case 7 : 
                cout << "Ingrese un Valor: ";
                cin >> valor;
                eliminado = quitarNodoX(lista, valor);
                if (eliminado != NULL) {
                    cout << "Se elimino el Valor indicdio" << endl;
                } else {
                    cout << "No se ha encontrado el Valor indicado. " << endl;
                }
                break;
            case 8 : 
                cout << "Ingrese un Valor: ";
                cin >> valor;
                if (buscarNodo(lista,valor)) {
                    cout << "Se encotro dentro de la lista" << endl;
                } else {
                    cout << "No se encontro dentro de la lista."<< endl;
                }
                break;
            case 9 : 
                mostrar(lista);
                break;    
            case 10 : 
                cout << "Ha Salido del Programa" << endl;
                cout << "Gracias..." << endl;
                break;
            default :  
                cout << "Error Opcion Invalida" << endl;
                cout << "Intente de Nuevo" << endl;
                break;        
        }
    }while(opcion != 10 ) ;
    cout << "salio";
    return 0;
    
}


//Menu De Opc
void menu(int &opc){
    system("CLS");
    cout << "_____________M E N U_____________" << endl;
    cout << "1 - Crear una Lista vacia (Inicializar)." << endl;
    cout << "2 - Agregar un nuevo Nodo al Inicio." << endl;
    cout << "3 - Agregar un nuevo Nodo al Final." << endl;
    cout << "4 - Agregar un nuevo Nodo en Orden." << endl;
    cout << "5 - Quitar el primer nodo de la lista." << endl;
    cout << "6 - Quitar el Ultimo Nodo de la Lista." << endl;
    cout << "7 - Quitar el nodo con el Valor X." << endl;
    cout << "8 - Buscar Dato en la Lista." << endl;
    cout << "9 - Mostar Lista." << endl;
    cout << "10 - Salir del Programa." << endl;
    cout << "" << endl;
    cin >> opc;
}

//Iniciar la lista.
void iniciarLista(pnodo &lista){
    lista = NULL;
}

// Crear un Nodo
void crear(pnodo &nuevo){
    nuevo = new tnodo;
    if (nuevo != NULL){
        cout << "Ingrese el Valor: " << endl;
        cin >> nuevo -> dato ;
        nuevo -> sig = NULL;
    } else {
        cout << "Memoria Insufiente" << endl;
    }
}

//Agregar al inicio de un nodo
void agregarInicio(pnodo &lista, pnodo nuevo){
    nuevo ->sig = lista;
    lista = nuevo;
}

//Agregar un Nodo al final de la lista
void agregarFinal(pnodo &lista, pnodo nuevo){
    pnodo i ;
    if (lista == NULL) {
        lista = nuevo;
    }else{
        for(i = lista ; i -> sig != NULL; i = i ->sig){
            i -> sig = nuevo;
        }
    }
}

//Agregar un nodo en orden
void agregarEmOrden(pnodo &lista, pnodo nuevo){
    pnodo i ;
    if (lista= NULL) {
        lista = nuevo ;
    }else{
        if (nuevo->dato < lista->dato) {
            nuevo->sig = lista;
            lista = nuevo;
        }else{
            for (i = lista ; i->sig != NULL && nuevo->dato > (i->sig)->dato ; i = i->sig);
                nuevo->sig = i->sig;
                i->sig = nuevo;
        }
    }
}

//Quitar un dato al inicio
pnodo quitarInicio(pnodo &lista){
    pnodo borrado;
    if (lista == NULL){
        borrado=NULL;
    }else{
        borrado=lista;
        lista = lista->sig;
        borrado->sig = NULL;
    }
    return borrado;
}

//Quitar el ultimo nodo de la lista
pnodo quitarFinal(pnodo &lista){
    pnodo borrado, i;
    if (lista == NULL) {
        borrado  = NULL;
    }else{
        if (lista->sig  == NULL) {
            borrado=lista;
            lista= NULL;
        }else{
            for(i = lista; (i->sig)->sig != NULL ; i=i->sig );
			borrado = i->sig ;
			i->sig = NULL ;
        }
    }
    return  borrado;
}

//Quitar un nodo de X valor de la lista
pnodo quitarNodoX(pnodo &lista, int valor){
    pnodo borrado, i;
    if (lista == NULL) {
        borrado=NULL;
    } else {
        if (lista->dato = valor) {
            borrado=lista;
            lista=borrado->sig;
            borrado->sig=NULL;
        } else {
            for(i=lista; i->sig != NULL && valor != (i->sig)->dato ; i=i->sig) ;
            if (i->sig!=NULL) {
                borrado= i->sig;
                i->sig= borrado->sig;
                borrado->sig=NULL;
            } else {
                borrado=NULL;
            }

        }

    }
    return borrado;
}

//Muestra del COntenido de la Lista
void mostrar(pnodo lista){
    pnodo i ;
    if (lista != NULL) {
        for(i= lista; i != NULL ; i=i->sig ){
        cout << "Nodo: " << i->dato<< endl;
    }
    } else {
        cout << "Lista Vacia." << endl;
    }
}

//Busca si el Valor se encuentra en la Lista
bool buscarNodo(pnodo lista, int valor){
    pnodo i;
    bool encontrado = false;
    if (lista != NULL){
        for(i=lista ; i != NULL && encontrado == false ; i = i->sig){
            if (i->dato == valor) {
                encontrado = true;
            }
        }
    }       
    return encontrado;
}

