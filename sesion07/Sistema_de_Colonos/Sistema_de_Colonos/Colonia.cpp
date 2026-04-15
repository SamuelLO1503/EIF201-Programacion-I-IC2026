#include "Colonia.h"
#include <iostream>
#include <algorithm>

namespace Colonizacion {
	Colonia::Colonia(const std::string& nombre, const std::string& planeta)
		: nombre(nombre), planeta(planeta){}

	Colonia::~Colonia() {
		for (auto d : domos) {
			delete d;
		}
		domos.clear();
	}

	void Colonia::construirDomo(const std::string& tipo, double capacidadOxigeno, int maxOcupantes) {
		int nuevoId = domos.size() + 1;
		Domo* nuevo = new Domo(nuevoId, tipo, capacidadOxigeno, maxOcupantes);
		domos.push_back(nuevo);
	}

	void Colonia::detruirDomo(int id) {
		auto it = std::remove_if(domos.begin(), domos.end(),
			[id](Domo* d) {return d->getId() == id; });
		if (it != domos.end()) {
			delete* it;
			domos.erase(it, domos.end());
		}
	}

	bool Colonia::asignarColono(Colono* c) {
		for (auto d : domos) {
			if (d->admitirColono(c)) {
				return true;
			}
		}
		return false;
	}

	int Colonia::evacuarDomo(int id) {
		for (auto d : domos) {
			if (d->getId() == id) {
				auto evacuados = d->evacuar();
				return (int)evacuados.size();
			}
		}
		return 0;
	}

	int Colonia::rebalancear() {
		int movimientos = 0;
		for (auto d : domos) {
			if (d->estaSobrecargado()) {
				auto evacuados = d->evacuar();
				for (auto c : evacuados) {
					if (asignarColono(c)) {
						movimientos++;
					}
				}
			}
		}
		return movimientos;
	}

	Colono* Colonia::buscarColono(int id) const {
		for (auto d : domos) {
			for (auto c : d->evacuar()) {
				if (c->getId() == id) {
					return c;
				}
			}
		}
		return nullptr;
	}

	void Colonia::tableroControl() const {
		std::cout << "=== Tablero de Conttrol de la Colonia ===" << std::endl;
		std::cout << "Colonia: " << nombre << " en planeta " << planeta << std::endl;
		for (auto d : domos) {
			d->imprimirInfo();
		}
	}

	std::vector<Domo*> Colonia::alertaOxigeno(double umbral) const {
		std::vector<Domo*> alerta;
		for (auto d : domos) {
			if (d->calcularRatioOxigeno() > umbral) {
				alerta.push_back(d);
			}
		}
		return alerta;
	}

	void Colonia::reporteProductividad() const {
		int total = 0;
		for (auto d : domos) {
			std::cout << "Domo " << d->getId() << " (" << d->getTipo() << "):" << std::endl;
		}
		std::cout << "Productividad total: " << total << std::endl;
	}

	void Colonia::estadisticasGlobales() const {
		int totalColonos = 0;
		for (auto d : domos) {
			totalColonos += d->estaSobrecargado() ? d->getMaxOcupantes() : 0;
		}
		std::cout << "Numeros de domos: " << domos.size() << std::endl;
		std::cout << "Colonos estimados: " << totalColonos << std::endl;
	}
}