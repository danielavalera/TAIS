/*@ <answer>
 *
 * Nombre y Apellidos:
 * Daniela Valera Fuentes TAIS 66
 * Felipe Martin Reyes TAIS 36
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Creamos un grafo dirigido realizando un recorrido en profundidad donde las instrucciones representan los vértices y el paso de una instrucción a otra las aristas.

 Creamos una última instrucción (FIN) para indicar que hemos terminado la ejecución.
 La ejecución termina SIEMPRE si: podemos llegar a FIN desde el origen (vertice 0) y si el grafo es acíclico.
 Termina A VECES si: se encuentra algún ciclo.
 No termina NUNCA si: no es alcanzable el FIN.

 COSTE:
 La entrada se lee en un número L de vueltas y como cada inserción es de orden 1, el coste del bucle es L.
 El coste del recorrido en profundidad es O(V+A) donde V es el nº de vértices = L+1, y A el nº de aristas.
 En el caso peor todas las instrucciones son saltos condicionales con dos aristas, por lo que dfs tendrá un coste de O(3*L) = O(L)

 Por lo que el coste total del ejercicio es lineal respecto al nº de instrucciones, O(L).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class Necronomicon {
public:
    Necronomicon(Digrafo const& g) : visit(g.V(), false), apilado(g.V(), false) {
        dfs(g, 0, g.V() - 1);
    }

    bool getTermina() {
        return termina;
    }
    bool getCiclo() {
        return ciclo;
    }

private:
    bool termina = false, ciclo = false;
    std::vector<bool> visit, apilado;

    void dfs(Digrafo const& g, int v, int fin) {
        visit[v] = true;
        apilado[v] = true;
        for (int w : g.ady(v)) {
            if (w == fin) //hemos terminado el recorrido
                termina = true;
            else if (apilado[w])//hay un ciclo
                ciclo = true;
            else if (!visit[w])
                dfs(g, w, fin);
        }
        apilado[v] = false;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int L = 0;
    std::cin >> L;
    if (!std::cin)  // fin de la entrada
        return false;

    Digrafo g(L + 1);
    for (int i = 0; i < L; i++) {
        char inst;
        std::cin >> inst;
        switch (inst) {
        case 'A': {
            g.ponArista(i, i + 1);
        }break;
        case 'J': {
            int N;
            std::cin >> N;
            g.ponArista(i, N - 1);
        }break;
        case 'C': {
            int N;
            std::cin >> N;
            g.ponArista(i, i + 1);
            g.ponArista(i, N - 1);
        }break;
        }
    }
    // resolver el caso posiblemente llamando a otras funciones
    Necronomicon sol(g);
    // escribir la solución
    if (!sol.getTermina())
        std::cout << "NUNCA";
    else if (sol.getCiclo())
        std::cout << "A VECES";
    else
        std::cout << "SIEMPRE";
    std::cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos5.E.txt");
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
