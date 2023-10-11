
/*@ <authors>
 *
 * Daniela Valentina Valera Fuentes TAIS66
 * Felipe Martín Reyes TAIS36
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <climits>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Este problema realiza un recorrido en profundidad donde el coste es V+A.
Faltaría encontrar el punto donde se encuentran ambos caminos.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int sol(Grafo& grafo, int casaAlex, int casaLucas, int trabajo) {
    // Aplica un algoritmo de búsqueda en profundidad para encontrar el costo mínimo.
    vector<bool> visitado(grafo.V(), false);

    // Función recursiva para buscar el costo mínimo.
    function<int(int, int)> dfs = [&](int v, int destino) {
        if (v == destino) return 0;
        visitado[v] = true;
        int minCoste = INT_MAX;

        for (int w : grafo.ady(v)) {
            if (!visitado[w]) {
                int coste = dfs(w, destino);
                if (coste != INT_MAX) {
                    minCoste = min(minCoste, 1 + coste);
                }
            }
        }

        visitado[v] = false;
        return minCoste;
    };

    // Calcula el costo mínimo total para llegar al trabajo desde las casas de Alex y Lucas.
    int costoTotal = dfs(casaAlex, trabajo) + dfs(casaLucas, trabajo);

    return costoTotal;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int nVertices, nAristas, casaAlex, casaLucas, trabajo;
    cin >> nVertices >> nAristas >> casaAlex >> casaLucas >> trabajo;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g = Grafo(nVertices);

    int a1, a2;
    for (int i = 0; i < nAristas; i++)
    {
        cin >> a1 >> a2;
        g.ponArista(a1 - 1, a2 - 1);
    }
    // resolver el caso posiblemente llamando a otras funciones
    int resultado = sol(g, casaAlex - 1, casaLucas - 1, trabajo - 1);
    // escribir la solución
    cout << resultado << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos4.E.txt");
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
