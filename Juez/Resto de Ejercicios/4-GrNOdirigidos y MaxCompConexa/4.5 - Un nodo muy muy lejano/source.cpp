
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

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
    CaminoMasCorto(Grafo const& g, int s) : visit(g.V(), false),
        ant(g.V()), dist(g.V(), INT_MAX), s(s) {
        bfs(g);
    }
    // ¿hay camino del origen a v?
    bool hayCamino(int v) const {
        return visit[v];
    }
    // número de aristas entre s y v
    int distancia(int v) const {
        return dist[v];
    }
    int inalcanzable(int TTL) const {
        int alcanzable = 0;

        for (int i = 0; i < dist.size(); i++){
            if (dist[i] <= TTL) alcanzable++;
        }
        return dist.size() - alcanzable;
    }
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
    int s;
    void bfs(Grafo const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; 
                    dist[w] = dist[v] + 1; 
                    visit[w] = true;
                    q.push(w);
                }
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, C; cin >> N >> C;
    if (!std::cin)  // fin de la entrada
        return false;
    Grafo g(N);
    int u, v;
    for (int i = 0; i < C; i++){
        cin >> u >> v;
        g.ponArista(u - 1, v - 1);
    }

    int k; cin >> k;
    int s, TTL;
    for (int i = 0; i < k; i++){
        cin >> s >> TTL;
        cout << CaminoMasCorto(g, s - 1).inalcanzable(TTL) << "\n";
    }
    cout << "---\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos4.6.txt");
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