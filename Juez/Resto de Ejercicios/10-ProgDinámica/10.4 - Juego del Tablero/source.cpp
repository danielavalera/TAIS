
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
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
void resolver(const int& N, const Matriz<int>& tablero){

	Matriz<int> camino(N + 1, N + 1, 0);

	//Caso base
	//j = 0 -> f (i,0) = 0;  -> si no tiene filas
	//i = 0 -> f (0,j) = 0;  -> si no tiene columnas
	for (int j = 0; j <= N; j++){
		camino[0][j] = 0;
		camino[j][0] = 0;
	}
	//f(1, j) = T[1][j]: En la primera linea ponemos las casillas mas altas del tablero
	//f(i, j) = T[i][j] + max(f(i - 1, j - 1, f(i - 1, j), f(i - 1, j + 1)) i>1:
	//En las siguientes filas, vamos sumando el valor de cada casilla con el valor maximo de sus adyacentes
	//de la fila anterior
	//f(i,j) devuelve la ganancia maxima que se puede obtener llegando a una casilla desde el origen y sin repetir fila
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= N; ++j){
			if (i == 1){
				camino[i][j] = tablero[i][j];
			}
			else {
				int diagonales;
				//delante,diag.izq y diag. der
				//Si j == 1 -> estamos en el borde izquierdo del tablero, nos fijaremos en la diagonal derecha
				if (j == 1){
					diagonales = camino[i - 1][j + 1];
				}
				//Si j == N -> estamos en el borde derecho del tablero, nos fijaremos en la diagonal izquierda
				else if (j == N) {
					diagonales = camino[i - 1][j - 1];
				}
				//En el resto de casos, comparamos las dos diagonales y guardamos la de mayor valor
				else {
					diagonales = max(camino[i - 1][j + 1], camino[i - 1][j - 1]);
				}
				//El valor del camino sera el valor de esa casilla en el tablero + el valor maximo entre sus adyacentes
				camino[i][j] = tablero[i][j] + max(diagonales, camino[i - 1][j]);
			}
		}
	}

	//Buscamos el mayor valor y su posicion
	int maxV = 0;
	int maxVTemp = 0;
	int posi = 0;
	for (int i = 1; i <= N; ++i){
		maxVTemp = maxV;
		maxV = max(maxV, camino[N][i]);
		if (maxV != maxVTemp){
			posi = i;
		}
	}

	//sacamos por pantalla el valor maximo alcanzable y desde que casilla se inicia el camino
	cout << maxV << " " << posi << "\n";

}


bool resuelveCaso() {

    // leer los datos de la entrada
    int dimension; cin >> dimension;
    if (!std::cin)  // fin de la entrada
        return false;
    Matriz<int> tablero(dimension + 1, dimension + 1);
	for (int i = 1; i <= dimension; i++) {
		for (int j = 1; j <= dimension; j++) {
			cin >> tablero[i][j];
		}
	}
    // resolver el caso posiblemente llamando a otras funciones
    resolver(dimension, tablero);
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos10.4.txt");
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
