#include "Flota.h"
#include <iostream>
#include <limits>

using namespace UNA;

//Mostrar el menu
int mostrarMenu() {
    std::cout << "\n--- Menu ---\n"
              << "1. Registrar vehiculo\n"
              << "2. Buscar vehiculo por placa\n"
              << "3. Mostrar vehiculos por marca\n"
              << "4. Registrar kilometros\n"
              << "5. Desactivar vehiculo\n"
              << "6. Reactivar vehiculo\n"
              << "7. Eliminar vehiculo\n"
              << "8. Mostrar flota completa\n"
              << "9. Mostrar cantidad de vehiculo activos\n"
              << "10. Salir\n"
              << "Opcion: ";
    int opcion;
    std::cin >> opcion;
    std::cout << std::endl;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    return opcion;
}

void registrarVehiculo(Flota& flota){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string placa, marca;
    int anio;
    double km;
    std::cout << "Placa: "; std::getline(std::cin, placa);
    std::cout << "Marca: "; std::getline(std::cin, marca);
    std::cout << "Ano: "; std::cin >> anio;
    std::cout << "Kilometraje: "; std::cin >> km;
    flota.agregar(new Vehiculo(placa, marca, anio, km));
    std::cout << std::endl;
}

void buscarVehiculo(Flota& flota) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string placa;
    std::cout << "Buscar a placa: "; std::getline(std::cin, placa);
    std::cout << std::endl;
    Vehiculo* v = flota.buscarPorPlaca(placa);
    if (v)v->mostrar();
    else std::cout << "Vehiculo no encontrado.\n";
}

void mostarPorMarca(Flota& flota) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string marca;
    std::cout << "Marca a mostrar: "; std::getline(std::cin, marca);
    std::cout << std::endl;
    flota.mostrarPorMarcar(marca);
}

void registrarKilometros(Flota& flota) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string placa;
    double km;
    std::cout << "Placa: "; std::getline(std::cin, placa);
    std::cout << "Kilometros a registrar: "; std::cin >> km;
    std::cout << std::endl;
    Vehiculo* v = flota.buscarPorPlaca(placa);
    if (v)v->registrarKilometros(km);
    else std::cout << "Vehiculo no encontrado.\n";
    std::cout << std::endl;
}

void desactivarVehiculo(Flota& flota) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string placa;
    std::cout << "Placa: "; std::getline(std::cin, placa);
    std::cout << std::endl;
    Vehiculo* v = flota.buscarPorPlaca(placa);
    if (v)v->desactivar();
    else std::cout << "Vehiculo no encontrado.\n";
    std::cout << std::endl;
}

void reactivarVehiculo(Flota& flota) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string placa;
    std::cout << "Placa: "; std::getline(std::cin, placa);
    std::cout << std::endl;
    Vehiculo* v = flota.buscarPorPlaca(placa);
    if (v)v->reactivar();
    else std::cout << "Vehiculo no encontrado.\n";
    std::cout << std::endl;
}

void eliminarVehiculo(Flota& flota) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string placa;
    std::cout << "Placa: "; std::getline(std::cin, placa);
    std::cout << std::endl;
    flota.eliminar(placa);
}

void mostrarFlota(Flota& flota) {
    flota.mostrarTodos();
}

void mostarActivos(Flota& flota) {
    std::cout << "Cantidad de vehiculo activos: " << flota.contarActivos() << "\n";
    std::cout << std::endl;
}

int main(){
    Flota flota;
    bool ejecuntando = true;

    while (ejecuntando) {
        int opcion = mostrarMenu();
        switch (opcion) {
        case 1: registrarVehiculo(flota); break;
        case 2: buscarVehiculo(flota); break;
        case 3: mostarPorMarca(flota); break;
        case 4: registrarKilometros(flota); break;
        case 5: desactivarVehiculo(flota); break;
        case 6: reactivarVehiculo(flota); break;
        case 7: eliminarVehiculo(flota); break;
        case 8: mostrarFlota(flota); break;
        case 9: mostarActivos(flota); break;
        case 10: ejecuntando = false; std::cout << "Saliendo...\n"; std::cout << std::endl; break;
        default:std::cout << "Opcion invalida.\n"; std::cout << std::endl; break;
        }
    }
}