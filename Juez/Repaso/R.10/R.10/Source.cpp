
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

struct festival {
    int grupos, precio;
};

int totalGrupos(std::vector<festival> const& v, int p, int N) {
    vector<int> sol(p + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = p; j >= 0 ; j--) {
            if (v[i].precio <= j)
                sol[j] = max(sol[j], sol[j - v[i].precio] + v[i].grupos);
        }
    }
    return sol[p];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int P, N;
    std::cin >> P >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<festival> festivales(N);
    for (int i = 0; i < N; i++) {
        int g, p;
        std::cin >> g >> p;
        festivales[i].grupos = g;
        festivales[i].precio = p;
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n
    std::cout << totalGrupos(festivales, P, N) << '\n';
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
