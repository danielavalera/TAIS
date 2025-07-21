
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
using Mapa = vector<string>;
using elem = pair <int, int>;
using dir = pair <int, int>;

const vector<dir> dirs = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };

class MaxConjuntoDisjunto{
private:
    ConjuntosDisjuntos mar;
    Mapa mapa;
    int tamMax;
    int nFilas;
    int nCols;

    int numElem(int i, int j) const {
        return i * nCols + j;
    }

    bool valida(const elem e) const {
        return (e.first >= 0 && e.first < nFilas) && (e.second >= 0 && e.second < nCols);
    }

    void comprobarUniones(int i, int j) {
        elem sig;
        for (dir d : dirs) {
            sig.first = i + d.first;
            sig.second = j + d.second;
            if (valida(sig) && mapa[sig.first][sig.second] == '#' && !mar.unidos(numElem(i, j), numElem(sig.first, sig.second)))
                mar.unir(numElem(i, j), numElem(sig.first, sig.second));
        }

        tamMax = max(tamMax, mar.cardinal(numElem(i, j)));
    }
    
public:
    MaxConjuntoDisjunto(int nF, int nC, Mapa const& m) : mar(ConjuntosDisjuntos(nF* nC)), tamMax(0), mapa(m), nFilas(nF), nCols(nC) {
        for (int i = 0; i < nF; i++){
            for (int j = 0; j < nC; j++)
            {
                if (m[i][j] == '#') comprobarUniones(i, j);
            }
        }
    }
    
    void addMancha(elem mancha) {
        mapa[mancha.first][mancha.second] = '#';
        comprobarUniones(mancha.first, mancha.second);
    }

    int manchaMax() {
        return tamMax;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int nF, nC; cin >> nF >> nC;
    if (!std::cin)  // fin de la entrada
        return false;

    Mapa mapa(nF);
    cin.ignore(1, '\n'); //que ignore los saltos de línea
    for (int i = 0; i < nF; i++)
    {
        getline(cin, mapa[i]);
    }
    // resolver el caso posiblemente llamando a otras funciones
    MaxConjuntoDisjunto sol(nF, nC, mapa);
    // escribir la solución
    cout << sol.manchaMax();

    int N; cin >> N;
    int aux1, aux2;
    for (int i = 0; i < N; i++)
    {
        cin >> aux1 >> aux2;
        sol.addMancha({aux1 -1, aux2 -1});
        cout << ' ' << sol.manchaMax();
    }

    cout << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos6.1.txt");
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
