#include "tas.h"
#include "graphe.h"
int main(){
  int nbSommet = 0;
  T_SOMMET** tas = creerTas(15);
  T_SOMMET* graphe = ouvrir_fichier ("data/graphe1.txt",&nbSommet);
  printf("il y a %d sommets \n", nbSommet);
  //afficher_graphe(graphe,nbSommet);

  //creation tas de test

  tas[0] = & graphe[0];
  tas[0]->F = 0;

  tas[1] = & graphe[1];
  tas[1]->F = 1;

  tas[2] = & graphe[2];
  tas[2]->F = 2;

  tas[3] = & graphe[3];
  tas[3]->F = 3;

  tas[4] = & graphe[4];
  tas[4]->F = 4;


  printf(" \n \n tas original\n");
  afficheTas(tas,nbSommet);


  /* printf("\n \n tas augmenté \n"); */
  /* augmenteTas(tas,4); */
  /* afficheTas(tas,4); */
  // augmente tas ok

  /* printf("tas descendu\n"); */
  /* descendreTas(tas,5); */
  /* afficheTas(tas,5); */

  /* printf("\ntas sans le sommet \n"); */
  /* supprimeSommetTas(tas,5); */
  /* afficheTas(tas,5); */
  /* //libereTas(tas); */

  printf("\n on fait pop le sommet du tas\n");
  T_SOMMET* sommetRetourné = popTas(tas,5);
  affiche_sommet(sommetRetourné);

  printf("et le tas \n");
  afficheTas(tas,5);

}
