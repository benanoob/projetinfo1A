#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tas.h"
#include "graphe.h"


//on a besoin de savoir si un sommet est présetn dans un tas
int cherche_dans_tas(T_SOMMET** tas,T_SOMMET* graphe,int search,int n_tas,int* posdanstas ){
  int i=0;
  for (i=0;i<n_tas;i++){
    if(*(tas+i)==(graphe+search){
      return(1);// est present
    }
  }
  return(0);// n'est pas present
}

// evalue H
double H(int sommets, int sommeta, T_SOMMET* graphe){
  double xa, xs, ya, ys;
  xa=(graphe+sommeta)->x;
  ya=(graphe+sommeta)->y;
  xs=(graphe+sommets)->x;
  ys=(graphe+sommets)->y;
  double norme=(xa-xs)*(xa-xs)+(ya-ys)*(ya-ys);
  return(sqrt(norme));
}

//revoie le cout pour aller d'un sommet à arrivée dans le cas où arrivée est son voisin ou bien -1 si arrivée n'est pas voisin de départ
double cout(int depart,int arrivee,T_SOMMET* graphe){
  L_ARC arc=(graphe+depart)->voisins;
  while(arc!=NULL){
    if((arc->val).arrivee==arrivee){
      return((arc->val).cout);
    }
  }
  return(-1);
}


//initialise le tableau dans lequel on crée le tas afin que tous les sommets* du graphe y soient déjà pointés
void init_tas(T_SOMMET** tas,T_SOMMET* graphe,int nbsommet){
  int i=0;
  for (i=0;i<nbsommet;i++){
    *(tas+i)=graphe+i;
  }

}


//cherche un sommet dans le graphe par son nom et en retourne le numero 
int trouver_sommet(char* depart,T_SOMMET* graphe,int nbsommet){
  int a=0;
  while(a<nbsommet){
    if(strcmp(depart,(graphe+a)->nom)==0){
      return(a);
    }
    a+=1;
  }
return(nbsommet+1);}


int main(){
  //initialisation
  int nbsommet;
  T_SOMMET* graphe=ouvrir_fichier("graphe1.txt",&nbsommet);

  printf("Quel est votre point de depart\n");
  char depart[20];
  scanf("%s",depart);
  int d=trouver_sommet(depart,graphe,nbsommet);

  printf("Quel est votre point d'arrivee\n");
  char arrivee[20];
  scanf("%s",arrivee);
  int a=trouver_sommet(arrivee,graphe,nbsommet);

  // debut boucle initialisation F

  (graphe+d)->F=H(d,a,graphe);

  int s=0;
  for (s=0;s<nbsommets;s++){
    if(s!=a && s!= d && cout(d,s,graphe)>=0){
      (graphe+s)->F=H(s,a,nbsommet)+cout(d,s,graphe);//F(k)←G(k)←H(k, a)←∞
    }

    return(1);
  }

  //initialisation tas
    T_SOMMET** tas=creerTas(nbsommet);
    int n_tas=0;
    init_tas(tas,graphe,nbsommet);
    T_SOMMET** stockage=tas;
    *tas= *(tas+d);
    *(tas+d)=stockage;
    int k=d;

    //algorithme iteratif
    while(k!=a && nbsommet!=0){
      augmenteTas(tas,n_tas);// on remet le tas en forme de tas
      T_SOMMET* stockage =popTas(tas,n_tas);//premier element du tas: le meilleur chemin
      k=stockage-graphe;//on cherche sa position dans le graphe plus commode à manipuler
      if (k!=a){//on est pas arrivé
        (graphe+k)->ListeFermee=1;
        L_ARC arc=(graphe+k)->voisins;
        while(arc!=NULL){
          int s=graphe(arc->val).arrivee;//on considère le sommet d'arrivee s
          if ((graphe+s)->ListeFermee==0){
            int posdanstas=0;

            if(cherche_dans_tas(tas,graphe,s,n_tas,&posdanstas )==0){//pas dans liste ouverte
              T_SOMMET* stock=*(tas+(k+1)/2);
              *(tas+(k+1)/2)=graphe+s;
              *(tas+posdanstas)=stock;//Pere(s)←k
              (graphe+k)->F=((graphe+k)->F)-H(k, a, graphe)+ cout(k,s,graphe)+ H(s,a,graphe);
              stock=*(tas+n_tas+1);
              *(tas+n_tas+1)=*(tas+posdanstas);
              *(tas+posdanstas)=stock;//on a inséré le nouveau sommet dans le tas
		n_tas=max(n_tas,posdanstas);
		n_tas=n_tas+1;
              augmentetas(tas,n_tas);
            }

            else{
              if(((graphe+k)->F)-H(k,a,graphe)+cout(k,s,graphe)<((graphe+s)->F)-H(s,a,graphe)){
                T_SOMMET* stock=*(tas+(k+1)/2);
                *(tas+(k+1)/2)=graphe+s;
                *(tas+posdanstas)=stock;//Pere(s)←k
		supprimeSommetTas(tas,posdanstas);
		(*(tas+posdanstas))->F;
		
              	(graphe+k)->F=((graphe+k)->F)-H(k, a, graphe)+ cout(k,s,graphe)+ H(s,a,graphe);
		n_tas=n_tas+1;
		augmenteTas(tas,n_tas);
		
              }
            }
          }
          arc=arc->suiv;
        }
      }
}

void affiche_chemin(tas tas,int nbsommet){
	int i=0;
	double cout=0
	while(i!=1){
		printf("on passe par %s \n",(*(tas+i))->nom);
		cout+=(*(tas+i))->cout;
		if(2*(i+1)-1>=nbsommet){
			printf("vous voilà arrivé\n");
			i=1;}
		i=2*(i+1)-1;
	}
	printf("le cout est alors de %lf \n",cout);
	} 

    
