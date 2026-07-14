#ifndef LISTA_REPRODUCCION_HPP
#define LISTA_REPRODUCCION_HPP

#include "Audio.hpp"

struct NodoAudio {
    Audio* pista;
    NodoAudio* siguiente;
    NodoAudio* anterior;

    explicit NodoAudio(Audio* nuevaPista)
        : pista(nuevaPista),
          siguiente(nullptr),
          anterior(nullptr)
    {
    }
};

class ListaReproduccion {
private:
    NodoAudio* primero;
    NodoAudio* actual;
    int cantidad;

public:
    ListaReproduccion();
    ~ListaReproduccion();

    bool estaVacia() const;
    int getCantidad() const;

    void agregarFinal(Audio* nuevaPista);

    Audio* obtenerActual();
    Audio* avanzar();
    Audio* retroceder();

    void mostrar() const;
    void vaciar();
};

#endif