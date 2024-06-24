
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
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

void recorrido(const std::vector<std::vector<int>>& p, const int& N, std::vector<std::vector<int>>& sol) {
    for (int i = 0; i < sol.size(); i++) {
        sol[i][i] = 0;
    }
    for (int d = 1; d < N; d++) {
        for (int f = 0; f < N - d; f++) {
            int col = d + f;
            for (int k = f + 1; k <= col; k++) {
                sol[f][col] = std::min(sol[f][col], p[f][k] + sol[k][col]);
            }
        }
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    std::cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector<std::vector<int>>precios(N, std::vector<int>(N, 0));
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            std::cin >> precios[i][j];
        }
    }
    std::vector<std::vector<int>> sol(N, std::vector<int>(N, INF));
    // resolver el caso posiblemente llamando a otras funciones
    recorrido(precios, N, sol);
    // escribir la solución
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            std::cout << sol[i][j] << " ";
        }
        std::cout << '\n';
    }
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