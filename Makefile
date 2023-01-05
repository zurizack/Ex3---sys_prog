OBJECTS1 = isort.out
OBJECTS2 = txtfind.out

all: isort txtfind clean

test: $(OBJECTS1) $(OBJECTS2)
	gcc -g -ANSI -Wall -pedantic $(OBJECTS1) -o isort
	gcc -g -ANSI -Wall -pedantic $(OBJECTS2) -o txtfind


isort: isort.out
	gcc -Wall -ANSI -pedantic isort.out -o isort

isort.out: isort.c isort.h
	gcc -g -c -Wall -pedantic isort.c -o isort.out

txtfind: txtfind.out
	gcc -Wall -ANSI -pedantic txtfind.out -o txtfind

txtfind.out: txtfind.c txtfind.h
	gcc -g -c -Wall -pedantic txtfind.c -o txtfind.out

clean:
	rm -f isort.out txtfind.out 
##rm -f $(OBJECTS1) isort $(OBJECTS2) txtfind
