
/*@ <answer>
 *
 * Nombre y Apellidos: Daniela Valentina Valera Fuentes TAIS66
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

//#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tarea {
    int tInicio, tFin, pRepet;
};

bool operator<(tarea const& t1, tarea const& t2) {
    return t1.tInicio > t2.tInicio;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int nTUnicas, nTPeriodicas, tEx; // tEx = tiempo de ejecución : tiempo para averiguar conflictos
    cin >> nTUnicas >> nTPeriodicas >> tEx;

    priority_queue<tarea> cola;
    if (!std::cin)  // fin de la entrada
        return false;

    int ini, fin, periodo;
    for (int i = 0; i < nTUnicas; i++) { //tareas únicas
        cin >> ini >> fin;
        if (ini < tEx) {
            cola.push({ ini, fin, 0 });
        }
    }
    for (int i = 0; i < nTPeriodicas; i++) { //tareas periódicas
        cin >> ini >> fin >> periodo;
        if (ini < tEx) {
            cola.push({ ini, fin, periodo });
        }
    }

    // resolver el caso posiblemente llamando a otras funciones
    bool conflicto = false;
    while (!conflicto && !cola.empty() && cola.top().tInicio <tEx) { //mientras conflicto sea false
        tarea primeraTarea = cola.top(); //cogemos la primera pos de la cola
        cola.pop();
        if (!cola.empty() && primeraTarea.tFin > cola.top().tInicio) {
            conflicto = true;
        }
        if (primeraTarea.pRepet > 0 && (primeraTarea.tInicio + primeraTarea.pRepet) <tEx) { //tareas periodicas
            cola.push({ primeraTarea.tInicio + primeraTarea.pRepet, primeraTarea.tFin + primeraTarea.pRepet, primeraTarea.pRepet });
        }
        
    }

    // escribir la solución
    if (conflicto == true) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }
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
