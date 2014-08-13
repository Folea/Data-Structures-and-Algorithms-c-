a.out: Aparicion.o Libro.o Letras.o Palabras.o Interprete.o ColeccionLibros.o HashLibro.o ArbolTrie.o 305.o
	g++ -g -o a.out Aparicion.o Libro.o Letras.o Palabras.o Interprete.o ColeccionLibros.o HashLibro.o ArbolTrie.o 305.o

Aparicion.o: Aparicion.cpp Aparicion.h
	g++ -c Aparicion.cpp

Libro.o: Libro.cpp Libro.h
	g++ -c Libro.cpp

Letras.o: Letras.cpp Letras.h
	g++ -c Letras.cpp

Palabras.o: Palabras.cpp Palabras.h
	g++ -c Palabras.cpp

Interprete.o: Interprete.cpp Interprete.h
	g++ -c Interprete.cpp

ColeccionLibros.o: ColeccionLibros.cpp ColeccionLibros.h
	g++ -c ColeccionLibros.cpp

HashLibro.o: HashLibro.cpp HashLibro.h
	g++ -c HashLibro.cpp

ArbolTrie.o: ArbolTrie.cpp ArbolTrie.h
	g++ -c ArbolTrie.cpp

305.o: 305.cpp
	g++ -c 305.cpp
