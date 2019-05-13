#include "tas.h"
#include " graphe.h "
int main(){
  int nbSommet = 0;
  T_SOMMET** tas = creerTas(15);
  T_SOMMET* graphe = ouvrir_fichier ("data/graphe1.txt",&nbSommet);
  printf("%d", nbSommet);
  afficher_graphe(graphe,nbSommet);

  // tas[0] = & graphe[0];
  // printf("%d %d",tas[0],&graphe[0]);
  // printf("coucou\n");
  // affiche_sommet(&graphe[0]);
  // tas[0]->F = 6;
  // printf("salut\n");

  // tas[1] = & graphe[1];
  // tas[1]->F = 2;

  // tas[2] = & graphe[2];
  // tas[2]->F = 3;

  // tas[3] = & graphe[3];
  // tas[3]->F = 0;

  // tas[4] = & graphe[4];
  // tas[4]->F = 9;

}
