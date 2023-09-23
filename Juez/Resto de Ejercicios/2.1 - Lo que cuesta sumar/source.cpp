/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

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

    int n;
    cin >> n;
    if (n == 0)
        return false;

    //cola prioridad
    PriorityQueue<long long int> pq;
    int lectorAux; // numeros para la cola

    for (int i = 0; i < n; i++)
    {
        cin >> lectorAux;
        pq.push(lectorAux);
    }

    long long int a, b;
    long long int coste = 0;

    for (int i = 0; i < n -1; i++)
    {
        a = pq.top(); //elemento prioritario con cte constante
        pq.pop(); //lo quito con cte logarítmico
        b = pq.top();
        pq.pop();

        coste += a + b;
        pq.push(a + b);
    }
    

    cout << coste << endl;
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
