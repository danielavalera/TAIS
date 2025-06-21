
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Creamos un GRAFO donde los vértices son los personajes y las aristas (M) son las relaciones entre los personajes. Lo que hacemos es hacer la suma total mínima
 de cada componente conexa según el recorrido en profundidad por los vértices.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class mision {
private:
    vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    vector<int> ant; // ant[v] = último vértice antes de llegar a v
    int s; // vértice origen
    int coste;
    vector<int> precios;
    int dfs(Grafo const& G, int v) {
        visit[v] = true;
        int minimo = precios[v];
        for (int w : G.ady(v)) {
            if (!visit[w]) {
                ant[w] = v;
                minimo = min(dfs(G, w), minimo);
            }
        }
        return minimo;
    }
public:
    mision(Grafo const& g, vector<int> const& precios, int s) :
        visit(g.V(), 0), ant(g.V()), s(s),
        coste(0), precios(precios) {
        for (int i = 0; i < g.V(); i++)
        {
            if (!visit[i]) coste += dfs(g, i);
        }
    }

    int costeTotal() {
        return coste;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M; cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g(N);
    vector<int> oro(N);
    for (int i = 0; i < N; i++)
    {
        cin >> oro[i];
    }

    int v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> v >> w;
        g.ponArista( v - 1,w - 1);
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    cout << mision(g, oro, 0).costeTotal() << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR6.txt");
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