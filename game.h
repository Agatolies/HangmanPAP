#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

int demarrerJeu();
void initialiser();
int rechercherLettre(char, char*, int*);
void jouerCoup();
char* obtenirMotMasque();
void afficherMessageFinPartie();
int verifierVictoire(int*, int);

#endif // GAME_H_INCLUDED
