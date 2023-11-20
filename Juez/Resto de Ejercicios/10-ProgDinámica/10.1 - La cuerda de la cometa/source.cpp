/*@ <answer>
 *
 * Nombre y Apellidos: DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct cordel {
    int longitud, coste;
};

struct solucion {
    long int nManeras, minCordeles, minCoste;
};


vector<int> devolver_cambio(vector<int> longitudes, vector<int> costes, int L, int& numCordeles) {
    int n = longitudes.size() - 1;
    vector<int> cometas(L + 1, INT_MAX - 1);
    cometas[0] = 0;

    // calcular la matriz sobre el propio vector
    int ant = cometas[L];
    int cont = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = longitudes[i]; j <= L; ++j) {
            cometas[j] = min(cometas[j], cometas[j - longitudes[i]] + 1);
            if (j == L) {
                if (ant == cometas[j]) {
                    cont++;
                }
                else {
                    ant = cometas[j];
                    cont = 1;
                }
            }
        }
    }

    numCordeles = cometas[L];
    if (numCordeles >= longitudes.size()) {
        numCordeles = -1;
        return {};
    }
    vector<int> nformas(n + 1, 0);
    vector<int> sol(n + 1, 0);
    int i = n, j = L;
    while (j > 0) { // no se ha pagado todo
        if (longitudes[i] <= j && cometas[j] == cometas[j - longitudes[i]] + 1) {
            // tomamos una moneda de tipo i
            sol[i]++;
            j = j - longitudes[i];
        }
        else // no tomamos más monedas de tipo i
            --i;
    }

    return sol;
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int nCordeles, longTotal; cin >> nCordeles >> longTotal;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<cordel> cordeles(nCordeles);
    int longAux, costeAux;
    for (int i = 0; i < nCordeles; i++)
    {
        cin >> longAux >> costeAux;
        cordeles[i] = {longAux, costeAux};
    }
    // resolver el caso posiblemente llamando a otras funciones
    vector<solucion> sol = vector<solucion>(longTotal + 1);
    for (int i = 1; i <= longTotal; i++) {
        sol[i].nManeras = 0;
        sol[i].minCoste = 0;
        sol[i].minCordeles = 0;
    }
    sol[0].nManeras = 1;
    sol[0].minCoste = 0;
    sol[0].minCordeles = 0;

    for (int i = 0; i < nCordeles; i++) {
        for (int j = longTotal; j >= cordeles[i].longitud; j--) {

            if (j - cordeles[i].longitud >= 0) { //La cuerda i-esima no es demasiado grande
                sol[j].nManeras += sol[j - cordeles[i].longitud].nManeras;

                if (sol[j - cordeles[i].longitud].nManeras != 0) { //Si sol[j-cuerdas[i].largo] se puede construir

                    if (sol[j - cordeles[i].longitud].nManeras == sol[j].nManeras) {
                        //Si sol[j].nFormas era 0, no podiamos construirlo, ahora si, actualizamos valors
                        sol[j].minCoste = sol[j - cordeles[i].longitud].minCoste + cordeles[i].coste;
                        sol[j].minCordeles = sol[j - cordeles[i].longitud].minCordeles + 1;
                    }
                    else {
                        sol[j].minCoste = min(sol[j].minCoste, sol[j - cordeles[i].longitud].minCoste + cordeles[i].coste);
                        sol[j].minCordeles = min(sol[j].minCordeles, sol[j - cordeles[i].longitud].minCordeles + 1);
                    }
                }

            }
        }
    }


    if (sol[longTotal].nManeras == 0) cout << "NO" << endl;
    else  cout << "SI " << sol[longTotal].nManeras
        << " " << sol[longTotal].minCordeles
        << " " << sol[longTotal].minCoste << endl;
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos10.1.txt");
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
