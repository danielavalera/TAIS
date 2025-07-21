
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <limits>
#include <deque>
#include <vector>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"
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
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, C; cin >> N >> C;
    if (!std::cin)  // fin de la entrada
        return false;

    DigrafoValorado<int> ida(N);
    DigrafoValorado<int> vuelta(N);
    int u, v, peso;
    for (int i = 0; i < C; i++){
        cin >> u >> v >> peso;
        ida.ponArista({ u - 1,v - 1,peso });
        vuelta.ponArista({ v - 1,u - 1,peso });
    }
    int origen, paquetes; cin >> origen >> paquetes;
    // resolver el caso posiblemente llamando a otras funciones
    Dijkstra<int> dijs_ida(ida, origen - 1);
    Dijkstra<int> dijs_vuelta(vuelta, origen - 1);
    int destino;
    int distancia = 0;
    bool camino = true;
    // escribir la solución
    for (int i = 0; i < paquetes; i++) {
        cin >> destino;
        if (dijs_ida.hayCamino(destino - 1) && dijs_vuelta.hayCamino(destino - 1)) {
            distancia += dijs_ida.distancia(destino - 1);
            distancia += dijs_vuelta.distancia(destino - 1);
        }
        else {
            cout << "IMPOSIBLE\n";
            camino = false;
        }
    }
    if (camino) cout << distancia << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos7.5.txt");
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