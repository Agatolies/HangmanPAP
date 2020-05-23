/*********************************************************************/
/* Principes algorithmique et programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-22                                             */
/*********************************************************************/

/* Contient les prototypes des fonctions de display.c                */


#ifndef DEF_DISPLAY
#define DEF_DISPLAY

void afficherMessageIntroduction();
void afficherMessageCoupsRestants(int);
void afficherMessageMotSecret();
char lireCaractere();
void afficherLettreTrouvee(char*, int);
void afficherLettreNonTrouvee();
void afficherMessageProposerLettre();
void afficherMessageGagnant(char*);
void afficherMessagePerdant(char*);
void afficherMessageErreurDico();

#endif

