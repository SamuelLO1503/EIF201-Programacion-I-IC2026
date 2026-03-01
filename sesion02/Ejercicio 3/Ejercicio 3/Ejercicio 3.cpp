#include "matriz.h"

int main() {
	int matriz[FILAS][COLS];

	//Leer Matriz
	leerMatriz(matriz);

	//Imprimir Matriz
	imprimirMatriz(matriz);

	//Suma de filas
	for (int i = 0; i < FILAS; i++) {
		cout << "Suma de la fila " << i + 1 << ": " << sumaFila(matriz, i) << endl;
	}
	cout << endl;

	//Suma de columnas
	for (int j = 0; j < COLS; j++) {
		cout << "Suma de la columna " << j + 1 << ": " << sumaColumna(matriz, j) << endl;
	}
	cout << endl;

	//Suma de diagonal pricipal
	cout << "Suma de la diagonal principal: " << sumaDiagonal(matriz) << endl;
	
	return 0;
}