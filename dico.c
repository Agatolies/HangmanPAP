/*********************************************************************/
/* Principes algorithmique et programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-22                                             */
/*********************************************************************/

/* dico.c
   ------
Ces fonctions servent � piocher au hasard un mot dans un fichier
dictionnaire pour le jeu du pendu                                    */

/*= Directives de pr�compilation ====================================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dico.h"

// Fonction pour piocher un mot au hasard
int piocherMot(char* motPioche)
{
    /*- D�clarations ================================================*/
    // Le pointeur de fichier qui va contenir le fichier dictionnaire
    FILE* dico = NULL;
    int nombreMots = 0;
    int numMotChoisi = 0;
    int cptr = 0;
    int caractereLu = 0;
    // Ouverture du dictionnaire en lecture seule
    dico = fopen("dico.txt", "r");

    // Si le fichier dictionnaire n'a pas pu �tre ouvert
    if (dico == NULL)
    {
        afficherMessageErreurDico();
        // Retour de 0 pour indiquer que la fonction a �chou�
        return 0;
        // A la lecture du return, la fonction s'arr�te imm�diatement.
    }

    // Somme des mots dans le fichier via comptage des '\n'
    do
    {
        caractereLu = fgetc(dico);

        if (caractereLu == '\n')
            nombreMots++;
    // Jusqu'au caract�re de fin de fichier(EOF)
    } while(caractereLu != EOF);

    // Pioche d'un mot au hasard
    numMotChoisi = genererNombreAleatoire(nombreMots);

    // Le fichier est lu � nouveau jusqu'au mot pioch�
    rewind(dico);

    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);

        if (caractereLu == '\n')
            numMotChoisi--;
    }

    // Le curseur du fichier est positionn� au bon endroit pour lire la ligne
    fgets(motPioche, 100, dico);

    // Modification du '\n' en '\0' en fin de ligne
    motPioche[strlen(motPioche) - 1] = '\0';

    // Fermeture du fichier dico
    fclose(dico);

    // La fonction s'est d�roul�e normalement
    return 1;
}

// Fonction pour g�n�rer un nombre al�atoire utile � la fonction piocherMot
int genererNombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}


