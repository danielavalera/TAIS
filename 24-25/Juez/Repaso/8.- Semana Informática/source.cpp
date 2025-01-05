
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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
struct act {
    int ini, fin;

    bool operator<(act const& other) const {
        return other.ini < ini;
    };
};


bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (N == 0)
        return false;
    int ini, fin;
    priority_queue<act> actividades;
    for (int i = 0; i < N; i++)
    {
        cin >> ini >> fin;
        actividades.push({ ini,fin });  

    }
    // resolver el caso posiblemente llamando a otras funciones
    priority_queue<int, vector<int>, greater<int>> finalAyudantes;
    while (!actividades.empty()) {
        act a = actividades.top();
        actividades.pop();
        if (finalAyudantes.empty() || finalAyudantes.top() > a.ini)
            finalAyudantes.push(a.fin);
        else {
            finalAyudantes.pop();
            finalAyudantes.push(a.fin);
        }
    }
    // escribir la solución
    cout << finalAyudantes.size() - 1 << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR8.txt");
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