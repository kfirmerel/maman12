magic: magic.o utils.o
	gcc -ansi -Wall -pedantic magic.o utils.o -o magic

magic.o: magic.c utils.h
	gcc -c -ansi -Wall -pedantic magic.c -o magic.o

utils.o: utils.c utils.h
	gcc -c -ansi -Wall -pedantic utils.c -o utils.o
clean:
	rm -f *.o magic
