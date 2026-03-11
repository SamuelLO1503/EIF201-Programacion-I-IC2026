#include <iostream>
#include <iomanip>
#include "paquetes.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
	int cantidad = 0;
	double* registroPesos = crearRegistro(cantidad);

	ingresarPesos(registroPesos, cantidad);

	double total = calcularPesosTotal(registroPesos, cantidad);

	double promedio = total / cantidad;

	double limite;
	cout << "\nIngrese el limite de peso permitido: ";
	cin >> limite;

	int sobreLimite = contarSobreLimite(registroPesos, cantidad, limite);

	const double* masPesado = buscarMasPesado(registroPesos, cantidad);

	cout << std::fixed << std::setprecision(2);
	cout << "\n---RESUMEN DEL REGISTRO---\n";
	cout << "Cantidad de paquetes: " << cantidad << "\n";
	cout << "Peso total: " << total << " kg\n";
	cout << "Peso promedio: " << promedio << " kg\n";
	cout << "Paquetes sobre el limite (" << limite << " kg): " << sobreLimite << "\n";
	cout << "Paquete mas pesado: " << *masPesado << " kg\n";

	delete[] registroPesos;
	registroPesos = nullptr;

	return 0;
}