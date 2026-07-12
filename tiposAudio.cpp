#include "TiposAudio.hpp"
#include <sstream>
#include <iostream>

//ANCION ESTUDIO

CancionEstudio::CancionEstudio(int id, const std::string& titulo, int duracionSegundos, const std::string& album, const std::string& productor, const std::string& rutaArchivo) : Audio(id, titulo, duracionSegundos, rutaArchivo), album(album), productor(productor) {}
 
CancionEstudio::~CancionEstudio() {}
 
std::string CancionEstudio::getAlbum() const { return album; }
std::string CancionEstudio::getProductor() const { return productor; }
 
void CancionEstudio::setAlbum(const std::string& nuevoAlbum) {
    if (nuevoAlbum.empty()) {
        std::cout << "Album invalido\n";
        return;
    }
    album = nuevoAlbum;
}
 
void CancionEstudio::setProductor(const std::string& nuevoProductor) {
    if (nuevoProductor.empty()) {
        std::cout << "Productor invalido\n";
        return;
    }
    productor = nuevoProductor;
}
 
void CancionEstudio::reproducir() {
    reproducciones++;
    reproducirArchivo();
}
 
std::string CancionEstudio::obtenerInfo() const {
    //ostringstream porque son tipos de datos diferentes y no los puedo hacer string
    std::ostringstream oss;
    oss << "[" << id << "] " << titulo << " - " << duracionSegundos << "s" << " | Cancion de Estudio | Album: " << album << " | Productor: " << productor << " | Reproducciones: " << reproducciones;
    return oss.str();
}
 
std::string CancionEstudio::tipo() const { return "CANCION_ESTUDIO"; }
 
std::string CancionEstudio::formatoEsperado() const { return ".mp3"; }
 
std::string CancionEstudio::serializar() const {
    std::ostringstream oss;
    oss << tipo() << "|" << id << "|" << titulo << "|" << duracionSegundos << "|" << album << "|" << productor << "|" << rutaArchivo;
    return oss.str();
}
 

//CANCION EN VIVO
CancionEnVivo::CancionEnVivo(int id, const std::string& titulo, int duracionSegundos, const std::string& lugar, const std::string& fecha, const std::string& rutaArchivo) : Audio(id, titulo, duracionSegundos, rutaArchivo), lugar(lugar), fecha(fecha) {}
 
CancionEnVivo::~CancionEnVivo() {}
 
std::string CancionEnVivo::getLugar() const { return lugar; }
std::string CancionEnVivo::getFecha() const { return fecha; }
 
void CancionEnVivo::setLugar(const std::string& nuevoLugar) {
    if (nuevoLugar.empty()) {
        std::cout << "Lugar invalido\n";
        return;
    }
    lugar = nuevoLugar;
}
 
void CancionEnVivo::setFecha(const std::string& nuevaFecha) {
    // Valida longitud 10 y guiones en posiciones 2 y 5
    if (nuevaFecha.size() != 10 || nuevaFecha[2] != '-' || nuevaFecha[5] != '-') {
        std::cout << "Fecha invalida: formato esperado DD-MM-AAAA.\n";
        return;
    }
    fecha = nuevaFecha;
}
 
void CancionEnVivo::reproducir() {
    reproducciones++;
    std::cout << "Reproduciendo cancion en vivo: \"" << titulo << "\" (Grabada en " << lugar << ", " << fecha << ")\n";
    reproducirArchivo();
}
 
std::string CancionEnVivo::obtenerInfo() const {
    std::ostringstream oss;
    oss << "[" << id << "] " << titulo << " - " << duracionSegundos << "s" << " | Cancion en Vivo | Lugar: " << lugar << " | Fecha: " << fecha << " | Reproducciones: " << reproducciones;
    return oss.str();
}
 
std::string CancionEnVivo::tipo() const { return "CANCION_EN_VIVO"; }
 
std::string CancionEnVivo::formatoEsperado() const { return ".wav"; }
 
std::string CancionEnVivo::serializar() const {
    std::ostringstream oss;
    oss << tipo() << "|" << id << "|" << titulo << "|" << duracionSegundos << "|" << lugar << "|" << fecha << "|" << rutaArchivo;
    return oss.str();
}
 

