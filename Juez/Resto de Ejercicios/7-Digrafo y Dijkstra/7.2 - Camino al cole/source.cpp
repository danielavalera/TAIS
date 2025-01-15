
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
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
const int INF = 999999999;
template <typename Valor>
class Dijkstra {
private:
    int origen;
    vector<Valor> dist;
    vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    vector<Valor> numCaminos;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            ulti[w] = a;
            pq.update(w, dist[w]);
            numCaminos[w] = numCaminos[v];
        }
        else if (dist[w] == dist[v] + a.valor())
            numCaminos[w] += numCaminos[v];
    }
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()), numCaminos(g.V(), 0) {
        dist[origen] = 0;
        numCaminos[origen] = 1;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    Valor numeroCaminos(int v) const { return numCaminos[v]; }

};
bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    int C; cin >> C;
    int u, v, peso;
    DigrafoValorado<long long int> dv(N);
    for (int i = 0; i < C; i++){
        cin >> u >> v >> peso;
        dv.ponArista({ u - 1,v - 1,peso });
        dv.ponArista({ v - 1,u - 1,peso });
    }
    // resolver el caso posiblemente llamando a otras funciones
    Dijkstra<long long int> djs(dv, 0);
    // escribir la solución
    auto nc = djs.numeroCaminos(N - 1);
    if (djs.hayCamino(N - 1)) cout << nc << "\n";
    else cout << "0\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos7.2.txt");
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