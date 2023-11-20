
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
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
class Aeropuertos {
private:
    Valor costeAeropuerto;
    ConjuntosDisjuntos cjtos;
    Valor coste;
public:
    Valor costeARM() const {
        return coste;
    }
    
    int getcjtos() {
        return cjtos.num_cjtos();
    }

    Aeropuertos(GrafoValorado<Valor> const& g, const int&a) : coste(0), cjtos(g.V()), costeAeropuerto(a) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        int visit = 0;
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (a.valor() < costeAeropuerto && !cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                coste += a.valor();
                ++visit;
                if (visit == g.V()) break;
            }
        }
    }
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M, A; cin >> N >> M >> A;
    if (!std::cin)  // fin de la entrada
        return false;

    GrafoValorado<int> g(N);
    int v, w, valor;
    for (int i = 0; i < N; i++)
    {
        cin >> v >> w >> valor;
        g.ponArista({v-1, w-1, valor});
    }
    // resolver el caso posiblemente llamando a otras funciones
    Aeropuertos<int> aer(g, A);
    int aeropuertos = aer.getcjtos();
    int coste = aer.costeARM();

    // escribir la solución
    cout << aeropuertos * A + coste << " " << aeropuertos << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos6.4.txt");
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
