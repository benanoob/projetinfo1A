#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tas.h"
#include "graphe.h"



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
int main(){
  //initialisation
  int nbsommet;
  T_SOMMET* graphe=ouvrir_fichier("data/graphe2.txt",&nbsommet,0);
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
            if((graphe+s)->ListeOuverte == 0){//pas dans liste ouverte
              //printf("pasdanslisteouverte\n");
              (graphe+s)->pere=k;
              //printf("bon_pour_pere\n");
              (graphe+s)->G=(graphe+k)->G+cout(k,s,graphe);
              //printf("miseajourG\n");
              (graphe+s)->F=(graphe+s)->G+H(s,a,graphe);
              //printf("miseajourF\n");
              *(tas+n_tas)=graphe+s;
              //printf("augmentetas,n_tas: %d\n",n_tas);
              (graphe+s)->ListeOuverte = 1;
               augmenteTas(tas,&n_tas); // on stock la postition dans le tas pour ne pas la chercher si on a besoin de supprimer cet elt du tas plus tard
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
                int positionTas = chercheDansTas(tas,n_tas,graphe,k); 
                printf("position dans le tas a delete est %d \n ",positionTas);
                supprimerElementYTas(tas,&n_tas,positionTas);//fct qui marche pas mdr, benano
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
