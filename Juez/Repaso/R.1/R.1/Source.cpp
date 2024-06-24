
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

template <typename Valor>
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor minimo;
    int nConjuntos;
public:

    int getnConjuntos() const {
        return nConjuntos;
    }
    Valor costeARM() const {
        return minimo;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g) : minimo(0) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); 
                if(minimo < a.valor()) minimo = a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
        nConjuntos = cjtos.num_cjtos();
    }
};

void resuelveCaso() {

    // leer los datos de la entrada
    int v, a;
    std::cin >> v >> a;
    GrafoValorado<int> g(v);
    int u, w, p;
    for (int i = 0; i < a; i++) {
        std::cin >> u >> w >> p;
        g.ponArista({ u - 1, w - 1, p });
    }
    ARM_Kruskal<int> armK(g);
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la soluci�n
    if (armK.getnConjuntos() == 1) {
        std::cout << armK.costeARM() << '\n';
    }
    else std::cout << "Imposible" << '\n';
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
