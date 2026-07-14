#include "ListaReproduccion.hpp"
#include "MotorAudio.hpp"
#include "tiposAudio.hpp"
#include "GestorXML.hpp"
#include <iostream>

int main()
{
    ListaReproduccion lista;
    MotorAudio motor;
    GestorXML gestor;
    // Agregar pistas
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

    // Mostrar lista completa
    std::cout << "Lista completa:\n";
    lista.mostrar();

    // Obtener primera pista
    Audio* pista = lista.obtenerActual();

    // Reproducir pista actual
    if (pista != nullptr) {
        if (motor.abrir(pista->getRutaArchivo())) {
            std::cout << "\nReproduciendo: "
                      << pista->getTitulo() << '\n';

            motor.reproducir();
            pista->registrarReproduccion();

            std::cout << "Presiona Enter para detener...\n";
            std::cin.get();

            motor.detener();
            motor.cerrar();
        }
        else {
            std::cout << "No se pudo abrir la primera pista.\n";
        }
    }

    // Avanzar a la siguiente pista
    pista = lista.avanzar();

    // Reproducir siguiente pista
    if (pista != nullptr) {
        if (motor.abrir(pista->getRutaArchivo())) {
            std::cout << "\nReproduciendo siguiente: "
                      << pista->getTitulo() << '\n';

            motor.reproducir();
            pista->registrarReproduccion();
   
            std::cout << "Presiona Enter para detener...\n";
            std::cin.get();

            motor.detener();
            motor.cerrar();
        }
        else {
            std::cout << "No se pudo abrir la siguiente pista.\n";
        }
    }

    // Mostrar reproducciones actualizadas
    std::cout << "\nLista actualizada:\n";
    lista.mostrar();

    // Prueba circular hacia adelante
    std::cout << "\nPrueba circular hacia adelante:\n";

    pista = lista.obtenerActual();

    for (int i = 0; i < 3; i++) {
        std::cout << pista->obtenerInfo() << '\n';
        pista = lista.avanzar();
    }

    std::cout << "Despues del ultimo:\n";
    std::cout << pista->obtenerInfo() << '\n';

    // Prueba circular hacia atrás
    std::cout << "\nPrueba circular hacia atras:\n";

    pista = lista.retroceder();
    std::cout << pista->obtenerInfo() << '\n';

    std::cout << "\nLista actualizada:\n";
   lista.mostrar();

if (gestor.guardar(lista, "biblioteca.xml")) {
    std::cout << "Biblioteca guardada correctamente.\n";
}
else {
    std::cout << "Error al guardar la biblioteca.\n";
}
ListaReproduccion listaCargada;

if (gestor.cargar(listaCargada, "biblioteca.xml")) {
    std::cout << "\nBiblioteca cargada desde XML:\n";
    listaCargada.mostrar();
}
else {
    std::cout << "Error al cargar el XML.\n";
}
    return 0;
}

