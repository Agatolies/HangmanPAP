/*********************************************************************/
/* Principes Algorithmique et Programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-23                                             */
/*********************************************************************/
/*                                                                   */
/* display.cpp                                                       */
/* ------                                                            */
/* Ces fonctions gerent les entrees et les sorties depuis et vers    */
/* la console (logique d'affichage)                                  */
/*                                                                   */
/*= DIRECTIVES DE PRECOMPILATION ====================================*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "display.h"
#include "option.h"

/*= FONCTIONS =======================================================*/

/*
 * Fonction:  lireCaractere
 * --------------------
 * Lit tous les caracteres saisis au clavier et convertit le premier en majuscule
 * Permet egalement de stopper l'execution d'une fonction d'affichage d'ecran.3
 *
 *  retourne: le premier caractere saisi
 */

char lireCaractere()
{
    /*= Declarations ================================================*/
    char caractere = ' ';

    /*= Traitements ================================================*/
    caractere = getchar();
    caractere = toupper(caractere);

    // Les autres caracteres memorises sont lus un a un jusqu'a l'\n
    // Sans cela, chaque caractere supplementaire cree une nouvelle tentative
    while (getchar() != '\n') ;

    return caractere;
}


/*
 * Fonction:  lireCaractereChoix
 * --------------------
 * Lit un caractere saisi au clavier en s'appuyant sur une liste de choix.
 * Elle utilise la fonction lireCaractere du meme module.
 * Si le caractere ne fait pas partie de la liste de choix, elle affiche
 * message d'erreur.
 *
 *  listeChoix: une chaîne de caractere contenant tous les choix possibles.
 *
 *  retourne: le premier caractere saisi
 */

char lireCaractereChoix(const char* listeChoix)
{
    char caractere = lireCaractere();

    while(strchr(listeChoix, caractere) == NULL)
    {
        afficherMessageSaisieIncorrecte();
        caractere = lireCaractere();
    }

    return caractere;
}


/*
 * Fonction:  lireCaractereAlpha
 * --------------------
 * Lit un caractere alphabétique saisi au clavier en s'appuyant
 * sur la fonction lireCaractere du meme module.
 * Cette implementation se base sur le code ASCII du caractere (de A=65 à Z=90)
 * Si le caractere n'est pas une lettre, elle affiche message d'erreur.
 *
 *  retourne: le premier caractere saisi
 */

char lireCaractereAlpha()
{
    char caractere = lireCaractere();

    while (caractere < 65 || caractere > 90)
    {
        afficherMessageSaisieIncorrecte();
        caractere = lireCaractere();
    }

    return caractere;
}


/*
 * Fonction:  afficherMessageIntroduction
 * --------------------
 * Ecrit dans la console le nom stylise de l'application.
 */

void afficherMessageIntroduction()
{
    printf("  _           ______              _             _ _ _             _   \n");
    printf(" | |          | ___ \\            | |           (_) | |           | |  \n");
    printf(" | |     ___  | |_/ /__ _ __   __| | ___  _   _ _| | | __ _ _ __ | |_ \n");
    printf(" | |    / _ \\ |  __/ _ \\ '_ \\ / _` |/ _ \\| | | | | | |/ _` | '_ \\| __|\n");
    printf(" | |___|  __/ | | |  __/ | | | (_| | (_) | |_| | | | | (_| | | | | |_ \n");
    printf(" \\_____/\\___| \\_|  \\___|_| |_|\\__,_|\\___/ \\__,_|_|_|_|\\__,_|_| |_|\\__|\n\n");
}


/*
 * Fonction:  afficherMessageCoupsRestants
 * --------------------
 * Ecrit dans la console le nombre de coups restants a jouer lors d'une partie.
 * Ce message est utilise par le module game.
 *
 *  coupsRestants: un entier representant le nombre de coups restants.
 */

void afficherMessageCoupsRestants(const int coupsRestants)
{
    printf("\n\n Il vous reste %d coups a jouer", coupsRestants);
}


