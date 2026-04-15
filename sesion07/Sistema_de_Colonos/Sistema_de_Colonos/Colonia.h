#ifndef COLONIA_H
#define COLONIA_H

#include <string>
#include <vector>
#include "Domo.h"
#include "Colono.h"

namespace Colonizacion {

class Colonia {
private:
	std::string nombre;
	std::string planeta;
	std::vector<Domo*> domos;

public:
	Colonia(const std::string& nombre, const std::string& planeta);

	~Colonia();

	void construirDomo(const std::string& tipo, double capacidadOxigeno, int maxOcupantes);
	void detruirDomo(int id);

	bool asignarColono(Colono* c);
	int evacuarDomo(int id);
	int rebalancear();

	Colono* buscarColono(int id) const;
	void tableroControl() const;
	std::vector<Domo*> alertaOxigeno(double umbral) const;
	void reporteProductividad() const;
	void estadisticasGlobales() const;
};

}

#endif // !COLONIA_H