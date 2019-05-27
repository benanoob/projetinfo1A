#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hachage.h"
#include "graphe.h"
#include "type.h"

unsigned int calcul_hachage(char* c,int taille_table){
  int i=strlen(c);
  //printf("\ni:%d\n",i);
  //printf("%s",c);
  unsigned int hach=0;
/*  while(c[i]!='o')
  {
    printf("%c\n",c);
    i--;
  }*/
  int a=31;
  //printf("debut boucle\n");
  while(i>=0)
  {
    //printf("%c",c[i]);
    hach=(hach*a+c[i])%taille_table;
    //printf("%d\n",hach);
    i=i-1;
  }
  //printf("fin boucle\n");
  return(hach);
}

table ajoute_sommet(table pos,T_SOMMET* psommet){
  table maillon=calloc(1,sizeof(*maillon));
  if(maillon==NULL){
    printf("allocation impossible\n");
    return(NULL);
  }
  maillon->val=psommet;
  maillon->suiv=pos;
  pos=maillon;
  return(maillon);
}

table* creation_table(T_SOMMET* graphe,int taille_table,int nbsommet){
  table* hachage=calloc(taille_table,sizeof(table));
  int i;
  for(i=0;i<taille_table;i++){
    hachage[i]=NULL;
  }
  char* nom;
  T_SOMMET* psommet;
  unsigned int hach;
  for(i=0;i<nbsommet;i++){
    psommet=graphe+i;
    nom=psommet->nom;
    //printf("calcul_hachage\n");
    hach=calcul_hachage(nom,taille_table);
    //printf("ajoute_sommet\n");
    hachage[hach]=ajoute_sommet(hachage[hach],psommet);
    if(hachage[hach]==NULL){
      printf("probleme\n");
    }
  }
  return(hachage);
}
/*
void supprimer_table(table* table,taille_table){

}
*/

void afficher_table(int taille_table,table* table_hach,T_SOMMET* graphe){
  int i=0;
  //printf("debut afficher table\n");
  //T_SOMMET* psommet;
  //printf("%d\n",table_hach[0]);
  table maillon=table_hach[0];
  //printf("avant boucle\n");
  for(i=0;i<taille_table;i++){
    maillon=table_hach[i];
    //printf("maiillon\n");
    while(maillon!=NULL){
      //printf("maillon non nul\n");
      //psommet=maillon->val;
      //printf("bon pour sommet\n");
      printf("%s\n",maillon->val->nom);
      maillon=maillon->suiv;
    }
  }
}

T_SOMMET* chercher_dans_table(table* table_hach,int taille_table,char* nom){
  int hach=calcul_hachage(nom,taille_table);
  table maillon=table_hach[hach];
  while(maillon!=NULL){
    if (strcmp(maillon->val->nom,nom)==0){
      return(maillon->val);
    }
    maillon=maillon->suiv;
  }
  return(NULL);
}

void liberer_table_hachage(table* table_hach,int taille_table){
  int i;
  table maillon;
  table suiv;
  for(i=0;i<taille_table;i++){
    maillon=table_hach[i];
    while(maillon!=NULL){
      suiv=maillon->suiv;
      free(maillon);
      maillon=suiv;
    }
  }
  free(table_hach);
}

/* debug
 int main(){
  int nbsommet;
  int i;
  int taille_table=31;
  //printf("on va ouvrir\n");
  T_SOMMET* graphe= ouvrir_fichier("graphe2.txt",&nbsommet,0);
  //printf("on a ouvert\n");
  table* table_hach =creation_table(graphe,31,nbsommet);
  //printf("on a crée table\n");
  afficher_table(taille_table, table_hach, graphe);
  char* nom=graphe[0].nom;
  for (i=0;i<nbsommet;i++){
    nom=graphe[i].nom;
    T_SOMMET* psommet=chercher_dans_table( table_hach, taille_table, nom);
    printf("%s: en position %d\n",nom,psommet-graphe);
    }
    liberer_table_hachage(table_hach,taille_table);
}*/
