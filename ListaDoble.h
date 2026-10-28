#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <string>
#include "Nodo.h"
#include "Estudiante.h"

class ListaDoble {
private:
    Nodo* cabeza;
    Nodo* cola;
    int tamano;

public:
    ListaDoble();
    ~ListaDoble();

    // Evita copias accidentales (doble delete)
    ListaDoble(const ListaDoble&) = delete;
    ListaDoble& operator=(const ListaDoble&) = delete;

    bool estaVacia() const;
    int getTamano() const;

    void insertarAlFinal(Estudiante* e);
    bool existeCorreo(const std::string& correo) const;
    void mostrarAdelante() const;
    void mostrarAtras() const;
};

#endif