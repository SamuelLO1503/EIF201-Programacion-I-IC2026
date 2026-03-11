#ifndef PAQUETES_H
#define PAQUETES_H

//Solicita la cantidad de paquetes
double* crearRegistro(int& cantidad);

//Lee el peso en kg en cada paquete
void ingresarPesos(double* pesos, int cantidad);

//Calcula y retorna la suma de todos los pesos del arreglo
double calcularPesosTotal(const double* pesos, int cantidad);

//Cuenta y retorna cuantos paquetes tienen un peso mayor al limite
int contarSobreLimite(const double* pesos, int cantidad, double limite);

//Retorna un puntero al elemento con el mayor peso del arreglo
//Encaso de empate retorna el primero encontrado 
const double* buscarMasPesado(const double* pesos, int cantidad);

#endif // !PAQUETES_H