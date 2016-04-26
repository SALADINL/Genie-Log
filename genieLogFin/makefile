CXX=g++
GNU=-std=gnu++11
OBJ=obj/
CPP=cpp/
HEADER=headers/
projet=matrice
mylib=operator+.o operator-.o operator*.o operator<<.o 

${projet}: ${OBJ}main.o ${OBJ}Matrice.o ${OBJ}lib.a
	${CXX} ${GNU} -w -o ${projet} ${OBJ}main.o ${OBJ}Matrice.o ${OBJ}lib.a

${OBJ}main.o: main.cpp ${HEADER}Matrice.h
	${CXX} ${GNU} -w -o ${OBJ}main.o -c main.cpp

${OBJ}Matrice.o: ${CPP}Matrice.cpp
	${CXX} ${GNU} -w -o ${OBJ}Matrice.o -c ${CPP}Matrice.cpp

${OBJ}lib.a:
	${CXX} ${GNU} -w -c librairie/*.cpp
	mv ${mylib} librairie/
	ar -r ${OBJ}lib.a librairie/*.o

clean:
	rm -f ${OBJ}*.o *~
mrproper: clean
	rm ./${projet}

re: clean ${projet}
