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
#include <Windows.h>

#include "game.h"
#include "display.h"
#include "dico.h"
#include "screen.h"
#include "option.h"

/*= CONSTANTES SYMBOLIQUES ==========================================*/

#define TRUE  1
#define FALSE 0
#define COUPS 6

/*= DECLARATIONS GLOBALES ===========================================*/

/* L'utilisation des variables globales est justifiée par le fait que*/
/* toutes les fonctions de ce module les utilisent.                  */

// Mot a trouver pour gagner la partie
char motSecret[100];
// Un tableau de booleens. Chaque case correspond a une lettre du mot secret. 0 = lettre non trouvee, 1 = lettre trouvee
int* lettresTrouvees;
// Compteur de coups restants (0 = fin du jeu)
int coupsRestants;
int tailleMot;
int victoire;
char lettresErronees[COUPS];

/*= FONCTIONS =======================================================*/

int demarrerJeu()
{
    initialiser();

    // Tant qu'il reste au moins un coup a jouer ou que la partie n'est pas gagnee
    rafraichirEcranPendu(coupsRestants, lettresErronees);
    while (coupsRestants > 0 && victoire == FALSE)
    {
        jouerCoup();
        rafraichirEcranPendu(coupsRestants, lettresErronees);
        victoire = verifierVictoire(lettresTrouvees, tailleMot);
    }

    afficherMessageFinPartie();
    afficherMessageRetourMenu();
    lireCaractere();

    // Liberation de la memoire allouee manuellement (par malloc)
    free(lettresTrouvees);

    return 0;
}

/* Initialisation de toutes les variables utilisees par le jeu du pendu */
void initialiser()
{
    int cptr = 0;

    // Réinitialisation des variables du module
    lettresTrouvees = NULL;
    coupsRestants = COUPS;
    tailleMot = 0;
    victoire = FALSE;

    for(cptr = 0 ; cptr < COUPS ; cptr++)
        lettresErronees[cptr] = ' ';

    // Verification que la fonction piocherMot retourne bien un motSecret existant
    if (piocherMot(motSecret) == FALSE)
        quitterProgramme();

    // Calculer la taille du tableau contenant le mot a trouver.
    tailleMot = strlen(motSecret);

    // Allocation de memoire pour le tableau lettresTrouvees
    lettresTrouvees = (int*) malloc(tailleMot * sizeof(int));

    // Verification de la fonction malloc pour lettresTrouvees
    if (lettresTrouvees == NULL)
        quitterProgramme();

    // Initialisation de toutes les cellules lettresTrouvees a 0
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        lettresTrouvees[cptr] = 0;
}

void jouerCoup()
{
    // Stocke la lettre proposee par l'utilisateur
    char lettre = lireCaractereAlpha();
    int lettreDejaProposee = FALSE;
    int cptr = 0;

    // Si lettre n'apparait pas dans motSecret
    if (rechercherLettre(lettre, motSecret, lettresTrouvees) == FALSE)
    {
        // La lettre est-elle deja dans le tableau lettresErronees?
        for(cptr = 0 ; cptr < COUPS ; cptr++)
        {
            if(lettre == lettresErronees[cptr])
            {
                lettreDejaProposee = TRUE;
                break;
            }
        }

        // Si oui, pas de coups en moins
        if(lettreDejaProposee == TRUE)
        {
            afficherMessageLettreDejaProposee();
            Sleep(2000);
        }
        // Si non, coups en moins et ajout de la lettre dans tableau
        else
        {
            lettresErronees[COUPS - coupsRestants] = lettre;
            coupsRestants--;
        }

    }
}

char* obtenirMotMasque()
{
    char* motMasque = (char*) malloc(sizeof(char) * (tailleMot + 1));
    int cptr = 0;


    if(lireOptionMode() == 'I')
    {
        // Affichage du mot secret en mode invisible - Exemple : ?+??++
        for (cptr = 0 ; cptr < tailleMot ; cptr++)
        {
            motMasque[cptr] = (lettresTrouvees[cptr] == TRUE)
                ? '+'
                : '?';
        }
    }
    else
    {
        // Affichage du motSecret en mode visible ou intermediaire - Exemple : *A**ON
        for (cptr = 0 ; cptr < tailleMot ; cptr++)
        {
            motMasque[cptr] = (lettresTrouvees[cptr] == TRUE)
                ? motSecret[cptr]
                : '*';
        }
    }

    motMasque[tailleMot] = '\0';

    return motMasque;
}

void afficherMessageFinPartie()
{
    (victoire == TRUE)
        ? afficherMessageGagnant(motSecret)
        : afficherMessagePerdant(motSecret);
}

// Fonction qui verifie si toutes les lettres du mot ont ete trouvees
// Et donc que la partie est gagnee
int verifierVictoire(const int* lettresTrouvees, const int tailleMot)
{
    int cptr = 0;
    int joueurGagne = 1;

    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        // Si l'une des lettres n'est pas encore trouvee, on sort de la condition
        if (lettresTrouvees[cptr] == 0)
        {
            joueurGagne = 0;
            break;
        }

    return joueurGagne;
}

// Fonction qui verifie si la lettre proposee se trouve dans motSecret
int rechercherLettre(const char lettreProposee, const char* motSecret, int* lettresTrouvees)
{
    int cptr = 0;
    int lettreExacte = FALSE;

    // Verification que la lettre proposee se trouve dans motSecret
    for (cptr = 0 ; motSecret[cptr] != '\0' ; cptr++)
    {
        // Si la lettre y est
        if (lettreProposee == motSecret[cptr])
        {
            // Memorisation de la lettre presente dans motSecret
            lettreExacte = TRUE;
            // La case du tableau de booleens correspondant a la lettre actuelle est mise a 1
            lettresTrouvees[cptr] = TRUE;
        }
    }

    return lettreExacte;
}


