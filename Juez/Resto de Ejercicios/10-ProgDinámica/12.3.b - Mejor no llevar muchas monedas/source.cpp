
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 RECURSIÓN
 -------------------------------------------------
 minMonedas(i,j) = minimo nº de monedas con las que podemos pagar la cantidad j si tenemos disponibles los tipos de moneda del 1 al i (Infinito si no se puede)

 minMonedas(i,j) = min_0<= k <= Ci_k*Vi <= j(minMonedas(i-1,j-Vi*k) + k


 CASOS BASE:
 minMonedas(0,j) = Infinito
 minMonedas(i,0) = 0

 Llamada inicial: minMonedas(N,P)

 RESOLUCIÓN
 -------------------------------------------------
 Se utiliza programación dinámica ascendente. Se va rellenando la matriz de N+1 filas (se añade la fila 0 para el conjunto vacio) y P+1 columnas (precio a pagar desde
 0 a P) de arriba a abajo y de derecha a izquierda. La primera columna será 0 y la primera fila Infinito (excepto la primera posición), por los casos base, y a partir de ahí
 basta aplicar la función recursiva. La solución quedará almacenada en la posición [N][P] de la matriz, correspondiente al caso en que contamos con todas las monedas y
 queda por pagar el precio total del coche. Para una posición sólo necesitamos posiciones de la fila superior (y en columnas <= j), por lo que podemos reducir el espacio
 a un único vector que se va rellenando de derecha a izquierda y que, en un momento dado, sería así:

 ----------------------------
 | fila i-1 | j | fila i |
 ----------------------------

 COSTE
 -------------------------------------------------
 El coste en tiempo está en el orden O(N * P), porque recorremos toda la matriz y sobre cada elemento realizamos operaciones de coste O(1).
 El coste en espacio está en el orden O(P), por el vector donde guardamos las soluciones de los subproblemas

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct moneda {
    int valor, cantidad;
};

EntInf minMonedas(vector<moneda> const& monedas, int P) {
    int N = monedas.size();
    vector<EntInf> v(P+1, Infinito);
    v[0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = P; j > 0; --j) {
            int k = 0;
            while(k <= monedas[i-1].cantidad && k* monedas[i-1].valor <= j){
                EntInf temp = v[j - k * monedas[i-1].valor] + k;
                if (temp < v[j]) {
                    v[j] = temp;
                }
                k++;
            }
        }
    }
    return v[P];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    
    vector<moneda> monedas(N);
    int aux;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        monedas[i] = { aux, 0 };
    }
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        monedas[i].cantidad = aux;
    }
    int P; cin >> P;

    // resolver el caso posiblemente llamando a otras funciones
    EntInf sol = minMonedas(monedas, P);
    // escribir la solución
    if (sol != Infinito) cout << "SI " << sol;
    else cout << "NO";
    cout << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos12.3.b.txt");
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
