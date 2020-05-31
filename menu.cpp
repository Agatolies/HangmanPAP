/*********************************************************************/
/* Principes Algorithmique et Programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-23                                             */
/*********************************************************************/
/*                                                                   */
/* menu.cpp                                                          */
/* ------                                                            */
/* Ces fonctions servent a gerer les menus                           */
/*                                                                   */
/*= DIRECTIVES DE PRECOMPILATION ====================================*/

#include <stdlib.h>

#include "menu.h"
#include "display.h"
#include "game.h"
#include "option.h"
#include "myconio.h"

/*= CONSTANTES SYMBOLIQUES ==========================================*/

#define COUPS 6

/*= FONCTIONS =======================================================*/

/*
 * Fonction:  rafraichirEcranMenu
 * --------------------
 * Rafraichit l'ecran menu tant que l'utilisateur n'a pas saisi la
 * lettre 'Q'.
 */

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
    } while (choixUtilisateur != 'Q');
}


/*
 * Fonction:  rafraichirEcranOptions
 * --------------------
 * Rafraichit l'ecran des options et attend une saisie de l'utilisateur.
 */

void rafraichirEcranOptions()
{
    clrscr();
    afficherMessageIntroduction();
    afficherPendu(COUPS);
    afficherOptions();
    afficherMessageVotreChoix();
    gererChoixOptions();
}


/*
 * Fonction:  rafraichirEcranOptionsMode
 * --------------------
 * Rafraichit l'ecran permettant la selection d'un mode de jeu.
 */

void rafraichirEcranOptionsMode()
{
    clrscr();
    afficherMessageIntroduction();
    afficherPendu(COUPS);
    afficherOptionsMode();
    afficherMessageVotreChoix();
    gererChoixOptionsMode();
}


/*
 * Fonction:  rafraichirEcranOptionsDifficulte
 * --------------------
 * Rafraichit l'ecran permettant la selection d'un niveau de difficulte.
 */

void rafraichirEcranOptionsDifficulte()
{
    clrscr();
    afficherMessageIntroduction();
    afficherPendu(COUPS);
    afficherOptionsDifficulte();
    afficherMessageVotreChoix();
    gererChoixOptionsDifficulte();
}



/*
 * Fonction:  rafraichirEcranAPropos
 * --------------------
 * Rafraichit l'ecran permettant d'afficher les informations sur le jeu.
 */

void rafraichirEcranAPropos()
{
    clrscr();
    afficherMessageIntroduction();
    afficherPendu(COUPS);
    afficherMessageAPropos();
    afficherMessageRetourMenu();
    lireCaractere();
}


/*
 * Fonction:  gererChoixMenu
 * --------------------
 * Lit le caractere saisi par l'utilisateur, verifie qu'il fait bien
 * partie des caracteres autorises (saisie securisee) et le redirige
 * vers la fonctionnalite choisie.
 *
 *  retourne: un caractere saisi par l'utilisateur.
 */

char gererChoixMenu()
{
    char choixUtilisateur = lireCaractereChoix("123Q");

    switch (choixUtilisateur)
    {
        case '1':
            demarrerJeu();
            break;
        case '2':
            rafraichirEcranOptions();
            break;
        case '3':
            rafraichirEcranAPropos();
            break;
    }

    return choixUtilisateur;
}


/*
 * Fonction:  gererChoixOptions
 * --------------------
 * Lit le caractere saisi par l'utilisateur, verifie qu'il fait bien
 * partie des caracteres autorises (saisie securisee) et le redirige
 * vers la fonctionnalite choisie.
 *
 *
 *
 */

void gererChoixOptions()
{
    char choixUtilisateur = lireCaractereChoix("123Q");

    switch (choixUtilisateur)
    {
        case '1':
            rafraichirEcranOptionsDifficulte();
            break;
        case '2':
            rafraichirEcranOptionsMode();
            break;
        case '3':
            retablirOptions();
            rafraichirEcranOptions();
    }
}


/*
 * Fonction:  gererChoixOptionsMode
 * --------------------
 *
 *
 *
 *
 *
 *
 */

void gererChoixOptionsMode()
{
    char choixUtilisateur = lireCaractereChoix("VNIQ");

    switch (choixUtilisateur)
    {
        case 'V':
        case 'N':
        case 'I':
            ecrireOptionMode(choixUtilisateur);
        case 'Q':
            rafraichirEcranOptions();
            break;
    }
}


/*
 * Fonction:  gererChoixOptionsDifficulte
 * --------------------
 *
 *
 *
 *
 *
 *
 */

void gererChoixOptionsDifficulte()
{
    char choixUtilisateur = lireCaractereChoix("12345Q");

    switch (choixUtilisateur)
    {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            ecrireOptionDifficulte(choixUtilisateur);
        case 'Q':
            rafraichirEcranOptions();
            break;
    }
}

