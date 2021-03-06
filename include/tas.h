#include "type.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef TAS_H
#define TAS_H

T_SOMMET** creerTas(int n); // n designe la taille du tas

void augmenteTas(T_SOMMET** tas,int* pn);//place l'elt en position n du tableau de sorte a reformer un tas jusqua n

void descendreTas(T_SOMMET** tas, int n);

void libereTas(T_SOMMET** tas);

void afficheTas(T_SOMMET** tas, int n);

T_SOMMET* popTas(T_SOMMET** tas, int* pn);

void supprimeSommetTas(T_SOMMET** tas, int* pn);

void supprimerElementYTas(T_SOMMET** tas, int* pn, int y);

int chercheDansTas(T_SOMMET** tas,int n_tas,T_SOMMET* graphe,int sommetCherche);
#endif
