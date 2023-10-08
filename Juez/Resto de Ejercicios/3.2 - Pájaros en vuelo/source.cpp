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

 Creamos dos colas, una para almacenar una cola de mínimos y otra para almacenar una de máximos. En
 estas colas se irán annadiendo las edades de las parejas en función de si es mayor o menor que la edad que
 encabeza el grupo(eMitad).

 El coste del algoritmo es lineal O(2*parejas).

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
    int eMitad = edad;
    priority_queue<int> menores;
    priority_queue<int, vector<int>, greater<int>> mayores;

    int edades;
    for (int i = 0; i < 2*parejas; i++)
    {
        cin >> edades;
        if (edades < eMitad) {
            menores.push(edades);
            if (menores.size() - mayores.size() > 0) {
                mayores.push(eMitad);
                eMitad = menores.top();
                menores.pop();
            }
        }
        else {
            mayores.push(edades);
            if (mayores.size() - menores.size() > 1) {
                menores.push(eMitad);
                eMitad = mayores.top();
                mayores.pop();
            }
        }

        if (i % 2 == 1) cout << eMitad << ' ';
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
