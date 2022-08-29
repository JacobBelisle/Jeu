/*====================================
Auteur : Frederick Perazzelli-Delorme, Marianne Thompson, Julien Lachance et Moussa Niang.
Laboratoire : Roche, Papier et Ciseau
Nom du fichier : main.cpp
Date : 2020/12/05
But : Créer un jeu de Roche, Papier et ciseau.
====================================*/

#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<fstream>
#include"fonctions.h"

using namespace std;

/* Variable global, non recommandée */

int pointTotal = 0;
string utilisateur;

void main(void) {

	/* Variables */

	int pointUtilisateur = 0;
	int pointProgramme = 0;
	char option;
	
	/* enregistrement de l'utilisateur */

	cout << "Bienvenue au jeu de roche, papier  et ciseau !" << endl;
	cout << "Avant de debuter, veuillez entrer votre nom d'utilisateur." << endl;
	cin >> utilisateur;
	cout << endl;
	cout << "Bienvenue " << utilisateur << " s.v.p placez votre ecran en plein-ecran (fullscreen)." << endl << endl;
	
	/* Affichage d'entrer*/

	cout << "Pour naviguer dans le menu, cliquer sur la touche clavier A, B, C, D, E, F ou Q." << endl;

	do {
		afficherMenu();
		option = toupper(_getch());

		switch (option) {

		case'A': regles();
			break;

		case'B': jeu1();
			break;

		case'C': jeu2();
			break;
		
		case'D': jeu3();
			break;

		case'E': jeu4();
			break;

		case'F': tableauPoints();
			break;
		case'Q': enregistrementUtilisateur();
			enregistrementPointFinal();
			cout << "Merci d'avoir jouer !" << endl;
			break;

		default: cout << "Choisissez une option valide." << endl << endl;
			break;

		}
	} while (option != 'Q');

	system("pause");
}

/* Le menu de notre programme */

void afficherMenu(void) {

	cout << endl;
	cout << "MENU" << endl;
	cout << "A) Regles" << endl;
	cout << "B) Faire une partie contre le programme" << endl;
	cout << "C) Faire un 2/3 contre le programme" << endl;
	cout << "D) Faire un 4/7 contre le programme" << endl;
	cout << "E) Partie illimitee" << endl;
	cout << "F) Tableau des points" << endl;
	cout << "Q) Quitter" << endl;
	cout << endl;

}

/* Regle de notre programme */

void regles(void) {

	cout << "Voici les regles du roche, papier, ciseau." << endl << endl;

	cout << "Vous devez commencer par choisir roche, papier ou ciseau." << endl;
	cout << "Votre adversaire, notre programme, choisira aussi entre ces trois options." << endl;
	cout << "Les resultats apparaitrons en meme temps." << endl << endl;

	cout << "La roche gagne contre les ciseaux (Roche > Ciseau) le joueur qui a choisie roche gagne 1 point." << endl;
	cout << "Le papier gagne contre la roche (Papier > Roche) le joueur qui a choisie papier gagne 1 point." << endl;
	cout << "Les ciseaux gagne contre le papier (Ciseaux > Papier) le joueur qui a choisie ciseaux gagne 1 point." << endl;
	cout << "Si les deux joueurs utilisent la meme option la partie est nule, personne ne fait de point." << endl << endl;

	cout << "Dans le menu, l'option A) vous affiche les regles" << endl;
	cout << "Dans le menu, l'option B) vous fait jouer une partie contre le programme jusqu'a ce que l'un d'entre vous fassiez 1 point." << endl;
	cout << "Dans le menu, l'option C) vous fait jouer plusieurs parties contre le programme jusqu'a ce que l'un d'entre vous fassiez 2 points." << endl;
	cout << "Dans le menu, l'option D) vous fait jouer plusieurs parties contre le programme jusqu'a ce que l'un d'entre vous fassiez 4 points." << endl;
	cout << "Dans le menu, l'option E) vous fait jouer plusieurs parties contre le programme jusqu'a ce que vous soyez tannee." << endl;
	cout << "Dans le menu, l'option F) affiche le tableau des points." << endl;
	cout << "Dans le menu, l'option Q) Quitte et enregistre votre résultat." << endl << endl;

	cout << "Amusez-vous !" << endl << endl;
}

