/*********************************************************************/
/* Principes Algorithmique et Programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-23                                             */
/*********************************************************************/
/*                                                                   */
/* screen.cpp                                                        */
/* ------                                                            */
/* Ces fonctions servent a gerer les ecrans                          */
/*                                                                   */
/*= DIRECTIVES DE PRECOMPILATION ====================================*/

#include <myconio.h>

#include "screen.h"
#include "display.h"
#include "game.h"

/*= CONSTANTES SYMBOLIQUES ==========================================*/

#define COUPS 6

/*= FONCTIONS =======================================================*/

void rafraichirEcranMenu()
{
    clrscr();
    afficherMessageIntroduction();
    afficherPendu(COUPS);
    afficherMenu();
    afficherMessageVotreChoix();
}

char gererChoixMenu()
{
    char choixUtilisateur = lireCaractere();

    switch(choixUtilisateur)
    {
        case '1' :
            demarrerJeu();
            break;
        case 'Q' :
            quitterProgramme();
            break;
    }

    return choixUtilisateur;
}

void quitterProgramme()
{
    exit(0);
}

void rafraichirEcranPendu(int coupsRestants)
{
    clrscr();
    afficherMessageIntroduction();
    afficherPendu(COUPS - coupsRestants);
    afficherMessageCoupsRestants(coupsRestants);
    afficherMessageMotSecret(obtenirMotMasque());
    afficherMessageProposerLettre();
}
