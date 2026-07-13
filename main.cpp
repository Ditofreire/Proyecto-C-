#include <iostream>
#include <string>
#include "audio.hpp"
#include "tiposAudio.hpp"
#include "MotorAudio.hpp"

int main (){

    MotorAudio motor;
     if(motor.abrir("audio/cancion.mp3")){
        motor.reproducir();
     }
    return 0;
}