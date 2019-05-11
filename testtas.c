#include "tas.h"
int main(){
  int nbSommet;
  T_SOMMET** tas = creerTas(15);
  T_SOMMET* graphe = ouvrir_fichier ("data/graphe1.txt",& nbSommet);
  printf("graphe cree");

  tas[0] = & graphe[0];
  tas[0]->F = 6;

  tas[1] = & graphe[1];
  tas[1]->F = 2;

  tas[2] = & graphe[2];
  tas[2]->F = 3;

  tas[3] = & graphe[3];
  tas[3]->F = 0;

  tas[4] = & graphe[4];
  tas[4]->F = 9;

}
