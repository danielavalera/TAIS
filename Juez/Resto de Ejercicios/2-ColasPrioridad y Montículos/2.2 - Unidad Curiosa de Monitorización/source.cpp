
/*@ <answer>
 *
 * Nombre y Apellidos: Daniela Valentina Valera Fuentes TAIS66
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
using namespace std;

/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> /*/


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct registro {
    int momento, id, periodo;
};

bool operator<(registro const& a, registro const& b) {
    return b.momento < a.momento || (a.momento == b.momento && b.id < a.id);
}

bool resuelveCaso() { //O(nlogn + klogn)
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    priority_queue<registro> cola;
    for (int i = 0; i < n; i++) {//O(nlogn)
        int id_aux, periodo_aux;
        cin >> id_aux >> periodo_aux;
        cola.push({ periodo_aux, id_aux, periodo_aux }); //O(logn)
    }

    // resolver el caso posiblemente llamando a otras funciones
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) { //O (k log n)
        auto primerElemento = cola.top(); //O(1)
        cola.pop(); //O(logn)
        cout << primerElemento.id << '\n';
        primerElemento.momento += primerElemento.periodo;
        cola.push(primerElemento); //O(logn)
    }

    // escribir la solución
    cout << "---" << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos2.2.txt");
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

