
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
struct trabajo {
    int ini, fin;
};

bool operator<(trabajo const& t1, trabajo const& t2) {
    return t1.fin < t2.fin;
}

int voraz(vector<trabajo>& trabajo, bool &posible, int& C, int& F) {
    int minTrabajos = 0, i= 0;
    int finUltTrabajo = trabajo[0].fin;

    while (posible && i < trabajo.size()) {

        if (trabajo[i].ini > finUltTrabajo)
            posible = false;
        
        if (trabajo[i].ini <= C)
            minTrabajos++;
        else if (trabajo[i].ini == finUltTrabajo) {
            minTrabajos++;
            finUltTrabajo = trabajo[i].fin;
        }

        i++;
    }

    return minTrabajos;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int C, F, N, c, f; cin >> C >> F >> N;
    bool posible = true;
    if (C == 0 && F == 0 && N == 0)
        return false;

    vector<trabajo> trabajos(N);
    for (int i = 0; i < trabajos.size(); i++)
    {
        cin >> c >> f;
        trabajos[i] = { c, f };
    }
    sort(trabajos.begin(), trabajos.end());
    // resolver el caso posiblemente llamando a otras funciones
    int minTrabajos = voraz(trabajos, posible, C, F);
    // escribir la solución
    if (posible)
        cout << minTrabajos << endl;
    else
        cout << "Imposible" << endl;

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos9.2.txt");
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