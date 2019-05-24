#include "tas.h"
#include "graphe.h"

void afficheTas(T_SOMMET** tas,int n){
  int i;
  for (i=0;i<n;i++){
    //affiche_sommet(tas[i])
    if (tas[i] != NULL){
    printf("nom %s\n",tas[i]->nom);
  }
  	/*printf("line %s\n",tas[i]->line);
  	printf("x %lf\n",tas[i]->x);
  	printf("y %lf\n",tas[i]->y);
    printf("\n");*/
  }
}

T_SOMMET** creerTas(int n){
  return(calloc(n,sizeof(T_SOMMET*)));
}

int augmenteTas(T_SOMMET** tas,int* pn){ //retourne la position de l'elt dans le tas 
  int n = *pn;
  *pn+=1;
  int i = n; //attention ici erreure corrigée, l'elt a monter est placé en [n] et pas [n-1]dernier element avant augmentation
  T_SOMMET* pere = tas[(i-1)/2];
  T_SOMMET* fils = tas[i];
  //printf("point1\n");
  if (pere->F < fils->F){
    return(i);
  }
  //printf("point2.5\n");
  do{
    /* printf("pere\n"); */
    /* affiche_sommet(pere); */
    /* printf("fils\n"); */
    /* affiche_sommet(fils); */
    /* printf("%d\n",i); */
    //printf("point2\n");
    tas[(i-1)/2] = fils;
    tas[i] = pere;
    i = (i-1)/2;
    fils = tas[i];
    pere = tas[(i-1)/2];
    //printf("point3\n");
  }
  while (i>=0 && (pere->F > fils->F));

  return(i);

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
 
  while((i<n && (j<n||k<n) )&& ( (fils1 !=NULL &&pere->F > fils1->F) || (fils2!=NULL && pere->F > fils2->F) ) ){
    printf("le tas, i = %d \n",i);
    afficheTas(tas,n);
    printf("i= %d ; j = %d ; k = %d \n",i,j,k);
    if (j>n-1){
      return;
    }
    else if (k>n-1){
      if (fils1->F < pere->F){
        printf("echange fils 1 et pere, il n'y a qu'un fils\n");
        tas[i] = fils1;
        tas[j] = pere;
        i = 2*(i+1)-1;
      }
      else{
        return;
      }
    }
    else if (fils1<fils2){
      printf("echange fils 1 et pere, il existe 2 fils\n");
      tas [i] = fils1;
      tas[j] = pere;
      i = 2*(i+1)-1;
    }
    else{
      printf("echange fils 2 et pere, il y a 2 fils\n");
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
  *pn -= 1;
  descendreTas(tas,n-1);
}

T_SOMMET* popTas(T_SOMMET** tas, int* pn){
  T_SOMMET* ret = tas[0];
  supprimeSommetTas(tas,pn);
  return(ret);
}

void libereTas(T_SOMMET** tas){
  free(tas);
}

void supprimerElementYTas(T_SOMMET** tas, int* pn, int y){
  T_SOMMET* temp = tas[y];
  int n = *pn;
  tas[y] = tas[n-1];
  tas[n-1] = temp;
  *pn-=1;
  n = *pn;
  //printf("n = %d, k = %d \n",n,k);
  //descendreTas(tas+k,n-k-1); surtout pas, cela ne respecte pas la structure de tas
  int i = y;
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
 
  while((i<n && (j<n||k<n) )&& ( (fils1 !=NULL &&pere->F > fils1->F) || (fils2!=NULL && pere->F > fils2->F) ) ){
    printf("le tas, i = %d \n",i);
    afficheTas(tas,n);
    printf("i= %d ; j = %d ; k = %d \n",i,j,k);
    if (j>n-1){
      return;
    }
    else if (k>n-1){
      if (fils1->F < pere->F){
        printf("echange fils 1 et pere, il n'y a qu'un fils\n");
        tas[i] = fils1;
        tas[j] = pere;
        i = 2*(i+1)-1;
      }
      else{
        return;
      }
    }
    else if (fils1<fils2){
      printf("echange fils 1 et pere, il existe 2 fils\n");
      tas [i] = fils1;
      tas[j] = pere;
      i = 2*(i+1)-1;
    }
    else{
      printf("echange fils 2 et pere, il y a 2 fils\n");
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
