#include "liste.h"

typedef struct { char* nom; char* line; double x,y ; L_ARC voisins;} T_SOMMET ; //avec x,y les coordonnées

typedef struct { int arrivee; double cout; } T_ARC ;

typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC; //liste des suivants immédiats



