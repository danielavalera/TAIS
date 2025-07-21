
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
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

class CosteMinimoARM {
private:
    int coste;
    bool conexo;

    bool kruskal(GrafoValorado<int> const& gv) {
        int add = 0; //nº vertices añadidos al ARM
        //mantenemos las aristas ordenadas crecientemente por valor:
        PriorityQueue<Arista<int>> pq(gv.aristas());
        ConjuntosDisjuntos cjtos(gv.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                ++add;
                coste += a.valor();
                if (add == gv.V()) break;
            }
        }

        if (cjtos.cardinal(0) != gv.V()) {
            return false;
        }
        else {
            return true;
        }
    }

public:
    CosteMinimoARM(GrafoValorado<int> const& gv) : coste(0) {
        conexo = kruskal(gv);
    }

    bool suficientesPuentes() {
        return conexo;
    }

    int costeMinimo() {
        return coste;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    GrafoValorado<int> grafo(cin, 1);
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    CosteMinimoARM sol(grafo);
    // escribir la solución
    if (sol.suficientesPuentes()) cout << sol.costeMinimo();
    else cout << "No hay puentes suficientes";
    cout << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos6.3.txt");
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
