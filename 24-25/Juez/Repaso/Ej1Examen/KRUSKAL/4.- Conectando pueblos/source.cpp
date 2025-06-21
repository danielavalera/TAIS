
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
//#include <...>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "GrafoValorado.h"
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
    ConjuntosDisjuntos cjtos;
public:
    Valor costeARM() const {
        return coste;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }

    int getNumCjtos() const{
        return cjtos.num_cjtos();
    }
    
    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), cjtos(g.V()) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); 
                coste = a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
    }
};
void resuelveCaso() {

    // leer los datos de la entrada
    int N, M; cin >> N >> M;
    int v, w, peso; 
    GrafoValorado<int> gv(N);
    for (int i = 0; i < M; i++)
    {
        cin >> v >> w >> peso;
        gv.ponArista({ v - 1,w - 1,peso });
    }

    // resolver el caso posiblemente llamando a otras funciones
    ARM_Kruskal<int> arm(gv);
    // escribir la solución
    if (arm.getNumCjtos() > 1) cout << "Imposible";
    else cout << arm.costeARM();
    cout << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR4.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}