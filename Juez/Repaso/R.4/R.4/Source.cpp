
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
//using namespace std;

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
struct act {
    int ini, fin;
};

bool operator<(act const& a1, act const& a2) {
    return a1.ini > a2.ini;
}

int planificar(std::priority_queue<act> & v) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> mates;
    mates.push(v.top().fin);
    v.pop();
    
    while (!v.empty()) {
        act aux = v.top();
        v.pop();
        if (aux.ini >= mates.top()) mates.pop();
        mates.push(aux.fin);
    }
    return mates.size() - 1;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    std::cin >> N;
    if (N == 0)
        return false;

    std::priority_queue<act> acts;
    int ini, fin;
    for (int i = 0; i < N; i++) {
        std::cin >> ini >> fin;
        acts.push({ ini, fin });
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    std::cout << planificar(acts) << '\n';
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
