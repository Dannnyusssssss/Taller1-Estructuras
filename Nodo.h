#ifndef NODO_H
#define NODO_H

#include "Estudiante.h"

class Nodo {
private:
    Estudiante* dato;
    Nodo* siguiente;
    Nodo* anterior;

public:
    Nodo(Estudiante* e) : dato(e), siguiente(nullptr), anterior(nullptr) {}

    Estudiante* getDato() const { return dato; }
    Nodo* getSiguiente() const { return siguiente; }
    Nodo* getAnterior() const { return anterior; }

    void setSiguiente(Nodo* s) { siguiente = s; }
    void setAnterior(Nodo* a) { anterior = a; }
};

#endif