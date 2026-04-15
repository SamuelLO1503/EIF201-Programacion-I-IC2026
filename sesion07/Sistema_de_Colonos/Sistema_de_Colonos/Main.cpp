#include "Colonia.h"
#include "Domo.h"
#include "Colono.h"
#include <iostream>

using namespace Colonizacion;

int main() {
	//Crear una colonia
	Colonia colonia("Nueva Esperanza", "Marte");

	//Algunos domos
	colonia.construirDomo("Agricola", 500.0, 3);
	colonia.construirDomo("Residencial", 300.0, 2);

	//Crear colonos
	Colono* c1 = new Colono(1, "Alice", "Ingeniera", 50.0, 80);
	Colono* c2 = new Colono(2, "Bob", "Medico", 40.0, 70);
	Colono* c3 = new Colono(3, "Charline", "Biologo", 60.0, 90);

	//Asignar colonos a colonias
	colonia.asignarColono(c1);
	colonia.asignarColono(c2);
	colonia.asignarColono(c3);

	//Mostrar tablero de control
	colonia.tableroControl();

	//Alerta de oxigeno
	auto alertas = colonia.alertaOxigeno(0.8);
	if (!alertas.empty()) {
		std::cout << "ALERTA! Domos con oxigeno critico:" << std::endl;
		for (auto d : alertas) {
			d->imprimirInfo();
		}
	}

	//Reporte de productividad
	colonia.reporteProductividad();

	//Estadisticas globales
	colonia.estadisticasGlobales();

	//Evacuar un domo
	int evacuados = colonia.evacuarDomo(1);
	std::cout << "Evacuados del domo 1: " << evacuados << std::endl;

	//Rebalancear colonos
	int movimientos = colonia.rebalancear();
	std::cout << "Colonos reubicados: " << movimientos << std::endl;
 
	return 0;
}