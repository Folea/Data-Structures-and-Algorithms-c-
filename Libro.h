#ifndef _TAD_LIBRO_
#define _TAD_LIBRO_
#include <iostream>

using namespace std;

class Libro{
	private:
	string titulo;
	string autores;
	int isbn;
	int fecha;
	int ncap;
	int npar;
	int npal;

	public:
	void leer();
	void mostrarCorto();
	void mostrarLargo();
	int codigoisbn();
	int numeroCapitulo();
};

#endif
