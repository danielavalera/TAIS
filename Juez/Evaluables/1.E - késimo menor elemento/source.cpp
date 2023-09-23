/*@ <answer>
 *
 * Nombre y Apellidos:
 *      Daniela Valera Fuentes TAIS66
 *      Felipe Martin Reyes TAIS36
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <exception>
using namespace std;

#include "TreeSet_AVL.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int n = 0, elem = 0, m = 0, pos = 0;
    cin >> n;

    if (n == 0)
        return false;

    Set<int> arbol;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        arbol.insert(elem);
    }
    cin >> m;
    vector<int> menores;
    for (int i = 0; i < m; i++) {
        cin >> pos;
        menores.push_back(pos);
    }
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    for (int& n : menores) {
        try {
            int sol = arbol.kesimo(n);
            cout << sol << "\n";
        }
        catch (std::domain_error e) {
            cout << e.what() << "\n";
        }
    }
    cout << "---" << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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