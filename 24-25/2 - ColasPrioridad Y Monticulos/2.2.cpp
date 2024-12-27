
/*@ <answer>
 *
 * DANIELA VALENTINA VALERA FUENTES, TAIS108
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
    long id;
    int periodo;
    int momento;
};

bool operator<(registro const& user1, registro const& user2) {
    return user2.momento < user1.momento ||
        (user1.momento == user2.momento && user2.id < user1.id);
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    priority_queue<registro> cola;
    for (int i = 0; i < n; i++) {
        long id_aux;
        int periodo_aux;
        cin >> id_aux >> periodo_aux;
        cola.push({ id_aux, periodo_aux, periodo_aux }); //O(logn)
    }

    // resolver el caso posiblemente llamando a otras funciones
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        registro primerElemento = cola.top(); //O(1)
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

