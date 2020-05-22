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
int  verifierVictoire (int*, long       );
int  rechercherLettre (char, char*, int*);
char lireCaractere    (                 );

/*= Fonction principale =============================================*/
int main(int argc, char* argv)
{
    /*= Déclarations ================================================*/
    // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char lettre = 0;
    // Ce sera le mot à trouver
    char* motSecret;
    // Un tableau de booléens. Chaque case correspond à une lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée
    int* lettreTrouvee = NULL;
    // Compteur de coups restants (0 = mort)
    long coupsRestants = 10;
    // Une petite variable pour parcourir les tableaux
    long cptr = 0;
    long tailleMot = 0;

    /*= Traitements ================================================*/
    //Introdutcion au jeu
    printf("Bienvenue dans le Pendu !\n\n");

    // Fonction pour aller piocher le mot à trouver. Retourne 0 si erreur
    if (piocherMot(motSecret) == FALSE)
        exit(0);

    // Calculer la taille du tableau contenant le mot à trouver.
    tailleMot = strlen(motSecret);

    // Allocation de mémoire pour le tableau lettreTrouvee
    lettreTrouvee = malloc(tailleMot * sizeof(int));
    if (lettreTrouvee == NULL)
        exit(0);

    // Initialisation de toutes les cellules de lettreTrouvee à 0
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        lettreTrouvee[cptr] = 0;

    // On continue à jouer tant qu'il reste au moins un coup à jouer ou qu'on n'a pas gagné
    while (coupsRestants > 0 && verifierVictoire(lettreTrouvee, tailleMot) == FALSE)
    {
        printf("\n\nIl vous reste %ld coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");

        // On affiche le mot secret en masquant les lettres non trouvées - Exemple : *A**ON
        for (cptr = 0 ; cptr < tailleMot ; cptr++)
            // Si on a trouvé la lettre n°cptr on l'affiche
            if (lettreTrouvee[cptr])
                printf("%c", motSecret[cptr]);
            // Sinon, on affiche une étoile pour les lettres non trouvées
            else
                printf("*");

        printf("\nProposez une lettre : ");
        lettre = lireCaractere();

        // Si ce n'était PAS une lettre du motSecret
        if (rechercherLettre(lettre, motSecret, lettreTrouvee) == FALSE)
            // On enlève un coup au joueur
            coupsRestants--;
    }

    if (verifierVictoire(lettreTrouvee, tailleMot))
        printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);

    // On libère la mémoire allouée manuellement (par malloc)
    free(lettreTrouvee);

        return 0;
}

char lireCaractere()
{
    /*= Déclarations ================================================*/
    char caractere = 0;

    /*= Traitements ================================================*/
    // On lit le premier caractère
    caractere = getchar();
    // On met la lettre en majuscule si elle ne l'est pas déjà
    caractere = toupper(caractere);

    // On lit les autres caractères mémorisés un à un jusqu'à l'\n
    while (getchar() != '\n') ;

    // On retourne le premier caractère qu'on a lu
    return caractere;
}

int verifierVictoire(int* lettreTrouvee, long tailleMot)
{
    /*= Déclarations ================================================*/
    long cptr = 0;
    int joueurGagne = 1;

    /*= Traitements ================================================*/
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        if (lettreTrouvee[cptr] == 0)
            joueurGagne = 0;

    return joueurGagne;
}

int rechercherLettre(char lettre, char* motSecret, int* lettreTrouvee)
{
    /*= Déclarations ================================================*/
    long cptr = 0;
    int bonneLettre = 0;

    /*= Traitements ================================================*/
    // On parcourt motSecret pour vérifier si la lettre proposée y est
    for (cptr = 0 ; motSecret[cptr] != '\0' ; cptr++)
        // Si la lettre y est
        if (lettre == motSecret[cptr])
        {
            // On mémorise que c'était une bonne lettre
            bonneLettre = 1;
            // On met à 1 le case du tableau de booléens correspondant à la lettre actuelle
            lettreTrouvee[cptr] = 1;
        }

    return bonneLettre;
}
