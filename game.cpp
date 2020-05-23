/*********************************************************************/
/* Principes Algorithmique et Programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-23                                             */
/*********************************************************************/
/*                                                                   */
/* game.cpp                                                          */
/* ------                                                            */
/* Ces fonctions servent a gerer la partie jeu du programme          */
/*                                                                   */
/*= DIRECTIVES DE PRECOMPILATION ====================================*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "game.h"
#include "display.h"
#include "dico.h"


/*= CONSTANTES SYMBOLIQUES ==========================================*/

#define TRUE  1
#define FALSE 0

/*= FONCTIONS =======================================================*/

int demarrerJeu()
{
    /*- Déclarations ------------------------------------------------*/
    // Stocke la lettre proposee par l'utilisateur
    char lettreProposee = 0;
    // Mot a trouver pour gagner la partie
    char motSecret[100] = {0};
    // Un tableau de bool�ens. Chaque case correspond a une lettre du mot secret. 0 = lettre non trouvee, 1 = lettre trouvee
    int* lettresTrouvees = NULL;
    // Compteur de coups restants (0 = fin du jeu)
    int coupsRestants = 10;
    // Compteur pour parcourir les differents tableaux
    int cptr = 0;
    int tailleMot = 0;

    /*- Traitements -------------------------------------------------*/

    afficherMessageIntroduction();

    //Verification que la fonction piocherMot retourne bien un motSecret existant
    if (piocherMot(motSecret) == FALSE)
        exit(0);

    // Calculer la taille du tableau contenant le mot a trouver.
    tailleMot = strlen(motSecret);

    // Allocation de memoire pour le tableau lettresTrouvees
    lettresTrouvees = (int*) malloc(tailleMot * sizeof(int));

    // Verification de la fonction malloc pour lettresTrouvees
    if (lettresTrouvees == NULL)
        exit(0);

    // Initialisation de toutes les cellules lettresTrouvees a 0
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        lettresTrouvees[cptr] = 0;

    essaisJeu(coupsRestants, tailleMot, lettresTrouvees, lettreProposee, motSecret);

    afficherMessageFinPartie(lettresTrouvees,tailleMot,motSecret);

    return 0;
}

// Fonction qui verifie si la lettre proposee se trouve dans motSecret
int rechercherLettre(char lettreProposee, char* motSecret, int* lettresTrouvees)
{
    /*= Declarations ================================================*/
    int cptr = 0;
    int lettreExacte = 0;

    /*= Traitements ================================================*/
    // Verification que la lettre proposee se trouve dans motSecret
    for (cptr = 0 ; motSecret[cptr] != '\0' ; cptr++)
        // Si la lettre y est
        if (lettreProposee == motSecret[cptr])
        {
            // Memorisation de la lettre presente dans motSecret
            lettreExacte = 1;
            // La case du tableau de booleens correspondant a la lettre actuelle est mise a 1
            lettresTrouvees[cptr] = 1;
        }

    return lettreExacte;
}

//Fonction qui sert a lancer le jeu et les essais suivants
void essaisJeu(int coupsRestants, int tailleMot, int* lettresTrouvees, char lettreProposee, char* motSecret)
{
    /*- Declarations ================================================*/
    int cptr = 0;

    /*- Traitements =================================================*/
    // Tant qu'il reste au moins un coup a jouer ou que la partie n'est pas gagnee
    while (coupsRestants > 0 && verifierVictoire(lettresTrouvees, tailleMot) == FALSE)
    {
        afficherMessageCoupsRestants(coupsRestants);
        afficherMessageMotSecret();

        // Affichage du mot secret en masquant les lettres non trouvees - Exemple : *A**ON
        for (cptr = 0 ; cptr < tailleMot ; cptr++)
            // Affichage des lettres si trouv�es
            if (lettresTrouvees[cptr])
                afficherLettreTrouvee(motSecret, cptr);
            // Sinon, affichage d'etoiles pour les lettres manquantes
            else
                afficherLettreNonTrouvee();

        afficherMessageProposerLettre();
        lettreProposee = lireCaractere();

        // Si lettrePorposee n'apparait pas dans motSecret, le joueur a un coup en moins
        if (rechercherLettre(lettreProposee, motSecret, lettresTrouvees) == FALSE)
            coupsRestants--;
    }
}

void afficherMessageFinPartie(int* lettresTrouvees, int tailleMot, char* motSecret)
{
    /*- Traitements =================================================*/
    if (verifierVictoire(lettresTrouvees, tailleMot) == TRUE)
        afficherMessageGagnant(motSecret);
    else
        afficherMessagePerdant(motSecret);

    // Liberation de la memoire allouee manuellement (par malloc)
    free(lettresTrouvees);
}

// Fonction qui verifie si toutes les lettres du mot ont ete trouvees
// Et donc que la partie est gagnee
int verifierVictoire(int* lettresTrouvees, int tailleMot)
{
    /*= Declarations ================================================*/
    int cptr = 0;
    int joueurGagne = 1;

    /*= Traitements ================================================*/
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        // Si l'une des lettres n'est pas encore trouvee, on sort de la condition
        if (lettresTrouvees[cptr] == 0)
        {
            joueurGagne = 0;
            break;
        }

    return joueurGagne;
}
