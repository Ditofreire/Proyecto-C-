#ifndef TIPOS_AUDIO_HPP
#define TIPOS_AUDIO_HPP

#include "Audio.hpp"
#include <string>

//CANCION ESTUDIO
class CancionEstudio : public Audio {
private:
    std::string album;
    std::string productor;
 
public:
    CancionEstudio(int id, const std::string& titulo, int duracionSegundos, const std::string& album, const std::string& productor, const std::string& rutaArchivo = "");
    ~CancionEstudio() override;
 
    std::string getAlbum() const;
    std::string getProductor() const;
 
    void setAlbum(const std::string& nuevoAlbum);
    void setProductor(const std::string& nuevoProductor);
 
    void reproducir() override;
    std::string obtenerInfo() const override;
    std::string tipo() const override;
    std::string serializar() const override;
    std::string formatoEsperado() const override;
};

//CANCION EN VIVO
class CancionEnVivo : public Audio {
private:
    std::string lugar;
    std::string fecha; //DD-MM-AAAA
 
public:
    CancionEnVivo(int id, const std::string& titulo, int duracionSegundos, const std::string& lugar, const std::string& fecha, const std::string& rutaArchivo = "");
    ~CancionEnVivo() override;
 
    std::string getLugar() const;
    std::string getFecha() const;
 
    void setLugar(const std::string& nuevoLugar);
    void setFecha(const std::string& nuevaFecha);
 
    void reproducir() override;
    std::string obtenerInfo() const override;
    std::string tipo() const override;
    std::string serializar() const override;
    std::string formatoEsperado() const override;
};

//PODCAST
class Podcast : public Audio {
private:
    std::string invitado;
    std::string tema;
 
public:
    Podcast(int id, const std::string& titulo, int duracionSegundos, const std::string& invitado, const std::string& tema, const std::string& rutaArchivo = "");
    ~Podcast() override;
 
    std::string getInvitado() const;
    std::string getTema() const;
 
    void setInvitado(const std::string& nuevoInvitado);
    void setTema(const std::string& nuevoTema);
 
    void reproducir() override;
    std::string obtenerInfo() const override;
    std::string tipo() const override;
    std::string serializar() const override;
    std::string formatoEsperado() const override;
};

//AUDIOLIBRO
class Audiolibro : public Audio {
private:
    std::string narrador;
    int capituloActual;
    int totalCapitulos;
 
public:
    Audiolibro(int id, const std::string& titulo, int duracionSegundos, const std::string& narrador, int totalCapitulos, const std::string& rutaArchivo = "");
    ~Audiolibro() override;
 
    std::string getNarrador() const;
    int getCapituloActual() const;
    int getTotalCapitulos() const;
 
    void setNarrador(const std::string& nuevoNarrador);
    void avanzarCapitulo();
    void setTotalCapitulos(int total);
 
    void reproducir() override;
    std::string obtenerInfo() const override;
    std::string tipo() const override;
    std::string serializar() const override;
    std::string formatoEsperado() const override;
};

#endif