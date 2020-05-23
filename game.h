#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

int demarrerJeu();
void initialiser();
int rechercherLettre(char, char*, int*);
void jouerCoup();
char* obtenirMotMasque();
int verifierVictoire(int*, int);
void afficherMessageFinPartie();

#endif // GAME_H_INCLUDED
