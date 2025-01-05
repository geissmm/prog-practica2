FLAGS = -ansi -Wall

.SILENT:

all: 1.cpp
	g++ 1.cpp -o 1 $(FLAGS)
	

test: ex1 
	echo "**** Exercici 1.0 ****"
	./1 < 1-jp0.txt
	echo "**** Exercici 1.1 ****"
	./1 < 1-jp1.txt
	echo "**** Exercici 1.2 ****"
	./1 < 1-jp2.txt
	echo "**** Exercici 1.3 ****"
	./1 < 1-jp3.txt
	echo "**** Exercici 1.4 ****"
	./1 < 1-jp4.txt
	

clean:
	rm -f 1 
	ls
