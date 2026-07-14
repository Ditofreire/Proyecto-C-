#include <iostream>
#include <string>
#include "MotorAudio.hpp"

int main (){

    MotorAudio motor;
     if(motor.abrir(R"(C:\Users\gerad\Documents\GitHub\Proyecto-C-\audio\prueba.wav)")){
        std::cout<<"Archivo abierto correctamente"<<std::endl;
        motor.reproducir();

        std::cout<<"Presiona enter para detener."<<std::endl;
        std::cin.get();

        motor.detener();
        motor.cerrar();
     }else{
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
     }
    return 0;
}