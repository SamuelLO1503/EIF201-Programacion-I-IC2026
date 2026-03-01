#include <iostream>
#include "arreglo.h"

using namespace std;

int main(){
	int n;

	cout << "Ingrese el tamano del arreglo (maximo 20): ";
	cin >> n;

	//Verificar el tamaño
	if (n <= 0 || n > 20) {
		cout << "Error: el tamano debe estar entre 1 y 20." << endl;
		return 1;
	}
	int original[20];
	int invertido[20];

	//Ingreso de datos
	cout << "Ingrese los " << n << " elementos del arreglos:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> original[i];
	}
	cout << endl;

	//Invertir arreglo
	invertirArreglo(original, invertido, n);

	//Mostrar resultados
	cout << "Arreglo original: ";
	imprimirArreglo(original, n);

	cout<<"Arreglo invertido: ";
	imprimirArreglo(invertido, n);

	return 0;
}