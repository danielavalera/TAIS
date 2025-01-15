/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>



class CaminoMasCorto {
public:
    CaminoMasCorto(Digrafo const& g, int ini, int dest, int K) : visit(g.V(), false),
        ant(g.V()), dist(g.V()), ini(ini), dest(dest), minMov(0), llega(false) {
        bfs(g, K);
    }
    // ¿hay camino del origen a v?
    bool hayCamino(int v) const {
        return visit[v];
    }
    // número de aristas entre s y v
    int distancia(int v) const {
        return dist[v];
    }
    int getMin() const { return minMov; }
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
    int ini, dest, minMov;
    bool llega;
    void bfs(Digrafo const& g, int K) {
        std::queue<pair<int, int>> q;
        dist[ini] = 0; visit[ini] = true;
        q.push({ ini, 0 });
        while (!llega) {
            auto act = q.front(); q.pop();
            int k = 1;
            while (!llega &&  k <= K) {
                int ady = act.first + k;
                if (g.ady(ady).size() > 0) ady = g.ady(ady)[0];
                if (ady == dest) {
                    llega = true;
                    minMov = act.second + 1;
                }
                else if (!visit[ady]) {
                    visit[ady] = true;
                    q.push({ ady, act.second + 1 });
                }
                k++;
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, K, S, E; cin >> N >> K >> S >> E;
    if (N == 0)
        return false;
    Digrafo dg(N * N);
    for (int i = 0; i < S + E; i++) {
        int v, w; cin >> v >> w;
        dg.ponArista(v - 1, w - 1);
    }
    // resolver el caso posiblemente llamando a otras funciones
    CaminoMasCorto cam(dg, 0, dg.V() - 1, K);
    // escribir la solución
    cout << cam.getMin() << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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