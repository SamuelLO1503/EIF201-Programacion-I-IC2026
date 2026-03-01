#include "matriz.h"
#include <iomanip> //para stew()

//Leer matriz
void leerMatriz(int matriz[FILAS][COLS]) {
	cout << "Ingrese los " << FILAS * COLS << " valores de lamatriz 3x3:" << endl;
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLS; j++) {
			cin >> matriz[i][j];
		}
	}
	cout << endl;
}

//Imprimir matriz con formato
void imprimirMatriz(int matriz[FILAS][COLS]) {
	cout << "Matriz ingresada:" << endl;
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << setw(5) << matriz[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//Suma de una fila
int sumaFila(int matriz[FILAS][COLS], int fila) {
	int suma = 0;
	for (int j = 0; j < COLS; j++) {
		suma += matriz[fila][j];
	}
	return suma;
}

//Suma de una columna
int sumaColumna(int matriz[FILAS][COLS], int col) {
	int suma = 0;
	for (int i = 0; i < FILAS; i++) {
		suma += matriz[i][col];
	}
	return suma;
}
//Suma de la diagonal principal
int sumaDiagonal(int matriz[FILAS][COLS]) {
	int suma = 0;
	for (int i = 0; i < FILAS; i++) {
		suma += matriz[i][i];
	}
	return suma;
}