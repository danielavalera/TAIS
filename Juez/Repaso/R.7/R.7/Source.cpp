
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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

    // escribir la soluci�n
    std::cout << gorras << '\n';

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
