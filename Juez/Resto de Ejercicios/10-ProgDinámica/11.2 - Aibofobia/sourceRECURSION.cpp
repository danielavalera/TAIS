
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS66
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase
#include "Matriz.h"
/*@ <answer>

f(i,j) = menor número de letras que hay que añadir

 CASO BASE:
 ------------
 f(i,j) = 0 si i >= j


 CASOS RECURSIVOS:
 ------------------
    --- f(i+1,j-1) si palabra[i] == palabra[j]

    --- min(
            f(i+1,j) + 1,
            f(i,j-1) + 1)   si palabra[i] != palabra[j]


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
// calcula la longitud del mayor palíndromo en patitos[i..j]
int aifobia(string const& palabra, int i, int j, Matriz<int>& combinaciones) {
    int& res = combinaciones[i][j];
    if (res == -1) {
        if (i >= j) res = 0; //caso base
        else if (palabra[i] == palabra[j]) //casos recursivos
            res = aifobia(palabra, i + 1, j - 1, combinaciones);
        else
            res = min(
                aifobia(palabra, i + 1, j, combinaciones) +1,
                aifobia(palabra, i, j - 1, combinaciones) +1);
    }
    return res;
}


// devuelve el palíndromo más largo en patitos[i..j]
string reconstruir(string palabra, Matriz<int> const& combinaciones, int i, int j) {
    if (i == j) return string(1, palabra[i]);

    if (i > j) return "";
    else {
        if (palabra[i] == palabra[j]) 
            return palabra[i] + reconstruir(palabra, combinaciones, i+1, j-1) + palabra[j];
        else if(combinaciones[i][j]-1 == combinaciones[i][j-1])
            return palabra[j] + reconstruir(palabra, combinaciones, i, j-1) + palabra[j];
        else 
            return palabra[i] + reconstruir(palabra, combinaciones, i + 1, j) + palabra[i];
    }
}


bool resuelveCaso() {

    // leer los datos de la entrada
    string palabra; cin >> palabra;
    if (!std::cin)  // fin de la entrada
        return false;
    int n = palabra.length();

    Matriz<int> combinaciones(n, n, - 1);
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    int minLetras = aifobia(palabra, 0, n - 1, combinaciones);

    if (minLetras != 0)
        cout << minLetras << " " << reconstruir(palabra, combinaciones, 0, n - 1);
    else
        cout << 0 << " " << palabra;

    cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos11.2.txt");
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
