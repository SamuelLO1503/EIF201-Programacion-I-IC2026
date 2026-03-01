#include "Estadisticas.h"

//Obtener el numero mayor
int obtenerMayor(const int arr[], int n) {
	int mayor = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > mayor) {
			mayor = arr[i];
		}
	}
	return mayor;
}

//obtener el numero menor
int obtenerMenor(const int arr[], int n) {
	int menor = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < menor) {
			menor = arr[i];
		}
	}
	return menor;
}

//Calcular la suma
int calcularSuma(const int arr[], int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma += arr[i];
	}
	return suma;
}
//Calcula el promedio
double calcularPromedio(const int arr[], int n) {
	int suma = calcularSuma(arr, n);
	return static_cast<double>(suma) / n;
}