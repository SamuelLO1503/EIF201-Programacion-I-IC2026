#include <iostream>
#include "Estadisticas.h"

using namespace std;

int main(){
    int numeros[TAM];

    //Pide el numero al usuario
    cout << "Ingrese " << TAM << " numeros enteros:" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << "Numero " << (i + 1) << ": ";
        cin >> numeros[i];
    }

    //Muestra todos los resultados
    cout << "\nResultados:" << endl;
    cout << "Mayor: " << obtenerMayor(numeros, TAM) << endl;
    cout << "Menor: " << obtenerMenor(numeros, TAM) << endl;
    cout << "Suma: " << calcularSuma(numeros, TAM) << endl;
    cout << "Promedio: " << calcularPromedio(numeros, TAM) << endl;
    
    return 0;
}