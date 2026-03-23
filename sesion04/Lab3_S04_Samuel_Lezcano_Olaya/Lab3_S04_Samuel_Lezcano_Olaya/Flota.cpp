#include "Flota.h"
#include <iostream>

namespace UNA {

	Flota::Flota(int capacidadInicial) :cantidad(0), capacidad(capacidadInicial) {
		vehiculos = new Vehiculo * [capacidad];
		for (int i = 0; i < capacidad; i++) vehiculos[i] = nullptr;
	}

	Flota::~Flota() {
		for (int i = 0; i < cantidad; i++) {
			delete vehiculos[i];
		}
		delete[] vehiculos;
		std::cout << "Flota destruida.\n";
		std::cout << std::endl;
	}

	void Flota::redimencionar() {
		int nuevaCapacidad = capacidad * 2;
		Vehiculo** nuevoArr = new Vehiculo * [nuevaCapacidad];
		for (int i = 0; i < cantidad; i++) nuevoArr[i] = vehiculos[i];
		for (int i = cantidad; i < nuevaCapacidad; i++) nuevoArr[i] = nullptr;
		delete[] vehiculos;
		vehiculos = nuevoArr;
		capacidad = nuevaCapacidad;
	}

	void Flota::agregar(Vehiculo* nuevo) {
		if (cantidad == capacidad) redimencionar();
		vehiculos[cantidad++] = nuevo;
	}

	Vehiculo* Flota::buscarPorPlaca(std::string placa) const {
		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getPlaca() == placa) return vehiculos[i];
		}
		return nullptr;
	}

	void Flota::mostrarPorMarcar(std::string marca) const {
		int encontrados = 0;
		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getMarca() == marca) {
				vehiculos[i]->mostrar();
				encontrados++;
			}
		}
		if (encontrados == 0) {
			std::cout << "No hay vehiculos de la marca " << marca << ".\n";
		}else {
			std::cout << "Total encontrados: " << encontrados << ".\n";
			std::cout << std::endl;
		}
	}

	bool Flota::eliminar(std::string placa) {
		int pos = -1;
		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getPlaca() == placa) {
				pos = i;
				break;
			}
		}
		if (pos == -1) {
			std::cout << "Vehiculo no encontrado.\n";
			return false;
		}
		if (vehiculos[pos]->getActivo()) {
			std::cout << "Debe desactivar el vehiculo antes de eliminarlo.\n";
			return false;
		}
		delete vehiculos[pos];
		for (int i = pos; i < cantidad - 1; i++) {
			vehiculos[i] = vehiculos[i + 1];
		}
		vehiculos[--cantidad] = nullptr;
		std::cout << "Vehiculo eliminado.\n";
		return true;
		std::cout << std::endl;
	}

	int Flota::contarActivos() const {
		int activos = 0;
		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getActivo()) activos++;
		}
		return activos;
	}

	void Flota::mostrarTodos() const {
		if (cantidad == 0) {
			std::cout << "La flota esta vacia.\n";
			return;
		}
		for (int i = 0; i < cantidad; i++) {
			vehiculos[i]->mostrar();
		}
	}

}