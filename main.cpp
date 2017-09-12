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
    arbol.insertar(8);
    arbol.mostrarArbol();
    arbol.imprimeAcendente();

    
    return 0;
}
