#ifndef Motor_HPP
#define Motor_HPP
#include<string>
class MotorAudio{
    private:
    bool archivoAbierto;
    public:
    MotorAudio();
    ~MotorAudio();
    
    bool abrir(const std::string& rutaArchivo);

    void reproducir();
    void pausar();
    void Continuar();
    void detener();
    bool cerrar();  
};

#endif 