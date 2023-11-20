/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
struct pelicula {
    int ini, fin;
};

bool operator<(pelicula const& p1, pelicula const& p2) {
    return p1.fin < p2.fin;
}

int voraz(vector<pelicula>& p, int descanso) {
    int maxPeli = 0, ultPeli = -descanso;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].ini >= ultPeli + descanso) {
            maxPeli++;
            ultPeli = p[i].fin;
        }
    }
    return maxPeli;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (N==0)  // fin de la entrada
        return false;
    int hora, min, duracion;
    char aux;
    vector<pelicula> p(N);
    for (int i = 0; i < N; i++)
    {
        cin >> hora >> aux >> min >> duracion;
        p[i] = { hora * 60 + min, hora * 60 + min + duracion };
    }
    sort(p.begin(), p.end());
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << voraz(p, 10) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos8.4.txt");
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


