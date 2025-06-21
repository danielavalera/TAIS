
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
template <typename Valor>
class ARM_Kruskal {
private:
	std::vector<Arista<Valor>> _ARM;
	Valor coste;
	ConjuntosDisjuntos cjtos;
public:
	Valor costeARM() const {
		return coste;
	}
	//std::vector<Arista<Valor>> const& ARM() const {
	//	return _ARM;
	//}
	int numCjtos() const{
		return cjtos.num_cjtos();
	}
	ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), cjtos(g.V()) {
		PriorityQueue<Arista<Valor>> pq(g.aristas());
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				_ARM.push_back(a); coste = a.valor();
				if (_ARM.size() == g.V() - 1) break;
			}
		}
	}
};
bool resuelveCaso() {
	// leer los datos de la entrada
	int N, M, a, b, p;
	cin >> N >> M;
	if (!std::cin)  // fin de la entrada
		return false;
	GrafoValorado<int> gv(N);
	if (M != 0) {
		for (int i = 0; i < N; i++)
		{
			cin >> a >> b >> p;
			gv.ponArista({ a - 1,b - 1,p });
		}
	}
	// resolver el caso posiblemente llamando a otras funciones
	ARM_Kruskal<int> arm(gv);
	// escribir la solución
	if (M == 0) cout << 0;
	else if (arm.numCjtos() == 1) cout << arm.costeARM();
	else cout << "IMPOSIBLE";
	cout << "\n";

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
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