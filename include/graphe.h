#include "type.h"

#ifndef GRAPHE_H
#define GRAPHE_H


T_SOMMET* creation_graphe(int nbsommet);

void creation_sommet(T_SOMMET* psommet,char* nom,char* line, double longi, double lat);

void affiche_arc(L_ARC voisins);

void affiche_sommet(T_SOMMET* psommet);

void afficher_graphe(T_SOMMET* graphe,int nbsommet);

void creation_arc(int numdepart, int numarrivee, double cout,T_SOMMET* graphe);

T_SOMMET* ouvrir_fichier(char* nomfichier,int* pnbsommet,int metro);

void suppression_arc(L_ARC arc);

void suppression_graphe(T_SOMMET* graphe,int nbsommet);

double cout(int depart,int arrivee,T_SOMMET* graphe);

double H(int sommets, int sommeta, T_SOMMET* graphe);

int trouver_sommet(char* depart,T_SOMMET* graphe,int nbsommet);

void affiche_chemin(T_SOMMET* graphe, int depart, int arrivee,int nbsommet);
#endif 

