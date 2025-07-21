
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
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

bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (N == 0)
        return false;

    priority_queue<long long int, vector<long long int>, greater<long long int>> partidos;
    long long int seguidores;
    for (int i = 0; i < N; i++)
    {
        cin >> seguidores;
        partidos.push(seguidores);
    }
    // resolver el caso posiblemente llamando a otras funciones
    long long int gorras = 0;
    while (partidos.size() > 1) {
        auto eq1 = partidos.top();
        partidos.pop();
        auto eq2 = partidos.top();
        partidos.pop();
        gorras += eq1 + eq2;
        partidos.push(eq1 + eq2);
    }
    // escribir la solución
    cout << gorras << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR12.txt");
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