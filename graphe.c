# include <stdio.h>
# include "graphe.h"

T_SOMMET* creation_graphe(int nbsommet){  
	T_SOMMET* graphe=calloc(nbsommet,sizeof(T_SOMMET));
	}

/*cree le graphe: alloue dynamiquement le tableau qui contient les sommets*/

void creation_sommet(T_SOMMET* psommet,char* nom,char* line, double longi, double lat){
	psommet->nom=calloc(strlen(nom),sizeof(char));
	strclcopy(&psommet->nom,nom);
	psommet->line=calloc(strclen(line),sizeof(char));
	strclcopy(&psommet->line,line);
	psommet->x=longi;
	psommet->y=lat;
	psommet->voisins=NULL;
	}

void suppression_graphe(T_SOMMET graphe,nbsommet){
	int sommet;
	for (sommet=0,sommet<nbsommet,sommet++){
		supprimer_arc
		malloc}
	}

void creation_arc(int numdepart, int numarrivee, double cout,T_SOMMET* graphe){
	L_ARC listsuiv=(graphe+numdepart)->voisins;//on selectionne la liste de voisins associee a ce sommet de depart
	
	L_ARC new=calloc(1,sizeof(*L_ARC));
	(new->val).arrivee=numarrivee;
	(new->val).cout=cout;
	new->suiv=NULL;
	
	if(listsuiv==NULL){
		(graphe+numdepart)->voisins=new;//on a ajoute notre nouvel arc ce qui cree la liste de successeurs
		}
	else{
		L_ARC arc=listsuiv->suiv;
		while(arc->suiv!=NULL){
			arc=arc->suiv;//on va au bout de la liste des successeurs deja repertories
			}	
		arc->suiv=new; //on a ajoute notre nouvel arc a la liste de successeurs
		
		}	
	}


T_SOMMET* remplir_graphe(T_SOMMET* sommet,int* pnbsommet){
	FILE* f; 
	int numero,nbsommet,nbarc; 
	double lat,longi ;
	char line[128] ;
	char mot[512] ;
	f=fopen("graphe1.txt","r");
	if (f==NULL) {
		printf("Impossible d’ouvrir le fichier\n");
		exit(EXIT_FAILURE);
		} 
	/* Lecture de la premiere ligne du fichier : nombre de sommet et nombre d’arcs */ 
	fscanf(f,"%d %d ",&nbsommet,&nbarc);

	T_SOMMET* graphe=creation_graphe(nbsommet);//cree le graphe
	if (T_SOMMET==NULL) {
		printf("Impossible de creer graphe\n");
		exit(EXIT_FAILURE);
		} 

	/* Ligne de texte "Sommets du graphe" qui ne sert a rien */ 
	fgets(mot,511,f);
	
	T_SOMMET* psommet;

	// maintenant on parcourt tous les sommets
	for(psommet=graphe,psommet-graphe<nbsommet,psommet++){
		/* lecture d’une ligne de description d’un sommet */
		/* on lit d’abord numero du sommet, la position, le nom de la ligne */ 
		fscanf(f,"%d %lf %lf %s", &(numero), &(lat), &(longi), line);
		/* numero contient alors l’entier ou numero du sommet, lat et longi la position, line le nom de la ligne */
		/* Le nom de la station peut contenir des separateurs comme l’espace. On utilise plutot fgets dans ce cas */ 
		fgets(mot,511,f);
		if (mot[strlen(mot)-1]<32) {mot[strlen(mot)-1]=0; }/* mot contient le nom du sommet. */

		creation_sommet( psommet, mot, line, longi, lat);}

	/*Pour sauter les lignes de commentaires, on peut simplement utiliser la fonction fgets sans utiliser la chaine de caracteres lue dans le fichier par */ 
	fgets(mot,511,f);

	int numdepart, numarrivee;
	double cout;	

	//maintenant on rempli les arcs
	for(nbarc,nbarc>0,nbarc--){
		//lecture de: un entier : numéro du sommet de départ 2. un entier : numéro du sommet d’arrivée 3. un réel : valeur ou coût de l’arc
		fscanf(f,"%d %d %lf", &(numdepart), &(numarrivee), &(cout));
		creation_arc(numdepart,numarrivee,cout,graphe);
		}
	
	/* Ne pas oublier de fermer votre fichier */ 
	fclose(f);
	return(graphe);
	}