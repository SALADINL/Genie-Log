CXX=g++
GNU=-std=gnu++11
projet=matrice

${projet}: main.o Matrice.o
	${CXX} ${GNU} -w -o ${projet} main.o Matrice.o

main.o: main.cpp Matrice.h
	${CXX} ${GNU} -w -o main.o -c main.cpp

Matrice.o: Matrice.cpp
	${CXX} ${GNU} -w -o Matrice.o -c Matrice.cpp

clean:
	rm -f *.o *~
mrproper: clean
	rm ./${projet}
