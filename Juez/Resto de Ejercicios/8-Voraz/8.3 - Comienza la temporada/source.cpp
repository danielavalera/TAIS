
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

CARACTERÍSTICAS:
-----------------
    Candidatos: equipaciones de fútbol
    Test Solución: que el participante cuente con una equipación
    Test Factibilidad: la equipación disponible es igual o una talla mayor que la del jugador
    Función objetivo: número mínimo de equipaciones que hay que comprar
    Función selección (estrategia voraz): asignar cada equipación disponible al jugador

Para esto se han creado dos vectores, uno para almacenar las tallas de los jugadores (vector<int> tallaJugador) y otro que almacena 
las tallas disponibles en la equipación (vector<int> tallaEquipacionesDispo). Mientras la tallaEquipacionesDispo sea igual o una más
que la talla del jugador, no se comprará una equipación nueva.

COSTE:
-------
El coste de leer las tallas de los jugadores es O(N), siendo N = número de jugadores.
El coste de leer las tallas disponibles es O(M), siendo M = número de equipaciones
El coste del algoritmo voraz es O(N log N) y O(M log M) debido a la ordenación de los vectores. Después se recorre el bucle max(N,M) veces,
y en cada vuelta se realizan operaciones con coste O(1) ya que tratamos el dato una única vez.
Por lo tanto, el coste del algoritmo es: O(N log N * M log M) = O(K log K) siendo k = max(N, M).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int voraz(vector<int>& tallaJugador, vector<int>& tallaEquipacionesDispo) {
    int minCompras = tallaJugador.size();
    int i = 0, j = 0;
    while (i < tallaJugador.size() && j < tallaEquipacionesDispo.size()) {
        if ((tallaEquipacionesDispo[j] == tallaJugador[i]) || (tallaEquipacionesDispo[j] == tallaJugador[i] + 1)) {
            minCompras--;
            i++;
            j++;
        }
        else if(tallaEquipacionesDispo[j] < tallaJugador[i]) {
            j++;
        }
        else {
            i++;
        }
    }
    return minCompras;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M; cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> tallaJugador(N);
    for (int i = 0; i < N; i++)
        cin >> tallaJugador[i];
    sort(tallaJugador.begin(), tallaJugador.end());

    vector<int> tallaEquipacionesDispo(M);
    for (int i = 0; i < M; i++)
        cin >> tallaEquipacionesDispo[i];
    sort(tallaEquipacionesDispo.begin(), tallaEquipacionesDispo.end());

    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << voraz(tallaJugador, tallaEquipacionesDispo) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos8.3.txt");
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
