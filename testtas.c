#include "tas.h"
#include "graphe.h"
int main(){
  int nbSommet = 0;
  T_SOMMET** tas = creerTas(15);
  T_SOMMET* graphe = ouvrir_fichier ("data/graphe1.txt",&nbSommet);
  printf("il y a %d sommets \n", nbSommet);
  //afficher_graphe(graphe,nbSommet);

  //creation tas de test

  tas[0] = & graphe[0]; //A
  tas[0]->F = 0;

  tas[1] = & graphe[1];//B
  tas[1]->F = 1;

  tas[2] = & graphe[2]; //C
  tas[2]->F = 2;

  tas[3] = & graphe[3];//D
  tas[3]->F = 3;

  tas[4] = & graphe[4]; //E
  tas[4]->F = 4;


  printf(" \n \n tas original\n");
  afficheTas(tas,5);


  // printf("\n \n tas augmenté \n"); 
  // int tailleTas = 3;
  // int nouvellePos = augmenteTas(tas,&tailleTas); 
  // afficheTas(tas,4); 
  // printf("la nouvelle pos est %d",nouvellePos);

  /* printf("tas descendu\n"); */
  /* descendreTas(tas,5); */
  /* afficheTas(tas,5); */

  /* printf("\ntas sans le sommet \n"); */
  /* supprimeSommetTas(tas,5); */
  /* afficheTas(tas,5); */
  /* //libereTas(tas); */

  /* printf("\n on fait pop le sommet du tas\n"); */
  /* T_SOMMET* sommetRetourné = popTas(tas,5); */
  /* affiche_sommet(sommetRetourné); */

  /* printf("et le tas \n"); */
  /* afficheTas(tas,5); */

  int n_tas = 5;
  printf("on supprime l'elt spécifié puis on desend le tas restant\n");
  supprimerElementKTas(tas,&n_tas,2);

  printf("tas final \n");
  afficheTas(tas,n_tas);



}
