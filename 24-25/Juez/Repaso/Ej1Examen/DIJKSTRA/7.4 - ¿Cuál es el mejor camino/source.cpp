/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
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
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()), aristas(g.V(), INF) { //INICIALIZAR ARISTAS
        dist[origen] = 0;
        aristas[origen] = 0; //DAMOS VALOR AL PRIMER VALOR DE ARISTAS
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    int minAristas(int v) const { return aristas[v]; } //AÑADIMOS MÉTODO QUE NECESITAMOS
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    vector<int> aristas;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;     
            aristas[w] = aristas[v];                    //AÑADIMOS
            aristas[w]++;                               //AÑADIMOS
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor() && aristas[w] > aristas[v] + 1) { //AÑADIMOS LÓGICA
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            aristas[w] = aristas[v];
            aristas[w]++;
            pq.update(w, dist[w]);
        }
    }
};

template <typename Valor>
class BFSDirigido {
public:
    BFSDirigido(DigrafoValorado<Valor> const& g, int s) : visit(g.V(), false),
        ant(g.V()), dist(g.V()), s(s) {
        bfs(g);
    }
    bool hayCamino(int v) const {
        return visit[v];
    }
    int distancia(int v) const {
        return dist[v];
    }
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s->v más corto
    int s;
    void bfs(DigrafoValorado<Valor> const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto A : g.ady(v)) {               //SE HA MODIFICADO xq...
                int  w = A.hasta();                 //SE HA MODIFICADO ...es un DigrafoValorado
                if (!visit[w]) {
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
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

    DigrafoValorado<int> dv(N);
    int u, v, peso;
    for (int i = 0; i < C; i++){
        cin >> u >> v >> peso;
        dv.ponArista({ u - 1,v - 1,peso });
        dv.ponArista({ v - 1,u - 1,peso });
    }

    int K; cin >> K;
    int origen, destino;
    for (int i = 0; i < K; i++){
        cin >> origen >> destino;
        Dijkstra<int> coste(dv, origen - 1);
        if (coste.hayCamino(destino - 1)) {
            int costeMin = coste.distancia(destino - 1);
            int tamCosteMin = coste.minAristas(destino - 1);
            cout << costeMin << " ";

            BFSDirigido<int> bfs(dv, origen - 1);
            int tamBFS = bfs.distancia(destino - 1);

            if (tamCosteMin == tamBFS) cout << "SI\n";
            else cout << "NO\n";

        }
        else
            cout << "SIN CAMINO\n";
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
    std::ifstream in("casos7.4.txt");
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