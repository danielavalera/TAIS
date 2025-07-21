
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
int voraz(vector<int>& voltajes, int V) {
    int i = 0, j = voltajes.size() - 1, numMax = 0;
    
    while(i < j){
        if (voltajes[i] + voltajes[j] >= V) {
            numMax++;
            i++;
        }
        j--;
    }

    return numMax;
}
void resuelveCaso() {

    // leer los datos de la entrada
    int N, V; cin >> N >> V;
    vector<int> voltajes(N);
    for (int i = 0; i < N; i++)
        cin >> voltajes[i];

    sort(voltajes.begin(), voltajes.end(), greater<int>());
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << voraz(voltajes, V) << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos9.3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}