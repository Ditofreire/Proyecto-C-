#include "ListaReproduccion.hpp"
#include "tiposAudio.hpp"

#include <iostream>

int main()
{
    ListaReproduccion lista;

    lista.agregarFinal(new CancionEstudio(
        1,
        "Cancion uno",
        180,
        "Album uno",
        "Productor uno",
        "audio/prueba.wav"
    ));

    lista.agregarFinal(new Podcast(
        2,
        "Podcast de prueba",
        600,
        "Invitado uno",
        "Programacion",
        "audio/podcast.wav"
    ));

    lista.agregarFinal(new Audiolibro(
        3,
        "Libro de prueba",
        1200,
        "Narrador uno",
        10,
        "audio/libro.wav"
    ));

    std::cout << "Lista completa:\n";
    lista.mostrar();

    std::cout << "\nPrueba circular hacia adelante:\n";

Audio* pista = lista.obtenerActual();

for (int i = 0; i < 3; i++) {
    std::cout << pista->obtenerInfo() << '\n';
    pista = lista.avanzar();
}

std::cout << "Despues del ultimo:\n";
std::cout << pista->obtenerInfo() << '\n';

std::cout << "\nPrueba circular hacia atras:\n";

pista = lista.retroceder();
std::cout << pista->obtenerInfo() << '\n';
    return 0;  
}