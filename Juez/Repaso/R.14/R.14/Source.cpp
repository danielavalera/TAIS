
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EntInf.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
struct bombilla {
    int potencia, precio;
};

pair<EntInf, int> resolver(std::vector<bombilla> const& b, int n, int pmx, int pmn) {
    
    std::vector<EntInf> v(pmx + 1, Infinito);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = b[i - 1].potencia; j <= pmx; j++) {
            v[j] = min(v[j], v[j - b[i - 1].potencia] + b[i - 1].precio);
        }
    }
    
    pair<EntInf, int> sol = {Infinito, -1};
    for (int i = pmn; i <= pmx; i++) {
        if (v[i] < sol.first) {
            sol.first = v[i];
            sol.second = i;
        }
    }
    return sol;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, Pmax, Pmin;
    std::cin >> N >> Pmax >> Pmin;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector<bombilla> bombillas(N);
    for (int i = 0; i < N; i++) {
        std::cin >> bombillas[i].potencia;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> bombillas[i].precio;
    }
    // resolver el caso posiblemente llamando a otras funciones
    auto sol = resolver(bombillas, N, Pmax, Pmin);
    // escribir la soluci�n
    if(sol.first == Infinito) std::cout << "IMPOSIBLE" << '\n';
    else std::cout << sol.first << " " << sol.second << '\n';
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
