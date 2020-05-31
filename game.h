#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void demarrerJeu();
void initialiser();
int rechercherLettre(const char);
void jouerCoup();
void rafraichirMotMasque();
int verifierVictoire();
void rafraichirEcranPendu();
void afficherMessageFinPartie();

#endif // GAME_H_INCLUDED
