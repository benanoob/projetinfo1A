#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"
#include <math.h>


T_SOMMET* creation_graphe(int nbsommet){
	return(calloc(nbsommet,sizeof(T_SOMMET)));
	}

/*cree le graphe: alloue dynamiquement le tableau qui contient les sommets*/

void creation_sommet(T_SOMMET* psommet,char* nom,char* line, double longi, double lat){
	psommet->nom=calloc(strlen(nom),sizeof(char));
	strcpy(psommet->nom,nom);
	psommet->line=calloc(strlen(line),sizeof(char));
	strcpy(psommet->line,line);
	psommet->x=longi;
	psommet->y=lat;
	psommet->ListeFermee=0;
	psommet->ListeOuverte=0;
	psommet->voisins=NULL;
	psommet->F=1000000000;
	psommet->G= 0;
	psommet->pere = -1;
	}

void affiche_arc(L_ARC voisins){
	while(voisins!=NULL){
		printf("mene au sommet %d\n",voisins->val.arrivee);
		printf("avec un cout de %lf\n",voisins->val.cout);
		voisins=voisins->suiv;
	}
}

void affiche_sommet(T_SOMMET* psommet){
	if (psommet ==NULL){
		printf("vide\n");
		return;
	}
	printf("nom %s\n",psommet->nom);
	printf("line %s\n",psommet->line);
	printf("x %lf\n",psommet->x);
	printf("y %lf\n",psommet->y);
	printf("ListeFermee %d\n",psommet->ListeFermee);
	printf("ListeOuverte %d\n",psommet->ListeOuverte);
	printf("rang du pere %d\n",psommet->pere);
	affiche_arc(psommet->voisins);
	printf("\n");
}

void afficher_graphe(T_SOMMET* graphe,int nbsommet){
	int i;
	for (i=0;i<nbsommet;i++){
		affiche_sommet( graphe+i);
	}
}

void creation_arc(int numdepart, int numarrivee, double cout,T_SOMMET* graphe){
	L_ARC listsuiv=(graphe+numdepart)->voisins;//on selectionne la liste de voisins associee a ce sommet de depart

	L_ARC new=calloc(1,sizeof(L_ARC));
	(new->val).arrivee=numarrivee;
	(new->val).cout=cout;
	new->suiv=NULL;
	if(listsuiv==NULL){
		(graphe+numdepart)->voisins=new;//on a ajoute notre nouvel arc ce qui cree la liste de successeurs
		}
	else{
		new->suiv=(graphe+numdepart)->voisins;
		(graphe+numdepart)->voisins=new;

		}
	}


T_SOMMET* ouvrir_fichier(char* nomfichier,int* pnbsommet,int metro){
	FILE* f;
	int numero,nbsommet,nbarc;
	double lat,longi ;
	char line[128] ;
	char mot[512] ;
	f=fopen(nomfichier,"r");
	if (f==NULL) {
		printf("Impossible d�ouvrir le fichier\n");
		exit(EXIT_FAILURE);
		}
	/* Lecture de la premiere ligne du fichier : nombre de sommet et nombre d�arcs */

	fscanf(f,"%d %d ",&nbsommet,&nbarc);

	T_SOMMET* graphe=creation_graphe(nbsommet);//cree le graphe
	if (graphe==NULL) {
		printf("Impossible de creer graphe\n");
		exit(EXIT_FAILURE);
		}
	*pnbsommet=nbsommet;
	/* Ligne de texte "Sommets du graphe" qui ne sert a rien */

	fgets(mot,511,f);

	T_SOMMET* psommet;

	// maintenant on parcourt tous les sommets
	for(psommet=graphe;psommet-graphe<nbsommet;psommet++){
		/* lecture d�une ligne de description d�un sommet */
		/* on lit d�abord numero du sommet, la position, le nom de la ligne */
		fscanf(f,"%d %lf %lf %s *c", &(numero), &(lat), &(longi), line);// *c : ne stocke pas la tabulation mais la supprime
		/* numero contient alors l�entier ou numero du sommet, lat et longi la position, line le nom de la ligne */
		/* Le nom de la station peut contenir des separateurs comme l�espace. On utilise plutot fgets dans ce cas */
		fgets(mot,511,f);
		while (mot[strlen(mot)-1]<32) {mot[strlen(mot)-1]=0; }/* mot contient le nom du sommet. */
		/*int v;
		for(v=0;v<32;v++){
			if(mot[v]!=" "){
				v=32;
			}
		}
		char mot2[32];
		int w=0;
		for (w=0;w<32;w++){
			mot2[w]=mot2[w+v];
		}*/
		creation_sommet( psommet, mot, line, longi, lat);
  }

	/*Pour sauter les lignes de commentaires, on peut simplement utiliser la fonction fgets sans utiliser la chaine de caracteres lue dans le fichier par */
	fgets(mot,511,f);

	int numdepart, numarrivee;
	double cout;

	//maintenant on rempli les arcs
	for(nbarc;nbarc>0;nbarc--){
		//lecture de: un entier : num�ro du sommet de d�part 2. un entier : num�ro du sommet d�arriv�e 3. un r�el : valeur ou co�t de l�arc
		fscanf(f,"%d %d %lf", &(numdepart), &(numarrivee), &(cout));

        if (metro){
            if (cout == 360.){
                cout = 10; //cout arbitraire pour les correspondances
}
            if ( cout == 600){
                cout = 20;
}
}
		creation_arc(numdepart,numarrivee,cout,graphe);
		}

	/* Ne pas oublier de fermer votre fichier */
	fclose(f);
	return(graphe);
	}

void suppression_arc(L_ARC arc){
	L_ARC parcours=arc;
	while(parcours!=NULL){
		L_ARC suiv=parcours->suiv;
		free(parcours);
		parcours=suiv;}
	}

void suppression_graphe(T_SOMMET* graphe,int nbsommet){
	int i;
	for(i=0;i<nbsommet;i++){
		suppression_arc((graphe+i)->voisins);
		}
	free(graphe);
	}

int rechercher_dans_arc(L_ARC arc,int numsommet){
	while(arc!= NULL){
		if((arc->val).arrivee==numsommet){
			return(1);
		}
		arc=arc->suiv;
	}
	return(0);
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
      //printf("cout: %lf\n",(arc->val).cout);
      return((arc->val).cout);
    }
    arc=arc->suiv;
  }
  //printf("fincout2\n");
  return(1000000000);
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
    printf("i = %s\n",graphe[sommet[i]].nom);
    //printf("%s -> ",(graphe+sommet[i])->nom );
  }
  printf("\non arrive à %d \n avec un cout de %lf\n",sommet[0]/*(graphe+arrivee)->nom*/,(graphe+sommet[0])->G);
	}

