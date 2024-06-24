
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    std::cin >> N;
    if (N == 0)
        return false;
  
    std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int>> aficion;
    long long int gorras = 0;
    for (int i = 0; i < N; i++) {
        long long int n;
        std::cin >> n;
        aficion.push(n);
    }
    while (aficion.size() > 1) {
        auto e1 = aficion.top();
        aficion.pop();
        auto e2 = aficion.top();
        aficion.pop();
        gorras += e1 + e2;
        aficion.push(e1 + e2);
    }
   
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    std::cout << gorras << '\n';

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
