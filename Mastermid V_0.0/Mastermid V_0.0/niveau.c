#include "niveau.h"

//Il est desormais impossible de tirer deux fois le même chiffre dans la chaine a trouver

//TO DO : 	Faire une structure personne contenant le pseudo du joueur ainsi que son nombre de coup
//			Faire une structure jeu contenant la chaine a trouver, la chaine de l'utilisateur et la chaine Affichage
//			Tableau dynamique pour stoquer la longueur de la chaine entrer et eviter les violation

void Niveau(int Difficulte)
{
	int genereraleaidentique = 0;
	int ChainePass[CHAINE_MASTERMIND_LONGEUR] = {0}; //Initialise la chaine contenant les chiffres a 0
	int ChaineUser[CHAINE_MASTERMIND_LONGEUR] = {0}; //Initialise la chaine contenant les chiffres de l'utilisateur a 0
	char Affichage[CHAINE_MASTERMIND_LONGEUR + 1] = {'\0'}; //Initialise la chaine contenantl'affichage ( X ou I )
	int nbrcoup = 12; //Definie le nombre de coup max
	int boolfinlevel = 0; //Findulevel a 1, Findeviea 2
	system("cls"); //Efface l'ecran
	DemandeAlea(&genereraleaidentique);
	InitTableau(ChainePass, CHAINE_MASTERMIND_LONGEUR, genereraleaidentique); //Initialise la chaine a trouver
	do //Faire
	{
		AfficheInfoJoueur(nbrcoup); //Affiche les infos aux joueurs
		InitChaineUtilisateur(ChaineUser, CHAINE_MASTERMIND_LONGEUR); //Initialise la chiane de l'utilisateur
		VerifUser(ChaineUser, ChainePass, CHAINE_MASTERMIND_LONGEUR, Affichage); //Verifie si la chaine est correcte, sinon, remplis la chaine d'affichage d'info a l'utilisateur
		nbrcoup--; //Supprime un coup au joueur
		if (Difficulte == 1) //Si difficulte est noob alors
		{
			AfficheTableau(Affichage,CHAINE_MASTERMIND_LONGEUR); //Affichage de la reponse pour le noob
		}
		else if ( Difficulte == 2 ) //SI difficulte est expert alors
		{
			AfficheTableauExpert(Affichage, CHAINE_MASTERMIND_LONGEUR);
		}
		boolfinlevel = FinDuJeu(Affichage, nbrcoup); //Verifie si il est temps de mettre fin au jeu
		system("pause"); //Mets en pause le programme
		system("cls"); //Efface l'ecran
	} while (boolfinlevel == 0); //Tant que la fin du jeu n'est pas annoncer par la fonction de verif

}

int Aleatoire (int min, int max)
{
	//Faire en sorte qu'il soit impossible de tirer deux fois le même chiffre
	int aleatoire = 0; //Initialise la variable aleatoire
	aleatoire = (rand() % (max - min + 1)) + min; //Aleatoire vaux donc le resultat de cette formule
	return aleatoire; //Renvois aleatoire
}

void InitTableau(int *Tableau,int TailleTab, int allowaleaiden)
{
	int i = 0; //Declare i a 0
	int j = 0; //Declare j a 0
	for (i = 0; i < TailleTab ; i++) //Pour i = 0 tant que i est inferieur a la taille du tableau j'incremente 1
	{
		Tableau[i] = Aleatoire(1,8); //Remplis les cases du tableau de chiffre aleatoire
	}
	if (allowaleaiden == 2) //Si l'utilisateur ne veut pas de deux chiffre identique alors :
	{
		i = 0; //Initialise I a 0
		j = i + 1; //Initialise J a I + 1
		while (i != TailleTab) //Tant que i n'est pas a la fin du tableau
		{
			while (j != TailleTab) //Tant que j n'est pas a la fin du tableau
			{
				while (Tableau[i] == Tableau[j]) //Tant que I est identique a J 
				{
					Tableau[j] = Aleatoire(1,8); //Alors je regenere le chiffre aleatoirement
				}
				j++; //Increment 1 a J 
			}
			i++; //Increment 1 a I 
			j = i + 1; //Place J a I + 1 
		}
	}
}

