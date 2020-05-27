#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

char lireCaractere();
char lireCaractereAlpha();
char lireCaractereChoix(const char*);

void afficherMessageIntroduction();
void afficherMessageCoupsRestants(const int);
void afficherMessageMotSecret(const char*);
void afficherMessageProposerLettre();
void afficherMessageGagnant(const char*);
void afficherMessagePerdant(const char*);
void afficherMessageVotreChoix();
void afficherMessageRetourMenu();
void afficherMessageLettresErronees(const char*);
void afficherMessageLettreDejaProposee();
void afficherMessageSaisieIncorrecte();
void afficherMessageErreurFichier(const char*);
void afficherMessageAPropos();
void afficherPendu(const int);
void afficherMenu();
void afficherOptions();
void afficherOptionsMode();
void afficherOptionsDifficulte();

#endif // DISPLAY_H_INCLUDED
