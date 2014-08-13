#include "Letras.h"
#include <iostream>

using namespace std;

string siguienteLetra(){
    
    string caracterEspecial;
    string caracterAuxiliar1;
    char caracterAuxiliar2;
    char caracterActual = cin.get();
    
    // Mayusculas
    if(caracterActual >= (char)0x41 && caracterActual <= (char)0x5A){
        caracterAuxiliar2 = tolower(caracterActual);
        caracterAuxiliar1 += caracterAuxiliar2;
        return caracterAuxiliar1;
    }
    // Minusculas y retorno de carro
    else if((caracterActual >= (char)0x61 && caracterActual <= (char)0x7A) ||
            (caracterActual == (char)0x0A)){
        caracterAuxiliar2 = caracterActual;
        caracterAuxiliar1 += caracterAuxiliar2;
        return caracterAuxiliar1;
    }
    // Caracteres especiales
    else if(caracterActual == (char)0xC3){
    
        caracterActual = cin.get();
    
        // Especiales a
        if((caracterActual == (char)0x81) || (caracterActual == (char)0xA1)){
            caracterEspecial += (char)0x61;
        }
        // Especiales e
        else if((caracterActual == (char)0x89)||(caracterActual == (char)0xA9)){
            caracterEspecial += (char)0x65;
        }
        // Especiales i
        else if((caracterActual == (char)0x8D)||(caracterActual == (char)0xAD)){
            caracterEspecial += (char)0x69;
        }
        // Especiales o
        else if((caracterActual == (char)0x93)||(caracterActual == (char)0xB3)){
            caracterEspecial += (char)0x6F;
        }
        // Especiales u
        else if((caracterActual == (char)0x9A)||(caracterActual == (char)0xBA)||
                (caracterActual == (char)0x9C)||(caracterActual == (char)0xBC)){
            caracterEspecial += (char)0x75;
        }
        // Especiales ñ
        else if ((caracterActual == (char)0x91)||(caracterActual == (char)0xB1)){
            caracterEspecial += (char)0xc3;
            caracterEspecial += (char)0xB1;
        
        }
        else caracterEspecial += " ";

    return caracterEspecial;
        
    }
    else return " ";
}
