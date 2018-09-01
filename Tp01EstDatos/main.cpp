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

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
    int dato;
    pnodo sig;
};

int main(){
}

//Menu De Opc
void menu(int &opc){
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






















