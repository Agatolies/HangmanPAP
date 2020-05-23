#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

char lireCaractere();

void afficherMessageIntroduction();
void afficherMessageCoupsRestants(int);
void afficherMessageMotSecret(char*);
void afficherMessageProposerLettre();
void afficherMessageGagnant(char*);
void afficherMessagePerdant(char*);
void afficherMessageErreurDico();
void afficherMessageVotreChoix();
void afficherPendu(int);
void afficherMenu();

#endif // DISPLAY_H_INCLUDED
