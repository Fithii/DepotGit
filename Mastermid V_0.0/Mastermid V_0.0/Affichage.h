#ifndef DEF_AFFICHAGE
#define DEF_AFFICHAGE

//Inclusion librairies standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Inclusion des fichier d'en-tête
#include "niveau.h"

//Inclusion des signatures des fonctions 
void AfficheMenu();
void AfficheTableau(char *Affichage, int TailleTab);
void AfficheTableauExpert(char *Affichage, int TailleTab);
void DemandeAlea (int *Valeur);
void AfficheInfoJoueur(int nbrcoup);



#endif