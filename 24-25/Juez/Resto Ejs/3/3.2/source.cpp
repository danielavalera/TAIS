
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "queue"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Explicación de la resolución:
--------------------------------------------------------------------------------------------------------------------------------------------------------------
Creamos dos colas de prioridad de maximos, cada una es la caja que almacena las pilas de cada tipo. 
El problema necesita que cada sábado se vuele 1 vez cada dron, por eso, cuando ya hemos usado cada dron una vez, el tiempo restante de cada pila se almacena
para la siguiente semana.
Para esto necesitamos un vector de pares donde almacenaremos el tiempo restante de cada pila, que volveremos a insertar en las colas para la siguiente semana.


Explicación del coste:
-------------------------------------------------------------------------------------------------------------------------------------------
El coste de los bucles de inserción en la colaPilaA y colaPilaB es O(n*log n) en cada uno, donde n es el número de pilas de A y el número de pilas B.
El coste del bucle principal del programa

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

using vuelo = pair<int, int>;

bool resuelveCaso() {

    // leer los datos de la entrada
    int nDrones, nPilasA, nPilasB, tiempoVuelo;
    cin >> nDrones >> nPilasA >> nPilasB;
    if (!std::cin)  // fin de la entrada
        return false;

    priority_queue<int> colaPilasA, colaPilasB;
    for (int i = 0; i < nPilasA; i++) //O(n)
    {
        cin >> tiempoVuelo;
        colaPilasA.push(tiempoVuelo); // O(log n)
    }

    for (int i = 0; i < nPilasB; i++) //O(n)
    {
        cin >> tiempoVuelo;
        colaPilasB.push(tiempoVuelo); //O(log n)
    }
    // resolver el caso posiblemente llamando a otras funciones
    tiempoVuelo = 0;
    int count_dron = 0;
    vector<vuelo> vuelos;

    while (!colaPilasA.empty() && !colaPilasB.empty()) {

        //vuelos de cada sábado mientras tengamos drones
        while (!colaPilasA.empty() && !colaPilasB.empty() && count_dron < nDrones) {

            int primerElemA = colaPilasA.top(); // O(1)
            int primerElemB = colaPilasB.top(); // O(1)
            int minElems = min(primerElemA, primerElemB);
            colaPilasA.pop(); //O(log n)
            colaPilasB.pop(); //O(log n)

            tiempoVuelo += minElems;
            primerElemA -= minElems;
            primerElemB -= minElems;
            vuelos.push_back({ primerElemA,primerElemB });

            ++count_dron;
        }

        cout << tiempoVuelo << ' ';

        //reseteamos la semana
        tiempoVuelo = 0;
        count_dron = 0;
        while (!vuelos.empty()) {
            vuelo aux = vuelos.back();
            if (aux.first != 0) 
                colaPilasA.push(aux.first); //O(log n)
            if (aux.second != 0) 
                colaPilasB.push(aux.second); //O(log n)
            vuelos.pop_back();
        }
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
    std::ifstream in("casos3.3.txt");
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
