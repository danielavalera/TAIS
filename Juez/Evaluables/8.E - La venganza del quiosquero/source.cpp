
/*@ <answer>
 *
 * Nombre y Apellidos:
 * Daniela Valera Fuentes TAIS66
 * Feliep Martin Reyes TAIS36
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Para resolver el problema, se emplea una estrategia voraz que busca minimizar el coste de seleccionar N resistencias eléctricas, mientras se cumple que:
 No se pueden seleccionar pares de resistencias cuya suma sea igual a S y se deben seleccionar las resistencias de menor coste posible.

 Para esto utilizamos un vector de booleanos llamado resistencias considerando las que tienen un valor menor que S y
 se analizan en orden creciente a su valor y, por lo tanto, en orden creciente de coste, con el objetivo de minimizarlo.

 Se utiliza un índice llamado i para rastrear el valor de las resistencias que se están considerando.
 Si es menor que S, el código verifica si la diferencia entre S e i no está presente en el vector resistencias[i] = false.
 Si es mayor o igual a S, se añade automáticamente, ya que no puede sumar S ohmios en pares con resistencias ya seleccionadas.

 En cuanto al coste de la solución:

 La inicialización del vector tiene un coste lineal en relación a S, ya que solo es necesario llevar un registro de las resistencias con valores menores que S (tiene S posiciones).
 El bucle tiene un máximo de N iteraciones, con un coste de O(1) cada vuelta.

 Por lo tanto, el coste total de la solución es O(N + S), ó O(max(N, S)).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

long long int calcularPrecioTotal(std::vector<bool>& resistencias, const int& N, const int& S) {
    long long int precioTotal = 1, i = 2, numRes = 1;
    resistencias[0] = true;
    
    while (numRes < N) {
        if (i < S) {
            if (!resistencias[S - i - 1]) {
                precioTotal += i;
                numRes++;
                resistencias[i - 1] = true;
            }
        }
        else {
            precioTotal += i;
            numRes++;
        }
        i++;
    }
  
    return precioTotal;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N = 0, S = 0;
    std::cin >> N >> S;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<bool> resistencias(S, false);

    // resolver el caso posiblemente llamando a otras funciones
    long long int sol = calcularPrecioTotal(resistencias, N, S);
    // escribir la solución
    std::cout << sol << std::endl;
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
