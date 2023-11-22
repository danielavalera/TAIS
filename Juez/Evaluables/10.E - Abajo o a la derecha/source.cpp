
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 * FELIPE MARTÍN REYES TAIS36
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*@ <answer>

 ------------------
 RECURRENCIA:

 -maneras(i,j) = num de formas diferentes en la que puedo ir desde ij hasta NM
 -maneras(i,j) = maneras(i + Lij, j) + maneras(i, j + Lij)
        *donde Lij = longitud del salto desde la posicion ij
        

 CASO BASE:
 -maneras(N, M) = 1     (hemos llegado)
 -maneras(i, j) = 0     si  i > N || j > M

 -----------------
 RESOLUCIÓN:

 Para resolver este problema usamos programación dinámica ascendente en el cual vamos rellenando una matriz
 de N filas y M columnas de abajo a arriba y de derecha a izquierda. Para calcular la posicion necesitamos 
 la arbitraria inferior y la de su derecha. Partimos de 1 de la última posición (por el caso base) y seguimos
 aplicando la función recursiva. Devolvemos la posicion [0][0] que es donde estará almacenada la solucion.
 -----------------
 COSTE:

 -En tiempo: O(N^2) ya que recorremos toda la matriz y realizamos operaciones de coste constante sobre cada elemento
 -En espacio adicional: O(N^2) por la matriz donde almacenamos las soluciones de los subproblemas.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
using matriz = vector<vector<int>>;

int celda(int i, int j, matriz const& m) {
    if (i >= m.size() || j >= m[0].size()) return 0;
    else return m[i][j];
}

int progDinamica(matriz const& m) {
    int N = m.size(), M = m[0].size();
    matriz sol(N, vector<int>(M, 0));
    sol[N - 1][M - 1] = 1;
    // rellenamos la matriz
    for (int i = N-1; i >= 0; --i) {
        for (int j = M-1; j >= 0; --j) {
            sol[i][j] += celda(i + m[i][j],j, sol) + celda(i, j + m[i][j], sol);
        }
    }
   
    return sol[0][0];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M; cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;
    matriz matriz(N, vector<int>(M));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> matriz[i][j];
        }
    }
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << progDinamica(matriz) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos10.E.txt");
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
