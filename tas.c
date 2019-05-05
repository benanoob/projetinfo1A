void afficherTas(T_SOMMET* tas,int n){
  for (i=0,i<n,i++){
    affiche_sommet(tas[i]);
  }
}

T_SOMMET* creerTas(int n){
  return(calloc(n,sizeof(T_SOMMET)));
}

void augmenteTas(T_SOMMET* tas, n){
  int pere = tas[(n-1)/2];
  int fils = tas[n-1];
  int i = n-1;

  if (pere<fils){
    return;
  }
  do{
    tas[(i-1)/2] = fils;
    tas[i] = pere;
    i = (i-1)/2;
    fils = tas[i];
    pere = tas[(i-1)/2];
  }
  while (pere>fils);
}

void descendreTas (int* tas, int n) {
  int  i = 0;
  int fils1 = tas[2*(i+1)];
  int fils2 = tas[2*(i+1) - 1];
  int pere  = tas[i];
  //printf("pere: %d   fils1: %d    fils2: %d \n",pere,fils1,fils2);

  while((pere>fils1 || pere>fils2) && i<n){
    if (fils1<fils2){
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

void supprimeSommetTas(T_SOMMET* tas, int n){
  T_SOMMET* temp = tas[0];
  tas[0] = tas [n-1];
  tas[n-1] = temp;
  descendreTas(tas,n-2);
}

T_SOMMET* retourneEtSupprimeSommetTas(T_SOMMET* tas, int n){
  T_SOMMET ret = tas[0];
  supprimeSommetTas(tas,n);
  return(ret);
}
void libereTas(T_SOMMET* tas){
  free(tas);
}
