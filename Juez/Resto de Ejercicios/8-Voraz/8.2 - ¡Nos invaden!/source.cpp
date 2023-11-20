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

int voraz(vector<int>& enemigos, vector<int>& defensa) {
    int victorias = 0;
    sort(enemigos.begin(), enemigos.end());
    sort(defensa.begin(), defensa.end());
    int cont_e = 0;
    for (int i = 0; i < defensa.size(); i++)
    {
        if (defensa[i] >= enemigos[cont_e]) {
            victorias++;
            cont_e++;
        }
    }
    return victorias;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n; cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> enemigos(n);
    vector<int> defensa(n);
    for (int i = 0; i < n; i++)
    {
        cin >> enemigos[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> defensa[i];
    }
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << voraz(enemigos, defensa) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos8.2.txt");
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
