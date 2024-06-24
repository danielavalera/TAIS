
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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

    // escribir la soluci�n
    std::cout << dias(bizcocho, N) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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