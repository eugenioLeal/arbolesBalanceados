//
//  arboles.h
//  arbolesBalanceados
//
//  Created by Antony Morales on 9/6/17.
//  Copyright © 2017 Antony Morales. All rights reserved.
//

#include "header.h"

/*********************************************************************
 *************************** Árbol AVL *********************************
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

    void mostrarArbol(){
        mostrarArbolTail(raiz, 0);
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

    void imprimeDecendente(){
        imprimeDecendenteTail(raiz);
    }

    NodoB* buscar(T dato){
        return buscarTail(dato, raiz);
    }

    int obtenerAlturaRaiz(){
        int altura;
        altura = obtenerAlturaTail(raiz);
        return altura;
    }

    int obtenerAlturaNodo(T dato){
        int altura;
        NodoB *t = buscar(dato);
        if(t){
            altura = obtenerAlturaTail(t);
            return altura;
        }else{
            return -1;
        }

    }

    int obtenerNivel(T dato){
        int nivel = -1;
        NodoB *t = buscar(dato);
        NodoB *raizN = raiz;
        if(t){
            nivel += 1;
            while (t != raizN) {
                if(raizN->dato == dato){
                    return nivel += 1;
                }else if(raizN->dato > dato){
                    raizN= raizN->izq;
                    nivel += 1;
                }else{
                    raizN = raizN->der;
                    nivel +=1;
                }
            }
        }
        return nivel;
    }


    int dif(NodoB *nodo){
        int d;
        int i_obtenerAltura = obtenerAlturaTail(nodo->izq);
        int d_obtenerAltura = obtenerAlturaTail(nodo->der);
        d = (i_obtenerAltura - d_obtenerAltura);
        return d;
    }

    NodoB* rotacionDD(NodoB *padre){
        NodoB *temp;
        temp = padre->der;
        padre->der = temp->izq;
        temp->izq = padre;
        return temp;
    }

    NodoB* rotacionII(NodoB *padre){
        NodoB* temp;
        temp = padre->izq;
        padre->izq = temp->der;
        temp->der = padre;
        return temp;
    }

    NodoB* rotacionID(NodoB *padre){
        NodoB* temp = padre->izq;
        padre->izq = rotacionDD(temp);
        return rotacionII(padre);
    }

    NodoB* rotacionDI(NodoB *padre){
        NodoB* temp = padre->der;
        padre->der = rotacionII(temp);
        return rotacionDD(padre);
    }

    NodoB* balancear(NodoB *nodo){
        int balanceFactor = dif(nodo);

        if (balanceFactor > 1) {
            if (dif (nodo->izq) > 0) {
                nodo = rotacionII(nodo);
            } else {
                nodo = rotacionID(nodo);
            }
        } else if (balanceFactor < -1) {
            if (dif(nodo->der) > 0) {
                nodo = rotacionDI(nodo);
            } else {
                nodo = rotacionDD(nodo);
            }
        }

        return nodo;
    }

private:
    NodoB* buscarTail(T dato, NodoB *lugar){
        NodoB *t = raiz;
        NodoB *falso;
        falso = NULL;

        while (t != NULL) {
            if(t->dato == dato){
                lugar = t;
                return t;
            }else if(t->dato > dato){
                t= t->izq;
            }else{
                t = t->der;
            }
        }
        return falso;
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

    void imprimeDecendenteTail(NodoB *nodo){
        if(nodo == NULL){
            return;
        }
        imprimeDecendenteTail(nodo->der);
        cout << nodo->dato << ", ";
        imprimeDecendenteTail(nodo->izq);
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

    void insertarTail(NodoB *&nodo, T dato){
        if(nodo == NULL){
            //cout << "LA raiz es: " << dato << endl;
            NodoB *n = new NodoB(dato);
            nodo = n;
        }else{
            //cout << "al eslse: " << endl;
            if(dato < nodo->dato){
                insertarTail(nodo->izq, dato);
                nodo = balancear(nodo);
            }else{
                insertarTail(nodo->der, dato);
                nodo = balancear(nodo);
            }
        }
    }

    int obtenerAlturaTail(NodoB *nodo){
        int a = 0;
        if(nodo){
            int i_obtenerAltura = obtenerAlturaTail(nodo->izq);
            int d_obtenerAltura = obtenerAlturaTail(nodo->der);
            int max = std::max(i_obtenerAltura, d_obtenerAltura);
            a = max + 1;
        }
        return a;
    }

};



/*********************************************************************
 *********************** Árbol Rojinegro ******************************
 *********************************************************************/
