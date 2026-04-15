#ifndef DOMO_H
#define DOMO_H

#include<string>
#include<vector>
#include "Colono.h"

namespace Colonizacion {

class Domo {
private:
	int id;
	std::string tipo;
	double capacidadOxigeno;
	int maxOcupantes;
	std::vector<Colono*> colonos;
	bool sellado;
public:
    //Construtor
	Domo(int id, const std::string& tipo, double capacidadOxigeno, int maxOcupantes);

	//Metodos
	int getId() const;
	std::string getTipo() const;
	double getCapacidadOxigeno() const;
	int getMaxOcupantes() const;
	bool estaSellado() const;

	bool admitirColono(Colono* c);
	bool retirarColono(int idColono);
	std::vector<Colono*> evacuar();

	double calcularRatioOxigeno() const;
	bool estaSobrecargado() const;

	void imprimirInfo() const;
};

}

#endif // !DOMO_H