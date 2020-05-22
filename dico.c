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

/*= Directives de pr�compilation ====================================*/
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

    // On v�rifie si on a r�ussi � ouvrir le dictionnaire
    // Si on n'a PAS r�ussi � ouvrir le fichier
    if (dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        // On retourne 0 pour indiquer que la fonction a �chou�
        return 0;
        // A la lecture du return, la fonction s'arr�te imm�diatement.
    }

    // On compte le nombre de mots dans le fichier (il suffit de compter les entr�es \n
    do
    {
        caractereLu = fgetc(dico);

        if (caractereLu == '\n')
            nombreMots++;

    } while(caractereLu != EOF);

    // On pioche un mot au hasard
    numMotChoisi = nombreAleatoire(nombreMots);

    // On recommence � lire le fichier depuis le d�but. On s'arr�te lorsqu'on est arriv�s au bon mot
    rewind(dico);

    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);

        if (caractereLu == '\n')
            numMotChoisi--;
    }

    /* Le curseur du fichier est positionn� au bon endroit.
    On n'a plus qu'� faire un fgets qui lira la ligne */
    fgets(motPioche, 100, dico);

    // On retire l'\n � la fin
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);

    // Tout s'est bien pass�, on retourne 1
    return 1;
}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}


