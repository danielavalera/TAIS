/*@ <answer>
 *
 * Nombre y Apellidos: DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct solucion {
    EntInf min;
    vector<int> puntos;
};

solucion progDinamica(int sumaTotal, vector<int> v) {
    EntInf minDardos;
    vector<int> puntos;
    int S = v.size();
    vector<EntInf> dardos(sumaTotal + 1, Infinito);
    dardos[0] = 0;
    // rellenamos la matriz
    for (int i = 1; i <= S; ++i) {
        for (int j = v[i - 1]; j <= sumaTotal; ++j) {
            dardos[j] = min(dardos[j], dardos[j - v[i - 1]] + 1);
        }
    }
    minDardos = dardos[sumaTotal];

    //reconstruimos la solución
    if (minDardos != Infinito) {
        int i = S, j = sumaTotal;
        while (j > 0) { // no se ha alcanzado la puntuación
            if (v[i - 1] <= j && dardos[j] == dardos[j - v[i - 1]] + 1) {
                // tomamos una moneda de tipo i
                puntos.push_back(v[i - 1]);
                j = j - v[i - 1];
            }
            else // no tomamos más monedas de tipo i
                --i;
        }
    }
    return {minDardos, puntos};
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int sumaTotal, nSectores; cin >> sumaTotal >> nSectores;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> v(nSectores);
    for (int i = 0; i < nSectores; i++)
    {
        cin >> v[i];
    }
    // resolver el caso posiblemente llamando a otras funciones
    solucion sol = progDinamica(sumaTotal, v);
    // escribir la solución
    if (sol.min != Infinito) {
        cout << sol.min << ":";
        for (int i : sol.puntos)
            cout << ' ' << i;
    }
    else 
        cout << "Imposible";
    cout << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos10.2.txt");
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
