
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

La clave de este problema es minimizar el número total de gorras repartidas durante todos los partidos. 
Para lograrlo, se modela la situación como un problema clásico de *fusión óptima de archivos*, 
donde cada fusión tiene un coste igual a la suma de los tamaños (en este caso, el número de seguidores de los dos equipos que juegan).

La estrategia óptima consiste en simular el proceso de partidos utilizando una *cola de prioridad mínima* ('priority_queue' con comparador 'greater'). 
En cada iteración, se seleccionan los dos equipos con menor número de seguidores (los que menos coste generan al enfrentarse), 
se suman sus seguidores (ya que el ganador se queda con todos), se añade esa suma al coste total de gorras, 
y el nuevo equipo resultante vuelve a añadirse a la cola.

Este proceso se repite hasta que solo queda un equipo en la cola (es decir, ya hay un único vencedor), 
garantizando que el coste acumulado (número total de gorras) sea el mínimo posible.

COSTE:
-------
El coste de esta solución es O(N log N), siendo N el número de equipos. 
Esto se debe a que cada operación de inserción y extracción de la cola de prioridad tiene coste logarítmico, y se realizan N - 1 fusiones 
(una menos que el número total de equipos).

@ </answer> */



 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (N == 0)
        return false;

    priority_queue<long long int, vector<long long int>, greater<long long int>> partidos;
    long long int seguidores;
    for (int i = 0; i < N; i++)
    {
        cin >> seguidores;
        partidos.push(seguidores);
    }
    // resolver el caso posiblemente llamando a otras funciones
    long long int gorras = 0;
    while (partidos.size() > 1) {
        auto eq1 = partidos.top();
        partidos.pop();
        auto eq2 = partidos.top();
        partidos.pop();
        gorras += eq1 + eq2;
        partidos.push(eq1 + eq2);
    }
    // escribir la solución
    cout << gorras << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR12.txt");
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