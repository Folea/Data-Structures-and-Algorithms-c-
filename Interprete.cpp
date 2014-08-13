#include "Interprete.h"
#include <iostream>
#include <string>
#include <list>
#include "Palabras.h"
#include "Libro.h"
#include "Aparicion.h"
#include "ColeccionLibros.h"
#include "HashLibro.h"
#include "ArbolTrie.h"

using namespace std;

static Libro * libro;
static Aparicion aparicion;
static ColeccionLibros coleccionLibros;

list<Aparicion*> * interseccionListas(list<Aparicion*> * l1, list<Aparicion*> * l2){
	if (l1 == NULL || l2 == NULL){
		return NULL;
	}

	list<Aparicion*> * lista = new list<Aparicion*>();
	list<Aparicion*>::reverse_iterator itl1 = l1->rbegin();
	list<Aparicion*>::reverse_iterator itl2 = l2->rbegin();


	while (itl1 != l1->rend() && itl2 != l2->rend()){

		if ((*itl1)->devuelveLibro()->codigoisbn() <  (*itl2)->devuelveLibro()->codigoisbn())
			itl1++;

		else if (((*itl1)->devuelveLibro()->codigoisbn() == (*itl2)->devuelveLibro()->codigoisbn()) 
			&& ((*itl1)->ncapA() < (*itl2)->ncapA()))
			itl1++;

		else if (((*itl1)->devuelveLibro()->codigoisbn() == (*itl2)->devuelveLibro()->codigoisbn()) 
			&& ((*itl1)->ncapA() == (*itl2)->ncapA())
			&& ((*itl1)->nparA() < (*itl2)->nparA()))
			itl1++;

		else if ((*itl1)->devuelveLibro()->codigoisbn() >  (*itl2)->devuelveLibro()->codigoisbn())
			itl2++;

		else if (((*itl1)->devuelveLibro()->codigoisbn() == (*itl2)->devuelveLibro()->codigoisbn()) 
			&& ((*itl1)->ncapA() > (*itl2)->ncapA()))
			itl2++;

		else if (((*itl1)->devuelveLibro()->codigoisbn() == (*itl2)->devuelveLibro()->codigoisbn()) 
			&& ((*itl1)->ncapA() == (*itl2)->ncapA())
			&& ((*itl1)->nparA() > (*itl2)->nparA()))
			itl2++;

		else if (((*itl1)->devuelveLibro()->codigoisbn() == (*itl2)->devuelveLibro()->codigoisbn()) 
			&& ((*itl1)->ncapA() == (*itl2)->ncapA())
			&& ((*itl1)->nparA() == (*itl2)->nparA())){
			lista->push_front(*itl1);
			itl1++;
			itl2++;
		}

	}

	return lista;
}

