/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES (TAIS66)
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "queue"  // propios o los de las estructuras de datos de clase

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
    int edad, parejas;
    cin >> edad >> parejas;
    if (edad == 0 && parejas == 0)
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    int mediana = edad;
    priority_queue<int> menores;
    priority_queue<int, vector<int>, greater<int>> mayores;

    int aux;
    for (int i = 0; i < 2*parejas; i++)
    {
        cin >> aux;
        if (aux < mediana) {
            menores.push(aux);
            if (menores.size() - mayores.size() > 0) {
                mayores.push(mediana);
                mediana = menores.top();
                menores.pop();
            }
        }
        else {
            mayores.push(aux);
            if (mayores.size() - menores.size() > 1) {
                menores.push(mediana);
                mediana = mayores.top();
                mayores.pop();
            }
        }

        if (i % 2 == 1) cout << mediana << ' ';
    }
    // escribir la solución
    cout << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos3.2.txt");
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
