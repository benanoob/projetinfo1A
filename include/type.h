
#ifndef TYPE_H
#define TYPE_H



typedef struct { int arrivee; double cout; } T_ARC ;

typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC; //liste des suivants imm�diats

typedef struct { char* nom; char* line; double x,y ;int ListeFermee;int ListeOuverte; L_ARC voisins;double F; int pere; double G;} T_SOMMET ; //avec x,y les coordonn�es

typedef struct table_hach{T_SOMMET* val; struct table_hach* suiv;}* table;
#endif
