/*********************************************************************/
/* Principes algorithmique et programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-22                                             */
/*********************************************************************/

/* main.c
   ------                                                            */

/*= Directives de précompilation ====================================*/
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
    /*= Déclarations ================================================*/
    // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char lettreProposee = 0;
    // Mot à trouver pour gagner la partie
    char* motSecret;
    // Un tableau de booléens. Chaque case correspond à une lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée
    int* lettreTrouvee = NULL;
    // Compteur de coups restants (0 = fin du jeu)
    int coupsRestants = 10;
    // Compteur pour parcourir les différents tableaux
    int cptr = 0;
    int tailleMot = 0;

    /*= Traitements ================================================*/
    afficherMessageIntroduction();

    debutJeu(motSecret, tailleMot, lettreTrouvee);

    /* Vérification que la fonction piocherMot retourne bien un motSecret existant
    if (piocherMot(motSecret) == FALSE)
        exit(0);

    // Calculer la taille du tableau contenant le mot à trouver.
    tailleMot = strlen(motSecret);

    // Allocation de mémoire pour le tableau lettreTrouvee
    lettreTrouvee = malloc(tailleMot * sizeof(int));

    // Vérification de la fonction malloc pour lettreTrouvee
    if (lettreTrouvee == NULL)
        exit(0);

    // Initialisation de toutes les cellules lettreTrouvee à 0
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        lettreTrouvee[cptr] = 0;*/

    essaisJeu(coupsRestants, tailleMot, lettreTrouvee, lettreProposee, motSecret);
    /* Tant qu'il reste au moins un coup à jouer ou que la partie n'est pas gagnée
    while (coupsRestants > 0 && verifierVictoire(lettreTrouvee, tailleMot) == FALSE)
    {
        afficherMessageCoupsRestants(coupsRestants);
        afficherMessageMotSecret();

        // Affichage du mot secret en masquant les lettres non trouvées - Exemple : *A**ON
        for (cptr = 0 ; cptr < tailleMot ; cptr++)
            // Affichage des lettres si trouvées
            if (lettreTrouvee[cptr])
                afficherLettreTrouvee(motSecret, cptr);
            // Sinon, affichage d'étoiles pour les lettres manquantes
            else
                afficherLettreNonTrouvee();

        afficherMessageProposerLettre();
        lettreProposee = lireCaractere();

        // Si lettrePorposee n'apparait pas dans motSecret, le joueur a un coup en moins
        if (rechercherLettre(lettreProposee, motSecret, lettreTrouvee) == FALSE)
            coupsRestants--;
    }*/

    // Affichage du résultat de fin de partie
    if (verifierVictoire(lettreTrouvee, tailleMot) == TRUE)
        afficherMessageGagnant(motSecret);
    else
        afficherMessagePerdant(motSecret);

    // Libération de la mémoire allouée manuellement (par malloc)
    free(lettreTrouvee);

    return 0;
}

// Fonction qui vérifie si toutes les lettres du mot ont été trouvées
// Et donc que la partie est gagnée
int verifierVictoire(int* lettreTrouvee, int tailleMot)
{
    /*= Déclarations ================================================*/
    int cptr = 0;
    int joueurGagne = 1;

    /*= Traitements ================================================*/
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        // Si l'une des lettres n'est pas encore trouvée, on sort de la condition
        if (lettreTrouvee[cptr] == 0)
        {
            joueurGagne = 0;
            break;
        }

    return joueurGagne;
}
// Fonction qui vérifie si la lettre proposée se trouve dans motSecret
int rechercherLettre(char lettreProposee, char* motSecret, int* lettreTrouvee)
{
    /*= Déclarations ================================================*/
    int cptr = 0;
    int lettreExacte = 0;

    /*= Traitements ================================================*/
    // Verification que la lettre proposee se trouve dans motSecret
    for (cptr = 0 ; motSecret[cptr] != '\0' ; cptr++)
        // Si la lettre y est
        if (lettreProposee == motSecret[cptr])
        {
            // Mémorisation de la lettre présente dans motSecret
            lettreExacte = 1;
            // La case du tableau de booléens correspondant à la lettre actuelle est mise à 1
            lettreTrouvee[cptr] = 1;
        }

    return lettreExacte;
}
