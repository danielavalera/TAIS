
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
    // escribir la soluci�n
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            std::cout << sol[i][j] << " ";
        }
        std::cout << '\n';
    }
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