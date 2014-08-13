#ifndef _TAD_ARBOLTRIE_
#define _TAD_ARBOLTRIE_

#include "Aparicion.h"
#include <list>

using namespace std;

class ArbolTrie{
	private:
	ArbolTrie * nodos[28]; // [0-25] a-z [26] ñ [27] $ 
	list<Aparicion*> * apariciones;
	static ArbolTrie * arbolActual;

	public:
	void insertar(string palabra);
	int consultar(string palabra);
	list<Aparicion*> * listaAparicionArbolActual(string palabra);
	void actualizarListaAparicion(string palabra, list<Aparicion*> * aparicion);
};

#endif
