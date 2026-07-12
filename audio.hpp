#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <iostream>
#include <string>

class Audio {
    protected: 
        int id; //sin setter
        std::string titulo;
        int duracionSegundos;
        int reproducciones; //contador, solo se modifica desde reproducir()
        std::string rutaArchivo;

        void reproducirArchivo() const; //cada clase derivada llama desde su propio reproducir

    public:
        Audio(int id, const std::string& titulo, int duracion, const std::string& rutaArchivo);

        virtual ~Audio();

        //Getters
        int getId() const;
        int getDuracionSeg () const;
        int getReproducciones() const; 
        std::string getTitulo() const;
        std::string getRutaArchivo() const;

        //setters
        void setTitulo(const std::string& nuevoTitulo);
        void setDuracionSegundos(int segundos);
        void setRutaArchivo(const std::string& nuevaRuta);

        //metodos
        virtual void reproducir() = 0;
        virtual std::string obtenerInfo() const = 0;
        virtual std:: string tipo() const = 0;
        virtual std::string serializar() const = 0; //para guardar en un .txt
        virtual std::string formatoEsperado() const = 0; // formato de archivo

        //friend(no es virtual): una funcion friend no es miembro de la clase pero tiene acceso a los atributos privados y protegidos de una clase. convecnion en cualquier tipo de sobrecarga de <<
        //sobrecarga del operador<<. un cout normal no funciona (no sobria como hacerlo imprimible ). 
        //Con operator<<, le estamos diciendo exacatemente que hacer cuando el lado derecho es un objeto. 
        // los flujos de datos (streams), no se pueden copiar, deben ser por referencia
        //primer parametro: es el fujo de datos donde vas a escribir (representa un cout)
        //segundo parametro: lo que quieres imprimir
        friend std::ostream& operator<<(std::ostream& os, const Audio& a);
};

#endif