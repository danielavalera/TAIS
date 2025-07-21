
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 CASOS BASE:
 ------------
 mtz(i,0) = 0           i >= 0 && i <= N
 mtz(0,j) = INF         j >= 0 && j <= precioCoche

 CASO RECURSIVO:
 ---------------
 mtz(i,j) = min(
                mtz(i-1,j),
                k + mtz(i-1, j - k * tipoMoneda[i-1]))
 donde k = nº monedas de cada tipo, k >= 1 && k <= cantMoneda[N]
 LLAMADA INICIAL:
 ----------------
 mtz(N,precioCoche)


 Realizamos prog.dinámica ascendente

 COSTE:
 ------
 El coste en tiempo es O(N * precioCoche * M), donde:
 - N es el número de tipos de monedas.
 - precioCoche es el objetivo.
 - M es el número máximo de monedas disponibles por tipo (en promedio).
 El coste en espacio es O(N * precioCoche) para almacenar la matriz.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
const int INF = 999999999;

pair<string, int> progDinamica(vector<int> const& tipoMoneda, vector<int> const& cantMoneda, int const& precioCoche, int const& N) {
    Matriz<int> mtz(N + 1, precioCoche + 1, INF);

    //caso base
    mtz[0][0] = 0;
    int acumulado;
    //rellenamos la matriz
    for (int i = 1; i <= N; i++){
        mtz[i][0] = 0;
        for (int j = 1; j <= precioCoche; j++){
            // Caso en que no utilizamos monedas del tipo actual
            mtz[i][j] = mtz[i - 1][j];
            if (tipoMoneda[i - 1] <= j) {
                acumulado = INF;
                // Probar con monedas del tipo actual
                for (int k = 1; k <= cantMoneda[i - 1] && (j-k * tipoMoneda[i - 1]) <=precioCoche && (j - k * tipoMoneda[i - 1]) >= 0; k++) {
                    acumulado = k + mtz[i - 1][j - k * tipoMoneda[i - 1]];
                    if(acumulado < mtz[i][j])
                        mtz[i][j] = min(mtz[i][j], acumulado);
                }
            }
        }
    }


    if (mtz[N][precioCoche] == INF) return { "NO", 0 };
    else return { "SI", mtz[N][precioCoche] };
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> tipoMoneda(N);
    for (int i = 0; i < N; i++)
        cin >> tipoMoneda[i];
    
    vector<int> cantMoneda(N);
    for (int i = 0; i < N; i++)
        cin >> cantMoneda[i];
    int precioCoche; cin >> precioCoche;

    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    if (progDinamica(tipoMoneda, cantMoneda, precioCoche, N).first == "NO") cout << "NO";
    else cout << progDinamica(tipoMoneda, cantMoneda, precioCoche, N).first << " " << progDinamica(tipoMoneda, cantMoneda, precioCoche, N).second;
    cout << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos12.3.b.txt");
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