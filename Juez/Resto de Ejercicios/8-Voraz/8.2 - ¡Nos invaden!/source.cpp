
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
    Candidatos: equipos de defensa disponibles para asignar
    Test Solución: conseguir el máximo número de ciudades defendidas exitosamente
    Test Factibilidad: la cantidad de efectivos del equipo de defensa asignado es mayor o igual a los efectivos enemigos de la ciudad correspondiente
    Función objetivo: maximizar el número de victorias garantizadas
    Función selección (estrategia voraz): averiguar qué equipo de defensa asignamos a cada equipo Asignar cada equipo de defensa al enemigo más débil que aún no haya sido enfrentado.

Para esto se han creado dos vectores, uno para representar el número de efectivos enemigos por ciudad (vector<int> enemigos) y otro para representar 
el número de efectivos de defensa (vector<int> defensa). Mientras nuestros efectivos de defensa sean el mismo número o más que los efectivos enemigos,
podremos asegurar la victoria en esa ciudad. Esto lo conseguimos ordenando los vectores y añadiendo un contador (int cont_e) auxiliar para recorrer el
vector enemigo, ya que al estar ordenados no va a haber posiblidad de contemplar esa ciudad con una defensa inferior.

COSTE:
-------
El coste de leer el número de efectivos tanto de enemigos como de defensa es O(N), siendo N = número de ciudades invadidas y equipos de defensa
El coste del algoritmo voraz es O(N log N) debido a la ordenación de los vectores. Después se recorre el vector defensa, de tamaño N,
haciendo operaciones de coste O(1) ya que solo tratamos el dato una vez.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int voraz(vector<int>& enemigos, vector<int>& defensa) {
    int victorias = 0;
    sort(enemigos.begin(), enemigos.end());
    sort(defensa.begin(), defensa.end());
    int cont_e = 0;
    for (int i = 0; i < defensa.size(); i++)
    {
        if (defensa[i] >= enemigos[cont_e]) {
            victorias++;
            cont_e++;
        }
    }
    return victorias;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> enemigos(N);
    vector<int> defensa(N);
    for (int i = 0; i < N; i++)
    {
        cin >> enemigos[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> defensa[i];
    }
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << voraz(enemigos, defensa) << '\n';
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos8.2.txt");
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
