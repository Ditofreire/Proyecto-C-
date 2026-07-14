#include "ListaReproduccion.hpp"

ListaReproduccion::ListaReproduccion()
    : primero(nullptr),
      actual(nullptr),
      cantidad(0)
{
}

bool ListaReproduccion::estaVacia() const
{
    return primero == nullptr;
}

int ListaReproduccion::getCantidad() const
{
    return cantidad;
}
void ListaReproduccion::agregarFinal(Audio* nuevaPista)
{
    NodoAudio* nuevoNodo = new NodoAudio(nuevaPista);

    if (estaVacia()) {
        primero = nuevoNodo;
        actual = nuevoNodo;

        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
    }
    else {
        NodoAudio* ultimo = primero->anterior;

        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;

        nuevoNodo->siguiente = primero;
        primero->anterior = nuevoNodo;
    }

    cantidad++;
}
Audio* ListaReproduccion::obtenerActual()
{
    if (actual == nullptr) {
        return nullptr;
    }

    return actual->pista;
}
Audio* ListaReproduccion::avanzar()
{
    if (actual == nullptr) {
        return nullptr;
    }

    actual = actual->siguiente;

    return actual->pista;
}
Audio* ListaReproduccion::retroceder()
{
    if (actual == nullptr) {
        return nullptr;
    }

    actual = actual->anterior;

    return actual->pista;
}
NodoAudio* ListaReproduccion::getPrimero() const
{
    return primero;
}
void ListaReproduccion::mostrar() const
{
    if (primero == nullptr) {
        std::cout << "La lista esta vacia.\n";
        return;
    }

    NodoAudio* auxiliar = primero;

    do {
        std::cout << auxiliar->pista->obtenerInfo() << '\n';
        auxiliar = auxiliar->siguiente;
    }
    while (auxiliar != primero);
}
void ListaReproduccion::vaciar()
{
    if (primero == nullptr) {
        return;
    }

    NodoAudio* auxiliar = primero->siguiente;

    while (auxiliar != primero) {
        NodoAudio* siguiente = auxiliar->siguiente;

        delete auxiliar->pista;
        delete auxiliar;

        auxiliar = siguiente;
    }

    delete primero->pista;
    delete primero;

    primero = nullptr;
    actual = nullptr;
    cantidad = 0;
}
ListaReproduccion::~ListaReproduccion()
{
    vaciar();
}