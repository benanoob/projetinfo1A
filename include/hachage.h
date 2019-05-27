#include "graphe.h"
#include "type.h"

#ifndef HACHAGE_H
#define HACHAGE_H

unsigned int calcul_hachage(char* c,int taille_table);//calcul le hachage associé à un mot
table ajoute_sommet(table pos,T_SOMMET* psommet);//ajoute un sommet à la table de hachage
table* creation_table(T_SOMMET* graphe,int taille_table,int nbsommet);//crée la table de hachage à partir du graphe
void afficher_table(int taille_table,table* table_hach,T_SOMMET* graphe);//affiche la table de hachage(plus du debugg qu'autre chose)
T_SOMMET* chercher_dans_table(table* table_hach,int taille_table,char* nom);//renvoie le pointeur sur le sommet dont le nom est passé en argument
void liberer_table_hachage(table* table_hach,int taille_table);//libere la memoire allouée pour la
#endif
