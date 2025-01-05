
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
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
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    ConjuntosDisjuntos cjtos;
public:
    Valor costeARM() const {
        return coste;
    }
    bool unidos(const int& a, const int& b) const {
        return cjtos.unidos(a,b);
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g,const int& origen, const int& destino) : coste(0), cjtos(g.V()) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        bool llega = false;
        while (!pq.empty() && !llega) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); coste = a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
            llega = cjtos.unidos(origen, destino);

        }
    }
};
bool resuelveCaso() {
    // leer los datos de la entrada
    int N, M; cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;

    GrafoValorado<int> gv(N);
    int v, w, p;
    for (int i = 0; i < M; i++)
    {
        cin >> v >> w >> p;
        gv.ponArista({ v - 1,w - 1,p });
    }
    int origen, destino;
    cin >> origen >> destino;
    origen--; destino--;
    // resolver el caso posiblemente llamando a otras funciones
    ARM_Kruskal<int> arm(gv, origen, destino);
    // escribir la solución
    if (origen == destino) cout << 0;
    else if (!arm.unidos(origen, destino)) cout << "IMPOSIBLE";
    else cout << arm.costeARM();
    cout << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR.1.txt");
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