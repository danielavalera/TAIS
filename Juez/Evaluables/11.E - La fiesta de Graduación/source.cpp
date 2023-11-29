
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 * FELIPE MARTIN REYES TAIS36
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Implementamos el algoritmo de programación dinámica para encontrar la subsecuencia común más larga entre dos listas de reproducción 
 representadas por los vectores l1 y l2. La función devuelve un vector de cadenas que representa la lista de reproducción común más larga.
 Para esto primero inicializamos la matriz con "0" y construimos la solución en ella de manera ascendente usando la función max()
 para obtener la subsecuencia más larga. Después reconstruimos la solución y mediante la funcion reverse() la invertimos.

 COSTE:
 El coste en tiempo del algoritmo es O(N*M), donde N y M son el tamaño de las listas de reproducción, respectivamente. 
 La memoria adicional utilizada es O(N*M) por la matriz de tamaño (N+1)*(M+1)
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
using matriz = vector<vector<int>>;

vector<string> progDinamica(const vector<string>& l1, const vector<string>& l2) {
    int N = l1.size();
    int M = l2.size();

    //inicializamos la matriz
    matriz m(N + 1, vector<int>(M + 1, 0));

    //llenamos la matriz
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (l1[i - 1] == l2[j - 1]) {
                m[i][j] = m[i - 1][j - 1] + 1;
            }
            else {
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
            }
        }
    }

    //reconstruimos la lista
    int i = N, j = M;
    vector<string> sol;
    while (i > 0 && j > 0) {
        if (l1[i - 1] == l2[j - 1]) {
            sol.push_back(l1[i - 1]);
            i--;
            j--;
        }
        else if (m[i - 1][j] > m[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    //invertimos la lista
    reverse(sol.begin(), sol.end());

    return sol;
}

//para dividir la línea de entrada en canciones
vector<string> split(const string& s) {
    vector<string> sol;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        sol.push_back(word);
    }
    return sol;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    vector<string> l1, l2;
    string song;
    if (!std::cin)  // fin de la entrada
        return false;

    //leemos la primera lista
    getline(cin, song);
    if (song.empty()) {
        return false;  //salto de linea
    }
    l1 = split(song);

    //leemos la segunda lista
    getline(cin, song);
    l2 = split(song);

    // resolver el caso posiblemente llamando a otras funciones
    vector<string> sol = progDinamica(l1, l2);
    // escribir la solución
    for (const string& song : sol) {
        cout << song << ' ';
    }
    cout << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos11.E.txt");
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
