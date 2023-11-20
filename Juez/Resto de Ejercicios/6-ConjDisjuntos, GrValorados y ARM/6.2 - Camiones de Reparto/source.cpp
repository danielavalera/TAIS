
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class CamionesReparto {
private:
    vector<bool> visit;
    bool alcanzado;

    // visita los nodos alcanzables desde v respetando el umbral
    void dfs(GrafoValorado<int> const& G, int v, int destino, int anchura) {
        visit[v] = true;
        int cont = 0;
        while (!alcanzado && cont < G.ady(v).size()) {
            if (G.ady(v)[cont].valor() >= anchura) {
                int sig = G.ady(v)[cont].uno();
                if(sig == v)
                    sig = G.ady(v)[cont].otro(sig);
                if (sig == destino)
                    alcanzado = true;
                else if (!visit[sig])
                    dfs(G, sig, destino, anchura);
            }
            ++cont;
        }
    }

public:
    CamionesReparto(GrafoValorado<int> const& gv, int origen, int destino, int anchura) : visit(vector<bool>(gv.V(), false)), alcanzado(false) {
        dfs(gv, origen, destino, anchura);
    }

    bool hayCamino() {
        return alcanzado;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A; cin >> V >> A;
    GrafoValorado<int> grafo(V);
    if (!std::cin)  // fin de la entrada
        return false;

    int u, v, valor;
    for (int i = 0; i < A; ++i) {
        cin >> u >> v >> valor;
        grafo.ponArista({ u -1, v-1, valor });
    }

    int k; cin >> k;
    int origen, destino, anchura;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < k; i++)
    {
        cin >> origen >> destino >> anchura;
        CamionesReparto sol(grafo, origen - 1, destino - 1, anchura);
        if (sol.hayCamino()) cout << "SI";
        else cout << "NO";
        cout << '\n';
    }
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos6.2.txt");
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
