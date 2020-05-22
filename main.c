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
int  verifierVictoire (int*, long       );
int  rechercherLettre (char, char*, int*);
char lireCaractere    (                 );

/*= Fonction principale =============================================*/
int main(int argc, char* argv)
{
    /*= D�clarations ================================================*/
    // Stocke la lettre propos�e par l'utilisateur (retour du scanf)
    char lettre = 0;
    // Ce sera le mot � trouver
    char* motSecret;
    // Un tableau de bool�ens. Chaque case correspond � une lettre du mot secret. 0 = lettre non trouv�e, 1 = lettre trouv�e
    int* lettreTrouvee = NULL;
    // Compteur de coups restants (0 = mort)
    long coupsRestants = 10;
    // Une petite variable pour parcourir les tableaux
    long cptr = 0;
    long tailleMot = 0;

    /*= Traitements ================================================*/
    //Introdutcion au jeu
    printf("Bienvenue dans le Pendu !\n\n");

    // Fonction pour aller piocher le mot � trouver. Retourne 0 si erreur
    if (piocherMot(motSecret) == FALSE)
        exit(0);

    // Calculer la taille du tableau contenant le mot � trouver.
    tailleMot = strlen(motSecret);

    // Allocation de m�moire pour le tableau lettreTrouvee
    lettreTrouvee = malloc(tailleMot * sizeof(int));
    if (lettreTrouvee == NULL)
        exit(0);

    // Initialisation de toutes les cellules de lettreTrouvee � 0
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        lettreTrouvee[cptr] = 0;

    // On continue � jouer tant qu'il reste au moins un coup � jouer ou qu'on n'a pas gagn�
    while (coupsRestants > 0 && verifierVictoire(lettreTrouvee, tailleMot) == FALSE)
    {
        printf("\n\nIl vous reste %ld coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");

        // On affiche le mot secret en masquant les lettres non trouv�es - Exemple : *A**ON
        for (cptr = 0 ; cptr < tailleMot ; cptr++)
            // Si on a trouv� la lettre n�cptr on l'affiche
            if (lettreTrouvee[cptr])
                printf("%c", motSecret[cptr]);
            // Sinon, on affiche une �toile pour les lettres non trouv�es
            else
                printf("*");

        printf("\nProposez une lettre : ");
        lettre = lireCaractere();

        // Si ce n'�tait PAS une lettre du motSecret
        if (rechercherLettre(lettre, motSecret, lettreTrouvee) == FALSE)
            // On enl�ve un coup au joueur
            coupsRestants--;
    }

    if (verifierVictoire(lettreTrouvee, tailleMot))
        printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);

    // On lib�re la m�moire allou�e manuellement (par malloc)
    free(lettreTrouvee);

        return 0;
}

char lireCaractere()
{
    /*= D�clarations ================================================*/
    char caractere = 0;

    /*= Traitements ================================================*/
    // On lit le premier caract�re
    caractere = getchar();
    // On met la lettre en majuscule si elle ne l'est pas d�j�
    caractere = toupper(caractere);

    // On lit les autres caract�res m�moris�s un � un jusqu'� l'\n
    while (getchar() != '\n') ;

    // On retourne le premier caract�re qu'on a lu
    return caractere;
}

int verifierVictoire(int* lettreTrouvee, long tailleMot)
{
    /*= D�clarations ================================================*/
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
    /*= D�clarations ================================================*/
    long cptr = 0;
    int bonneLettre = 0;

    /*= Traitements ================================================*/
    // On parcourt motSecret pour v�rifier si la lettre propos�e y est
    for (cptr = 0 ; motSecret[cptr] != '\0' ; cptr++)
        // Si la lettre y est
        if (lettre == motSecret[cptr])
        {
            // On m�morise que c'�tait une bonne lettre
            bonneLettre = 1;
            // On met � 1 le case du tableau de bool�ens correspondant � la lettre actuelle
            lettreTrouvee[cptr] = 1;
        }

    return bonneLettre;
}
