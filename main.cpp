#include <iostream>
#include <string>
#include "GestorEstudiantes.h"
using namespace std;

int main() {
    GestorEstudiantes gestor("estudiantes.txt");
    int opcion;

    do {
        cout << "\n1. Registrar estudiante\n"
             << "2. Mostrar (adelante)\n"
             << "3. Mostrar (atras)\n"
             << "0. Salir\n"
             << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string cedula, nombres, apellidos;
            cout << "Cedula: ";    getline(cin, cedula);
            cout << "Nombres: ";   getline(cin, nombres);
            cout << "Apellidos: "; getline(cin, apellidos);
            gestor.registrar(cedula, nombres, apellidos);
        } else if (opcion == 2) {
            gestor.mostrarTodos();
        } else if (opcion == 3) {
            gestor.mostrarAlReves();
        }
    } while (opcion != 0);

    return 0;
}