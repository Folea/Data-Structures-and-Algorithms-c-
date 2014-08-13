#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Aparicion.h"
#include "Libro.h"
#include "Letras.h"
#include "Palabras.h"

using namespace std;

string palabraActual;

int Aparicion::ncapActual;
int Aparicion::nparActual;
int Aparicion::numeroPalabras;
int Aparicion::numeroParrafos;

void Aparicion::iniciarActuales(){
	ncapActual = 1;
	nparActual = 1;
	numeroPalabras = 0;
	numeroParrafos = 1;
}

string Aparicion::devuelvePalabra(){
	return palabraActual;
}

string Aparicion::leerAparicion(Libro * l){
	libro = l;
	bool parrafoNuevo = false;
	//palabraActual = 0;

		palabraTexto = siguientePalabra();

		if (palabraTexto == "\n"){
			palabraTexto = siguientePalabra();
			if (palabraTexto == "\n"){
				nparActual++;
				numeroParrafos++;
				parrafoNuevo = true;
				while (palabraTexto == "\n"){
					palabraTexto = siguientePalabra();
				}
			}
		}

		if (palabraTexto == "findecapitulo"){
			if (ncapActual!=libro->numeroCapitulo()){
				ncapActual++;
				nparActual = 1;
				if (!parrafoNuevo) numeroParrafos++;
			}
			else{
				if(parrafoNuevo) numeroParrafos--;
				return "fiiin";
			}
		}

	if (palabraTexto!="findecapitulo"){
		numeroPalabras++;
		palabraActual = palabraTexto;
	}

	parrafoNuevo = false;
	ncap = ncapActual;
	npar = nparActual;

	return palabraTexto;
}

void Aparicion::mostrarAparicion(){
		if (palabraTexto!="findecapitulo"){
		libro->mostrarCorto();
		cout << ", Cap. " << ncap << ", par. " << npar << endl;
	}
}

int Aparicion::totalParrafos(){
	return numeroParrafos;
}

int Aparicion::totalPalabras(){
	return numeroPalabras;
}

int Aparicion::ncapA(){
	return ncap;
}

int Aparicion::nparA(){
	return npar;
}

Libro * Aparicion::devuelveLibro(){
	return libro;
}
