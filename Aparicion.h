#ifndef _TAD_APARICION_
#define _TAD_APARICION_
#include <iostream>
#include "Libro.h"

using namespace std;

class Aparicion{
	private:
	string palabraTexto;
	Libro * libro;
	 int ncap;
	 int npar;
	 static int ncapActual;
	 static int nparActual;
	 static int numeroPalabras;
	 static int numeroParrafos;

	public:
	string devuelvePalabra();
	string leerAparicion(Libro * l);
	void mostrarAparicion();
	void iniciarActuales();
	int totalParrafos();
	int totalPalabras();
	Libro * devuelveLibro();
	int ncapA();
	int nparA();
};

#endif
