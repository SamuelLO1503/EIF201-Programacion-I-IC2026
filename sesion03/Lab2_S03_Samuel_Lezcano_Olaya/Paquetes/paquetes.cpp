#include "paquetes.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;


double* crearRegistro(int& cantidad) {
	cout << "Ingrese la cantidad de paquetes: ";
	cin >> cantidad;
	while (cantidad <= 0) {
		cout << "Error debe ser mayor a cero, intentelo de nuevo: ";
	}
	double* pesos = new double[cantidad];
	return pesos;
}

void ingresarPesos(double* pesos, int cantidad) {
	cout << "\nIngrese el peso de cada paquete en kg:\n";
	for (int i = 0; i < cantidad; i++) {
		cin >> pesos[i];
		while (pesos[i] <= 0) {
			cout << "Error el peso debe ser mayor a 0, intentelo de nuevo:";
			cin >> pesos[i];
		}
	}
}

double calcularPesosTotal(const double* pesos, int cantidad) {
	double suma = 0.0;
	for (int i = 0; i < cantidad; i++) {
		suma += pesos[i];
	}
	return suma;
}

int contarSobreLimite(const double* pesos, int cantidad, double limite) {
	int contador = 0;
	for (int i = 0; i < cantidad; i++) {
		if (pesos[i] > limite) {
			contador++;
		}
	}
	return contador;
}

const double* buscarMasPesado(const double* pesos, int cantidad) {
	const double* mayor = &pesos[0];
	for (int i = 0; i < cantidad; i++) {
		if (pesos[i] > *mayor) {
			mayor = &pesos[i];
		}
	}
	return mayor;
}