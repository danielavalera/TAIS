
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

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

struct festival {
    int grupos, precio;
};

int totalGrupos(std::vector<festival> const& v, int p, int N) {
    vector<int> sol(p + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = p; j >= 0 ; j--) {
            if (v[i].precio <= j)
                sol[j] = max(sol[j], sol[j - v[i].precio] + v[i].grupos);
        }
    }
    return sol[p];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int P, N;
    std::cin >> P >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<festival> festivales(N);
    for (int i = 0; i < N; i++) {
        int g, p;
        std::cin >> g >> p;
        festivales[i].grupos = g;
        festivales[i].precio = p;
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    std::cout << totalGrupos(festivales, P, N) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
