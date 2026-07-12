#include "Audio.hpp"
#include <cctype>

Audio::Audio(int id, const std::string& titulo, int duracionSegundos, const std::string& rutaArchivo) : id(id), titulo(titulo), duracionSegundos(duracionSegundos), reproducciones(0), rutaArchivo(rutaArchivo) {};

Audio::~Audio() {}

int Audio::getId() const {
    return id;
}

std::string Audio::getTitulo() const {
    return titulo;
}

int Audio::getDuracionSeg() const {
    return duracionSegundos;
}

int Audio::getReproducciones() const {
    return reproducciones;
}

std::string Audio::getRutaArchivo() const {
    return rutaArchivo;
}

void Audio::setTitulo(const std::string& nuevoTitulo) {
    //rechaza cadena vacía o solo espacios
    bool soloEspacios = true;
    for (char c : nuevoTitulo) {
        if (c != ' ') { soloEspacios = false; break; }
    }
    if (nuevoTitulo.empty() || soloEspacios) {
        std::cout << "Titulo invalido: no puede estar vacio.\n";
        return;
    }
    titulo = nuevoTitulo;
}

void Audio::setDuracionSegundos(int segundos) {
    if (segundos <= 0) {
        std::cout << "Duracion invalida: debe ser mayor a 0.\n";
        return;
    }
    duracionSegundos = segundos;
}

void Audio::setRutaArchivo(const std::string& nuevaRuta) {
    std::string extensionEsperada = formatoEsperado(); 
}

void Audio::reproducirArchivo() const {}

std::ostream& operator<<(std::ostream& os, const Audio& a) {
    //como friend no es virtual, el operador llama a obtenerInfo que si es virtual para que si cambie dependiendo del obejto hijo
    os << a.obtenerInfo();
    return os;
}