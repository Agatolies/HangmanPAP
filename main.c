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
    char lettreProposee = 0;
    // Mot � trouver pour gagner la partie
    char* motSecret;
    // Un tableau de bool�ens. Chaque case correspond � une lettre du mot secret. 0 = lettre non trouv�e, 1 = lettre trouv�e
    int* lettreTrouvee = NULL;
    // Compteur de coups restants (0 = fin du jeu)
    long coupsRestants = 10;
    // Compteur pour parcourir les diff�rents tableaux
    long cptr = 0;
    long tailleMot = 0;

    /*= Traitements ================================================*/
    //Introdutcion au jeu
    printf("Bienvenue dans le Pendu !\n\n");

    // V�rification que la fonction piocherMot retourne bien un motSecret existant
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
        lettreTrouvee[cptr] = 0;

    // Tant qu'il reste au moins un coup � jouer ou que la partie n'est pas gagn�e
    while (coupsRestants > 0 && verifierVictoire(lettreTrouvee, tailleMot) == FALSE)
    {
        printf("\n\nIl vous reste %ld coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");

        // Affichage du mot secret en masquant les lettres non trouv�es - Exemple : *A**ON
        for (cptr = 0 ; cptr < tailleMot ; cptr++)
            // Affichage des lettres si trouv�es
            if (lettreTrouvee[cptr])
                printf("%c", motSecret[cptr]);
            // Sinon, affichage d'�toiles pour les lettres manquantes
            else
                printf("*");

        printf("\nProposez une lettre : ");
        lettreProposee = lireCaractere();

        // Si lettrePorposee n'apparait pas dans motSecret, le jouer a un coup en moins
        if (rechercherLettre(lettreProposee, motSecret, lettreTrouvee) == FALSE)
            coupsRestants--;
    }

    // Affichage du r�sultat de fin de partie
    if (verifierVictoire(lettreTrouvee, tailleMot) == TRUE)
        printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);

    // Lib�ration de la m�moire allou�e manuellement (par malloc)
    free(lettreTrouvee);

    return 0;
}

// Fonction qui lit le 1er caract�re propos�
char lireCaractere()
{
    /*= D�clarations ================================================*/
    char caractere = 0;

    /*= Traitements ================================================*/
    // Le premier caract�re est lu
    caractere = getchar();
    // Si le caract�re est en minuscule, il est pass� en majuscule
    caractere = toupper(caractere);

    // Les autres caract�res m�moris�s sont lus un � un jusqu'� l'\n
    // Sinon, chaque caract�re suppl�mentaire cr�e une nouvelle tentative
    while (getchar() != '\n') ;

    // Retour du premier caract�re lu
    return caractere;
}

// Fonction qui v�rifie si toutes les lettres du mot ont �t� trouv�es
// Et donc que la partie est gagn�e
int verifierVictoire(int* lettreTrouvee, long tailleMot)
{
    /*= D�clarations ================================================*/
    long cptr = 0;
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
// Fonction qui v�rifier si la lettre propos�e se trouve dans motSecret
int rechercherLettre(char lettreProposee, char* motSecret, int* lettreTrouvee)
{
    /*= D�clarations ================================================*/
    long cptr = 0;
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
