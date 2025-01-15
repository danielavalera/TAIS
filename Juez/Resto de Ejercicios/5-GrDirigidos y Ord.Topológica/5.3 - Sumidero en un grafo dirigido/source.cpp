
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 * 
 *@ </authors> */

#include <iostream>
#include <fstream>
//#include <...>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

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
    int V, A;
    cin >> V >> A;
    if (!std::cin)  // fin de la entrada
        return false;

    Digrafo dg(V);
    int u, v;
    for (int i = 0; i < A; i++){
        cin >> u >> v;
        dg.ponArista(u, v);
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    Digrafo dgInverso = dg.inverso();
    bool encontrado = false;
    for (int i = 0; i < V; i++){
        vector<int> gradoSalida = dg.ady(i);
        vector<int> gradoEntrada = dgInverso.ady(i);
        if(gradoSalida.size() == 0 && gradoEntrada.size() == V-1){
            cout << "SI " << i << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) cout << "NO\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos5.3.txt");
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