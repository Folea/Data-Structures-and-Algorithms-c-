#include "Libro.h"
#include <iostream>
#include <sstream>

using namespace std;

void Libro::leer(){
	cin >> isbn >> fecha >> ncap;
	cin.ignore();
	getline(cin, titulo);
	getline(cin, autores);
}

void Libro::mostrarCorto(){
	cout << titulo << ", " << autores << ", " << fecha;
}

void Libro::mostrarLargo(){
	cout << titulo << endl;
	cout << autores << ", " << fecha << endl;
	cout << ncap << " capítulos" << endl;
}

int Libro::codigoisbn(){
	return isbn;
}

int Libro::numeroCapitulo(){
	return ncap;
}
