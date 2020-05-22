/*********************************************************************/
/* Principes algorithmique et programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-22                                             */
/*********************************************************************/

/* dico.c
   ------
Ces fonctions piochent au hasard un mot dans un fichier dictionnaire
pour le jeu du pendu                                                 */

/*= Directives de précompilation ====================================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dico.h"
/* PiocherMot                                                        */
int piocherMot(char* motPioche)
{
    // Le pointeur de fichier qui va contenir notre fichier
    FILE* dico = NULL;
    int nombreMots = 0, numMotChoisi = 0, cptr = 0;
    int caractereLu = 0;
    // On ouvre le dictionnaire en lecture seule
    dico = fopen("dico.txt", "r");

    // On vérifie si on a réussi à ouvrir le dictionnaire
    // Si on n'a PAS réussi à ouvrir le fichier
    if (dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        // On retourne 0 pour indiquer que la fonction a échoué
        return 0;
        // A la lecture du return, la fonction s'arrête immédiatement.
    }

    // On compte le nombre de mots dans le fichier (il suffit de compter les entrées \n
    do
    {
        caractereLu = fgetc(dico);

        if (caractereLu == '\n')
            nombreMots++;

    } while(caractereLu != EOF);

    // On pioche un mot au hasard
    numMotChoisi = nombreAleatoire(nombreMots);

    // On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivés au bon mot
    rewind(dico);

    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);

        if (caractereLu == '\n')
            numMotChoisi--;
    }

    /* Le curseur du fichier est positionné au bon endroit.
    On n'a plus qu'à faire un fgets qui lira la ligne */
    fgets(motPioche, 100, dico);

    // On retire l'\n à la fin
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);

    // Tout s'est bien passé, on retourne 1
    return 1;
}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}


