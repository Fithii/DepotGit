#include "main.h"

int main()
{
	int ChoixUtilisateur = 0;
	int Difficulte = 0;
	srand(time(NULL)); //Initialisation pour le chiffre aleatoire
	do
	{
		AfficheMenu();
		printf("Dans quel niveau joues-tu : ");
		scanf("%d", &ChoixUtilisateur);
		switch (ChoixUtilisateur)
		{
		default: 
			system("cls");
			printf("Erreur, vous avez entrer une valeur invalide.\n");
			system("pause");
			break;
		case 0 :
			break;
		case 1 :
			Difficulte = 1; //Selection du niveau des noobs
			Niveau(Difficulte);
			break;
		case 2 :
			Difficulte = 2; //Selection du niveau de PGM
			Niveau(Difficulte);
			break;
		case 3 :
			//Affiche le tableau des scores
			break;
		}
	} while (ChoixUtilisateur != 0);
	return 0;
}
