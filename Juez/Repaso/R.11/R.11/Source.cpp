
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

using matriz = std::vector<std::vector<int>>;

int casilla(int i, int j, matriz const& m) {
    if (i < 0 || j < 0 || i >= m.size() || j >= m.size()) return 0;
    else return m[i][j];
}

int dias(std::vector<int> const& b, int N) {
    matriz m(N, std::vector<int>(N, 0));

    for (int d = 2; d <= N; d++) {
        for (int i = N - d; i >= 0; i--) {
            int j = i + d - 1;
            int sum1 = b[i] != 0 && b[i] == b[j];
            int sum2 = b[i] != 0 && b[i] == b[i + 1];
            int sum3 = b[j] != 0 && b[j] == b[j - 1];
            m[i][j] = max(m[i + 1][j - 1] + sum1, casilla(i + 2, j, m) + sum2);
            m[i][j] = max(m[i][j], casilla(i, j - 2, m) + sum3);
        }
    }
    return m[0][N - 1];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    std::cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector<int> bizcocho(N);
    for (int i = 0; i < N; i++) {
        std::cin >> bizcocho[i];
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    std::cout << dias(bizcocho, N) << '\n';
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