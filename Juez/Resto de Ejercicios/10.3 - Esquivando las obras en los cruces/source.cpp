
/*@ <answer>
 *
 * Nombre y Apellidos: DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

using ciudad = vector<vector<char>>;
using matriz = vector<vector<int>>;

int casilla(int j, vector<int> const& v) {
    if (j < 0) return 0;
    else return v[j];
}

int progDinamica(ciudad const& cuadracity) {
    int N = cuadracity.size(), M = cuadracity[0].size();
    vector<int> v(M, 0);
    v[0] = 1; //intersección inicial 
    // rellenamos la matriz
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < M; ++j) 
            if (cuadracity[i][j] == 'X')
                v[j] = 0;
            else
                v[j] = v[j] + casilla(j-1,v);

    return v[M-1];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int callesEO, callesNS; cin >> callesEO >> callesNS;
    if (!std::cin)  // fin de la entrada
        return false;
    ciudad cuadracity(callesEO, vector<char>(callesNS));
    for (int i = 0; i < callesEO; i++)
        for (int j = 0; j < callesNS; j++)
            cin >> cuadracity[i][j];
    
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << progDinamica(cuadracity) << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos10.3.txt");
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
