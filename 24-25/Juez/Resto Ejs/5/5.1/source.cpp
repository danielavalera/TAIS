
/*@ <authors>
 *
 * Daniela Valentina Valera Fuentes TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 La resolución de este algoritmo nos devuelve el camino más corto desde el origen hasta el destino.
 El recorrido finaliza cuando el origen y el destino son iguales, habremos llegado al final.
 Sino, empieza el recorrido: crea una cola DISTANCIA de tamaño MAX con INF como valor en cada posición, que se va modificando 
 según los valores de adyacencia. Si un vértice tiene valor INF significa que aún no ha sido visitado.
 Creamos otra cola donde añadimos el primer vertice. Mientras la cola no sea vacia, sacamos el primer vertice de la cola
 y recorremos sus tres adyacentes.

 El coste de la función es O(V + A) siendo V= 10.000 y A= 30.000.


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

const int MAX = 10000;
const int INF = 1000000000; // ∞

int adyacente(int v, int i) {
    switch (i) {
    case 0: return (v + 1) % MAX; // + 1
    case 1: return (v * 2) % MAX; // * 2
    case 2: return v / 3; // / 3
    }
}

int bfs(int origen, int destino) {
    if (origen == destino) return 0; //finaliza la ejecución

    vector<int> distancia(MAX, INF); // creamos un vector de tamaño MAX con INF como valor de cada posición
    distancia[origen] = 0;
    queue<int> cola; 
    cola.push(origen);
    while (!cola.empty()) {
        int v = cola.front(); 
        cola.pop();
        for (int i = 0; i < 3; ++i) {
            int w = adyacente(v, i);
            if (distancia[w] == INF) {
                distancia[w] = distancia[v] + 1;
                if (w == destino) return distancia[w];
                else cola.push(w);
            }
        }
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int origen, destino;
    cin >> origen >> destino;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << bfs(origen, destino) << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos5.1.txt");
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
