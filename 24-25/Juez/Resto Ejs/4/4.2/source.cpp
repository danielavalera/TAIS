
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 El problema se representa mediante un grafo, donde los vertices representan las personas y las aristas la relación de amistad entre ellas.
 De esta manera conoceremos la componente conexa más grande.

 Para esto, generamos el grafo que se recorrerá en profundidad por su lista de vertices adyacentes, marcándolos a true cuando se hayan visitado.
 Cada vez que visitemos un vértice se sumará 1 al tamaño para después conocer el tamaño total de la componente conexa, que se elegirá entre los máximos de cada componente conexa del grafo.

 El coste es O(V+A) donde V es el número de vertices (personas) y A es el número de aristas (relaciones de amistad).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class MaximaCompConexa {
public:
    MaximaCompConexa(Grafo const& g) : 
        visit(g.V(), false),
        maxim(0) {


        for (int v = 0; v < g.V(); ++v) {
            if (!visit[v]) { // se recorre una nueva componente conexa
                int tam = dfs(g, v);
                maxim = max(maxim, tam);
            }
        }
    }
    // tamaño máximo de una componente conexa
    int maximo() const {
        return maxim;
    }

private:
    vector<bool> visit; // visit[v] = se ha visitado el vértice v?
    int maxim; // tamaño de la componente mayor

    int dfs(Grafo const& g, int v) {
        visit[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visit[w])
                tam += dfs(g, w);
        }
        return tam;
    }
};

void resuelveCaso() {

    // leer los datos de la entrada
    int nPersonas, nPares;
    cin >> nPersonas >> nPares;
    Grafo g = Grafo(nPersonas);

    int a, b;
    for (int i = 0; i < nPares; i++)
    {
        cin >> a >> b;
        g.ponArista(a - 1, b - 1);
    }
    // resolver el caso posiblemente llamando a otras funciones
    MaximaCompConexa mcc(g);
    // escribir la solución

    cout << mcc.maximo() << '\n';
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos4.2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
