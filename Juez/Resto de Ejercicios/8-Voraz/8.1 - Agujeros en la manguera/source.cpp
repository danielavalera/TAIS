
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

CARACTERÍSTICAS:
-----------------
    Candidatos: agujeros de la manguera
    Test Solución: todos los agujeros deben estar cubiertos con parches
    Test Factibilidad: verificar que el agujero actual no esté cubierto por el último parche
    Función objetivo: minimizar el número de parches necesarios
    Función selección (estrategia voraz): colocar un parche en el primer agujero no cubierto que ocupe tantos agujeros como permita su longitud L

Para esto se ha creado un vector de enteros posAgujero, en el que aparece la posición de la manguera dónde está el agujero.
Mientras la última posición libre en la manguera (int ultPosLibreSigParche) sea menor que la posición del siguiente agujero en la manguera,
añadimos un parche para cubrir el siguiente agujero. De esta manera, controlamos cuántos agujeros se pueden cubrir con cada parche.

COSTE:
-------
El coste de leer los agujeros tiene un coste de O(N), siendo N = número de agujeros.
El coste del algoritmo es O(N) ya que la posición de los agujeros está en orden y se recorren todos realizando operaciones
de coste O(1), ya que los tratamos sólo una vez, en cada vuelta del bucle.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int voraz(vector<int> const& posAgujero, int L) {
    int parches = 0, ultPosLibreSigParche = -1;
    for (int i = 0; i < posAgujero.size(); i++)
    {
        if (ultPosLibreSigParche < posAgujero[i]) {
            ++parches;
            ultPosLibreSigParche = posAgujero[i] + L;
        }
    }
    return parches;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, L; cin >> N >> L;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> posAgujero(N);
    for (int i = 0; i < N; i++)
    {
        cin >> posAgujero[i];
    }
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << voraz(posAgujero, L) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos8.1.txt");
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
