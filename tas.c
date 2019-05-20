#include "tas.h"
#include "graphe.h"

void afficheTas(T_SOMMET** tas,int n){
  int i;
  for (i=0;i<n;i++){
    affiche_sommet(tas[i]);
  }
}

T_SOMMET** creerTas(int n){
  return(calloc(n,sizeof(T_SOMMET*)));
}

void augmenteTas(T_SOMMET** tas,int* pn){
  int n = *pn;
  int i = n-1;
  T_SOMMET* pere = tas[(i-1)/2];
  T_SOMMET* fils = tas[i];

  if (pere->F < fils->F){
    return;
  }
  do{
    /* printf("pere\n"); */
    /* affiche_sommet(pere); */
    /* printf("fils\n"); */
    /* affiche_sommet(fils); */
    /* printf("%d\n",i); */
    tas[(i-1)/2] = fils;
    tas[i] = pere;
    i = (i-1)/2;
    fils = tas[i];
    pere = tas[(i-1)/2];
  }
  while (i>=0 && (pere->F > fils->F));
  *pn+=1;
}



void descendreTas (T_SOMMET** tas, int n) {
  int i = 0;
  int j = 2*(i+1) -1;
  int k = 2*(i+1);
  //bordel
  T_SOMMET* fils1 = tas[j];
  T_SOMMET* fils2 = tas[k];
  T_SOMMET* pere = tas[i];
  if (pere == NULL){
    return;
  }
  if (fils1 == NULL){
    return;
  }
  while((i<n && (j<n||k<n) )&& (pere->F > fils1->F || pere->F > fils2->F) ){
    if (j>n-1){
      return;
    }
    else if (k>n-1){
      if (fils1 < pere){
        tas[i] = fils1;
        tas[j] = pere;
        i = 2*(i+1)-1;
      }
      else{
        return;
      }
    }
    else if (fils1<fils2){
      tas [i] = fils1;
      tas[j] = pere;
      i = 2*(i+1)-1;
    }
    else{
      tas[i] = fils2;
      tas[k] = pere;
      i = 2*(i+1);
    }
    j = 2*(i+1)-1;
    k = 2*(i+1);
    fils1 = tas[j];
    fils2 = tas[k];
    pere = tas[i];

  }
}


void supprimeSommetTas(T_SOMMET** tas, int* pn){
  int n = *pn;
  T_SOMMET* temp = tas[0];
  tas[0] = tas [n-1];
  tas[n-1] = temp;
  descendreTas(tas,n-1);
  *pn -= 1;
}

T_SOMMET* popTas(T_SOMMET** tas, int* pn){
  T_SOMMET* ret = tas[0];
  supprimeSommetTas(tas,pn);
  return(ret);
}

void libereTas(T_SOMMET** tas){
  free(tas);
}

void supprimerElementKTas(T_SOMMET** tas, int* pn, int k){
  T_SOMMET* temp = tas[k];
  int n = *pn;
  tas[k] = tas[n-1];
  tas[n-1] = temp;
  descendreTas(tas,n-1);
  *pn-=1;
}
