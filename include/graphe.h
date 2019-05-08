typedef struct { int arrivee; double cout; } T_ARC ;

typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC; //liste des suivants imm�diats

typedef struct { char* nom; char* line; double x,y ;int ListeFermee; L_ARC voisins;int F;} T_SOMMET ; //avec x,y les coordonn�es

//fonctions

T_SOMMET* creation_graphe(int nbsommet);

void creation_sommet(T_SOMMET* psommet,char* nom,char* line, double longi, double lat);

void affiche_arc(L_ARC voisins);

void creation_sommet(T_SOMMET* psommet,char* nom,char* line, double longi, double lat);

void affiche_sommet(T_SOMMET* psommet);

void afficher_graphe(T_SOMMET* graphe,int nbsommet);

void creation_arc(int numdepart, int numarrivee, double cout,T_SOMMET* graphe);

T_SOMMET* ouvrir_fichier(char* nomfichier,int* pnbsommet);

void suppression_arc(L_ARC arc);

void suppression_graphe(T_SOMMET* graphe,int nbsommet);
