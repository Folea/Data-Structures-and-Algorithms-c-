#include <list>
#include "Libro.h"
#include "HashLibro.h"

using namespace std;

int HashLibro::funcionDispersion(int isbn){
	int posicion;
	posicion = isbn%50;
	return posicion;
}

void HashLibro::insertar(Libro * libro){
	int posicion = funcionDispersion(libro->codigoisbn());
	// Evaluamos la lista referente a esa posición.
	list <Libro*> * posicionHashLibros = &HashLibros[posicion];
	list <Libro*>::iterator it = posicionHashLibros->begin();

	if(posicionHashLibros->size() == 0) {
		posicionHashLibros->insert(it, libro);
	}
	else {
		bool insertado = false;
		for (it = posicionHashLibros->begin(); it != posicionHashLibros->end(); it++) {
    		if(((*it)->codigoisbn() > libro->codigoisbn()) && !insertado){
    			posicionHashLibros->insert(it, libro);
    			insertado = true;
    		}
    		else if (((*it)->codigoisbn() == libro->codigoisbn()) && !insertado){
    			//delete (*it);
    			(*it) = libro;
    			insertado = true;
    		}
		}
		if(!insertado) posicionHashLibros->insert(it, libro);
	}
}

Libro * HashLibro::consultar(int isbn){
	int posicion = funcionDispersion(isbn);
	list <Libro*> * posicionHashLibros = &HashLibros[posicion];
	list <Libro*>::iterator it;
	
	for (it = posicionHashLibros->begin(); it != posicionHashLibros->end(); it++){
		if((*it)->codigoisbn() == isbn){
    		return (*it);
    	}
	}
	return NULL;
}
