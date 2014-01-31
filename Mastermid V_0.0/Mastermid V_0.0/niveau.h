#ifndef DEF_NIVEAU
#define DEF_NIVEAU

#define CHAINE_MASTERMIND_LONGEUR 5
//Inclusion librairies standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Inclusion des fichier d'en-tête nescessaire 
#include "Affichage.h"

//Inclusion des alias des structures
typedef struct Joueur Joueur;
typedef struct JeuEnCour JeuEnCour;

//Inclusion des structures

struct Joueur //Definition des propriétés du joueur
{
	char *Pseudo;
	int NbrCoup;
};

struct JeuEnCour
{
	int *ChainePass;
	int *ChaineUser;
	char *Affichage;
};


//Inclusion des signatures des fonctions
int Aleatoire (int min, int max);
void InitTableau(int *Tableau,int TailleTab, int allowaleaiden);
void Niveau(int Difficulte);
void DecoupTableau(int *TableauUser, char *ChaineUser, int TailleTab );
void VerifUser(int *TableauUser, int *ChainePass, int TailleTab);
void VerifUser(int *TableauUser, int *ChainePass, int TailleTab, char *Affichage);
void InitChaineUtilisateur(int *Tableau, int TailleTab);
int FinDuJeu(char *Affichage, int nbrcoup);

#endif