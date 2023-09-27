
/*@ <answer>
 *
 * Nombre y Apellidos:
 * Daniela Valentina Valera Fuentes TAIS66
 * Felipe Martin Reyes TAIS36
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Tenemos una cola de prioridad ordenada por el coeficiente (según la formula del enunciado).
Para resolver el problema cogemos el elemento más prioritario de la cola, lo desapilamos, recalculamos su coeficiente
al sumarle un escanio y lo volvemos a introducir en la cola. Esta lo ordenará de nuevo según su coeficiente.
Iteramos hasta que hemos terminado de repartir todos los escanios.
Para la salida vamos desapilando los elementos y asignándolos en un vector según su orden de entrada al programa.
Lo imprimimos por pantalla en ese orden.
El coste de la función que resuelve el problema es O(nlogn) siendo n el número de escanios.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct voto {
    int nVotos, coeficiente, posicionEntrada, escanios;
};
bool operator<(voto const& e1, voto const& e2) {
    return (e1.coeficiente > e2.coeficiente) || (e1.coeficiente == e2.coeficiente && e1.posicionEntrada < e2.posicionEntrada);
}

void reparto(PriorityQueue<voto>& cola, int esc) {
    while (esc != 0) {
        voto aux = cola.top();
        cola.pop();
        aux.escanios++;
        aux.coeficiente = aux.nVotos / (1 + aux.escanios);
        cola.push({ aux.nVotos, aux.coeficiente, aux.posicionEntrada, aux.escanios });
        esc--;
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int nCandidatos, nEscanios;
    cin >> nCandidatos >> nEscanios;
    if (nCandidatos == 0 && nEscanios == 0)
        return false;

    int v, c;
    PriorityQueue<voto> cola;
    for (int i = 0; i < nCandidatos; i++)
    {
        cin >> v;
        c = v / (1 + 0);
        cola.push({v, c, i, 0});
    }

    // resolver el caso posiblemente llamando a otras funciones
    reparto(cola, nEscanios);
    // escribir la solución
    vector<int> sol(nCandidatos);
    while (!cola.empty()) {
        sol[cola.top().posicionEntrada] = cola.top().escanios;
        cola.pop();
    }
    
    for (int i = 0; i < sol.size(); i++)
    {
        if (i == sol.size() - 1) {
            cout << sol[i] << endl;
        }
        else {
            cout << sol[i] << " ";
        }
    }
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
