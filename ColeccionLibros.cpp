#include <list>
#include "Libro.h"
#include "ColeccionLibros.h"
#include "HashLibro.h"
#include "ArbolTrie.h"

using namespace std;

void ColeccionLibros::insertar(Libro * libro){
	libros.insertar(libro);
}

void ColeccionLibros::consultar(int isbn){
	Libro * libro = libros.consultar(isbn);

	if(libro == NULL) cout << "ISBN " << isbn << " no encontrado" << endl;
	else libro->mostrarLargo();
}

ArbolTrie * ColeccionLibros::devuelveArbol(){
	return &diccionario;
}

void ColeccionLibros::cargarLibro(){
	Libro * lib = new Libro;
	Aparicion * apa = new Aparicion;
	string palabra;
	int parrafos = 0;
	int palabras = 0;

	lib->leer();

	insertar(lib);

	apa->iniciarActuales();

	palabra = apa->leerAparicion(lib);

	while (palabra != "fiiin"){
		
		bool insertado = false;
	
		// Si la palabra que se lee ya existía en el árbol...
		if (diccionario.consultar(palabra)){

			// ... accedemos a la lista de apariciones que ya tenía dicha palabra creada...
			list<Aparicion*> * listaApariciones = diccionario.listaAparicionArbolActual(palabra);
			
			// ... y la insertamos con las restricciones de menor/mayor blablabla...
			list<Aparicion*>::iterator it = listaApariciones->begin();
			for (it = listaApariciones->begin(); it != listaApariciones->end(); it++){


				if (((*it)->devuelveLibro()->codigoisbn() < apa->devuelveLibro()->codigoisbn())
					&& !insertado){
					listaApariciones->insert(it, apa);
					insertado = true;
				}

				else if (((*it)->devuelveLibro()->codigoisbn() == apa->devuelveLibro()->codigoisbn()) 
					&& ((*it)->ncapA() < apa->ncapA())
					&& !insertado) {
					
					listaApariciones->insert(it,apa);
					insertado = true;
				}


				else if (((*it)->devuelveLibro()->codigoisbn() == apa->devuelveLibro()->codigoisbn()) 
					&& ((*it)->ncapA() == apa->ncapA())
					&& ((*it)->nparA() < apa->nparA())
					&& !insertado){
					
					listaApariciones->insert(it,apa);
					insertado = true;
				}

				else if (((*it)->devuelveLibro()->codigoisbn() == apa->devuelveLibro()->codigoisbn()) 
					&& ((*it)->ncapA() == apa->ncapA())
					&& ((*it)->nparA() == apa->nparA())){
					
					delete apa;
					insertado = true;
				}
			}

			if (!insertado && it == listaApariciones->end()){
				listaApariciones->insert(it,apa);
		}

		diccionario.actualizarListaAparicion(palabra, listaApariciones);
		}

		// Si la palabra que se lee NO existía en el árbol..
		else{
			// .. se crea una nueva lista (a la que se le mete la aparición al principio), y ésta al árbol.
			diccionario.insertar(palabra);
			list<Aparicion*> * listaApariciones = new list<Aparicion*>();
			list<Aparicion*>::iterator it = listaApariciones->begin();
			listaApariciones->insert(it,apa);
			
			diccionario.actualizarListaAparicion(palabra, listaApariciones);

		}

		parrafos = apa->totalParrafos();
		palabras = apa->totalPalabras();

		apa = new Aparicion;

		palabra = apa->leerAparicion(lib);
	}
	
	delete apa;

	lib->mostrarLargo();
	cout << parrafos << " párrafos" << endl;
	cout << palabras << " palabras" << endl;
}
