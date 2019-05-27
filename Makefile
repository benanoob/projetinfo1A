CC = gcc
CFLAGS = -Wall -Wextra -g -I include
LFLAGS = -lm


astarte : astarte.o graphe.o tas.o hachage.o
	$(CC) astarte.o graphe.o tas.o hachage.o -o astarte $(LFLAGS)

testtas : graphe.o testtas.o tas.o
	$(CC) graphe.o testtas.o tas.o  -o testtas $(LFLAGS)

hachage : graphe.o hachage.o
	$(CC) graphe.o hachage.o  -o hachage $(LFLAGS)
	
hachage.o : hachage.c
	$(CC) hachage.c -c $(CFLAGS)

astarte.o : astarte.c
	$(CC) astarte.c -c $(CFLAGS)

testtas.o : testtas.c
	$(CC) testtas.c -c $(CFLAGS)

tas.o : tas.c
	$(CC) tas.c -c $(CFLAGS)

graphe.o: graphe.c
	$(CC) graphe.c -c $(CFLAGS)

clean :
	rm -f *.o testtas astarte hachage