/*
 * Fonction:  afficherMessageMotSecret
 * --------------------
 * Ecrit dans la console un message demandant quel est le mot secret.
 * Ainsi que le mot a deviner sous les formes:
 *   - *Y**E*E ("*" pour une lettre trouvee
 *              en mode visible et intermediaire)
 *   - ?+??+?+ ("+" pour une lettre trouvee
                "?"  pour une lettre non trouvee
                en mode invisible)
 *
 *  motMasque: une chaîne de caractere qui comprend des "1" si la lettre a
 *             ete trouvee, sinon "0"
 */

void afficherMessageMotSecret(const char* motMasque)
{
    printf("\n Quel est le mot secret ?    \"%s\"", motMasque);
}

/*
 * Fonction:  afficherMessageProposerLettre
 * --------------------
 * Ecrit dans la console un message demandant de proposer une lettre
 * pour le mot secret.
 */

void afficherMessageProposerLettre()
{
    printf("\n Proposez une lettre : ");
}


/*
 * Fonction:  afficherMessageGagnant
 * --------------------
 * Ecrit dans la console un message indiquant au joueur qu'il a trouve
 * le mot mystere et donc gagne la partie.
 *
 *  motSecret: chaîne de caractere qui contient toutes les lettres du
 *             mot secret.
 *
 *
 *  retourne:
 */

void afficherMessageGagnant(const char* motSecret)
{
    printf("\n\n Gagne ! Le mot secret etait bien : %s\n", motSecret);
}


/*
 * Fonction:  afficherMessagePerdant
 * --------------------
 * Ecrit dans la console un message indiquant au joueur qu'il n'a pas
 * trouve le mot mystere et a perdu la partie.
 *
 *  motSecret: chaîne de caractere qui contient toutes les lettres du
 *             mot secret.
 */

void afficherMessagePerdant(const char* motSecret)
{
    printf("\n\n Perdu ! Le mot secret etait : %s\n", motSecret);
}


/*
 * Fonction:  afficherMessageVotreChoix
 * --------------------
 * Ecrit dans la console un message demandant le choix de l'utilisateur.
 */

void afficherMessageVotreChoix()
{
    printf("\n Votre choix : ");
}


/*
 * Fonction:  afficherMessageRetourMenu
 * --------------------
 * Ecrit dans la console un message demandant a l'utilisateur d'appuyer 2 fois
 * sur la touche entree.
 */

void afficherMessageRetourMenu()
{
    printf("\n Appuyer deux fois sur <entree> pour revenir au Menu principal");
}


/*
 * Fonction:  afficherMessageLettresErronees
 * --------------------
 * Ecrit dans la console un message avec les lettres erronnees deja proposee
 * par l'utilisateur.
 * Si la premiere cellule du tableau contient un ' ' c'est que ce tableau est vide
 *
 *  lettresErrones: une chaîne de caracteres reprenant les lettres proposees
 *                   par l'utilisateur mais qui ne font pas partie du mot mystere.
 */

void afficherMessageLettresErronees(const char* lettresErronees)
{
    if(lettresErronees[0] != ' ')
        printf("\n Les lettres erronees sont : %s\n", lettresErronees);
}


/*
 * Fonction:  afficherMessageLettreDejaProposee
 * --------------------
 * Ecrit dans la console un message indiquant a l'utilisateur que le lettre
 * qu'il saisi a deja ete proposee auparavant.
 */

void afficherMessageLettreDejaProposee()
{
    printf("\n Cette lettre a deja ete proposee.");
}


/*
 * Fonction:  afficherMessageSaisieIncorrecte
 * --------------------
 * Ecrit un message dans la console lorsque l'utilisateur saisi un
 * caractere qui n'est pas permis.
 */

void afficherMessageSaisieIncorrecte()
{
    printf(" Saisie incorrecte : ");
}


/*
 * Fonction:  afficherMessageErreurFichier
 * --------------------
 * Ecrit dans la console un message si le fichier n'existe pas.
 *
 *  nomFichier: une chaine de caractere reprenant le nom du fichier.
 */

void afficherMessageErreurFichier(const char* nomFichier)
{
    printf("Impossible d'ouvrir le fichier %s.", nomFichier);
}


/*
 * Fonction:  afficherMessageAPropos
 * --------------------
 * Ecrit dans la console un message reprenant les informations sur le pendu.
 */

