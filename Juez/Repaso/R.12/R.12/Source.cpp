
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <climits>
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

struct comic {
    int pila, id;
};

bool operator<(comic const& c1, comic const& c2) {
    return c2.id < c1.id;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    std::cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector<std::deque<comic>> pilas(N);
    int mejor = INT_MAX;
    for (int i = 0; i < N; i++) {
        int K;
        std::cin >> K;
        for (int j = 0; j<K; j++) {
            int n;
            std::cin >> n;
            mejor = std::min(mejor, n);
            pilas[i].push_front({i, n});
        }
    }
    // resolver el caso posiblemente llamando a otras funciones
    int turno = 0;
    bool encontrado = false;
    std::priority_queue<comic> cimas;
    for (int i = 0; i < N; i++) {
        cimas.push(pilas[i].front());
        pilas[i].pop_front();
    }
    while (!encontrado) {
        turno++;
        if (cimas.top().id == mejor) encontrado = true;
        else {
            comic top = cimas.top();
            cimas.pop();
            if (!pilas[top.pila].empty()) {
                cimas.push(pilas[top.pila].front());
                pilas[top.pila].pop_front();
            }
        }
    }
    // escribir la solución
    std::cout << turno << '\n';
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
