
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

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
using matriz = vector<vector<int>>;

// calcula la longitud del mayor palíndromo en patitos[i..j]
int pal(string palabra, matriz& m) {
    int tamPalabra = palabra.size();
    for (int i = tamPalabra - 2; i >= 0; i--){
        for (int j = i+1; j < tamPalabra; j++){
            if (palabra[i] == palabra[j])
                m[i][j] = m[i+1][j-1];
            else
                m[i][j] = min(m[i + 1][j], m[i][j - 1]) +1;
        }
    }
    
    return m[0][tamPalabra-1];
}


// devuelve el palíndromo más largo en patitos[i..j]
string reconstruir(int i, int j, matriz const& m, string palabra ) {
    if (i == j) return string(1, palabra[i]);
    if (i > j) return "";
    else
        if (palabra[i] == palabra[j])
            return palabra[i] + reconstruir(i + 1, j - 1, m, palabra) + palabra[j];
        else if (m[i][j]-1 == m[i][j-1])
            return palabra[j] + reconstruir(i, j - 1, m, palabra) + palabra[j];
        else
            return palabra[i] + reconstruir(i + 1, j, m, palabra) + palabra[i];
}

pair<int, string> progDinamica(string palabra) {
    int tamPalabra = palabra.size();

    matriz m(tamPalabra, vector<int>(tamPalabra, 0));
    int minLetras = pal(palabra, m);
    string pal = palabra;

    if (minLetras != 0)
        pal = reconstruir(0, tamPalabra - 1, m, palabra);

    return{ minLetras, pal };
}
bool resuelveCaso() {

    // leer los datos de la entrada
    string palabra; cin >> palabra;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    pair<int, string> sol = progDinamica(palabra);
    // escribir la solución
    cout << sol.first << ' ' << sol.second << '\n';
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
