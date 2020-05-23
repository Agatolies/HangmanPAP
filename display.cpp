/*********************************************************************/
/* Principes Algorithmique et Programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-23                                             */
/*********************************************************************/
/*                                                                   */
/* display.cpp                                                       */
/* ------                                                            */
/* Ces fonctions g�rent les entr�es et les sorties depuis et vers    */
/* la console                                                        */
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

void afficherLettreTrouvee(char* motSecret, int cptr)
{
    printf("%c", motSecret[cptr]);
}

void afficherLettreNonTrouvee()
{
    printf("*");
}

void afficherMessageIntroduction()
{
    printf("Bienvenue dans le Pendouillant !\n\n");
}

void afficherMessageCoupsRestants(int coupsRestants)
{
    printf("\n\nIl vous reste %d coups a jouer", coupsRestants);
}

void afficherMessageMotSecret()
{
    printf("\nQuel est le mot secret ? ");
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

