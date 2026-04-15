#include "Domo.h"
#include <iostream>

namespace Colonizacion {

	Domo::Domo(int id,const std::string& tipo, double capacidadOxigeno, int maxOcupantes)
		: id(id), tipo(tipo), capacidadOxigeno(capacidadOxigeno),
		  maxOcupantes(maxOcupantes), sellado(true) {}


	int Domo::getId() const {
		return id;
	}

	std::string Domo::getTipo() const {
		return tipo;
	}

	double Domo::getCapacidadOxigeno() const {
		return capacidadOxigeno;
	}

	int Domo::getMaxOcupantes() const {
		return maxOcupantes;
	}

	bool Domo::estaSellado() const {
		return sellado;
	}

	bool Domo::admitirColono(Colono* c) {
		if (!sellado) return false;
		if ((int)colonos.size() >= maxOcupantes) return false;
		colonos.push_back(c);
		return true;
	}

	bool Domo::retirarColono(int idColono) {
		for (auto it = colonos.begin(); it != colonos.end(); ++it) {
			if ((*it)->getId() == idColono) {
				colonos.erase(it);
				return true;
			}
		}
		return false;
	}

	std::vector<Colono*> Domo::evacuar() {
		sellado = false;
		std::vector<Colono*> evacuados = colonos;
		colonos.clear();
		return evacuados;
	}

	double Domo::calcularRatioOxigeno() const {
		double consumoTotal = 0.0;
		for (auto c : colonos) {
			consumoTotal += c->getConsumoOxigeno();
		}
		return consumoTotal / capacidadOxigeno;
	}

	bool Domo::estaSobrecargado() const {
		return (int)colonos.size() > maxOcupantes || calcularRatioOxigeno() > 1.0;
	}

	void Domo::imprimirInfo() const {
		std::cout << "Domo [ID: " << id
				  << ", Tipo: " << tipo
				  << ", Capacidad 02: " << capacidadOxigeno
				  << ", Max Ocupantes: " << maxOcupantes
				  << ", Colonos Actuales: " << colonos.size()
				  << ", Sellado: " << (sellado ? "Si" : "No") << "]"
				  << std::endl;
	}

}