void afficherMessageAPropos()
{
    printf("\n *** A PROPOS ***\n\n");
    printf(" Ce jeu du pendu a ete cree par Laure D'Este en mai 2020 dans le cadre\n");
    printf(" du cours de Principes Algorithmiques et Programmation donne par\n");
    printf(" Monsieur S. Evrard a l'ecole IPEPS Seraing.\n");
}


/*
 * Fonction:
 * --------------------
 * Ecrit dans la console un message sous la forme d'un pendu en format ASCII.
 * Le pendu evolue en fonction du nombre d'erreurs.
 *
 *   cptrErreur: un entier qui represente le nombre d'erreurs faites dans
 *               la partie en cours.
 */

void afficherPendu(const int cptrErreur)
{
    char tete        = (cptrErreur >= 1) ? '@'  : ' ';
    char buste       = (cptrErreur >= 2) ? '|'  : ' ';
    char brasGauche  = (cptrErreur >= 3) ? '/'  : ' ';
    char brasDroit   = (cptrErreur >= 4) ? '\\' : ' ';
    char jambeGauche = (cptrErreur >= 5) ? '/'  : ' ';
    char jambeDroite = (cptrErreur == 6) ? '\\' : ' ';

    printf("      =========     \n");
    printf("       ||/   |      \n");
    printf("       ||    %c     \n", tete);
    printf("       ||   %c%c%c  \n", brasGauche, buste, brasDroit);
    printf("       ||    %c     \n", buste);
    printf("       ||   %c %c   \n", jambeGauche, jambeDroite);
    printf("   ____||__________ \n");
    printf("  /    ||         /|\n");
    printf(" /_______________/ /\n");
    printf(" |_______________|/ \n");
}


/*
 * Fonction:  afficherMenu
 * --------------------
 * Ecrit dans la console un message reprenant les options du menu principal.
 */

void afficherMenu()
{
    printf("\n *** MENU PRINCIPAL ***");
    printf("\n\n <1>   Nouvelle partie\n");
    printf(" <2>   Options de jeu\n");
    printf(" <3>   A propos\n");
    printf(" <Q>   Quitter\n");
}


/*
 * Fonction:  afficherOptions
 * --------------------
 * Ecrit dans la console un message reprenant les options du menu options.
 * Ainsi que le niveau de difficulte et le mode (par defaut ou selectionne
 * par l'utilisateur).
 */

void afficherOptions()
{
    printf("\n *** OPTIONS ***\n\n");
    printf(" <1> Difficulte du dictionnaire     (%s)\n", lireOptionDifficulteString());
    printf(" <2> Mode du jeu                    (%s)\n", lireOptionModeString());
    printf(" <3> Options par defaut\n");
    printf(" <Q> Revenir a l'ecran principal\n");
}


/*
 * Fonction:  afficherOptionsMode
 * --------------------
 * Ecrit dans la console un message reprenant les options du menu mode.
 * La fonction convertirOptionModeString est utilisee pour afficher les
 * differents modes possibles en toutes lettres.
 */

void afficherOptionsMode()
{
    printf("\n *** OPTIONS MODE ***\n\n");
    printf(" <V> %s\n", convertirOptionModeString('V'));
    printf(" <N> %s\n", convertirOptionModeString('N'));
    printf(" <I> %s\n", convertirOptionModeString('I'));
    printf(" <Q> Revenir a l'ecran des options\n");
}


/*
 * Fonction:  afficherOptionsDifficulte
 * --------------------
 * Ecrit dans la console un message reprenant les options du menu difficulte.
 * La fonction convertirOptionDifficulteString est utilisee pour afficher les
 * differents choix de difficultes possibles en toutes lettres.
 */

void afficherOptionsDifficulte()
{
    printf("\n *** OPTIONS DIFFICULTE ***\n\n");
    printf(" <1> %s\n", convertirOptionDifficulteString('1'));
    printf(" <2> %s\n", convertirOptionDifficulteString('2'));
    printf(" <3> %s\n", convertirOptionDifficulteString('3'));
    printf(" <4> %s\n", convertirOptionDifficulteString('4'));
    printf(" <5> %s\n", convertirOptionDifficulteString('5'));
    printf(" <Q> Revenir a l'ecran des options\n");
}
