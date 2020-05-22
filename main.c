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
    char lettreProposee = 0;
    // Mot à trouver pour gagner la partie
    char* motSecret;
    // Un tableau de booléens. Chaque case correspond à une lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée
    int* lettreTrouvee = NULL;
    // Compteur de coups restants (0 = fin du jeu)
    long coupsRestants = 10;
    // Compteur pour parcourir les différents tableaux
    long cptr = 0;
    long tailleMot = 0;

    /*= Traitements ================================================*/
    //Introdutcion au jeu
    printf("Bienvenue dans le Pendu !\n\n");

    // Vérification que la fonction piocherMot retourne bien un motSecret existant
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
        lettreTrouvee[cptr] = 0;

    // Tant qu'il reste au moins un coup à jouer ou que la partie n'est pas gagnée
    while (coupsRestants > 0 && verifierVictoire(lettreTrouvee, tailleMot) == FALSE)
    {
        printf("\n\nIl vous reste %ld coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");

        // Affichage du mot secret en masquant les lettres non trouvées - Exemple : *A**ON
        for (cptr = 0 ; cptr < tailleMot ; cptr++)
            // Affichage des lettres si trouvées
            if (lettreTrouvee[cptr])
                printf("%c", motSecret[cptr]);
            // Sinon, affichage d'étoiles pour les lettres manquantes
            else
                printf("*");

        printf("\nProposez une lettre : ");
        lettreProposee = lireCaractere();

        // Si lettrePorposee n'apparait pas dans motSecret, le jouer a un coup en moins
        if (rechercherLettre(lettreProposee, motSecret, lettreTrouvee) == FALSE)
            coupsRestants--;
    }

    // Affichage du résultat de fin de partie
    if (verifierVictoire(lettreTrouvee, tailleMot) == TRUE)
        printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);

    // Libération de la mémoire allouée manuellement (par malloc)
    free(lettreTrouvee);

    return 0;
}

// Fonction qui lit le 1er caractère proposé
char lireCaractere()
{
    /*= Déclarations ================================================*/
    char caractere = 0;

    /*= Traitements ================================================*/
    // Le premier caractère est lu
    caractere = getchar();
    // Si le caractère est en minuscule, il est passé en majuscule
    caractere = toupper(caractere);

    // Les autres caractères mémorisés sont lus un à un jusqu'à l'\n
    // Sinon, chaque caractère supplémentaire crée une nouvelle tentative
    while (getchar() != '\n') ;

    // Retour du premier caractère lu
    return caractere;
}

// Fonction qui vérifie si toutes les lettres du mot ont été trouvées
// Et donc que la partie est gagnée
int verifierVictoire(int* lettreTrouvee, long tailleMot)
{
    /*= Déclarations ================================================*/
    long cptr = 0;
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
// Fonction qui vérifier si la lettre proposée se trouve dans motSecret
int rechercherLettre(char lettreProposee, char* motSecret, int* lettreTrouvee)
{
    /*= Déclarations ================================================*/
    long cptr = 0;
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
