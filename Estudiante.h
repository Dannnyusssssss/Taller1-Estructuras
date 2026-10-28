#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
private:
    std::string cedula;
    std::string nombres;
    std::string apellidos;
    std::string correo;

public:
    Estudiante();
    Estudiante(const std::string& cedula, const std::string& nombres,
               const std::string& apellidos, const std::string& correo = "");

    const std::string& getCedula() const;
    const std::string& getNombres() const;
    const std::string& getApellidos() const;
    const std::string& getCorreo() const;

    void setCedula(const std::string& c);
    void setNombres(const std::string& n);
    void setApellidos(const std::string& a);
    void setCorreo(const std::string& c);

    std::string getPrimerNombre() const;
    std::string getSegundoNombre() const;
    std::string getPrimerApellido() const;

    void mostrar() const;
};

#endif