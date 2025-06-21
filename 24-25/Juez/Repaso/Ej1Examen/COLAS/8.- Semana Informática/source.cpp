
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

/*@ <answer>
La solución al problema se basa en saber cuantas personas necesitamos (sin contar con nosotros) para que se pueda asistir a todas las actividades sin solaparse. 

Para ello, se utiliza una cola de prioridad (priority_queue(default: mayor)) ordenanda ascendentemente según su hora de inicio de actividad. 
Se crea otra cola ordenada ascendentemente según la hora de finalización de las actividades.

Si no hay ninguna persona disponible, es decir, la hora de fin de la actividad es después de que otra empiece, se necesita una persona nueva. 
Si hay una persona que ha terminado su actividad antes de que comience la actual, se le asigna la nueva actividad.

El tamaño final de la cola de finalizaciones representa el número total de personas necesarias para cubrir las actividades sin solapamiento. 
Como uno mismo también cuenta, se devuelve el número de compañeros necesarios como 'finalAyudantes.size() - 1'.

COSTE:
-------
El coste del algoritmo es O(N log N) siendo N el número de actividades. 
Esto se debe al uso de colas de prioridad para insertar y extraer actividades y tiempos de finalización, operaciones que tienen coste logarítmico.

@ </answer> */



 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct act {
    int ini, fin;

    bool operator<(act const& other) const {
        return other.ini < ini;
    };
};


bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (N == 0)
        return false;
    int ini, fin;
    priority_queue<act> actividades;
    for (int i = 0; i < N; i++)
    {
        cin >> ini >> fin;
        actividades.push({ ini,fin });  

    }
    // resolver el caso posiblemente llamando a otras funciones
    priority_queue<int, vector<int>, greater<int>> finalAyudantes;
    while (!actividades.empty()) {
        act a = actividades.top();
        actividades.pop();
        if (finalAyudantes.empty() || finalAyudantes.top() > a.ini)
            finalAyudantes.push(a.fin);
        else {
            finalAyudantes.pop();
            finalAyudantes.push(a.fin);
        }
    }
    // escribir la solución
    cout << finalAyudantes.size() - 1 << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR8.txt");
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