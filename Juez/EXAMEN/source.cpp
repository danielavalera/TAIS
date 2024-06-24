
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

template <typename Valor>
class ARM_Kruskal {
private:
    vector<Arista<Valor>> _ARM;
    int maxPeso,s,d;
    ConjuntosDisjuntos cjtos;
public:
    int getMaxPeso() const {
        return maxPeso;
    }
    int getHayCaminos() const {
        return cjtos.unidos(s, d);
    }
    vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g, const int& s, const int& d) : maxPeso(0), s(s), d(d), cjtos(g.V()) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        bool llega = cjtos.unidos(s, d);
        while (!pq.empty() && !llega) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a);
                if(maxPeso = max(maxPeso, a.valor())) maxPeso = a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
            llega = cjtos.unidos(s, d);
        }
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada
    int v, e; cin >> v >> e;
    if (!std::cin)  // fin de la entrada
        return false;

    GrafoValorado<int> g(v);
    for (int i = 0; i < e; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        g.ponArista({ v1 - 1, v2 - 1, w });
    }

    // resolver el caso posiblemente llamando a otras funciones
    int source, dest; cin >> source >> dest;
    ARM_Kruskal<int> arm(g, source-1, dest-1);
    // escribir la solución
    if (!arm.getHayCaminos()) cout << "IMPOSIBLE" << "\n";
    else cout << arm.getMaxPeso() << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("XE1.txt");
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