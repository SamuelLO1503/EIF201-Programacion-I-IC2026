#include <iostream>
#include "arreglo.h"

using namespace std;

//Funcion que invierte el arreglo
void invertirArreglo(const int original[], int invertido[], int n) {
	for (int i = 0; i < n; i++) {
		invertido[i] = original[n - 1 - i];
	}
}

//Funcion para imprimir un arreglo
void imprimirArreglo(const int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}