void VerifUser(int *TableauUser, int *ChainePass, int TailleTab, char *Affichage)
{
	int i = 0; //i vaut 0
	int j = 0; //j vaut 0
	for (i = 0; i < TailleTab; i++) //Pour i = 0 tant que i est inferieur a la taille du tableau j'incremente 1 a i
	{
		if (TableauUser[i] == ChainePass[i]) //la case i est identique a la chaine
		{
			Affichage[i] = 'X'; //Alors la case i de l'Affichage vaut X 
		}
		else if (TableauUser[i] != ChainePass[i]) //Sinon si la case i est differente de la case i de la chaine 
		{
			j = 0; //J vaut 0
			for ( j = 0; j < TailleTab; j++)  //Pour i vaut 0 tant que j est inferieur a la taille du tableau j'incremente 1 a i
			{
				if (TableauUser[i] == ChainePass[j] && Affichage[i] != 'X') //Si la case i est identique a la case J de la chainePass
				{
					Affichage[i] = 'I'; //Alors la case I vaut I 
				}
			}
		}
		else //Sinon  
		{
			Affichage[i] = 'O'; //Alors la case i vaut ' '
		}
	}
}

void InitChaineUtilisateur(int *Tableau, int TailleTab)  
{
	int i = 0;
	int SaisieOk = 0;
	char temp = ' ';
	char ChaineSaisie[CHAINE_MASTERMIND_LONGEUR+1] = {'\0'}; //Cree une chaine de caractère de taille 5 + 1 pour l'\0 
	do
	{
		do
		{
			printf("\nSaisie la combinaison : "); //Affiche le message
			scanf("%s", ChaineSaisie); //Recupere la valeur 
			if (strlen(ChaineSaisie) > 5)
			{
				printf("\nLa chaine saisie est trop longue.."); 
			}
		} while (atoi(ChaineSaisie) == 0 || strlen(ChaineSaisie) > 5); //Tant que la chaine n'est pas un chiffre numerique ( Atoi envoie 0 en code d'erreur, dans ce jeu le 0 n'est pas utiliser atoi est donc utilisable ) ou si la taille de la chaine est superieur a 5
		i = 0;
		while (ChaineSaisie[i] != '\0') //Tant qu'on est pas arriver a la fin de la chaine
		{
			temp = ChaineSaisie[i]; //Alors je stoque la case I de la chaine saisie par l'utilisateur dans la variable temp qui est de type caractère
			Tableau[i] = atoi(&temp); //J'indique que la case I du tableau d'entier a pour valeur le resultat de la fonction atoi
			if (Tableau[i] >= 1 && Tableau[i] <= 8)
			{
				SaisieOk = 1;
			}
			else
			{
				SaisieOk = 0;
				printf("\nLe caractere [%c] n'est pas autoriser", ChaineSaisie[i]);
			}
			i++;
		}	
	} while (SaisieOk == 1);
}

int FinDuJeu(char *Affichage, int nbrcoup)
{
	int i = 0; //i vaut 0
	for (i = 0; i != CHAINE_MASTERMIND_LONGEUR; i++) //Pour i vaut 0 tant que i est different de la taille de la chaine, j'incremente 1 a i
	{
		if (Affichage[i] == 'X') //Si la case Affichage vaut X
		{
			if (i == CHAINE_MASTERMIND_LONGEUR - 1) //Et si i vaut la derniere case avec le X
			{
				return 1; //Alors le joueur a trouver la bonne combinaison
			}
		}
	}
	if (nbrcoup == 0) //Si nombre de coup vaut 0
	{
		return 2;//Le joueur n'a plus de vie 
	}
	return 0; //Si on arrive jusque la, c'est que le jeu n'est pas terminer.
}


