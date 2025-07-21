
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
//#include <...>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int calcularIndice(char c) {
    switch (c) {
    case 'A': return 0;
    case 'C': return 1;
    case 'G': return 2;
    case 'T': return 3;
    default: return 4;
    }
}
int adn(int n, int m, string s1, string s2, const Matriz<int>& mtz) {
    Matriz<int> sol(n + 1, m + 1, 0);

    for (int i = 1; i <= n; i++)
        sol[i][0] = mtz[calcularIndice(s1[i - 1])][4] + sol[i - 1][0];

    for (int j = 1; j <= m; j++)
        sol[0][j] = mtz[4][calcularIndice(s2[j - 1])] + sol[0][j-1];

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int indiceI = calcularIndice(s1[i - 1]);
            int indiceJ = calcularIndice(s2[j - 1]);

            sol[i][j] = max(
                            mtz[indiceI][4] + sol[i-1][j],
                            max(
                                mtz[4][indiceJ] + sol[i][j-1],
                                mtz[indiceI][indiceJ] + sol[i-1][j-1]));
        }
    }

    return sol[n][m];
    
}
void resuelveCaso() {

    // leer los datos de la entrada
    Matriz<int> mtz(5, 5, 0);
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
            cin >> mtz[i][j];
    }

    int pares; cin >> pares;
    string cadena1, cadena2;
    for (int i = 0; i < pares; i++){
        cin >> cadena1 >> cadena2;
        cout << adn(cadena1.size(), cadena2.size(), cadena1, cadena2, mtz) << "\n";
    }
    
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos12.4.b.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}