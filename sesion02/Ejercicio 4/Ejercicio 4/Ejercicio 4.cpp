#include <iostream>
#include "cadena.h"
using namespace std;

int main(){
	string nombreCompleto;

	cout << "Ingrese su nombre completo (PrimerNombre PrimerApellido SegundoApellido): ";
	getline(cin, nombreCompleto);
	cout << endl;

	cout << "Primer nombre: " << obtenerPrimerNombre(nombreCompleto) << endl;
	cout << "Primer apellido: " << obtenerPrimerApellido(nombreCompleto) << endl;
	cout << "Cantidad de vocales: " << contarVocales(nombreCompleto) << endl;
	cout << "Nombre completo en mayusculas: " << convertirMayusculas(nombreCompleto) << endl;
	cout << "Longitud total del nombre: " << nombreCompleto.length() << endl;

	return 0;

}