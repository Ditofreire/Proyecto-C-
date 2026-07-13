#include "MotorAudio.hpp"
#include <string>
#include <windows.h>//header principal de la API Windows. Declara tipos y funciones que permiten comunicarse con el OS.
#include <mmsystem.h> //Header antiguo dedicado a funciones multimedia, especialmente: .wav, Control de dispositivos, Temp multimedia, etc.

#pragma comment(lib,"winmm.lib") 
/*
pragma: Instruccion especial al compilador
comment(lib, ...): Instruccion de Microsoft que agrega una biblioteca al proces de enlazado
winmm.lib: Biblioteca multimedia de windows

pd: se usan tanto mmsystem.h como winmm.lib porque ambas se complementan.
    mmsystem.h --->explica como llamar a una funcion(ejemplo: playsound)
    winmm.lib ---> Permite conectar esa llamada con windows
*/

MotorAudio::MotorAudio():archivoAbierto(false){}
MotorAudio::~MotorAudio(){
    if(archivoAbierto){
        cerrar();
    }
} 

bool MotorAudio::abrir(const std::string& rutaArchivo){
    std::string comando = "open \""+rutaArchivo+"\" alias musica";
    MCIERROR resultado = mciSendStringA(comando.c_str(), nullptr, 0, nullptr);
    if(resultado==0){
        archivoAbierto = true;
        return true;
    }else{
        archivoAbierto = false;
        return false;
    }

    /*############e'ta vaina e'ta potente#####################3
    ////////////////////////////Que es MCI? 
MCI es Media Control Interface. Es una partee de Windows que permite controlar archivos multimedia usando instrucciones escritas como texto. En vez de programar directamente
el decodificador de MP3 o WAV, tu le dices a Windows: Abre archivo, Reproducelo, Pausalo, etc.
Especificamente, mciSendString toma la instruccion y la envia al sistema multimedia de windows.

    /////////// Funcion mciSendString
Sintaxis basica:

mciSendStringA(comando.c_str();nullptr,0,nullptr); ----> Cuatro Parametros

Primer parametro: Comando. Aqui se envia la instruccion que windows debe ejecutar.
Segundo parametro: nullptr.Donde recivir respuesta, le mandamos a nullptr porque no necesitamos recibir informacion(ej:texto), solo abrir.
Tercer parametro: 0/. Tamanio de espacio para la respuesta.
Cuarto parametro: nullptr. Ventana que recivira notificacion (mucho phi. proyecto no tan pro)
pd: si no se pone la A(Texto basado en paginas de codigos ANSI) al final se mciSendString, se puede interpretar como mciSendString W que es de wide, caracteres anchos(En windows normalmente representa texto Unicode UTF-16)
Resumen, A--> No error y W --> Error
    ///////////////// "\ o \"
Marcan el inicio y el fin del string. sin eso Windows podria interpretar cada parte de la palabra como un diferente comando.

    ////////////// c_str()
Comando es un objeto de de la clase string pot eso se le pone c_str(). Pues que proveniendo de un str, devuelce un const char*. Compatible con
funcones antiguas de C.

    //////MCIERROR
Es un tipo de dato definido por windows para guardar e; resultado de una operacion MCI.

    */
}

void MotorAudio::reproducir(){
 mciSendStringA("play musica", nullptr, 0, nullptr);   
}
void MotorAudio::pausar(){
 mciSendStringA("pause", nullptr, 0, nullptr);   
}
void MotorAudio::Continuar(){
 mciSendStringA("resume musica", nullptr, 0, nullptr);   
}
void MotorAudio::detener(){
 mciSendStringA("stop musica", nullptr, 0, nullptr);   
}
bool MotorAudio::cerrar(){
    if(!archivoAbierto){
        return false;
    }
    MCIERROR resultado = mciSendStringA("close musica", nullptr, 0, nullptr);
    if(resultado==0){
        archivoAbierto = false;
        return true;
    }else{
        return false;
    }
    
}

//pd:Los string funcionan porque son comandos predefinidos por Windows(los odio de corazon)