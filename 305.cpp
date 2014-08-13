#include <iostream>
#include "Libro.h"
#include "Aparicion.h"
#include "Letras.h"
#include "Palabras.h"
#include "Interprete.h"

using namespace std;

int main(){
	string identificador;

	while(!cin.eof())
		while(cin >> identificador){
			//s exit
			if (identificador=="i"){
				procesarInsertar();
			}
			else if (identificador=="c"){
				procesarConsultar();
			}
			else if (identificador=="a"){
				buscarAND();
			}
			else if (identificador=="o"){
				buscarOR();
			}
			else if (identificador=="s"){
				return 0;
			}

		}
	
	return 0;
}
