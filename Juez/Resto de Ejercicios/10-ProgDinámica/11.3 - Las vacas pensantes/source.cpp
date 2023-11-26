
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

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
using matriz = vector<vector<int>>;

// calcula la longitud del mayor palíndromo en patitos[i..j]
int resuelve(vector<int> const& cubos) {
    int N = cubos.size();
    matriz m(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        m[i][i] = cubos[i];
    }
    int sol_i, sol_j;
    for (int i = N -2; i >= 0; i--) {
        for (int j = i+1; j < N; j++){

            if (cubos[i+1] > cubos[j])
               sol_i = m[i + 2][j];
            else
                sol_i = m[i + 1][j-1];

            if (cubos[i] < cubos[j-1])
                sol_j = m[i][j-2];
            else
                sol_j = m[i + 1][j - 1];
            m[i][j] = max(cubos[i] + sol_i, cubos[j] + sol_j);
            
        }
    }

    return m[0][N - 1];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int nCubos; cin >> nCubos;
    if (nCubos == 0)  // fin de la entrada
        return false;

    vector<int> cubos(nCubos);
    for (int i = 0; i < nCubos; i++){
        cin >> cubos[i];
    }
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << resuelve(cubos) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos11.3.txt");
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
