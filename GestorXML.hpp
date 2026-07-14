#ifndef GESTOR_XML_HPP
#define GESTOR_XML_HPP

#include "ListaReproduccion.hpp"
#include <string>

class GestorXML {
public:
    bool guardar(
        const ListaReproduccion& lista,
        const std::string& rutaArchivo
    );

    bool cargar(
        ListaReproduccion& lista,
        const std::string& rutaArchivo
    );
};

#endif