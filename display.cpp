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

#include "display.h"

/*= FONCTIONS =======================================================*/

// Fonction qui lit le 1er caractere propose
char lireCaractere()
{
    /*= Declarations ================================================*/
    char caractere = 0;

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

void afficherMessageIntroduction()
{
    printf("Bienvenue dans le Pendouillant !\n\n");
}

void afficherMessageCoupsRestants(int coupsRestants)
{
    printf("\n\nIl vous reste %d coups a jouer", coupsRestants);
}

void afficherMessageMotSecret(char* motMasque)
{
    printf("\nQuel est le mot secret ? %s", motMasque);
}

void afficherMessageProposerLettre()
{
    printf("\nProposez une lettre : ");
}

void afficherMessageGagnant(char* motSecret)
{
    printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
}

void afficherMessagePerdant(char* motSecret)
{
    printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);
}

void afficherMessageErreurDico()
{
    printf("\nImpossible de charger le dictionnaire de mots");
}

void afficherMessageVotreChoix()
{
    printf("\nVotre choix : ");
}

void afficherPendu(int cptrErreur)
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
    printf("\n<1>   Nouvelle partie\n");
    //printf("<2>   Options de jeu\n");
    printf("<Q>   Quitter\n");
}