/* Roche Papier Ciseau */

void rochePapierCiseau(int& pointUtilisateur, int& pointProgramme) {

	char choixProgramme;
	char choix;

	cout << string(60, '=') << endl;
	cout << string(25, '*') << " DEBUT " << string(27, '*') << '|' << endl;
	cout << string(60, '=') << endl;

	do {
		
		cout << "Choisissez ---> Roche (R), Papier(P) ou Ciseau(C)" << endl;
		choix = toupper(_getch());

	} while (choix != 'R' && choix != 'C' && choix != 'P');

	cout << string(60, '=') << endl;
	cout << left << setw(10) << " " << left << setw(25) << utilisateur << "Programme " << endl;

	cout << left << setw(10) << " " << string(10, '=') << left << setw(15) << " " << string(10, '=') << endl;
	if (choix == 'R') {
		cout << left << setw(10) << " " << left << setw(15) << "| ROCHE  |";
	}
	else if (choix == 'P') {
		cout << left << setw(10) << " " << left << setw(15) << "| PAPIER |";
	}
	else {
		cout << left << setw(10) << " " << left << setw(15) << "| CISEAU |";
	}

	/* Entre les choix possible du programme dans un tableau */

	char tableauChoix[3][3];

		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {

				if (i == 0) {

					tableauChoix[i][j] = '*';
				}
				else if (i == 1) {

					tableauChoix[i][j] = 'R';
				}
				else if (i == 2) {

					tableauChoix[i][j] = 'P';
				}
				else {

					tableauChoix[i][j] = 'C';
				}

			}

		}

		/* Prend une section du tableau au hasard, il devrait y avoir 3 chances sur 9 pour chacun des résultats */

		int val = 0;
		val = rand() % 3 + 1;

		int val1 = 0;
		val1 = rand() % 3 + 1;

		tableauChoix[val][val1];
		choixProgramme = tableauChoix[val][val1];

		if (choixProgramme == 'R') {
			choixProgramme = 'R';
			cout << left << setw(10) << " " << left << setw(15) << "| ROCHE  |" << endl;
		}
		else if (choixProgramme == 'P') {
			choixProgramme = 'P';
			cout << left << setw(10) << " " << left << setw(15) << "| PAPIER |" << endl;
		}
		else {
			choixProgramme = 'C';
			cout << left << setw(10) << " " << left << setw(15) << "| CISEAU |" << endl;
		}


		/* Compare les reponses de l'utilisateur et du programme */

		cout << left << setw(10) << " " << string(10, '=') << left << setw(15) << " " << string(10, '=') << endl;
		cout << endl;
		
		if (choix == 'P' && choixProgramme == 'R') {

			pointUtilisateur++;
			cout << left << setw(8) << " " << left << setw(15) << "--> Felicitation! Vous avez gagner! <--" <<  endl;
			
		}
		else if (choix == 'R' && choixProgramme == 'C') {

			pointUtilisateur++;
			cout << left << setw(8) << " " << left << setw(15) << "--> Felicitation! Vous avez gagner! <--" <<  endl;
			
		}
		else if (choix == 'C' && choixProgramme == 'P') {

			pointUtilisateur++;
			cout << left << setw(8) << " " << left << setw(15) << "--> Felicitation! Vous avez gagner! <--" << endl;
			
		}
		else if (choix == 'R' && choixProgramme == 'P') {
			pointProgramme++;
			cout << left << setw(10) << " " << left << setw(15) << "--> Desole... Vous avez perdu :( <--" << endl;
			
		}
		else if (choix == 'C' && choixProgramme == 'R') {
			pointProgramme++;
			cout << left << setw(10) << " " << left << setw(15) << "--> Desole... Vous avez perdu :( <--" <<  endl;
			
		}
		else if (choix == 'P' && choixProgramme == 'C') {
			pointProgramme++;
			cout << left << setw(10) << " " << left << setw(15) << "--> Desole... Vous avez perdu :( <--" << endl;
			
		}
		else {
			cout << left << setw(12) << " " << left << setw(13) << "--> Partie nulle, recommencez ! <--" << endl;
			
		}

		cout << endl;
		cout << left << setw(7) << " " << utilisateur << " : " << left << setw(20) << pointUtilisateur << left << setw(5) << "Programme : " << pointProgramme << endl;
		cout << string(60, '=') << endl;
		cout << string(26, '*') << " FIN " << string(28, '*') << '|' << endl;
		cout << string(60, '=') << endl;
		cout << string(60, '|') << endl;

		system("pause");
		system("cls");

}

