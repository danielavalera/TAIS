
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
    Candidatos: Películas disponibles para ver.
    Test Solución: Maximizar el número de películas vistas durante el maratón.
    Test Factibilidad: La hora de inicio de una película es mayor o igual a la hora de finalización (incluido el descanso) de la anterior película seleccionada.
    Función objetivo: Maximizar el número de películas que se pueden ver.
    Función selección (estrategia voraz): Ordenar las películas por hora de finalización, seleccionando siempre la siguiente película que termine más temprano y sea compatible con la selección previa.

Para esto hemos creado un vector que almacena una estructura con la información de cada película. La información es la hora de inicio y de fin
adaptada a los minutos que tiene un día. Mientras la hora de inicio de la pelicula no sea inferior a la hora de fin (incluyendo el descanso) de 
la película anterior, podremos ver la película.

COSTE:
-------
El coste de leer las películas es O(N), donde N = número de películas.
El coste del algoritmo es del orden de O(N log N) debido a la ordenación del vector de películas. Después de ordenar el vector se 
realizan operaciones con coste (O(1)) ya que se accede a estos datos una única vez.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct pelicula {
    int ini, fin;
};

bool operator<(pelicula const& p1, pelicula const& p2) {
    return p1.fin < p2.fin;
}

int voraz(vector<pelicula>& p, int descanso) {
    int maxPeli = 0, finUltPeli = -descanso;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].ini >= finUltPeli + descanso) {
            maxPeli++;
            finUltPeli = p[i].fin;
        }
    }
    return maxPeli;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (N==0)  // fin de la entrada
        return false;

    int hora, min, duracion;
    char aux;
    vector<pelicula> p(N);
    for (int i = 0; i < N; i++)
    {
        cin >> hora >> aux >> min >> duracion;
        p[i] = { hora * 60 + min, hora * 60 + min + duracion };
    }
    sort(p.begin(), p.end());
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << voraz(p, 10) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos8.4.txt");
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


