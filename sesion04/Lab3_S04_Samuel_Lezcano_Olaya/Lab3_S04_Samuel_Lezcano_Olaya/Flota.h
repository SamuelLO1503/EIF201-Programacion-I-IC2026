#ifndef FLOTA_H
#define FLOTA_H

#include "Vehiculo.h"
#include <string>

namespace UNA {

	class Flota {
	private:
		Vehiculo** vehiculos; //arreglo dinamico
		int cantidad;
		int capacidad;

		void redimencionar();

	public:
		Flota(int capacidadInicial = 3);
		~Flota();

		void agregar(Vehiculo* nuevo);
		Vehiculo* buscarPorPlaca(std::string placa) const;
		void mostrarPorMarcar(std::string marca) const;
		bool eliminar(std::string placa);
		int contarActivos() const;
		void mostrarTodos() const;
	};

}
#endif // !FLOTA_H