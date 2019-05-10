int main(){
	int nbsommet=0;
	int* pnbsommet=&nbsommet;

	T_SOMMET* graphe=remplir_graphe("graphe1.txt",pnbsommet);
	afficher_graphe(graphe,nbsommet);
}