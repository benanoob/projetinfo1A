CC = clang
CFLAGS = -Wall -Wextra -g -I include
LFAGS = -lm

testtas : graphe.o testtas.o tas.o 
	$(CC) graphe.o testtas.o tas.o  -o testtas $(LFLAGS)

testtas.o : testtas.c
	$(CC) testtas.c -c $(CFLAGS)

tas.o : tas.c
	$(CC) tas.c -c $(CFLAGS)

graphe.o: graphe.c
	$(CC) graphe.c -c $(CFLAGS)

clean :
	rm -f *.o testtas
