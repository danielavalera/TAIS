
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES, TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;
#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {
	// leer los datos de la entrada
	int n,e; cin >> n;
	if (n == 0)
		return false;

	PriorityQueue<long long int> c;
	for (int i = 0; i < n; i++) //O(N*logN)
	{
		cin >> e;
		c.push(e); //O(logN)
	}

	long long int a, b, esfuerzo = 0;
	for (int i = 0; i < n - 1; i++)
	{
		a = c.top(); //O(1)
		c.pop();//O(logN)
		b = c.top();
		c.pop();

		esfuerzo += a + b;
		c.push(a + b); //O(logN)
	}
	
	// resolver el caso posiblemente llamando a otras funciones

	// escribir la solución
	cout << esfuerzo << endl;

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("2.1.txt");
	if (!in.is_open())
		std::cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout << "Pulsa Intro para salir..." << std::flush;
	std::cin.get();
#endif
	return 0;
}
