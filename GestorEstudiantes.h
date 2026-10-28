#ifndef GESTORESTUDIANTES_H
#define GESTORESTUDIANTES_H

#include <string>
#include "ListaDoble.h"
#include "Estudiante.h"

class GestorEstudiantes {
private:
    ListaDoble lista;
    std::string nombreArchivo;
    static const std::string DOMINIO;

    static std::string aMinusculas(std::string s);
    static std::string valor(const std::string& linea);

    std::string generarUsuarioBase(const Estudiante& e) const;
    std::string generarCorreoUnico(const Estudiante& e) const;
    void guardarEnArchivo(const Estudiante& e) const;

public:
    GestorEstudiantes(const std::string& archivo);

    void cargarDesdeArchivo();
    void registrar(const std::string& cedula, const std::string& nombres,
                   const std::string& apellidos);
    void mostrarTodos() const;
    void mostrarAlReves() const;
};

#endif