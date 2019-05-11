typedef struct { int arrivee; double cout; } T_ARC ;

typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC; //liste des suivants imm�diats

typedef struct { char* nom; char* line; double x,y ;int ListeFermee; L_ARC voisins;int F;} T_SOMMET ; //avec x,y les coordonn�es

