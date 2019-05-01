//structure

typedef struct { int arrivee; double cout; } T_ARC ;

typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC; //liste des suivants immédiats

typedef struct { char* nom; char* line; double x,y ; L_ARC voisins; int ListeFermee} T_SOMMET ; //avec x,y les coordonnées et ListeFermee un booleen qui donne l'appartenance à la liste fermée du sommet




//fonctions

T_SOMMET* creation_graphe(int nbsommet);
void creation_sommet(T_SOMMET* psommet,char* nom,char* line, double longi, double lat);
void creation_arc(int numdepart, int numarrivee, double cout,T_SOMMET* graphe);
void suppression_graphe(T_SOMMET* graphe,int nbsommet);
void affiche_arc(L_ARC voisins)
void afficher_graphe(T_SOMMET* graphe,int nbsommet)
void creation_arc(int numdepart, int numarrivee, double cout,T_SOMMET* graphe)

T_SOMMET* ouvrir_fichier(char* nomfichier,int* pnbsommet);







