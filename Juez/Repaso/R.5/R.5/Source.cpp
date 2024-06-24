
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

struct super {
    int Num, pre;
};

bool operator< (super const& s1, super const& s2) {
    return s1.pre < s2.pre;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, C;
    std::cin >> N >> C;
    if (!std::cin)  // fin de la entrada
        return false;

    ConjuntosDisjuntos c(N);
    for (int i = 0; i < C; i++) {
        int v, w;
        std::cin >> v >> w;
        c.unir(v - 1, w - 1);
    }
    int S;
    std::cin >> S;
    std::vector<super> supers(S); 
    for (int i = 0; i < S; i++) {
        int l, p;
        std::cin >> l >> p;
        supers[i].Num = l - 1;
        supers[i].pre = p;
    }
    std::sort(supers.begin(), supers.end());
    int K;
    std::cin >> K;
    for (int i = 0; i < K; i++) {
        int p, j = 0;
        bool llegar = false;
        std::cin >> p;
        super aux;
        while (j < S && !llegar) {
            aux = supers[j];
            if (c.unidos(p - 1, aux.Num)) llegar = true;
            j++;
        }
        if (llegar) std::cout << aux.pre << '\n';
        else std::cout << "MENUDO MARRON" << '\n';
    }
    // resolver el caso posiblemente llamando a otras funciones
    std::cout << "---" << '\n';
    // escribir la soluci�n

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
