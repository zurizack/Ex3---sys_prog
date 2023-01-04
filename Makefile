OBJECTS1=isort.o
OBJECTS2=txtfind.o

all: test isort txtfind

test: $(OBJECTS1) $(OBJECTS2)
	gcc -g -ansi -Wall -pedantic $(OBJECTS1) -o isort
	gcc -g -ansi -Wall -pedantic $(OBJECTS2) -o txtfind

isort: isort.o
	gcc -Wall -ansi -pedantic isort.o -o isort

isort.o: isort.c isort.h
	gcc -g -c -ansi -Wall -pedantic isort.c -o isort.o

txtfind: txtfind.o
	gcc -Wall -ansi -pedantic txtfind.o -o txtfind

txtfind.o: txtfind.c txtfind.h
	gcc -g -c -ansi -Wall -pedantic txtfind.c -o txtfind.o


clean:
	rm -f $(OBJECTS1) isort $(OBJECTS2) txtfind
