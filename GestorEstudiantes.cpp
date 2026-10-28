#include "GestorEstudiantes.h"
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

const string GestorEstudiantes::DOMINIO = "@espe.edu.ec";

string GestorEstudiantes::aMinusculas(string s) {
    for (size_t i = 0; i < s.size(); i++)
        s[i] = (char)tolower((unsigned char)s[i]);
    return s;
}

// Devuelve lo que hay despues de "Etiqueta: "
string GestorEstudiantes::valor(const string& linea) {
    size_t pos = linea.find(':');
    if (pos == string::npos) return "";
    size_t ini = linea.find_first_not_of(' ', pos + 1);
    if (ini == string::npos) return "";
    return linea.substr(ini);
}

// jcteran, e_teran (sin el dominio)
string GestorEstudiantes::generarUsuarioBase(const Estudiante& e) const {
    string base;
    base += e.getPrimerNombre()[0];
    string segundo = e.getSegundoNombre();
    base += segundo.empty() ? '_' : segundo[0];
    base += e.getPrimerApellido();
    return aMinusculas(base);
}

// Agrega 1, 2, 3... mientras el correo ya exista
string GestorEstudiantes::generarCorreoUnico(const Estudiante& e) const {
    string base = generarUsuarioBase(e);
    string correo = base + DOMINIO;
    int n = 0;
    while (lista.existeCorreo(correo)) {
        n++;
        correo = base + to_string(n) + DOMINIO;
    }
    return correo;
}

void GestorEstudiantes::guardarEnArchivo(const Estudiante& e) const {
    ofstream out(nombreArchivo.c_str(), ios::app);
    if (!out) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    out << "Cedula: " << e.getCedula() << "\n";
    out << "Nombres: " << e.getNombres() << "\n";
    out << "Apellidos: " << e.getApellidos() << "\n";
    out << "Correo: " << e.getCorreo() << "\n";
    out << "\n";
}

GestorEstudiantes::GestorEstudiantes(const string& archivo) : nombreArchivo(archivo) {
    cargarDesdeArchivo();
}

void GestorEstudiantes::cargarDesdeArchivo() {
    ifstream in(nombreArchivo.c_str());
    if (!in) return;                       // aun no existe, no pasa nada

    string linea, ced, nom, ape, cor;
    while (getline(in, linea)) {
        if (linea.rfind("Cedula", 0) == 0) ced = valor(linea);
        else if (linea.rfind("Nombres", 0) == 0) nom = valor(linea);
        else if (linea.rfind("Apellidos", 0) == 0) ape = valor(linea);
        else if (linea.rfind("Correo", 0) == 0) {
            cor = valor(linea);
            lista.insertarAlFinal(new Estudiante(ced, nom, ape, cor));
        }
    }
}

void GestorEstudiantes::registrar(const string& cedula, const string& nombres,
                                  const string& apellidos) {
    if (nombres.find_first_not_of(' ') == string::npos ||
        apellidos.find_first_not_of(' ') == string::npos) {
        cout << "Nombres y apellidos no pueden estar vacios.\n";
        return;
    }
    Estudiante* nuevo = new Estudiante(cedula, nombres, apellidos);
    nuevo->setCorreo(generarCorreoUnico(*nuevo));
    lista.insertarAlFinal(nuevo);
    guardarEnArchivo(*nuevo);
    cout << "Registrado. Correo asignado: " << nuevo->getCorreo() << endl;
}

void GestorEstudiantes::mostrarTodos() const { lista.mostrarAdelante(); }

void GestorEstudiantes::mostrarAlReves() const { lista.mostrarAtras(); }
