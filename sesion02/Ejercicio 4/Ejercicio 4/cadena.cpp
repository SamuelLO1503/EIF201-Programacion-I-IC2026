#include "cadena.h"
#include <iostream>
using namespace std;

//Primer nombre: hasta el primer espacio
string obtenerPrimerNombre(string nombreCompleto) {
	int pos = nombreCompleto.find(' ');
	return nombreCompleto.substr(0, pos);
}

//Primer apellido: entre el primer y el segundo espacio
string obtenerPrimerApellido(string nombreCompleto) {
	int pos1 = nombreCompleto.find(' ');
	int pos2 = nombreCompleto.find(' ', pos1 + 1);
	return nombreCompleto.substr(pos1 + 1, pos2 - pos1 - 1);
}

//Contar vocales
int contarVocales(string nombreCompleto) {
	int contador = 0;
	for (int i = 0; i < nombreCompleto.length(); i++) {
		char c = tolower(nombreCompleto[i]);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			contador++;
		}
	}
	return contador;
}

//Convertir a mayusculas
string convertirMayusculas(string nombreCompleto) {
	for (int i = 0; i < nombreCompleto.length(); i++) {
		nombreCompleto[i] = toupper(nombreCompleto[i]);
	}
	return nombreCompleto;
}