OBJECTS1=isort.o
OBJECTS2=txtfind.o
#isort txtfind
all: isort txtfind

test: $(OBJECTS1) $(OBJECTS2)
	gcc -g -ansi -Wall -pedantic $(OBJECTS1) -o isort
	gcc -g -ansi -Wall -pedantic $(OBJECTS2) -o txtfind

isort: isort.c isort.h
	gcc -g -c -Wall -ansi -pedantic isort.c -o isort

##isort.o: isort.c isort.h
##gcc -g -c -ansi -Wall -pedantic isort.c -o isort.o

txtfind: txtfind.c txtfind.h
	gcc -g -c -Wall -ansi -pedantic txtfind.c -o txtfind

##txtfind.o: txtfind.c txtfind.h
##gcc -g -c -ansi -Wall -pedantic txtfind.c -o txtfind.o


clean:
	rm -f $(OBJECTS1) isort $(OBJECTS2) txtfind
