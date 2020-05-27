#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

int demarrerJeu();
void initialiser();
int rechercherLettre(const char, const char*, int*);
void jouerCoup();
char* obtenirMotMasque();
int verifierVictoire(const int*, const int);
void afficherMessageFinPartie();

#endif // GAME_H_INCLUDED
