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

// Fonction qui lit le 1er caractere propose
char lireCaractere()
{
    /*= Declarations ================================================*/
    char caractere = ' ';

    /*= Traitements ================================================*/
    // Le premier caractere est lu
    caractere = getchar();
    // Si le caractere est en minuscule, il est passe en majuscule
    caractere = toupper(caractere);

    // Les autres caracteres memorises sont lus un a un jusqu'a l'\n
    // Sinon, chaque caractere supplementaire cree une nouvelle tentative
    while (getchar() != '\n') ;

    // Retour du premier caractere lu
    return caractere;
}

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

void afficherMessageIntroduction()
{
    printf("  _           ______              _             _ _ _             _   \n");
    printf(" | |          | ___ \\            | |           (_) | |           | |  \n");
    printf(" | |     ___  | |_/ /__ _ __   __| | ___  _   _ _| | | __ _ _ __ | |_ \n");
    printf(" | |    / _ \\ |  __/ _ \\ '_ \\ / _` |/ _ \\| | | | | | |/ _` | '_ \\| __|\n");
    printf(" | |___|  __/ | | |  __/ | | | (_| | (_) | |_| | | | | (_| | | | | |_ \n");
    printf(" \\_____/\\___| \\_|  \\___|_| |_|\\__,_|\\___/ \\__,_|_|_|_|\\__,_|_| |_|\\__|\n\n");
}

void afficherMessageCoupsRestants(const int coupsRestants)
{
    printf("\n\n Il vous reste %d coups a jouer", coupsRestants);
}

void afficherMessageMotSecret(const char* motMasque)
{
    printf("\n Quel est le mot secret ?    \"%s\"", motMasque);
}

void afficherMessageProposerLettre()
{
    printf("\n Proposez une lettre : ");
}

void afficherMessageGagnant(const char* motSecret)
{
    printf("\n\n Gagne ! Le mot secret etait bien : %s", motSecret);
}

void afficherMessagePerdant(const char* motSecret)
{
    printf("\n\n Perdu ! Le mot secret etait : %s", motSecret);
}

void afficherMessageVotreChoix()
{
    printf("\n Votre choix : ");
}

void afficherMessageRetourMenu()
{
    printf("\n Appuyer deux fois sur <entree> pour revenir au Menu principal");
}

void afficherMessageLettresErronees(const char* lettresErronnees)
{
    // Si la premiere cellule du tableau contient un ' ' c'est que ce tableau est vide
    if(lettresErronnees[0] != ' ')
        printf("\n Les lettres erronees sont : %s\n", lettresErronnees);
}

void afficherMessageLettreDejaProposee()
{
    printf("\n Cette lettre a deja ete proposee.");
}

void afficherMessageSaisieIncorrecte()
{
    printf(" Saisie incorrecte : ");
}

void afficherMessageErreurFichier(const char* nomFichier)
{
    printf("Impossible d'ouvrir le fichier %s.", nomFichier);
}

void afficherMessageAPropos()
{
    printf("\n Ce jeu du pendu a ete cree par Laure D'Este en mai 2020 dans le cadre\n");
    printf(" du cours de Principes Algorithmiques et Programmation donne par\n");
    printf(" Monsieur S. Evrard de l'ecole IPEPS Seraing.\n");
}

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

void afficherMenu()
{
    printf("\n *** MENU PRINCIPAL ***");
    printf("\n\n <1>   Nouvelle partie\n");
    printf(" <2>   Options de jeu\n");
    printf(" <3>   A propos\n");
    printf(" <Q>   Quitter\n");
}

void afficherOptions()
{
    printf("\n *** OPTIONS ***\n\n");
    printf(" <1> Difficulte du dictionnaire     (%s)\n", lireOptionDifficulteString());
    printf(" <2> Mode du jeu                    (%s)\n", lireOptionModeString());
    printf(" <3> Options par defaut\n");
    printf(" <Q> Revenir a l'ecran principal\n");
}

void afficherOptionsMode()
{
    printf("\n *** OPTIONS MODE ***\n\n");
    printf(" <V> %s\n", convertirOptionModeString('V'));
    printf(" <N> %s\n", convertirOptionModeString('N'));
    printf(" <I> %s\n", convertirOptionModeString('I'));
    printf(" <Q> Revenir a l'ecran des options\n");
}

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





