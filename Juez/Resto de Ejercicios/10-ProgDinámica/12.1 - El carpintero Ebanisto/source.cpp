
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 RECURSIÓN
 ----------------------
 minCoste(i,j) = esfuerzo minimo para realizar cortes en las marcas desde la i+1 a la j-1

 minCoste(i,j) = min_i<k<j(minCoste(i,k) + minCoste(k,j)) + 2*(Mj - Mi)


 CASOS BASE:
 minCoste(i,i+1) = 0 (no quedan cortes por hacer)

 Llamada inicial: minCoste(0,N-1)

 RESOLUCIÓN
 -----------------------
 Se utiliza programación dinámica ascendente. Se va generando la tabla con N filas y N columnas. La diagonal principal y todas las posiciones que quedan por debajo de ella
 son 0 (j >= i, no tiene sentido en este problema porque no se llega a esos casos). Además, la diagonal que está encima de la principal también vale 0, por ser el caso base.
 Queda, por tanto, rellenar el resto de la matriz, que se irá haciendo por diagonales hasta llegar a la posición superior derecha de la matriz, donde quedara almacenada la
 solución al problema (caso i= 0, j=N-1). Esto lo podemos haer porque para cada posición ij (i<j-1) solo necesitamos posiciones a la izquierda de esta e inferiores.

 COSTE
 ------------------------
 El coste en tiempo está en el orden O(N^2/N) = O(N^2), porque recorremos "toda" la matriz y sobre cada elemento realizamos operaciones de coste O(1).
 El coste en espacio está en el orden O(N^2), por la matriz donde guardamos las soluciones de los subproblemas.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
const int INF = 1000000000;
using matriz = vector<vector<EntInf>>;

EntInf minCoste(vector<int> const& marcas) {
    int N = marcas.size();
    matriz m(N, vector<EntInf>(N, 0));
    //saltamos la primera diagonal porque es el caso base
    for (int d = 2; d < N; ++d) {
        for (int i = 0; i < N-d; ++i) {
            int j = i + d;
            m[i][j] = INF;
            for (int k = i+1; k < j; ++k) {
                EntInf temp = m[i][k] + m[k][j] + 2 * (marcas[j] - marcas[i]);
                if (temp < m[i][j]) {
                    m[i][j] = temp;
                }
            }
        }
    }
    return m[0][N - 1];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int L, N; cin >> L >> N;
    if (L == 0 && N == 0)
        return false;

    vector<int> marcas(N + 2);
    marcas[0] = 0;
    marcas[N + 1] = L;
    for (int i = 1; i <= N; i++)
    {
        cin >> marcas[i];
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    cout << minCoste(marcas) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos12.1.txt");
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
