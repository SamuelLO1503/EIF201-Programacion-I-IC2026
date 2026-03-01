#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
using namespace std;

const int FILAS = 3;
const int COLS = 3;

void leerMatriz(int matriz[FILAS][COLS]);
void imprimirMatriz(int matriz[FILAS][COLS]);
int sumaFila(int matriz[FILAS][COLS], int fila);
int sumaColumna(int matriz[FILAS][COLS], int col);
int sumaDiagonal(int matriz[FILAS][COLS]);

#endif