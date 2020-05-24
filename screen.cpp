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
#include "option.h"

/*= CONSTANTES SYMBOLIQUES ==========================================*/

#define COUPS 6

/*= FONCTIONS =======================================================*/

void rafraichirEcranMenu()
{
    char choixUtilisateur = ' ';

    do
    {
        clrscr();
        afficherMessageIntroduction();
        afficherPendu(COUPS);
        afficherMenu();
        afficherMessageVotreChoix();
        choixUtilisateur = gererChoixMenu();
    }
    while (choixUtilisateur != 'Q');
}

void rafraichirEcranOptions()
{
    clrscr();
    afficherMessageIntroduction();
    afficherPendu(COUPS);
    afficherOptions();
    afficherMessageVotreChoix();
    gererChoixOptions();
}

void rafraichirEcranOptionsMode()
{
    clrscr();
    afficherMessageIntroduction();
    afficherPendu(COUPS);
    afficherOptionsMode();
    afficherMessageVotreChoix();
    gererChoixOptionsMode();
}

void rafraichirEcranOptionsDifficulte()
{
    clrscr();
    afficherMessageIntroduction();
    afficherPendu(COUPS);
    afficherOptionsDifficulte();
    afficherMessageVotreChoix();
    gererChoixOptionsDifficulte();
}

char gererChoixMenu()
{
    char choixUtilisateur = lireCaractere();

    switch(choixUtilisateur)
    {
        case '1' :
            demarrerJeu();
            break;
        case '2' :
            rafraichirEcranOptions();
            break;
        case 'Q' :
            quitterProgramme();
            break;
    }

    return choixUtilisateur;
}

char gererChoixOptions()
{
    char choixUtilisateur = lireCaractere();

    switch(choixUtilisateur)
    {
        case '1' :
            rafraichirEcranOptionsDifficulte();
            break;
        case '2' :
            rafraichirEcranOptionsMode();
            break;
        case 'Q' :
            rafraichirEcranMenu();
            break;
    }
}

char gererChoixOptionsMode()
{
    char choixUtilisateur = lireCaractere();

    switch(choixUtilisateur)
    {
        case 'V' :
        case 'N' :
        case 'I' :
            ecrireOptionMode(choixUtilisateur);
        case 'Q' :
            rafraichirEcranOptions();
            break;
    }
}

char gererChoixOptionsDifficulte()
{
    char choixUtilisateur = lireCaractere();

    switch(choixUtilisateur)
    {
        case '1' :
        case '2' :
        case '3' :
        case '4' :
        case '5' :
            ecrireOptionDifficulte(choixUtilisateur);
        case 'Q' :
            rafraichirEcranOptions();
            break;
    }
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
