/*********************************************************************/
/* Principes Algorithmique et Programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-23                                             */
/*********************************************************************/
/*                                                                   */
/* dico.cpp                                                          */
/* ------                                                            */
/* Ces fonctions servent a piocher au hasard un mot dans un fichier  */
/* dictionnaire pour le jeu du pendu                                 */
/*                                                                   */
/*= DIRECTIVES DE PRECOMPILATION ====================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dico.h"
#include "display.h"
#include "option.h"

/*= FONCTIONS =======================================================*/

/*
 * Fonction:  piocherMot
 * --------------------
 * Selectionne le fichier dico correspondant au niveau de difficulte,
 * ouvre ce fichier en lecture seule et en compte le nombre de mot.
 * Pioche un mot aléatoirement dans le fichier et parcourt a nouveau le
 * fichier jusqu'a la premiere lettre du mot pioche.
 * Affecte les lettres de ce mot dans la chaîne de caractre motSecret du
 * module game.
 *
 *  motPioche: un pointeur sur char pour une zone mémoire nulle
 *             d'une taille de 50 cellules.
 *
 *  retourne: un entier booléen.
 */

// Fonction pour piocher un mot au hasard
int piocherMot(char* motPioche)
{
    /*- Declarations ================================================*/

    // Le pointeur de fichier qui va contenir le fichier dictionnaire
    FILE* dico = NULL;
    int nombreMots = 0;
    int numMotChoisi = 0;
    char caractereLu = ' ';
    char nomFichier[20];

    sprintf(nomFichier, "dico%c.txt", lireOptionDifficulte());

    // Ouverture du dictionnaire en lecture seule
    dico = fopen(nomFichier, "r");

    // Si le fichier dictionnaire n'a pas pu etre ouvert
    if (dico == NULL)
    {
        afficherMessageErreurFichier(nomFichier);
        // Retour de 0 pour indiquer que la fonction a echoue
        return 0;
        // A la lecture du return, la fonction s'arrete immediatement.
    }

    // Somme des mots dans le fichier via comptage des '\n'
    do
    {
        caractereLu = (char) fgetc(dico);

        if (caractereLu == '\n')
            nombreMots++;
    // Jusqu'au caractere de fin de fichier(EOF)
    } while(caractereLu != EOF);

    // Pioche d'un mot au hasard
    numMotChoisi = genererNombreAleatoire(nombreMots);

    // Le fichier est lu a nouveau jusqu'au mot pioche
    rewind(dico);

    while (numMotChoisi > 0)
    {
        caractereLu = (char) fgetc(dico);

        if (caractereLu == '\n')
            numMotChoisi--;
    }

    // Le curseur du fichier est positionne au bon endroit pour lire la ligne
    fgets(motPioche, 50, dico);

    // Modification du '\n' en '\0' en fin de ligne
    motPioche[strlen(motPioche) - 1] = '\0';

    // Fermeture du fichier dico
    fclose(dico);

    // La fonction s'est deroulee normalement
    return 1;
}


/*
 * Fonction:
 * --------------------
 * Genere un nombre aletaoire compris entre 0 et nombreMax.
 *
 *  nombreMax: entier representant le total de mot dans un fichier
 *             dico.
 *
 *  retourne: un entier
 */

int genererNombreAleatoire(const int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}
