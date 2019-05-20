CC = clang
CFLAGS = -Wall -Wextra -g -I include
LFLAGS = -lm


astarte : astarte.o graphe.o tas.o
	$(CC) astarte.o graphe.o tas.o -o astarte $(LFLAGS)

testtas : graphe.o testtas.o tas.o
	$(CC) graphe.o testtas.o tas.o  -o testtas $(LFLAGS)

astarte.o : astarte.c
	$(CC) astarte.c -c $(CFLAGS)

testtas.o : testtas.c
	$(CC) testtas.c -c $(CFLAGS)

tas.o : tas.c
	$(CC) tas.c -c $(CFLAGS)

graphe.o: graphe.c
	$(CC) graphe.c -c $(CFLAGS)

clean :
	rm -f *.o testtas