list<Aparicion*> * unionListas(list<Aparicion*> * l1, list<Aparicion*> * l2){
	if (l1 == NULL && l2 == NULL)
		return NULL;

	if (l1 == NULL)
		return l2;

	if (l2 == NULL)
		return l1;

	list<Aparicion*> * lista = new list<Aparicion*>();
	list<Aparicion*>::reverse_iterator itl1 = l1->rbegin();
	list<Aparicion*>::reverse_iterator itl2 = l2->rbegin();


	while (itl1 != l1->rend() && itl2 != l2->rend()){

		if ((*itl1)->devuelveLibro()->codigoisbn() <  (*itl2)->devuelveLibro()->codigoisbn()){
			lista->push_front(*itl1);
			itl1++;
		}

		else if (((*itl1)->devuelveLibro()->codigoisbn() == (*itl2)->devuelveLibro()->codigoisbn()) 
			&& ((*itl1)->ncapA() < (*itl2)->ncapA())){
			lista->push_front(*itl1);
			itl1++;
		}

		else if (((*itl1)->devuelveLibro()->codigoisbn() == (*itl2)->devuelveLibro()->codigoisbn()) 
			&& ((*itl1)->ncapA() == (*itl2)->ncapA())
			&& ((*itl1)->nparA() < (*itl2)->nparA())){
			lista->push_front(*itl1);
			itl1++;
		}

		else if ((*itl1)->devuelveLibro()->codigoisbn() >  (*itl2)->devuelveLibro()->codigoisbn()){
			lista->push_front(*itl2);
			itl2++;
		}

		else if (((*itl1)->devuelveLibro()->codigoisbn() == (*itl2)->devuelveLibro()->codigoisbn()) 
			&& ((*itl1)->ncapA() > (*itl2)->ncapA())){
			lista->push_front(*itl2);
			itl2++;
		}

		else if (((*itl1)->devuelveLibro()->codigoisbn() == (*itl2)->devuelveLibro()->codigoisbn()) 
			&& ((*itl1)->ncapA() == (*itl2)->ncapA())
			&& ((*itl1)->nparA() > (*itl2)->nparA())){
			lista->push_front(*itl2);
			itl2++;
		}

		else if (((*itl1)->devuelveLibro()->codigoisbn() == (*itl2)->devuelveLibro()->codigoisbn()) 
			&& ((*itl1)->ncapA() == (*itl2)->ncapA())
			&& ((*itl1)->nparA() == (*itl2)->nparA())){
			lista->push_front(*itl1);
			itl1++;
			itl2++;
		}

	}

	while (itl1 != l1->rend()){
		lista->push_front(*itl1);
		itl1++;
	}

	while (itl2 != l2->rend()){
		lista->push_front(*itl2);
		itl2++;
	}

	return lista;
}

void procesarInsertar(){
	coleccionLibros.cargarLibro();
}

void procesarConsultar(){
	int isbn;
	cin >> isbn;
	cin.ignore();
	coleccionLibros.consultar(isbn);
}

void buscarAND(){
	string palabraAND = siguientePalabra();

	list<Aparicion*> * aux = coleccionLibros.devuelveArbol()->listaAparicionArbolActual(palabraAND);
	list<Aparicion*> * listaResultadoAND = aux;

	palabraAND = siguientePalabra();
	while (palabraAND != "\n"){
		aux = coleccionLibros.devuelveArbol()->listaAparicionArbolActual(palabraAND);
		listaResultadoAND = interseccionListas(aux, listaResultadoAND);
		palabraAND = siguientePalabra();
	}

	int apariciones = 0;

	if (listaResultadoAND)
		apariciones = listaResultadoAND->size();

	int numeroLista = 1;

	cout << "Total: " << apariciones << " resultados" << endl;

	if (apariciones>0){

		list<Aparicion*>::reverse_iterator it = listaResultadoAND->rbegin();
		for (int i=0; i<listaResultadoAND->size(); i++, it++){
			cout << numeroLista << ". ";
			(*it)->mostrarAparicion();
			numeroLista++;
		}
	}

}

void buscarOR(){

	string palabraOR = siguientePalabra();

	list<Aparicion*> * aux = coleccionLibros.devuelveArbol()->listaAparicionArbolActual(palabraOR);
	list<Aparicion*> * listaResultadoOR = aux;

	palabraOR = siguientePalabra();
	while (palabraOR != "\n"){
		aux = coleccionLibros.devuelveArbol()->listaAparicionArbolActual(palabraOR);
		listaResultadoOR = unionListas(aux, listaResultadoOR);
		palabraOR = siguientePalabra();
	}

	int apariciones = 0;

	if (listaResultadoOR)
		apariciones = listaResultadoOR->size();

	int numeroLista = 1;

	cout << "Total: " << apariciones << " resultados" << endl;

	if (apariciones>0){

		list<Aparicion*>::reverse_iterator it = listaResultadoOR->rbegin();
		for (int i=0; i<listaResultadoOR->size(); i++, it++){
			cout << numeroLista << ". ";
			(*it)->mostrarAparicion();
			numeroLista++;
		}
	}

}
