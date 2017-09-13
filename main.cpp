//
//  main.cpp
//  arbolesBalanceados
//
//  Created by Antony Morales on 9/6/17.
//  Copyright © 2017 Antony Morales. All rights reserved.
//

#include "arboles.h"

int main(int argc, const char * argv[]) {
    
    ArbolBinario<float> arbol;
    
    arbol.insertar(50);
    arbol.insertar(55);
    arbol.insertar(58);
    arbol.insertar(40);
    arbol.insertar(45);
    arbol.insertar(52);
    arbol.insertar(5);
    arbol.insertar(4);
    arbol.insertar(2);
    arbol.insertar(60);
    arbol.insertar(70);
    arbol.insertar(80);
    arbol.insertar(90);
    arbol.mostrarArbol();
    arbol.imprimeAcendente();
    cout << endl;
    arbol.imprimeDecendente();
    cout << endl;
    cout << "Altura del arbol: " << arbol.obtenerAlturaRaiz() << endl;
    
    cout << "Altura del nodo: " << arbol.obtenerAlturaNodo(40) << endl;
    
    cout << "Nivel del nodo: " << arbol.obtenerNivel(55) << endl;
    cout << endl;
    arbol.mostrarArbol();
    return 0;
}
