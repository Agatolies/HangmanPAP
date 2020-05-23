#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

int demarrerJeu();
int rechercherLettre(char, char*, int*);
void essaisJeu(int, int, int*, char, char*);
void afficherMessageFinPartie(int*, int, char*);
int verifierVictoire(int*, int);

#endif // GAME_H_INCLUDED
