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
    if(*(tas+i)==(graphe+search)){
      *posdanstas=i;
      return(1);// est present
    }
  }
  *posdanstas=-1;
  return(0);// n'est pas present
}

// evalue H
double H(int sommets, int sommeta, T_SOMMET* graphe){
  //printf("debut H\n");
  double xa, xs, ya, ys;
  xa=(graphe+sommeta)->x;
  ya=(graphe+sommeta)->y;
  xs=(graphe+sommets)->x;
  ys=(graphe+sommets)->y;
  //printf("on a trouve les xa:%lf,ya:%lf,xb:%lf,yb:%lf",xa,ya,xs,ys);
  double diff = fabs(xa-xs) + fabs(ya-ys);
  //printf("%lf\n",norme);
  //printf("%lf\n",sqrt(norme));
  return(diff/5); //par 4 meilleur ?
  //printf("fin H\n");
}

//revoie le cout pour aller d'un sommet à arrivée dans le cas où arrivée est son voisin ou bien -1 si arrivée n'est pas voisin de départ
double cout(int depart,int arrivee,T_SOMMET* graphe){
  //printf("debut cout\n");
  L_ARC arc=(graphe+depart)->voisins;
  //printf("fin prem\n");
  while(arc!=NULL){
    if((arc->val).arrivee==arrivee){
      printf("cout: %lf\n",(arc->val).cout);
      return((arc->val).cout);
    }
    arc=arc->suiv;
  }
  //printf("fincout2\n");
  return(1000000000);
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
  //printf("pas trouve");
return(nbsommet+1);}

/*void initialiser_arrivee_depart_recherche_simple(){
  printf("\nQuel est votre point de depart\n");
  char depart[20];
  scanf("%s",depart);
  //printf("%s%d",depart,1);
  //printf("%s",(graphe+1)->nom);
  int d=trouver_sommet(depart,graphe,nbsommet);
  if(d>nbsommet){
    printf("%d\n",d-nbsommet);
    return(0);
  }

  printf("Quel est votre point d'arrivee\n");
  char arrivee[20];
  scanf("%s",arrivee);
  int a=trouver_sommet(arrivee,graphe,nbsommet);
  if(a>nbsommet){
    return(0);
  }
}
*/

void affiche_chemin(T_SOMMET* graphe, int depart, int arrivee,int nbsommet){
  int sommet[nbsommet];
  int isommet=0;
  do{
    //printf("on passe par %d \n",arrivee /*(graphe+depart)->nom*/);
    printf("arrivee = %d \n", arrivee);
    sommet[isommet]=arrivee;
    arrivee=(graphe+arrivee)->pere;
    isommet+=1;
    //affiche_sommet(graphe+arrivee);
  }
	while(depart!=arrivee && arrivee>=0 );
  printf("Chemin à emprunter:\n");
  //printf("isommet = %d",isommet);
  int i;
  for(i=isommet-1;i>=0;i--){
    printf("i = %d\n",sommet[i]);
    //printf("%s -> ",(graphe+sommet[i])->nom );
  }
  printf("\non arrive à %d \n avec un cout de %lf\n",sommet[0]/*(graphe+arrivee)->nom*/,(graphe+sommet[0])->G);
	}

