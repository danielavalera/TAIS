/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int voraz(vector<int> const& agujeros, int L) {
    int parches = 0, ultParche = -1;
    for (int i = 0; i < agujeros.size(); i++)
    {
        if (ultParche < agujeros[i]) {
            ++parches;
            ultParche = agujeros[i] + L;
        }
    }
    return parches;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, L; cin >> N >> L;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> agujeros(N);
    for (int i = 0; i < N; i++)
    {
        cin >> agujeros[i];
    }
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << voraz(agujeros, L) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos8.1.txt");
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
