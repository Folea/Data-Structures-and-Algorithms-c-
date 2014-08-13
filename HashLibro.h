#ifndef _TAD_HASH_LIBRO_
#define _TAD_HASH_LIBRO_

#include <list>
#include "Libro.h"

class HashLibro{
	private:
	list <Libro*> HashLibros[50];
	int funcionDispersion(int isbn);
	
	public:
	void insertar(Libro * libro);
	Libro * consultar(int isbn);
};

#endif
