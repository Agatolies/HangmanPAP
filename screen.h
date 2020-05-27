#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

void rafraichirEcranMenu();
void rafraichirEcranOptions();
void rafraichirEcranOptionsMode();
void rafraichirEcranOptionsDifficulte();
void rafraichirEcranPendu(const int, const char*);
void rafraichirEcranAPropos();
char gererChoixMenu();
char gererChoixOptions();
char gererChoixOptionsMode();
char gererChoixOptionsDifficulte();
void quitterProgramme();

#endif // SCREEN_H_INCLUDED
