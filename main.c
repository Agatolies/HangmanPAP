/*********************************************************************/
/* Principes algorithmique et programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-22                                             */
/*********************************************************************/

/* main.c
   ------                                                            */

/*= Directives de pr�compilation ====================================*/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dico.h"

/*= Constantes symboliques ==========================================*/
#define TRUE  1
#define FALSE 0

/*= Prototypes des fonctions ========================================*/
int  verifierVictoire (int*, int        );
int  rechercherLettre (char, char*, int*);
char lireCaractere    (                 );

/*= Fonction principale =============================================*/
int main(int argc, char* argv)
{
    /*= D�clarations ================================================*/
    // Stocke la lettre propos�e par l'utilisateur (retour du scanf)
    char lettreProposee = 0;
    // Mot � trouver pour gagner la partie
    char* motSecret;
    // Un tableau de bool�ens. Chaque case correspond � une lettre du mot secret. 0 = lettre non trouv�e, 1 = lettre trouv�e
    int* lettreTrouvee = NULL;
    // Compteur de coups restants (0 = fin du jeu)
    int coupsRestants = 10;
    // Compteur pour parcourir les diff�rents tableaux
    int cptr = 0;
    int tailleMot = 0;

    /*= Traitements ================================================*/
    afficherMessageIntroduction();

    debutJeu(motSecret, tailleMot, lettreTrouvee);

    /* V�rification que la fonction piocherMot retourne bien un motSecret existant
    if (piocherMot(motSecret) == FALSE)
        exit(0);

    // Calculer la taille du tableau contenant le mot � trouver.
    tailleMot = strlen(motSecret);

    // Allocation de m�moire pour le tableau lettreTrouvee
    lettreTrouvee = malloc(tailleMot * sizeof(int));

    // V�rification de la fonction malloc pour lettreTrouvee
    if (lettreTrouvee == NULL)
        exit(0);

    // Initialisation de toutes les cellules lettreTrouvee � 0
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        lettreTrouvee[cptr] = 0;*/

    essaisJeu(coupsRestants, tailleMot, lettreTrouvee, lettreProposee, motSecret);
    /* Tant qu'il reste au moins un coup � jouer ou que la partie n'est pas gagn�e
    while (coupsRestants > 0 && verifierVictoire(lettreTrouvee, tailleMot) == FALSE)
    {
        afficherMessageCoupsRestants(coupsRestants);
        afficherMessageMotSecret();

        // Affichage du mot secret en masquant les lettres non trouv�es - Exemple : *A**ON
        for (cptr = 0 ; cptr < tailleMot ; cptr++)
            // Affichage des lettres si trouv�es
            if (lettreTrouvee[cptr])
                afficherLettreTrouvee(motSecret, cptr);
            // Sinon, affichage d'�toiles pour les lettres manquantes
            else
                afficherLettreNonTrouvee();

        afficherMessageProposerLettre();
        lettreProposee = lireCaractere();

        // Si lettrePorposee n'apparait pas dans motSecret, le joueur a un coup en moins
        if (rechercherLettre(lettreProposee, motSecret, lettreTrouvee) == FALSE)
            coupsRestants--;
    }*/

    // Affichage du r�sultat de fin de partie
    if (verifierVictoire(lettreTrouvee, tailleMot) == TRUE)
        afficherMessageGagnant(motSecret);
    else
        afficherMessagePerdant(motSecret);

    // Lib�ration de la m�moire allou�e manuellement (par malloc)
    free(lettreTrouvee);

    return 0;
}

// Fonction qui v�rifie si toutes les lettres du mot ont �t� trouv�es
// Et donc que la partie est gagn�e
int verifierVictoire(int* lettreTrouvee, int tailleMot)
{
    /*= D�clarations ================================================*/
    int cptr = 0;
    int joueurGagne = 1;

    /*= Traitements ================================================*/
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        // Si l'une des lettres n'est pas encore trouv�e, on sort de la condition
        if (lettreTrouvee[cptr] == 0)
        {
            joueurGagne = 0;
            break;
        }

    return joueurGagne;
}
// Fonction qui v�rifie si la lettre propos�e se trouve dans motSecret
int rechercherLettre(char lettreProposee, char* motSecret, int* lettreTrouvee)
{
    /*= D�clarations ================================================*/
    int cptr = 0;
    int lettreExacte = 0;

    /*= Traitements ================================================*/
    // Verification que la lettre proposee se trouve dans motSecret
    for (cptr = 0 ; motSecret[cptr] != '\0' ; cptr++)
        // Si la lettre y est
        if (lettreProposee == motSecret[cptr])
        {
            // M�morisation de la lettre pr�sente dans motSecret
            lettreExacte = 1;
            // La case du tableau de bool�ens correspondant � la lettre actuelle est mise � 1
            lettreTrouvee[cptr] = 1;
        }

    return lettreExacte;
}
