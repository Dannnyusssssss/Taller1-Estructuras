#include "Estudiante.h"
#include <iostream>
#include <sstream>
using namespace std;

Estudiante::Estudiante() {}

Estudiante::Estudiante(const string& cedula, const string& nombres,
                       const string& apellidos, const string& correo)
    : cedula(cedula), nombres(nombres), apellidos(apellidos), correo(correo) {}

const string& Estudiante::getCedula() const { return cedula; }
const string& Estudiante::getNombres() const { return nombres; }
const string& Estudiante::getApellidos() const { return apellidos; }
const string& Estudiante::getCorreo() const { return correo; }

void Estudiante::setCedula(const string& c) { cedula = c; }
void Estudiante::setNombres(const string& n) { nombres = n; }
void Estudiante::setApellidos(const string& a) { apellidos = a; }
void Estudiante::setCorreo(const string& c) { correo = c; }

string Estudiante::getPrimerNombre() const {
    istringstream ss(nombres);
    string p;
    ss >> p;
    return p;
}

string Estudiante::getSegundoNombre() const {
    istringstream ss(nombres);
    string primero, segundo;
    ss >> primero >> segundo;
    return segundo;               // "" si no tiene
}

string Estudiante::getPrimerApellido() const {
    istringstream ss(apellidos);
    string p;
    ss >> p;
    return p;
}

void Estudiante::mostrar() const {
    cout << "Cedula: " << cedula << endl;
    cout << "Nombres: " << nombres << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "Correo: " << correo << endl;
}
