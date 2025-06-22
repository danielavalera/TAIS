
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"
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
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int orig, vector<int> const& tCarga) : origen(orig),
		dist(g.V(), INF), ulti(g.V()), pq(g.V()), _tCarga(tCarga) {
		dist[origen] = 0 + tCarga[origen];
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}
	bool hayCamino(int v) const { return dist[v] != INF; }
	Valor distancia(int v) const { return dist[v]; }
	/*Camino<Valor> camino(int v) const {
		Camino<Valor> cam;
		// recuperamos el camino retrocediendo
		AristaDirigida<Valor> a;
		for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
			cam.push_front(a);
		cam.push_front(a);
		return cam;
	}*/
private:
	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	std::vector<Valor> dist;
	std::vector<AristaDirigida<Valor>> ulti;
	IndexPQ<Valor> pq;
	vector<int> _tCarga;
	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor() + _tCarga[w]) {
			dist[w] = dist[v] + a.valor() + _tCarga[w]; ulti[w] = a;
			pq.update(w, dist[w]);
		}
	}
};
bool resuelveCaso() {
	// leer los datos de la entrada
	int N; cin >> N;
	if (N == 0)
		return false;

	vector<int> tCarga(N);
	for (int i = 0; i < N; i++)
		cin >> tCarga[i];
	
	DigrafoValorado<int> dv(N);
	int M; cin >> M;
	int v, w, p;
	for (int i = 0; i < M; i++)
	{
		cin >> v >> w >> p;
		dv.ponArista({ v - 1,w - 1,p });
	}
	// resolver el caso posiblemente llamando a otras funciones
	Dijkstra<int> dj(dv, 0, tCarga);
	// escribir la solución
	if (dj.hayCamino(N - 1))	cout << dj.distancia(N - 1);
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