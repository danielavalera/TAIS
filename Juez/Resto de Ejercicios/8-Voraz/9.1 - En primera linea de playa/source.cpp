
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

La estrategia voraz consiste en considerar los edificios en orden creciente según E, que es el punto donde acaban. Para cada edificio
se pondrá un túnel si no está cubierto por otro inferior.

COSTE:
-------
La lectura de datos tiene un coste O(N), siendo N = número de edificios. Pero el coste del problema está en el O(N log N) 
debido a la ordenación que hacemos, aunque recorrer el vector de edificios sea O(N).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct edificio {
    int ini, fin;
};

bool operator<(edificio const& e1, edificio const& e2) {
    return e1.fin < e2.fin;
}

int voraz(vector<edificio>& edificios) {
    int minTuneles = 1;
    int finUltTunel = edificios[0].fin;

    for (int i = 1; i < edificios.size(); i++)
    {
        if (finUltTunel <= edificios[i].ini) {
            minTuneles++;
            finUltTunel = edificios[i].fin;
        }
    }

    return minTuneles;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, W, E; cin >> N;
    if (N == 0)
        return false;

    vector<edificio> edificios(N);
    for (int i = 0; i < N; i++)
    {
        cin >> W >> E;
        edificios[i] = { W, E };
    }
    sort(edificios.begin(), edificios.end()); //O(N log N)

    // resolver el caso posiblemente llamando a otras funciones
    cout << voraz(edificios) << endl;
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos9.1.txt");
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