int main(){
  //initialisation
  int nbsommet;
  T_SOMMET* graphe=ouvrir_fichier("data/grapheNewYork.csv",&nbsommet,0);
  //afficher_graphe( graphe, nbsommet);
  /*int i;
  printf("voici les sommets:\n");
  for(i=0;i<nbsommet;i++){
    printf("%s ",(graphe+i)->nom);
  }
  */

  printf("\nQuel est votre point de depart\n");
  int d;
  scanf("%d",&d);
  if(d>nbsommet){
    printf("%d\n",d-nbsommet);
    return(0);
  }

  printf("Quel est votre point d'arrivee\n");
  int a;
  scanf("%d",&a);
  if(a>nbsommet){
    return(0);
  }
  //int d=3;
  //int a=7;
  // debut boucle initialisation F


  /* int s=0; */
  /* for (s=0;s<nbsommet;s++){ */
  /*   if(s!=a && s!= d && cout(d,s,graphe)>=0){ */
  /*     (graphe+s)->F=H(s,a,nbsommet)+cout(d,s,graphe);//F(k)←G(k)←H(k, a)←∞ */
  /*   } */

  /* } */

  //initialisation tas
    T_SOMMET** tas=creerTas(nbsommet);
    int n_tas=0;
    *tas=graphe+d;// ajouter depart au tas
    n_tas=1;
    (graphe+d)->ListeOuverte = 0;
    int k=d; //init k (sommet en cours) au depart
    (graphe+k)->F=H(k,a,graphe); // F = heuristique car G =0
    (graphe+k)->G=0;

    //algorithme iteratif
    while(k!=a && n_tas!=0){
      //printf("debut grand while\n");
      //afficheTas(tas,n_tas);
      //augmenteTas(tas,n_tas);// on remet le tas en forme de tas
T_SOMMET* stockage =tas[0];//premier element du tas: le meilleur chemin
      k=stockage-graphe;//on cherche sa position dans le graphe plus commode à manipuler
      if(k>nbsommet){
        printf("probleme k\n"); //recherche une erreur majeure
        return(1);
      }


      if (k!=a){//tant qu'on est pas arrivé
        (graphe+k)->ListeFermee=1; //ajout k a la LF
        supprimeSommetTas(tas, &n_tas); // supprime k de la LO
        (graphe+k)->ListeOuverte = -1;
        //printf("k: %d",k);
        L_ARC arc=(graphe+k)->voisins; // liste des voisins
        while(arc!=NULL){
          //printf("debut while\n");
          //affiche_sommet(graphe+k);
          int s=(arc->val).arrivee;//on considère le sommet d'arrivee s
          //printf("s:%d, suiv:%d\n",s,arc->suiv->val.arrivee);
          if ((graphe+s)->ListeFermee==0){
            //int posdanstas=0;
            if((graphe+s)->ListeOuverte == -1){//pas dans liste ouverte
              //printf("pasdanslisteouverte\n");
              (graphe+s)->pere=k;
              //printf("bon_pour_pere\n");
              (graphe+s)->G=(graphe+k)->G+cout(k,s,graphe);
              //printf("miseajourG\n");
              (graphe+s)->F=(graphe+s)->G+H(s,a,graphe);
              //printf("miseajourF\n");
              *(tas+n_tas)=graphe+s;
              //printf("augmentetas,n_tas: %d\n",n_tas);
              (graphe+s)->ListeOuverte=augmenteTas(tas,&n_tas); // on stock la postition dans le tas pour ne pas la chercher si on a besoin de supprimer cet elt du tas plus tard
              //printf("fincasLO, n_tas: %d \n",n_tas);

              //printf("le sommet k est en pos %d dans le tas\n",(graphe+s)->ListeOuverte);
              //affiche_sommet(graphe+s);
              //printf("\n #####");
              //afficheTas(tas,n_tas);

              }

            else{
              //printf("sinon\n");
              //printf("onvafaireif\n");
              if(((graphe+k)->G+cout(k,s,graphe)) <(graphe+s)->G)//s'il existe un meilleur chemin
              {
                //printf("il y a un meilleur chemin\n");
                (graphe+s)->pere=k;
                (graphe+s)->G=(graphe+k)->G+cout(k,s,graphe);

                //printf("le sommet k est en pos %d dans le tas\n",(graphe+s)->ListeOuverte);
                //affiche_sommet(graphe+s);
                //printf("\n #####");
                //afficheTas(tas,n_tas);

                supprimerElementYTas(tas,&n_tas,(graphe+s)->ListeOuverte);//fct qui marche pas mdr, benano
                (graphe+s)->F=(graphe+s)->G+H(s,a,graphe);
                *(tas+n_tas)=graphe+s;
                augmenteTas(tas,&n_tas);
                //printf("fin cas meilleur chemin\n");
              }
              }
            }
            arc=arc->suiv;
          }//fin parcours voisin

        }//fin si k !=a
      }//fin while principal


      //afficheTas(tas,n_tas);
      printf("\n%d,%d\n",d,a);
      //printf("%s\n"(*tas)->nom);
      //printf("%s\n"(*tas)->);
      affiche_chemin(graphe,d,a,nbsommet);
      suppression_graphe(graphe,nbsommet);
      libereTas(tas);
      return(1);
}
