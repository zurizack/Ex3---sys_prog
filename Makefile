OBJECTS=isort.o

test: $(OBJECTS)
	gcc -g -ansi -Wall -pedantic $(OBJECTS) -o isort

isort: isort.o
	gcc -Wall -ansi -pedantic isort.o -o isort

isort.o: isort.c isort.h
	gcc -g -c -ansi -Wall -pedantic isort.c -o isort.o

clean:
	rm -f $(OBJECTS) isort
