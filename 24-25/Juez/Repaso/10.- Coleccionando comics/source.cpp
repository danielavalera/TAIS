
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
const int INF = 100000000;

struct comic {
    int id, pila;

    bool operator<(const comic& other) const{
        return other.id < id;
    }
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<deque<int>> pilas(N);
    int K, id, mejorEjemplar = INF; 
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> id;
            mejorEjemplar = min(mejorEjemplar, id);
            pilas[i].push_front(id);
        }
    }
    // resolver el caso posiblemente llamando a otras funciones
    int pos = 1;
    priority_queue<comic> cimas;
    for (int i = 0; i < N; i++)
    {
        if (!pilas[i].empty()) {
            cimas.push({ pilas[i].front(), i });
            pilas[i].pop_front();
        }
    }
    while (cimas.top().id != mejorEjemplar) {
        comic c = cimas.top();
        cimas.pop();
        if (!pilas[c.pila].empty()) {
            cimas.push({ pilas[c.pila].front(), c.pila });
            pilas[c.pila].pop_front();
        }
        pos++;
    }
    // escribir la solución
    cout << pos << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR10.txt");
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