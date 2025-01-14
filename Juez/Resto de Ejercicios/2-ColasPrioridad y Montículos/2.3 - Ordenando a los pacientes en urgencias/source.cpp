/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
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

struct paciente {
    string nombre;
    int gravedad;
    int tiempo;
};


//MIRAR OPERATOR
bool operator<(paciente const& p1, paciente const& p2) {  //el operador menor es el que yo le digo
    return (p1.gravedad < p2.gravedad) || (p1.gravedad == p2.gravedad && p1.tiempo > p2.tiempo);
}

bool resuelveCaso() {

    int nEvents;
    cin >> nEvents;
    if (nEvents == 0)
        return false;

    char action;
    string nombre_aux;
    int gravedad_aux;
    int tiempo_aux = 0;
    priority_queue<paciente> cola;

    for (int i = 0; i < nEvents; i++)
    {
        cin >> action;
        if (action == 'I') {
            cin >> nombre_aux >> gravedad_aux;
            cola.push({ nombre_aux, gravedad_aux, tiempo_aux }); //O(logn)
            tiempo_aux++;
        }
        else {
            cout << cola.top().nombre << endl;//O(1)
            cola.pop(); //O(logn)
        }
    }

    cout << "---" << endl;
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos2.3.txt");
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
