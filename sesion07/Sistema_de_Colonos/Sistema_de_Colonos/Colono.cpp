#include "Colono.h"
#include <iostream>

namespace Colonizacion {

	Colono::Colono(int id, const std::string& nombre, const std::string& especialidad,
		double consumoOxigeno, int productividad)
		: id(id), nombre(nombre), especialidad(especialidad),
		consumoOxigeno(consumoOxigeno), productividad(productividad) {
	}

	int Colono::getId() const {
		return id;
	}

	std::string Colono::getNombre() const {
		return nombre;
	}

	std::string Colono::getEspecialidad() const {
		return especialidad;
	}

	double Colono::getConsumoOxigeno() const {
		return consumoOxigeno;
	}

	int Colono::getProductividad() const {
		return productividad;
	}

	void Colono::imprimirInfo() const {
		std::cout << "Colono [ID: " << id
				  << ", Nombre: " << nombre
				  << ", Especialidad: " << especialidad
				  << ", Consumo 02: " << consumoOxigeno << " L/h"
				  << ", Productividad: " << productividad << "]"
				  << std::endl;
	}

}