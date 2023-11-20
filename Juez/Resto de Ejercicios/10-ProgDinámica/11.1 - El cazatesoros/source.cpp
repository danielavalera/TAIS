
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct cofre {
    int profundidad, oro;
};

double mochila_rec(vector<cofre> const& cofres, int tamCofres, int seg, Matriz<double>& mochila) {
    if (mochila[tamCofres][seg] != -1) // subproblema ya resuelto
        return mochila[tamCofres][seg];
    if (tamCofres == 0 || seg == 0) mochila[tamCofres][seg] = 0;
    else if (cofres[tamCofres - 1].profundidad > seg)
        mochila[tamCofres][seg] = mochila_rec(cofres, tamCofres - 1, seg, mochila);
    else
        mochila[tamCofres][seg] = max(mochila_rec(cofres, tamCofres - 1, seg, mochila), mochila_rec(cofres, tamCofres - 1, seg - cofres[tamCofres - 1].profundidad, mochila) + cofres[tamCofres - 1].oro);
    return mochila[tamCofres][seg];
}

double mochila(vector<cofre> const& cofres, int seg, vector<bool>& sol) {
    int tamCofres = cofres.size();
    Matriz<double> mochila(tamCofres + 1, seg + 1, -1);
    double valor = mochila_rec(cofres, tamCofres, seg, mochila);
    // cálculo de los cofres
    int i = tamCofres, j = seg;
    sol = vector<bool>(tamCofres, false);
    while (i > 0 && j > 0) {
        if (mochila[i][j] != mochila[i - 1][j]) {
            sol[i - 1] = true; j = j - cofres[i - 1].profundidad;
        }
        --i;
    }
    return valor;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int seg; cin >> seg;
    if (!std::cin)  // fin de la entrada
        return false;
    int numCofres; cin >> numCofres;
    vector<cofre> cofres(numCofres);
    int p, o;
    for (int i = 0; i < numCofres; i++){
        cin >> p >> o;
        cofres[i].profundidad = 3 * p;
        cofres[i].oro = o;
    }
    // resolver el caso posiblemente llamando a otras funciones
    vector<bool> sol;
    double valor = mochila(cofres, seg, sol);
    cout << valor << '\n';
    int cont = 0;
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i])
            cont++;
    }
    cout << cont << '\n';
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i])
            cout << cofres[i].profundidad / 3 << " " << cofres[i].oro << '\n';
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
    std::ifstream in("casos11.1.txt");
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

