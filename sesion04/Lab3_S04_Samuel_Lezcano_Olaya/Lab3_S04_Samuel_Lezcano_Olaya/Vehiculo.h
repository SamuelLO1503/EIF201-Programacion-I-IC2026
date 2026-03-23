#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>

namespace UNA {

	class Vehiculo {
	private:
		std::string placa;
		std::string marca;
		int anio;
		double kilometraje;
		bool activo;

	public:
		//Construtor
		Vehiculo(std::string placa, std::string marca, int anio, double kilometraje);

		//Getters
		std::string getPlaca() const;
		std::string getMarca() const;
		int getAnio() const;
		double getKilometraje() const;
		bool getActivo() const;

		//Metodos
		void registrarKilometros(double km);
		void desactivar();
		void reactivar();
		void mostrar() const;

	};

}
#endif // !VEHICULO_H