
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
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
    int id, tiempo, descarga;
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int B; cin >> B;
    if (!std::cin)  // fin de la entrada
        return false;
    priority_queue<bateria> baterias;
    int t;
    for (int i = 0; i < B; i++)
    {
        cin >> t;
        baterias.push({ i +1, t, t });
    }
    int R; cin >> R;
    vector<bateria> repuesto(R);
    int r;
    for (int i = 0; i < R; i++)
    {
        cin >> r;
        repuesto[i] = { B +i+ 1, t,-1 };
    }
    int Z, T; cin >> Z >> T;
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR14.txt");
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