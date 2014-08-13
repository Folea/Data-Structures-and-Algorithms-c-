#ifndef _TAD_COLECCION_LIBROS_
#define _TAD_COLECCION_LIBROS_
#include <list>
#include "Libro.h"
#include "HashLibro.h"
#include "ArbolTrie.h"

using namespace std;

class ColeccionLibros{
	private:
	HashLibro libros;
	ArbolTrie diccionario;
	
	public:
	void insertar(Libro * libro);
	void consultar(int isbn);
	ArbolTrie * devuelveArbol();
	void cargarLibro();
};

#endif
