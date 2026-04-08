#ifndef COLONO_H
#define COLONO_H

#include <string>

namespace Colonizacion {

class Colono {
private:
	int id;
	std::string nombre;
	std::string especialidad;
	double consumoOxigeno;
	int productividad;

public:
	//Constructor
	Colono(int id, const std::string& nombre, const std::string& especialidad,
		   double consumoOxigeno, int productividad);

	//Metodos
	int getId() const;
	std::string getNombre() const;
	std::string getEspecialidad() const;
	double getConsumoOxigeno() const;
	int getProductividad() const;

	void imprimirInfo() const;

};

}

#endif // !COLONO_H