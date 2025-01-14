
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
    int N, M; cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;

    ConjuntosDisjuntos grupos(N);
    int numUsuarios;
    for (int i = 0; i < M; i++){
        cin >> numUsuarios;
        int u1, u2;
        for (int j = 0; j < numUsuarios; j++){
            if (j == 0) cin >> u1;
            else {
                cin >> u2;
                grupos.unir(u1 - 1, u2 - 1);
                u1 = u2;
            }
        }
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    for (int i = 0; i < N; i++){
        cout << grupos.cardinal(i) << " ";
    }
    cout << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos4.5.txt");
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