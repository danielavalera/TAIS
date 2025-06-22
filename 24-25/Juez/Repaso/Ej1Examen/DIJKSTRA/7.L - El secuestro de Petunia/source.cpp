
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
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
    Dijkstra(DigrafoValorado<Valor> const& g, vector<int>& origenes, int D) : alcanzables(0),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()) {

        for (int i : origenes) {
            dist[i - 1] = 0;
            pq.push(i - 1, 0);
        }

        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            if (dist[v] <= D) {
                alcanzables++;
                for (auto a : g.ady(v))
                    relajar(a);
            }
        }
    }
    int getAlcanzables() { return alcanzables; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int alcanzables;
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
    int D, P, C, v, w, valor, B; cin >> D >> P >> C;
    if (!std::cin)  // fin de la entrada
        return false;

    DigrafoValorado<int> digrafo(P);
    for (int i = 0; i < C; i++)
    {
        cin >> v >> w >> valor;
        digrafo.ponArista({v-1,w-1,valor});
        digrafo.ponArista({ w - 1,v - 1,valor });
    }

    cin >> B;
    int cont = 0;
    vector<int>origenes(B);
    for (int& i : origenes) cin >> i;
    // resolver el caso posiblemente llamando a otras funciones
    Dijkstra<int> dj(digrafo, origenes, D);
    // escribir la solución
    cout << dj.getAlcanzables() << '\n';
    return true;
    
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos7.L.txt");
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