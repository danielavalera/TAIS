
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
class Mision {
    private:
        std::vector<bool> visit;
        std::vector<int> costos;
        int coste;

        int dfs(Grafo const& g, int v) {
            visit[v] = true;
            int minimo = costos[v];
            for (int w : g.ady(v)) {
                if (!visit[w]) minimo = min(dfs(g, w), minimo);
            }
            return minimo;
        }
    public:
        Mision(Grafo const& g, std::vector<int> const& c) : visit(g.V(), false), costos(c), coste(0) {
            for (int i = 0; i < g.V(); i++) {
                if (!visit[i]) coste += dfs(g, i);
            }
        }
        int getCoste() { return coste; }
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M;
    std::cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector<int> costos(N);
    Grafo g(N);
    for (int i = 0; i < N; i++) std::cin >> costos[i];
    int u, w;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> w;
        g.ponArista(u - 1, w - 1);
    }
    // resolver el caso posiblemente llamando a otras funciones
    Mision m(g, costos);
    // escribir la soluci�n
    std::cout << m.getCoste() << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
