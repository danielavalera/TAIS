
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS 108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
//#include <...>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 ACLARACIONES:
 --------------
    n = filas matriz
    m = columnas matriz
    mtz[i][j] = salto que tiene que dar desde la posicion ij de la matriz


 RECURSIÓN:
 -------------
 maneras(i,j) = número de maneras distintas para ir desde la posicion ij a la NM

 maneras(i,j) = maneras(i, j + Aij) + maneras(i + Aij, j)

 Esto significa que las formas de llegar a (i, j) se calculan como la suma de las formas de llegar a las posiciones posibles desde las que se puede saltar hacia (i, j):
    - Desde (i, j + Aij) si el salto hacia la derecha es posible.
    - Desde (i + Aij, j) si el salto hacia abajo es posible.

 CASOS BASE:
 --------------
 maneras(n,m) = 1 (hemos llegado)
 maneras(i,j) = 0 si i > n & j > m

 Llamada inicial: maneras(1,1)

 COSTE:
 -------
 El problema se define sobre una matriz de tamaño n*m, lo que significa que el algoritmo debe procesar n*m celdas.
 Cada celda se evalúa una única vez durante el recorrido de los bucles. Por lo tanto el algoritmo tiene un coste de O(n*m)
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int progDinamica(Matriz<int> const& matriz,int n, int m) {
    Matriz<int> sol(n, m, 0);
    //caso base
    sol[0][0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (sol[i][j] > 0) {
                int salto = matriz[i][j];

                // hacia abajo
                if (i + salto < n) 
                    sol[i + salto][j] += sol[i][j];
                

                // hacia la derecha
                if (j + salto < m) 
                    sol[i][j + salto] += sol[i][j];
                
            }
        }
    }
    return sol[n-1][m-1];
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m; cin >> n >> m;
    if (!std::cin)  // fin de la entrada
        return false;

    Matriz<int> mtz(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> mtz[i][j];
    }

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    cout << progDinamica(mtz,n,m) << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR7.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}