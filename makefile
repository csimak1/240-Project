all: proj4

proj4: proj4.o User.o BST.o Heap.o
	g++ proj4.o User.o BST.o Heap.o -g -o proj4

proj4.o: proj4.cpp 
	g++ -g -c proj4.cpp

BST.o: BST.cpp BST.h
	g++ -g -c BST.cpp

User.o: User.cpp User.h
	g++ -g -c User.cpp

Heap.o: Heap.cpp Heap.h 
	g++ -g -c Heap.cpp

clean:
	rm -f *.o proj4