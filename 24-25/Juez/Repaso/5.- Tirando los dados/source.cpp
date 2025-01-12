
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 RECURRENCIA:
 ------------
 formas(i,j) = formas de obtener la cantidad j con un dado de i caras
 formas(i,j) = { formas(i-1,j) si i < j
               { formas(i-1,j) + formas(i,j-i) si i <= j

 CASOS BASE:
 -----------
 formas(i,0) = 1, caso en el que tenemos un dado de 0 caras --> la única manera de conseguirlo es no tirar el dado
 formas(0,j) = 0, no tenemos forma de tirar el dado

 COSTES:
 --------
 Tiempo: O(N*M) es necesario recorrer cada celda de la matriz calculando su valor con operaciones de coste en O(1)
 Espacio: O(N*M) los valores se guardan en una matriz de esas dimensiones

 REDUCCIÓN DE ESPACIO:
 ----------------------
 Se puede guardar los valores en un vector de tamaño S + 1, y recorriéndolo de izq a dcha ya que nos
 interesan los valores a la izq de j. Esquema del vector:
 --------------------------
 | Fila i | j | Fila i - 1 |
 --------------------------

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int progDinamica(int const& k, int const& S) {
    vector<int> formas(S + 1, 0);
    formas[0] = 1;

    for (int i = 1; i <= k; i++){
        for (int j = i; j <= S; j++)
            formas[j] += formas[j - i];
    }

    return formas[S];
}
void resuelveCaso() {

    // leer los datos de la entrada
    int k, S; cin >> k >> S;
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    cout << progDinamica(k, S) << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR5.txt");
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