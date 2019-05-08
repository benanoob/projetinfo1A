T_SOMMET** creerTas(int n ); // n designe la taille du tas

void augmenteTas(T_SOMMET** tas,int n);//place l'elt en position n du tableau de sorte a reformer un tas jusqua n

void descendreTas(T_SOMMET** tas, int n);

void libereTas(T_SOMMET** tas);

void afficheTas(T_SOMMET** tas, int n);

T_SOMMET* popTas(T_SOMMET** tas, int n);

void supprimeSommetTas(T_SOMMET** tas, int n);
