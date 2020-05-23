#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

char lireCaractere();

void afficherLettreTrouvee(char*, int);
void afficherLettreNonTrouvee();

void afficherMessageIntroduction();
void afficherMessageCoupsRestants(int);
void afficherMessageMotSecret();
void afficherMessageProposerLettre();
void afficherMessageGagnant(char*);
void afficherMessagePerdant(char*);
void afficherMessageErreurDico();

#endif // DISPLAY_H_INCLUDED
