
/*@ <authors>
 *
 * Daniela Valentina Valera Fuentes TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <climits>
#include <queue>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Este problema realiza un recorrido en profundidad donde el coste es V+A.
Faltaría encontrar el punto donde se encuentran ambos caminos.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

const int INF = 99999999;
class CaminoMasCorto {
public:
    CaminoMasCorto(Grafo const& g, int s) : visit(g.V(), false),
        ant(g.V()), dist(g.V(), INF), s(s) {
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
int sol(Grafo& grafo, int casaAlex, int casaLucas, int trabajo) {
    CaminoMasCorto alex(grafo, casaAlex);
    CaminoMasCorto lucas(grafo, casaLucas);
    CaminoMasCorto trabajoDist(grafo, trabajo);

    int minCoste = INF;

    for (int i = 0; i < grafo.V(); i++) {
        if (alex.hayCamino(i) && lucas.hayCamino(i) && trabajoDist.hayCamino(i)) {
            int costeTotal = alex.distancia(i) + lucas.distancia(i) + trabajoDist.distancia(i);
            minCoste = min(minCoste, costeTotal);
        }
    }

    return minCoste;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int nVertices, nAristas, casaAlex, casaLucas, trabajo;
    cin >> nVertices >> nAristas >> casaAlex >> casaLucas >> trabajo;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g = Grafo(nVertices);

    int a1, a2;
    for (int i = 0; i < nAristas; i++)
    {
        cin >> a1 >> a2;
        g.ponArista(a1 - 1, a2 - 1);
    }
    // resolver el caso posiblemente llamando a otras funciones
    int resultado = sol(g, casaAlex - 1, casaLucas - 1, trabajo - 1);
    // escribir la solución
    cout << resultado << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos4.L.txt");
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