//PODCAST
Podcast::Podcast(int id, const std::string& titulo, int duracionSegundos, const std::string& invitado, const std::string& tema, const std::string& rutaArchivo) : Audio(id, titulo, duracionSegundos, rutaArchivo), invitado(invitado), tema(tema) {}
 
Podcast::~Podcast() {}
 
std::string Podcast::getInvitado() const { return invitado; }
std::string Podcast::getTema() const { return tema; }
 
void Podcast::setInvitado(const std::string& nuevoInvitado) {
    invitado = nuevoInvitado.empty() ? "Sin invitado" : nuevoInvitado;
}
 
void Podcast::setTema(const std::string& nuevoTema) {
    if (nuevoTema.empty()) {
        std::cout << "Tema invalido\n";
        return;
    }
    tema = nuevoTema;
}
 
void Podcast::reproducir() {
    reproducciones++;
    std::cout << "Reproduciendo podcast: \"" << titulo << "\" (Invitado: " << invitado << ", Tema: " << tema << ")\n";
    reproducirArchivo();
}
 
std::string Podcast::obtenerInfo() const {
    std::ostringstream oss;
    oss << "[" << id << "] " << titulo << " - " << duracionSegundos << "s" << " | Podcast | Invitado: " << invitado << " | Tema: " << tema << " | Reproducciones: " << reproducciones;
    return oss.str();
}
 
std::string Podcast::tipo() const { return "PODCAST"; }
 
std::string Podcast::formatoEsperado() const { return ".m4a"; }
 
std::string Podcast::serializar() const {
    std::ostringstream oss;
    oss << tipo() << "|" << id << "|" << titulo << "|" << duracionSegundos << "|" << invitado << "|" << tema << "|" << rutaArchivo;
    return oss.str();
}
 
//AUDIOLIBRO
Audiolibro::Audiolibro(int id, const std::string& titulo, int duracionSegundos, const std::string& narrador, int totalCapitulos, const std::string& rutaArchivo) : Audio(id, titulo, duracionSegundos, rutaArchivo), narrador(narrador), capituloActual(1), totalCapitulos(totalCapitulos > 0 ? totalCapitulos : 1) {}
 
Audiolibro::~Audiolibro() {}
 
std::string Audiolibro::getNarrador() const { return narrador; }
int Audiolibro::getCapituloActual() const { return capituloActual; }
int Audiolibro::getTotalCapitulos() const { return totalCapitulos; }
 
void Audiolibro::setNarrador(const std::string& nuevoNarrador) {
    if (nuevoNarrador.empty()) {
        std::cout << "Narrador invalido\n";
        return;
    }
    narrador = nuevoNarrador;
}
 
void Audiolibro::avanzarCapitulo() {
    if (capituloActual < totalCapitulos) {
        capituloActual++;
    } else {
        std::cout << "Ya estas en el ultimo capitulo.\n";
    }
}
 
void Audiolibro::setTotalCapitulos(int total) {
    if (total <= 0 || total < capituloActual) {
        std::cout << "Total de capitulos invalido\n";
        return;
    }
    totalCapitulos = total;
}
 
void Audiolibro::reproducir() {
    reproducciones++;
    std::cout << "Reproduciendo audiolibro: \"" << titulo << "\" narrado por " << narrador << " (Capitulo " << capituloActual << "/" << totalCapitulos << ")\n";
    reproducirArchivo();
    avanzarCapitulo();
}
 
std::string Audiolibro::obtenerInfo() const {
    std::ostringstream oss;
    oss << "[" << id << "] " << titulo << " - " << duracionSegundos << "s" << " | Audiolibro | Narrador: " << narrador << " | Capitulo: " << capituloActual << "/" << totalCapitulos << " | Reproducciones: " << reproducciones;
    return oss.str();
}
 
std::string Audiolibro::tipo() const { return "AUDIOLIBRO"; }
 
std::string Audiolibro::formatoEsperado() const { return ".wma"; }
 
std::string Audiolibro::serializar() const {
    std::ostringstream oss;
    oss << tipo() << "|" << id << "|" << titulo << "|" << duracionSegundos << "|" << narrador << "|" << totalCapitulos << "|" << rutaArchivo;
    return oss.str();
}