//
//  arboles.h
//  arbolesBalanceados
//
//  Created by Antony Morales on 9/6/17.
//  Copyright © 2017 Antony Morales. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

/*********************************************************************
 *************************** Árbol Binario *********************************
 *********************************************************************/

//Arbol binario de búsqueda
template <class T>
class ArbolBinario{
public:
    struct NodoB{
        T dato;
        NodoB *izq;
        NodoB *der;

        NodoB(T d){
            dato = d;
            izq = NULL;
            der = NULL;
        }
    };

    NodoB *raiz = NULL;

    void insertar(T dato){
        insertarTail(raiz, dato);
    }


    void insertarTail(NodoB *&nodo, T dato){
        if(nodo == NULL){
            //cout << "LA raiz es: " << dato << endl;
            NodoB *n = new NodoB(dato);
            nodo = n;
        }else{
            //cout << "al eslse: " << endl;
            if(dato < nodo->dato){
                insertarTail(nodo->izq, dato);
            }else{
                insertarTail(nodo->der, dato);
            }
        }
    }

    void mostrarArbol(){
        mostrarArbolTail(raiz, 0);
    }

    void mostrarArbolTail(NodoB *nodo, int cont){
        if(nodo == NULL){
            return;
        }else{
            mostrarArbolTail(nodo->der, cont+1);
            for(int i = 0; i<cont; i++){
                cout << "    ";
            }
            cout << nodo->dato << endl;
            mostrarArbolTail(nodo->izq, cont+1);
        }
    }

    bool elimina(T dato){
        NodoB *t = raiz;
        NodoB *padre = raiz;
        int contador = 0;

        while (t != NULL) {
            if(t->dato == dato){
                break;
            }else if(t->dato > dato){
                t= t->izq;
            }else{
                t = t->der;
            }
            contador++;
        }


        for(int i = 0; i<contador-1;i++){
            if(padre->dato > dato){
                padre= padre->izq;
            }else{
                padre = padre->der;
            }
        }


        if(t->izq == NULL && t->der == NULL){
            if(padre->izq->dato == t->dato){
                padre->izq = NULL;
            }else{
                padre->der = NULL;
            }
        }

        return false;
    }

    void imprimeAcendente(){
        imprimeAcendenteTail(raiz);
    }

    void imprimeAcendenteTail(NodoB *nodo){
        if(nodo == NULL){
            return;
        }else{
            imprimeAcendenteTail(nodo->izq);
            cout << nodo->dato << ", ";
            imprimeAcendenteTail(nodo->der);
        }
    }

    bool buscar(T dato){
        buscarTail(dato, raiz);
    }

    bool buscarTail(T dato, NodoB *&lugar){
        NodoB *t = raiz;

        while (t != NULL) {
            if(t->dato == dato){
                lugar = t;
                return true;
            }else if(t->dato > dato){
                t= t->izq;
            }else{
                t = t->der;
            }
        }
        return false;
    }

};
/*********************************************************************
 *************************** Árbol AVL *********************************
 *********************************************************************/



/*********************************************************************
 *********************** Árbol Rojinegro ******************************
 *********************************************************************/




/*********************************************************************
 *********************** Árbol Rojinegro ******************************
 *********************************************************************/




// Nodo ******************************************************
