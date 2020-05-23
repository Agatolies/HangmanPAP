#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

int demarrerJeu();
void initialiser();
int rechercherLettre(char, char*, int*);
void jouerCoup();
void gererChoixMenu();
char* obtenirMotMasque();
int verifierVictoire(int*, int);
void afficherMessageFinPartie();
void quitterProgramme();

void rafraichirEcranMenu();
void rafraichirEcranPendu();

#endif // GAME_H_INCLUDED
