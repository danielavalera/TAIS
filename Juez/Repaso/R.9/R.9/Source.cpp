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

struct bateria {
    int llegada, carga, aportado;
};

bool operator< (bateria const& b1, bateria const& b2) {
    return b1.aportado > b2.aportado || b1.aportado == b2.aportado && b1.llegada > b2.llegada;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int B;
    std::cin >> B;
    if (!std::cin)  // fin de la entrada
        return false;
    std::priority_queue<bateria> bUso;
    for (int i = 0; i < B; i++) {
        int b;
        std::cin >> b;
        bUso.push({ i + 1, b, b });
    }
    int R;
    std::cin >> R;
    std::priority_queue<bateria> bRep;
    for (int i = B; i < R + B; i++) {
        int r;
        std::cin >> r;
        bRep.push({ i + 1, r, 0 });
    }
    int Z, T;
    std::cin >> Z >> T;
    // resolver el caso posiblemente llamando a otras funciones
    while (!bUso.empty() && bUso.top().aportado <= T) {
        auto b = bUso.top();
        bUso.pop();
        int t = b.aportado;
        b.carga -= Z;
        b.aportado += b.carga;
        if (b.carga > 0) bUso.push(b);
        else if (!bRep.empty()) {
            b = bRep.top();
            bRep.pop();
            b.aportado = t + b.carga;
            bUso.push(b);
        }
    }
    // escribir la solución
    if (bUso.empty()) std::cout << "ABANDONEN INMEDIATAMENTE LA BASE";
    else if (bUso.size() == B) std::cout << "CORRECTO";
    else std::cout << "FALLO EN EL SISTEMA";
    std::cout << '\n';
    while (!bUso.empty()) {
        std::cout << bUso.top().llegada << " " << bUso.top().aportado << '\n';
        bUso.pop();
    }
    std::cout << "---" << '\n';
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