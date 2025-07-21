
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES (TAIS66)
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "queue"  // propios o los de las estructuras de datos de clase

/*@ <answer>
Explicación de la resolución:
------------------------------------------------------------------------------------------------------------------------------------------
Para hacer una cola de mínimos con prioridades variables creamos un struct con el tiempo de espera de cada cliente y el id de cada caja.
La prioridad del elemento será cuando el tiempo sea el menor y en el caso de que los tiempos sean iguales, se dará prioridad al menor id de caja.

Primero hacemos un for recorriendo el numero de cajas que inicializamos en 1 para asignarles un ID a cada caja. El tEspera = 0 ya que aun no ha pasado
ningún cliente por la caja.
Con el segundo for añadimos el tiempo de espera de cada cliente a cada caja.

Explicación del coste:
-------------------------------------------------------------------------------------------------------------------------------------------
Ambas funciones tiene coste O(n * log n) = O(n*logn + n*logn)


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct caja {
    int tEspera, idCaja;
};

bool operator<(const caja& c1, const caja& c2) {
    return c2.tEspera < c1.tEspera || c2.tEspera == c1.tEspera && c2.idCaja < c1.idCaja;
}

int solucion(int nCajas, int nClientes) {
    priority_queue<caja> cola;

    for (int i = 1; i <= nCajas; i++) // O(n * log n)
    {
        cola.push({ 0,i }); //O(log n)
    }

    int sgundos;
    for (int i = 0; i < nClientes; i++) //O(n * log n)
    {
        cin >> sgundos;
        caja primerElemento = cola.top(); //O(1)
        cola.pop();//O(logn)
        primerElemento.tEspera += sgundos;
        cola.push(primerElemento); //O(log n)
    }
    
    return cola.top().idCaja;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int nCajas, nClientes;
    cin >> nCajas >> nClientes;
    if (nCajas == 0 && nClientes == 0)
        return false;
    
    // resolver el caso posiblemente llamando a otras funciones
    int sol = solucion(nCajas, nClientes);

    // escribir la solución
    cout << sol << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos3.1.txt");
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
