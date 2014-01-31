#include "Affichage.h"


void AfficheMenu() 
{
	system("cls");
	printf("\tBienvenue dans le MASTERMIND !\n\n");
	printf("\t------------------------------\n");
	printf("\t0.Quitter\n");
	printf("\t1.Niveau pour les noobs\n");
	printf("\t2.Niveau pour les experts\n");
	printf("\t3.Afficher les scores\n");
	printf("\t------------------------------\n\n");
}

void AfficheTableau(char *Affichage, int TailleTab)
{
	int i = 0;
	for ( i = 0; i < TailleTab ; i++)
	{
		printf("[%c] ", Affichage[i]);
	}
	printf("\n");
} 

void AfficheTableauExpert(char *Affichage, int TailleTab)
{
	int i = 0;
	int NbrX = 0;
	int NbrI = 0;
	int NbrInconnue = 0;
	for (i = 0 ; i < TailleTab ; i++)
	{
		if (Affichage[i] == 'X')
		{
			NbrX++;
		}
		else if (Affichage[i] == 'I')
		{
			NbrI++;
		}
		else
		{
			NbrInconnue++;
		}
	}
	printf("[X] apparait %d fois.\n[Y] apparait %d fois.\n[ ] apparait %d fois.\n", NbrX, NbrI, NbrInconnue);
}

void DemandeAlea (int *Valeur)
{
	int valeur = 0;
	system("cls");
	printf("Souhaite tu pouvoir generer deux fois le meme \nchiffre dans la chaine secrete ( 1 oui, 2 non ) : ");
	scanf("%d", &valeur);
	*Valeur = valeur;
}

void AfficheInfoJoueur(int nbrcoup)
{
	system("cls");
	printf("Bonne valeur : [X]\nMauvaise palce : [Y]\nValeur incorrect : [O]\n");
	printf("il te reste %d coup(s)", nbrcoup);
}
