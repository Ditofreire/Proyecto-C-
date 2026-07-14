#include "GestorXML.hpp"
#include "tiposAudio.hpp"

#include <fstream>
#include <iostream>

static std::string leerEtiqueta(
    const std::string& linea,
    const std::string& etiqueta
)
{
    std::string inicio = "<" + etiqueta + ">";
    std::string fin = "</" + etiqueta + ">";

    size_t posicionInicio = linea.find(inicio);
    size_t posicionFin = linea.find(fin);

    if (posicionInicio == std::string::npos ||
        posicionFin == std::string::npos) {
        return "";
    }

    posicionInicio += inicio.length();

    return linea.substr(
        posicionInicio,
        posicionFin - posicionInicio
    );
}

bool GestorXML::guardar(
    const ListaReproduccion& lista,
    const std::string& rutaArchivo
)
{
    std::ofstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        std::cout << "No se pudo crear el XML.\n";
        return false;
    }

    archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    archivo << "<biblioteca>\n";

    NodoAudio* primero = lista.getPrimero();

    if (primero != nullptr) {
        NodoAudio* auxiliar = primero;

        do {
            Audio* audio = auxiliar->pista;

            archivo << "  <audio tipo=\"" << audio->tipo() << "\">\n";
            archivo << "    <id>" << audio->getId() << "</id>\n";
            archivo << "    <titulo>" << audio->getTitulo() << "</titulo>\n";
            archivo << "    <duracion>"
                    << audio->getDuracionSeg()
                    << "</duracion>\n";

            archivo << "    <reproducciones>"
                    << audio->getReproducciones()
                    << "</reproducciones>\n";

            archivo << "    <ruta>"
                    << audio->getRutaArchivo()
                    << "</ruta>\n";
                
                    if (CancionEstudio* cancion =dynamic_cast<CancionEstudio*>(audio)) {

                        archivo << "    <album>"
                                << cancion->getAlbum()
                                << "</album>\n";

                        archivo << "    <productor>"
                                << cancion->getProductor()
                                << "</productor>\n";
                    }
                    else if (Podcast* podcast =dynamic_cast<Podcast*>(audio)) {

                        archivo << "    <invitado>"
                                << podcast->getInvitado()
                                << "</invitado>\n";

                         archivo << "    <tema>"
                                 << podcast->getTema()
                                 << "</tema>\n";
                    }
                    else if (Audiolibro* libro =dynamic_cast<Audiolibro*>(audio)) {

                        archivo << "    <narrador>"
                                << libro->getNarrador()
                                << "</narrador>\n";

                        archivo << "    <totalCapitulos>"
                                << libro->getTotalCapitulos()
                                << "</totalCapitulos>\n";
                    }   

            archivo << "  </audio>\n";

            auxiliar = auxiliar->siguiente;

        } 
        
        while (auxiliar != primero);
    }

    archivo << "</biblioteca>\n";
    archivo.close();

    return true;
}

bool GestorXML::cargar(
    ListaReproduccion& lista,
    const std::string& rutaArchivo
)
{
    std::ifstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el XML.\n";
        return false;
    }

    lista.vaciar();

    std::string linea;
    std::string tipo;
    std::string titulo;
    std::string ruta;

    std::string album;
    std::string productor;
    std::string invitado;
    std::string tema;
    std::string narrador;

    int id = 0;
    int duracion = 0;
    int reproducciones = 0;
    int totalCapitulos = 0;

    while (std::getline(archivo, linea)) {

    if (linea.find("<audio tipo=") != std::string::npos) {

        size_t inicio = linea.find("\"") + 1;
        size_t fin = linea.find("\"", inicio);

        tipo = linea.substr(inicio, fin - inicio);

        std::cout << "Tipo encontrado: " << tipo << '\n';
    }

    if (linea.find("<id>") != std::string::npos) {
         id = std::stoi(leerEtiqueta(linea, "id"));
    }
    else if (linea.find("<titulo>") != std::string::npos) {
        titulo = leerEtiqueta(linea, "titulo");
    }
    else if (linea.find("<duracion>") != std::string::npos) {
        duracion = std::stoi(leerEtiqueta(linea, "duracion"));
    }
    else if (linea.find("<reproducciones>") != std::string::npos) {
        reproducciones =
        std::stoi(leerEtiqueta(linea, "reproducciones"));
    }
    else if (linea.find("<ruta>") != std::string::npos) {
        ruta = leerEtiqueta(linea, "ruta");
    }
    else if (linea.find("<album>") != std::string::npos) {
    album = leerEtiqueta(linea, "album");
    }
    else if (linea.find("<productor>") != std::string::npos) {
        productor = leerEtiqueta(linea, "productor");
    }
    else if (linea.find("<invitado>") != std::string::npos) {
        invitado = leerEtiqueta(linea, "invitado");
    }
    else if (linea.find("<tema>") != std::string::npos) {
        tema = leerEtiqueta(linea, "tema");
    }
    else if (linea.find("<narrador>") != std::string::npos) {
        narrador = leerEtiqueta(linea, "narrador");
    }
    else if (linea.find("<totalCapitulos>") != std::string::npos) {
        totalCapitulos =
        std::stoi(leerEtiqueta(linea, "totalCapitulos"));
    }
    if (linea.find("</audio>") != std::string::npos) {

    Audio* nuevoAudio = nullptr;

    if (tipo == "CANCION_ESTUDIO") {
        nuevoAudio = new CancionEstudio(
            id,
            titulo,
            duracion,
            album,
            productor,
            ruta
        );
    }
    else if (tipo == "PODCAST") {
        nuevoAudio = new Podcast(
            id,
            titulo,
            duracion,
            invitado,
            tema,
            ruta
        );
    }
    else if (tipo == "AUDIOLIBRO") {
        nuevoAudio = new Audiolibro(
            id,
            titulo,
            duracion,
            narrador,
            totalCapitulos,
            ruta
        );
    }

    if (nuevoAudio != nullptr) {
    nuevoAudio->setReproducciones(reproducciones);
    lista.agregarFinal(nuevoAudio);
    }

    // Reiniciar datos para el siguiente audio
    tipo = "";
    titulo = "";
    ruta = "";
    album = "";
    productor = "";
    invitado = "";
    tema = "";
    narrador = "";

    id = 0;
    duracion = 0;
    reproducciones = 0;
    totalCapitulos = 0;
    
    }
}
    archivo.close();

    return true;
}