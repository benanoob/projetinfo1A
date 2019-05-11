CC = clang
CFLAGS = -Wall -Wextra -g -I include
LFAGS = -lm

testtas : testtas.o tas.o graphe.o
	$(CC) testtas.o tas.o graphe.o -o testtas $(LFLAGS)

testtas.o : testtas.c
	$(CC) testtas.c -c $(CFLAGS)

tas.o : tas.c
	$(CC) tas.c -c $(CFLAGS)

graphe.o: graphe.c
	$(CC) graphe.c -c $(CFLAGS)

clean :
	rm -f *.o testtas