/* option B) */

void jeu1(void) {

	
	int pointUtilisateur = 0;
	int pointProgramme = 0;

	cout << "Vous avez choisie l'option B), une seule partie" << endl;

	do {

		rochePapierCiseau(pointUtilisateur, pointProgramme);

	} while (pointUtilisateur != 1 && pointProgramme != 1);

	pointTotal += pointUtilisateur;

}

/* option C) */

void jeu2(void) {

	int pointUtilisateur = 0;
	int pointProgramme = 0;

	cout << "Vous avez choisie l'option C), le premier a 2 point gagne. (2/3)" << endl;

	do {

		rochePapierCiseau(pointUtilisateur, pointProgramme);

	} while (pointUtilisateur != 2 && pointProgramme != 2);

	pointTotal += pointUtilisateur;

}


/* option D) */

void jeu3(void) {

	int pointUtilisateur = 0;
	int pointProgramme = 0;

	cout << "Vous avez choisie l'option D), le premier a 4 point gagne. (4/7)" << endl;

	do {

		rochePapierCiseau(pointUtilisateur, pointProgramme);

	} while (pointUtilisateur != 4 && pointProgramme != 4);

	pointTotal += pointUtilisateur;

}


/* option E) */

void jeu4(void) {

	int pointUtilisateur = 0;
	int pointProgramme = 0;
	char choix;

	cout << "Vous avez choisie l'option F), partie illimite. Suite a chaque partie, un message vous demanderas si vous voulez en jouer une autre" << endl;

	do {

		rochePapierCiseau(pointUtilisateur, pointProgramme);

		do {
			cout << "Voulez-vous faire une autre partie ? (O/N)" << endl;
			choix = toupper(_getch());

			if (choix == 'O') {

				cout << " Prochaine partie ! " << endl;
			}
			else if (choix == 'N') {

				cout << " Retour au menu " << endl;
			}
			else {

				cout << "Selectioner une option valide" << endl;
			}

		} while (choix != 'O' && choix != 'N');

	} while (choix != 'N');

	pointTotal += pointUtilisateur;

}

/* Enregistrement de l'utilisateur */

void enregistrementUtilisateur(void) {

	string chemin = "..//tableauPoint.txt";
	ofstream flux(chemin.c_str(), ios::app);

	if (flux) {

		flux << utilisateur << " ";

	}
	else {
		cout << "Erreur";
	}

}
/* Enregistrement des points */

void enregistrementPointFinal(void) {

	string chemin = "..//tableauPoint.txt";
	ofstream flux(chemin.c_str(), ios::app);

	if (flux) {

		flux << pointTotal << endl;

	}
	else {
		cout << "Erreur";
	}

}

/* Affichage du tableau des points */

void tableauPoints(void) {

	ifstream lecture("..//tableauPoint.txt");
	
	if (lecture) {

		cout << string(59, '=') << endl;
		cout << left << setw(25) << "Utilisateur : " << left << setw(25) << "# de victoires : " << endl;
		cout << string(60, '=') << endl;

		string score;

		int i = 0;

		while (lecture >> score) {

			cout << left << setw(25) << score;

			i++;

			if (i == 2) {

				cout << endl;
				i = 0;

			}
		}

		cout << left << setw(25) << utilisateur << left << setw(25) << pointTotal << endl;

	}
	else {
		cout << "Erreur";
	}

}


