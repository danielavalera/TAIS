
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
    // escribir la soluci�n
    std::cout << turno << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
