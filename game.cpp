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
#include "option.h"
#include "myconio.h"

/*= CONSTANTES SYMBOLIQUES ==========================================*/

#define TRUE  1
#define FALSE 0
#define COUPS 6

/*= DECLARATIONS GLOBALES ===========================================*/

/* L'utilisation des variables globales est justifi�e par le fait que*/
/* toutes les fonctions de ce module les utilisent.                  */

// Mot a trouver pour gagner la partie
char motSecret[50];
// Un tableau de booleens. Chaque case correspond a une lettre du mot secret. 0 = lettre non trouvee, 1 = lettre trouvee
int* lettresTrouvees;
// Compteur de coups restants (0 = fin du jeu)
int coupsRestants;
// Taille du mot mystere
int tailleMot;
// Booleen qui indique si le joueur a gagne la partie ou non
int victoire;
// chaine de caractere reprenant l'ensemble des lettres erronees deja proposees.
char lettresErronees[COUPS];
// chaine de caractere reprenant l'etat actuel du mot mystere
char* motMasque = NULL;

/*= FONCTIONS =======================================================*/


/*
 * Fonction:  demarrerJeu
 * --------------------
 * Routine principale du module qui initilise ses variables,
 * gere la progression d'une partie et verifie � chaque coup
 * si l'utilisateur a gagne.
 * A la fin d'une partie, un message invite l'utilisateur a
 * retourner vers le menu principal.
 */

void demarrerJeu()
{
    char* motMasque = NULL;

    initialiser();

    // Tant qu'il reste au moins un coup a jouer ou que la partie n'est pas gagnee
    rafraichirEcranPendu();
    while (coupsRestants > 0 && victoire == FALSE)
    {
        jouerCoup();
        rafraichirEcranPendu();
        victoire = verifierVictoire();
    }

    afficherMessageFinPartie();
    afficherMessageRetourMenu();
    lireCaractere();

    // Liberation de la memoire allouee manuellement (par malloc)
    free(lettresTrouvees);
}


/*
 * Fonction:  initialiser
 * --------------------
 * Initialise toutes les variables utilisees par le jeu du pendu
 * avant de demarrer une partie.
 */

void initialiser()
{
    int cptr = 0;

    // R�initialisation des variables du module
    lettresTrouvees = NULL;
    coupsRestants = COUPS;
    tailleMot = 0;
    victoire = FALSE;

    for(cptr = 0 ; cptr < COUPS ; cptr++)
        lettresErronees[cptr] = ' ';

    // Verification que la fonction piocherMot retourne bien un motSecret existant
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
}


/*
 * Fonction:  jouerCoup
 * --------------------
 * Lit la proposition de l'utilisateur et verifie si cette lettre est
 * dans le mot secret ou non. Si oui, la fonction s'arrete.
 * Si non, la fonction  verifie si la lettre proposee l'a deja ete
 * auparavant. Si oui, un message apparait et la fonction s'arrete.
 * Si non, l'utilisateur a un coup en moins et la fonction s'arrete.
 */

void jouerCoup()
{
    // Stocke la lettre proposee par l'utilisateur
    char lettre = lireCaractereAlpha();
    int lettreDejaProposee = FALSE;
    int cptr = 0;

    // Si lettre n'apparait pas dans motSecret
    if (rechercherLettre(lettre) == FALSE)
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
        // Si non, coups en moins et ajout de la lettre dans la chaine lettresErronees
        else
        {
            lettresErronees[COUPS - coupsRestants] = lettre;
            coupsRestants--;
        }

    }
}


/*
 * Fonction:  rafraichirMotMasque
 * --------------------
 * Lit le mode choisi par l'utilisateur et modifie la chaine motMasque
 * en fonction:
 * en mode invisible ajout de + (si lettre trouvee) et ? (si lettre introuvee)
 * en mode visible ou intermediaire ajout des lettres trouvees et de * (si lettre
 * non trouvee).
 */

void rafraichirMotMasque()
{
    // Allocation de memoire pour le tableau motMasque
    motMasque = (char*) malloc(sizeof(char) * (tailleMot + 1));
    int cptr = 0;

    // Verification de la fonction malloc pour motMasque
    if(motMasque == NULL)
        exit(0);

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
}


/*
 * Fonction:  rafraichirEcranPendu
 * --------------------
 * Rafraichi la chaine de caractere motMasque, efface l'ecran actuel,
 * affiche le titre du jeu, le pendu actualise (en fonction des coups restants),
 * le mot secret actualise, le nombre de coups restants et eventuellement
 * le tableau des lettres erroness deja proposees. Libere la memoire de la chaine motMasque.
 */

void rafraichirEcranPendu()
{
    rafraichirMotMasque();

    clrscr();
    afficherMessageIntroduction();
    afficherPendu(COUPS - coupsRestants);
    afficherMessageMotSecret(motMasque);
    afficherMessageCoupsRestants(coupsRestants);

    if (lireOptionMode() == 'V')
        afficherMessageLettresErronees(lettresErronees);

    afficherMessageProposerLettre();

    free(motMasque);
}


/*
 * Fonction:  afficherMessageFinPartie
 * --------------------
 * Gere le message a afficher en cas de victoire ou de perte de
 * la partie.
 */

void afficherMessageFinPartie()
{
    (victoire == TRUE)
        ? afficherMessageGagnant(motSecret)
        : afficherMessagePerdant(motSecret);
}


/*
 * Fonction:  verifierVictoire
 * --------------------
 * Verifie si toutes les lettres du mot mystere ont ete trouvees
 * et donc que la partie est gagnee.
 *
 *  retourne : booleen indiquant si le joueur a gagne la partie
 */

int verifierVictoire()
{
    int cptr = 0;
    int joueurGagne = TRUE;

    for (cptr = 0 ; cptr < tailleMot ; cptr++)
    {
        // Si l'une des lettres n'est pas encore trouvee, on sort de la condition
        if (lettresTrouvees[cptr] == 0)
        {
            joueurGagne = FALSE;
            break;
        }
    }

    return joueurGagne;
}


/*
 * Fonction:  rechercherLettre
 * --------------------
 * Verifie si la lettre proposee se trouve dans motSecret
 *
 *  retourne: un booleen, 1 si la lettre est trouvee, 0 si non
 */

// Fonction qui v
int rechercherLettre(const char lettreProposee)
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


