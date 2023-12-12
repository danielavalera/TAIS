
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 RECURSIÓN
 -------------------------
 volar(i) = nº maneras para llegar hasta el pivote N empezando en el i

 volar(i) = SUM_1 <= k <= S+1_i+k < P(maneras(i+k))

 CASOS BASE:
 volar(N) = 1;

 Llamada inicial : volar(1)

 RESOLUCIÓN
 ----------------------------
 Se utiliza programación dinámica ascendente. Como la recursión tiene solo 1 parámetro necesitamos un vector, que se irá rellenando de derecha a izq, ya que para una posición i
 necesitamos posiciones posteriores (i+k). La última posición del vector, correspondiente al caso base, será 1, y la solución quedará almacenada en la primera posición, 
 correspondiente a empezar en el primer pivote (i=0);

 COSTE
 ----------------------------
 El coste en espacio está en orden O(P), por el vector donde guardamos las soluciones de los subproblemas.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
long long int volar(int P, int S) {
    vector<long long int> v(P, 0);
    v[P - 1] = 1;
    for (int i = P-2; i >= 0; i--)
    {
        int k = 1;
        while (k <= S + 1 && i + k < P) {
            v[i] = (v[i] + v[i + k]) % 1000000007;
            ++k;
        }
    }
    return v[0];
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int P, S; cin >> P >> S;
    if (P==0 && S==0)
        return false;

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    cout << volar(P, S) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos12.4.b.txt");
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
