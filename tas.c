#include "graphe.h"
#include "tas.h"
#include <stdlib.h>


void afficheTas(T_SOMMET** tas,int n){
  int i;
  for (i=0;i<n;i++){
    affiche_sommet(tas[i]);
  }
}

T_SOMMET** creerTas(int n){
  return(calloc(n,sizeof(T_SOMMET*)));
}

void augmenteTas(T_SOMMET** tas,int n){
  T_SOMMET* pere = tas[(n-1)/2];
  T_SOMMET* fils = tas[n-1];
  int i = n-1;

  if (pere->F < fils->F){
    return;
  }
  do{
    tas[(i-1)/2] = fils;
    tas[i] = pere;
    i = (i-1)/2;
    fils = tas[i];
    pere = tas[(i-1)/2];
  }
  while (pere->F > fils->F);
}

void descendreTas (T_SOMMET** tas, int n) {
  int  i = 0;
  T_SOMMET* fils1 = tas[2*(i+1)];
  T_SOMMET* fils2 = tas[2*(i+1) - 1];
  T_SOMMET* pere  = tas[i];
  while((pere->F > fils1->F || pere->F > fils2->F) && i<n){
    if (fils1->F < fils2->F){
      tas[2*(i+1)] = pere;
      tas[i] = fils1;
    }
    else{
      tas[2*(i+1) - 1] = pere;
      tas[i] = fils2;
    }
    i = 2*(i+1) - 1;
    fils1 = tas[2*(i+1)];
    fils2 = tas[2*(i+1) - 1];
    pere = tas[i];
  }
}

void supprimeSommetTas(T_SOMMET** tas, int n){
  T_SOMMET* temp = tas[0];
  tas[0] = tas [n-1];
  tas[n-1] = temp;
  descendreTas(tas,n-2);
}

T_SOMMET* popTas(T_SOMMET** tas, int n){
  T_SOMMET* ret = tas[0];
  supprimeSommetTas(tas,n);
  return(ret);
}

void libereTas(T_SOMMET** tas){
  free(tas);
}
