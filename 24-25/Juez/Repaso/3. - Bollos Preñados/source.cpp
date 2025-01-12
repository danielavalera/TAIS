
/*@ <authors>
 *
 * DANIELA VALENTINA VALERA FUENTES TAIS108
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 ACLARACIONES:
 -------------
 N = nº chorizos disponibles
 masa = masa total disponible para hacer bollos
 maxBollos = cantidad de chorizo disponible de chorizo i / cantidad de chorizo i por bollo
 k = cantidad de bollos
 masaNecesariaTotal: masa total necesaria para hacer k bollos del chorizo i [k * masa posible para cada chorizo i]
 beneficio: beneficio por k bollos del chorizo i [k * precio de chorizo i]
 masaRestante: masa disponible después de utilizar la masa necesaria para producir una cierta cantidad k de bollos de un tipo de chorizo i [j - masaNecesariaTotal]

 RECURRENCIA:
 -------------
 maxBeneficio(i,j) = máx. bº que se puede conseguir usando j gramos de masa haciendo los bollos con el tipo de chorizo i

 maxBeneficio(i,j) = max 1 <= k <= maxBollos(maxBeneficio(i-1,j), maxBeneficio(i-1,masaRestante) + beneficio)


 CASOS BASE:
 ------------
 maxBeneficio(0,j) = 0 , cuando no consideramos ningún tipo de chorizo
 maxBeneficio(i,0) = 0 , cuando no tenemos masa disponible


 COSTE:
 -------
 El coste es O(N * masa * maxBollos), donde:
 - N: número de tipos de chorizos.
 - masa: masa máxima disponible.
 - maxBollos: cantidad máxima de bollos que se pueden hacer por cada tipo de chorizo.

 REDUCCIÓN DE ESPACIO:
 ---------------------
 Es posible reducir el espacio necesario para almacenar la solución a un vector de tamaño masa, que se va rellenando
 de derecha a izquierda.
 ---------------------------
 | Fila i - j | j | Fila i |
 ---------------------------

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct Chorizo {
    int grTotales, grPorChorizo, masaPorChorizo, precio;
};

int prDinamica(vector<Chorizo> const& chorizos, int const& masa, int const& N) {
    vector<int> sol(masa + 1, 0);

    for (int i = 0; i < N; i++){
        Chorizo chorizo = chorizos[i];

        for (int j = masa; j >= chorizo.masaPorChorizo; j--) {
            int maxBollos = chorizo.grTotales / chorizo.grPorChorizo;

            for (int k = 1; k <= maxBollos; k++) {
                int masaNecesariaTotal = k * chorizo.masaPorChorizo;
                int beneficio = k * chorizo.precio;
                int masaRestante = j - masaNecesariaTotal;

                if (masaNecesariaTotal <= j) {
                    sol[j] = max(sol[j], sol[masaRestante] + beneficio);
                }
                else {
                    break;
                }
            }
        }
    }

    return sol[masa];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, masa; cin >> N >> masa;
    if (!std::cin)  // fin de la entrada
        return false;

    int grTotales, grPorChorizo, masaPorChorizo, precio;
    vector<Chorizo> chorizos;
    for (int i = 0; i < N; i++){
        cin >> grTotales >> grPorChorizo >> masaPorChorizo >> precio;
        chorizos.push_back({ grTotales, grPorChorizo, masaPorChorizo, precio });
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    cout << prDinamica(chorizos, masa, N) << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casosR3.txt");
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