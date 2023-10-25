/*@ <answer>
 *
 * Nombre y Apellidos:
 * Daniela Valera Fuentes TAIS66
 * Felipe Martin Reyes TAIS36
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "ConjutosDisjuntos.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"// propios o los de las estructuras de datos de clase

/*@ <answer>

    El problema se resuelve con el uso del algoritmo Kruskal, con una modificación que guarda el menor depósito. Este es valor de la mayor arista que necesitamos para construir
    el grafo con una única componente conexa (conjunto disjunto). Si obtenemos una sola componente conexa se mostrará el valor de la arista de mayor valor, en caso que 
    haya mas de una componente se mostrará "Imposible".

    El coste del algoritmo es de O(MlogM), siendo M el número de aristas. 
    El coste de leer los datos es lineal respecto al número de aristas O(M).
    El coste total es O(MlogM).
    
 @ </answer> */


 // ================================================================
 // Escribe el c digo completo de tu soluci n aqu  debajo
 // ================================================================
 //@ <answer>
template <typename Valor>
class Autonomia {
private:
    std::vector<Arista<Valor>> aristas;
    Valor autMin;
    ConjuntosDisjuntos cjtos;
public:
    int getComponentesConexas() {
        return cjtos.num_cjtos();
    }
    Valor getAtonomiaMin() const {
        return autMin;
    }
    std::vector<Arista<Valor>> const& getAristas() const {
        return aristas;
    }
    Autonomia(GrafoValorado<Valor> const& g) : autMin(0), cjtos(g.V()) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                aristas.push_back(a);
                if (a.valor() > autMin)
                    autMin = a.valor();
                if (aristas.size() == g.V() - 1) break;
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N = 0, M = 0;
    std::cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;

    GrafoValorado <int>g(N);
    for (int i = 0; i < M; i++) {
        int v = 0, w = 0, c = 0;
        std::cin >> v >> w >> c;
        g.ponArista({ v - 1, w - 1, c });
    }
    // resolver el caso posiblemente llamando a otras funciones
    Autonomia <int> coches(g);
    // escribir la soluci n
    if (coches.getComponentesConexas() == 1)
        std::cout << coches.getAtonomiaMin() << "\n";
    else 
        std::cout << "Imposible" << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l nea ya no forma parte de la soluci n.

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
