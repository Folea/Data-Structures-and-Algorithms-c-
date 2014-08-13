#include <iostream>
#include <sstream>
#include <cmath>
#include <list>
#include "ArbolTrie.h"

using namespace std;

ArbolTrie * ArbolTrie::arbolActual;

// 97 es 'a' en ASCII

void ArbolTrie::insertar(string palabra){
	arbolActual = this;
	int indiceActual = 0;

	// Hasta que se acabe la palabra.
	for (int indicePalabra = 0; palabra[indicePalabra]!=0; indicePalabra++){

		indiceActual = ((int)palabra[indicePalabra])-97;

		//Evaluamos si es ñ
		if (palabra[indicePalabra]==(char)0xC3){
			indicePalabra++;
			if (palabra[indicePalabra]==(char)0xB1){
			indiceActual = 26;
			}
		}

			// Si existe ya, avanza al siguiente nodo.
			if (arbolActual->nodos[indiceActual]){
				arbolActual = arbolActual->nodos[indiceActual];
			}

			// Si no existe, lo crea.
			else {
				ArbolTrie * arbolNuevo = new ArbolTrie();
				arbolActual->nodos[indiceActual] = arbolNuevo;
				arbolActual = arbolNuevo;
			}
		
	}

	// Como ya se ha finalizado de leer la palabra, ponemos $.
	arbolActual->nodos[27] = arbolActual;
}

int ArbolTrie::consultar(string palabra){
	arbolActual = this;
	int indiceActual = 0;

	// Hasta que se acabe la palabra.
	for (int indicePalabra = 0; palabra[indicePalabra]!=0; indicePalabra++){
		
		indiceActual = ((int)palabra[indicePalabra])-97;

		//Evaluamos si es ñ
		if (palabra[indicePalabra]==(char)0xC3){
			indicePalabra++;
			if (palabra[indicePalabra]==(char)0xB1){
			indiceActual = 26;
			}
		}

		// Si existe ya, avanza al siguiente nodo.
		if (arbolActual->nodos[indiceActual]){
			arbolActual = arbolActual->nodos[indiceActual];
		}

		// Si no existe, devuelve 0.
		else return 0;
	}

	// Una vez finalizada la palabra, si se encuentra $, se da por correcta.
	if (arbolActual->nodos[27]){
		return 1;
	}
	else return 0;
}

list<Aparicion*> * ArbolTrie::listaAparicionArbolActual(string palabra){
		 if (consultar(palabra)) return arbolActual->apariciones;
		 else return NULL;
}

void ArbolTrie::actualizarListaAparicion(string palabra, list<Aparicion*> * aparicion){
		if (consultar(palabra)) {
		arbolActual->apariciones = aparicion;
		}
}
