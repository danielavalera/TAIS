
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
int voraz(vector<int>& puntosRivales, vector<int>& puntosBroncos) {
    int exitoMax = 0, i = 0, j=0;

    while (i < puntosRivales.size() && j < puntosBroncos.size()) {
        if (puntosBroncos[i] > puntosRivales[j])
            exitoMax += puntosBroncos[i] - puntosRivales[j];
        i++;
        j++;
    }

    return exitoMax;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (N == 0)
        return false;

    vector<int> puntosRivales(N);
    for (int i = 0; i < N; i++)
        cin >> puntosRivales[i];
    sort(puntosRivales.begin(), puntosRivales.end());

    vector<int> puntosBroncos(N);
    for (int i = 0; i < N; i++)
        cin >> puntosBroncos[i];
    sort(puntosBroncos.begin(), puntosBroncos.end(), greater<int>());
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    cout << voraz(puntosRivales, puntosBroncos) << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos9.4.txt");
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