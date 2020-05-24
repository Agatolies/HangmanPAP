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
void afficherMessageRetourMenu();
void afficherMessageLettresErronees(char*);
void afficherMessageLettreDejaProposee();
void afficherPendu(int);
void afficherMenu();
void afficherOptions();
void afficherOptionsMode();
void afficherOptionsDifficulte();

#endif // DISPLAY_H_INCLUDED
