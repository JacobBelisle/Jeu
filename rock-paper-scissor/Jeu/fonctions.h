/*====================================
Auteur : Frederick Perazzelli-Delorme, Marianne Thompson, Julien Lachance et Moussa Niang.
Laboratoire : Roche, papier et ciseau.
Nom du fichier : fonctions.h
Date : 2020/12/05
But : Liste des fonctions utilisées
====================================*/


#pragma once

/* menu */

void afficherMenu(void);

/* Enregistrement de l'utilisateur et des points */

void enregistrementUtilisateur(void);
void enregistrementPointFinal(void);

/* Tableau des points */

void tableauPoints(void);

/* Regle et jeu */

void regles(void);
void rochePapierCiseau(int& , int&);
void jeu1(void);
void jeu2(void);
void jeu3(void);
void jeu4(void);
