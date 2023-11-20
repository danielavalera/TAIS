/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
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
int voraz(vector<int>& jugadores, vector<int>& equipaciones) {
    int minCompras = jugadores.size();
    int i = 0, j = 0;
    while (i < jugadores.size() && j < equipaciones.size()) {
        if ((equipaciones[j] == jugadores[i]) || (equipaciones[j] == jugadores[i] + 1)) {
            minCompras--;
            i++;
            j++;
        }
        else if( equipaciones[j] < jugadores[i]) {
            j++;
        }
        else {
            i++;
        }
    }
    return minCompras;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M; cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> jugadores(N);
    vector<int> equipaciones(M);
    for (int i = 0; i < N; i++)
        cin >> jugadores[i];
    
    for (int i = 0; i < M; i++)
        cin >> equipaciones[i];
    sort(jugadores.begin(), jugadores.end());
    sort(equipaciones.begin(), equipaciones.end());
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << voraz(jugadores, equipaciones) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos8.3.txt");
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
