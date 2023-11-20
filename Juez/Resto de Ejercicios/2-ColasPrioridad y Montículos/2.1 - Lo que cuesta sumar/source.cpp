/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Ya que por defecto PriorityQueue.h ordena la cola con una prioridad de mínimos en un montículo de mínimos,
basta con sumar los dos primeros elementos de la cola (que después eliminamos) e insertar el resultado de la suma. 
Luego los elementos se volverán a ordenar según la prioridad del mínimo elemento y así sucesivamente.
Además, se crea un acumulador con la suma total de los esfuerzos que será la salida del programa.

Se realizan 3 operaciones en este bucle (durante n-1 sumas necesarias): pop, pop y push, y cada una de ellas tiene
un coste logarítmico (O(logn)). Por lo que el orden de esta función es cuasilineal: 3*logn, O(n*logn).

//DEBERÍA SACAR EL COSTE DE CUANDO HACEMOS PUSH A LA COLA??

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    int n; //¿long int?
    cin >> n;
    if (n == 0)
        return false;

    //cola prioridad
        PriorityQueue<long long int> cola;
    // numeros para la cola
        int sumando;//¿long int?

    for (int i = 0; i < n; i++)
    {
        cin >> sumando;
        cola.push(sumando); // 0() ?
    }

    long long int a, b; //¿no me sobraria un long?
    long long int esfuerzo = 0; //¿no me sobraria un long?

    for (int i = 0; i < n - 1; i++) // (n-1) sumas necesarias
    {
        a = cola.top(); //elemento prioritario con cte constante (O(1))
        cola.pop(); //lo quito con cte O(logn)
        b = cola.top(); // O(1)
        cola.pop(); // O(logn)

        esfuerzo += a + b;
        cola.push(a + b); //lo inserto con cte O(logn)
    }


    cout << esfuerzo << endl;
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos2.1.txt");
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
