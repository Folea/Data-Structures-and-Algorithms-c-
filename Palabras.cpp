#include "Palabras.h"
#include <iostream>
#include "Letras.h"

using namespace std;

string siguientePalabra(){
    string letraActual = siguienteLetra();
    string palabraCompleta;
    
    while ((letraActual == " ") && (letraActual != "\n")) {
        letraActual = siguienteLetra();
    }
    
    if (letraActual == "\n") {
        return letraActual;
    }
    else if(cin.eof()) {
        return "";
    }
    else {
        while (letraActual != " " && !cin.eof() && letraActual != "\n") {
            palabraCompleta += letraActual;
            letraActual = siguienteLetra();
        }
        cin.unget();
        return palabraCompleta;
    }
    
}
