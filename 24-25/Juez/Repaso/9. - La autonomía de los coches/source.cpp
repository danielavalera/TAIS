
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
//#include <...>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"

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
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    ConjuntosDisjuntos cd;
public:
    Valor costeARM() const {
        return coste;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    int getNumCjtos() const {
        return cd.num_cjtos();
    }

    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), cd(g.V()) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cd.unidos(v, w)) {
                cd.unir(v, w);
                _ARM.push_back(a); 
                if (a.valor() > coste)
                    coste = a.valor();
                if (_ARM.size() == g.V() - 1) 
                    break;
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M, v1, v2, peso; cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;

    GrafoValorado<int> g(N);
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2 >> peso;
        g.ponArista({ v1 - 1,v2 - 1,peso });
    }
    // resolver el caso posiblemente llamando a otras funciones
    ARM_Kruskal<int> arm(g);

    // escribir la solución
    if (arm.getNumCjtos() == 1)
        cout << arm.costeARM() << "\n";
    else
        cout << "Imposible" << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR9.txt");
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