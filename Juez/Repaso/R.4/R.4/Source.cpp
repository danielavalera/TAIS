
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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

    // escribir la soluci�n
    std::cout << planificar(acts) << '\n';
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
