
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase
#include "Matriz.h"
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
void Floyd(Matriz<EntInf> const& G, Matriz<EntInf>& C) {
    int V = G.numfils(); // número de vértices de G
    // inicialización
    C = G;
    // actualizaciones de las matrices
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                auto temp = C[i][k] + C[k][j];
                if (temp < C[i][j]) { // es mejor pasar por k
                    C[i][j] = temp;
                }
            }
        }
    }

    
}

EntInf ordenMax(Matriz<EntInf> const& C) {
    EntInf orden = 0;

    for (int i = 0; i < C.numfils(); i++){
        for (int j = i+1; j < C.numcols(); j++){
            orden = max(orden, C[i][j]);
        }
    }

    return orden;
}

pair<bool, EntInf> separacion(Matriz<EntInf> const& G) {
    //calculamos los grados de separación entre cada par de personas
    Matriz<EntInf> C;
    Floyd(G, C);
    bool conexo = true;
    EntInf orden = ordenMax(C);

    if (orden == Infinito)
        conexo = false;

    return{ conexo, orden };
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int P; cin >> P;
    if (!std::cin)  // fin de la entrada
        return false;
    int R; cin >> R;
    Matriz<EntInf> G(P, P, Infinito);
    //rellenamos la diagonal de la matriz del grafo
    for (int i = 0; i < P; i++)
    {
        G[i][i] = 0;
    }
    unordered_map<string, int> personas;
    string p1, p2;
    int indPersona = 0;
    for (int i = 0; i < R; i++)
    {
        cin >> p1 >> p2;
        if (personas.count(p1) == 0){
            personas[p1] = indPersona;
            indPersona++;
        }
        if (personas.count(p2) == 0) {
            personas[p2] = indPersona;
            indPersona++;
        }
        G[personas[p1]][personas[p2]] = 1;
        G[personas[p2]][personas[p1]] = 1;
    }
    // resolver el caso posiblemente llamando a otras funciones
    pair<bool, EntInf> sol = separacion(G);
    // escribir la solución
    if (sol.first)
        cout << sol.second << '\n';
    else
        cout << "DESCONECTADA" << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos11.4.txt");
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
