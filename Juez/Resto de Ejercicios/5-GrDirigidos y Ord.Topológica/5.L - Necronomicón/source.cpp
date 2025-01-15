/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

class CicloDirigido {
public:
    CicloDirigido(Digrafo const& g) : visit(g.V(), false), ant(g.V()),
        apilado(g.V(), false), hayciclo(false), alcanzado(false) {
        dfs(g, 0);
    }
    bool hayCiclo() const { return hayciclo; }
    int getAlcanzado() const { return alcanzado; }
private:
    std::vector<bool> visit; // visit[v] = ¿se ha alcanzado a v en el dfs?
    std::vector<int> ant; // ant[v] = vértice anterior en el camino a v
    std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
    bool hayciclo, alcanzado;
    void dfs(Digrafo const& g, int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (w == g.V() - 1) alcanzado = true;
            else if (apilado[w]) hayciclo = true;
            else if (!visit[w]) dfs(g, w);
        }
        apilado[v] = false;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    Digrafo dg(N + 1);
    for (int i = 0; i < N; i++) {
        char l; cin >> l;
        if (l == 'A') {
            dg.ponArista(i, i + 1);
        }
        else {
            int s; cin >> s;
            if (l == 'J') {
                dg.ponArista(i, s - 1);
            }
            else {
                dg.ponArista(i, s - 1);
                dg.ponArista(i, i + 1);
            }
        }
            
    }
    // resolver el caso posiblemente llamando a otras funciones
    CicloDirigido cd(dg);
    // escribir la solución
    if (!cd.getAlcanzado()) cout << "NUNCA";
    else if (cd.hayCiclo()) cout << "A VECES";
    else cout << "SIEMPRE";
    cout << '\n';
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