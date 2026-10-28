#include "ListaDoble.h"
#include <iostream>
using namespace std;

ListaDoble::ListaDoble() : cabeza(nullptr), cola(nullptr), tamano(0) {}

// La lista es dueña de los nodos y de los estudiantes
ListaDoble::~ListaDoble() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* sig = actual->getSiguiente();
        delete actual->getDato();
        delete actual;
        actual = sig;
    }
}

bool ListaDoble::estaVacia() const { return cabeza == nullptr; }

int ListaDoble::getTamano() const { return tamano; }

void ListaDoble::insertarAlFinal(Estudiante* e) {
    Nodo* nuevo = new Nodo(e);
    if (estaVacia()) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola->setSiguiente(nuevo);
        nuevo->setAnterior(cola);
        cola = nuevo;
    }
    tamano++;
}

bool ListaDoble::existeCorreo(const string& correo) const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->getDato()->getCorreo() == correo) return true;
        actual = actual->getSiguiente();
    }
    return false;
}

void ListaDoble::mostrarAdelante() const {
    if (estaVacia()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        actual->getDato()->mostrar();
        cout << "-------------------------\n";
        actual = actual->getSiguiente();
    }
}

void ListaDoble::mostrarAtras() const {
    if (estaVacia()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }
    Nodo* actual = cola;
    while (actual != nullptr) {
        actual->getDato()->mostrar();
        cout << "-------------------------\n";
        actual = actual->getAnterior();
    }
}
