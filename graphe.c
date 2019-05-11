#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"

T_SOMMET* creation_graphe(int nbsommet){
	return(calloc(nbsommet,sizeof(T_SOMMET)));
	}

/*cree le graphe: alloue dynamiquement le tableau qui contient les sommets*/

void creation_sommet(T_SOMMET* psommet,char* nom,char* line, double longi, double lat, int ListeFermee, int F){
	psommet->nom=calloc(strlen(nom),sizeof(char));
	strcpy(psommet->nom,nom);
	psommet->line=calloc(strlen(line),sizeof(char));
	strcpy(psommet->line,line);
	psommet->x=longi;
	psommet->y=lat;
	psommet->ListeFermee=ListeFermee;
	psommet->voisins=NULL;
	psommet->F=F;
	}

void affiche_arc(L_ARC voisins){
	while(voisins!=NULL){
		printf("mene au sommet %d\n",voisins->val.arrivee);
		printf("avec un cout de %lf\n",voisins->val.cout);
		voisins=voisins->suiv;
	}
}

void affiche_sommet(T_SOMMET* psommet){
	printf("nom %s\n",psommet->nom);
	printf("line %s\n",psommet->line);
	printf("x %lf\n",psommet->x);
	printf("y %lf\n",psommet->y);
	printf("ListeFermee %d\n",psommet->ListeFermee);
	printf("F %d\n",psommet->F);
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
		new->suiv=listsuiv;
		affiche_arc(listsuiv);
		(graphe+numdepart)->voisins=new;
		affiche_arc(listsuiv);
	}
	}


T_SOMMET* ouvrir_fichier(char* nomfichier,int* pnbsommet){
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
		fscanf(f,"%d %lf %lf %s", &(numero), &(lat), &(longi), line);
		/* numero contient alors l�entier ou numero du sommet, lat et longi la position, line le nom de la ligne */
		/* Le nom de la station peut contenir des separateurs comme l�espace. On utilise plutot fgets dans ce cas */
		fgets(mot,511,f);
		if (mot[strlen(mot)-1]<32) {mot[strlen(mot)-1]=0; }/* mot contient le nom du sommet. */

		creation_sommet( psommet, mot, line, longi, lat, 0, -1);
  }

	/*Pour sauter les lignes de commentaires, on peut simplement utiliser la fonction fgets sans utiliser la chaine de caracteres lue dans le fichier par */
	fgets(mot,511,f);

	int numdepart, numarrivee;
	double cout;

	//maintenant on rempli les arcs
	for(nbarc;nbarc>0;nbarc--){
		//lecture de: un entier : num�ro du sommet de d�part 2. un entier : num�ro du sommet d�arriv�e 3. un r�el : valeur ou co�t de l�arc
		fscanf(f,"%d %d %lf", &(numdepart), &(numarrivee), &(cout));

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
