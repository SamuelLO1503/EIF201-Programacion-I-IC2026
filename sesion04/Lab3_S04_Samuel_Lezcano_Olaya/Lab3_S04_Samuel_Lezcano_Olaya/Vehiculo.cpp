#include "Vehiculo.h"

namespace UNA {

	Vehiculo::Vehiculo(std::string placa, std::string marca, int anio, double kilometraje)
		:placa(placa), marca(marca), anio(anio), kilometraje(kilometraje), activo(true){ }

	std::string Vehiculo::getPlaca() const { return placa; }
	std::string Vehiculo::getMarca() const { return marca; }
	int Vehiculo::getAnio() const { return anio; }
	double Vehiculo::getKilometraje() const { return kilometraje; }
	bool Vehiculo::getActivo() const { return activo; }

	void Vehiculo::registrarKilometros(double km) {
		if (!activo) {
			std::cout << "Error: el vehiculo esta fuera de servicio.\n";
			return;
		}
		if (km <= 0) {
			std::cout << "Error: los kilometros deben ser positivos.\n";
			return;
		}
		kilometraje += km;
	}

	void Vehiculo::desactivar() {
		if (!activo) {
			std::cout << "El vehiculo ya esta fuera de servicio.\n";
		}else {
			activo = false;
			std::cout << "Vehiculo desactivado.\n";
		}
	}

	void Vehiculo::reactivar() {
		if (activo) {
			std::cout << "El vehiculo ya esta activo.\n";
		}else {
			activo = true;
			std::cout << "Vehiculo reactivado.\n";
		}
	}

	void Vehiculo::mostrar() const {
		std::cout << "[ " << placa << " ] " << marca
		 	<< " | Ano: " << anio
			<< " | Km: " << kilometraje
			<< " | Estado: " << (activo ? "ACTIVO" : "FUERA DE SERVICIO")
			<< std::endl;
	}

}