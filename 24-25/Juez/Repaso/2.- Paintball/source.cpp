
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Realizamos una búsqueda en profundidad en la que si un vértice u adyacente a v pertenece al mismo equipo,
 entonces no es posible realizar equipos. Los equipos se han ido asignando en función de sus adyacentes, 
 si u es adyacente a v entonces pertenece al equipo contrario, ya que según se ha planteado:
 las rivalidades son las adyacencias en el grafo.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class CaminosDFS {
private:
    Grafo grafo;
    vector<int> equipos;
    bool posible;

    void asignarEquipo(int jugador, int numEquipo) {

        equipos[jugador] = numEquipo;

        for (int ady : grafo.ady(jugador)){
            if (equipos[ady] == -1) {
                asignarEquipo(ady, 1 - numEquipo);
                if (!posible) return;
            }
            else if (equipos[ady] == numEquipo) {
                posible = false;
                return;
            }
        }

    }
public:
    CaminosDFS(Grafo const& g) :  grafo(g), equipos(g.V(),-1), posible(true) {}

    bool esPosibleAsignarEquipos() {
        for (int i = 0; i < grafo.V(); i++){
            if (equipos[i] == -1) {
                asignarEquipo(i, 0);

                if (!posible)
                    return false;
            }
        }
        return posible;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int A, R; cin >> A >> R;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g(A);
    int i, j; 
    for (int l = 0; l < R; l++){
        cin >> i >> j;
        g.ponArista(i - 1,j - 1);
    }
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    if (CaminosDFS(g).esPosibleAsignarEquipos() == true) cout << "SI";
    else cout << "NO";
    cout << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR2.txt");
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