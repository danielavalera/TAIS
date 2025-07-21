
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
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
const int INF = 999999999;
template <typename Valor>
class Dijkstra {
private:
    int origen;
    std::vector<int> dist;
    vector<Valor> tsCarga;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() + tsCarga[w]) {
            dist[w] = dist[v] + a.valor() + tsCarga[w];
            ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig, vector<Valor> const& tCarga) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()), tsCarga(g.V()) {
        tsCarga = tCarga;
        dist[origen] = tsCarga[0];
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }

};
bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (N == 0)
        return false;

    vector<int> tCarga(N);
    for (int i = 0; i < N; i++) cin >> tCarga[i];

    int M; cin >> M;
    int u, v, peso;
    DigrafoValorado<int> dv(N);
    for (int i = 0; i < M; i++){
        cin >> u >> v >> peso;
        dv.ponArista({ u - 1, v - 1, peso });
    }
    // resolver el caso posiblemente llamando a otras funciones
    Dijkstra<int> dijstra(dv, 0, tCarga);
    // escribir la solución
    if (dijstra.hayCamino(N - 1))
        cout << dijstra.distancia(N - 1) << "\n";
    else cout << "IMPOSIBLE\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos7.1.txt");
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