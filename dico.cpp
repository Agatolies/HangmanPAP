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

    // Selection du fichier dico correspondant au niveau de difficulte
    sprintf(nomFichier, "dico%c.txt", lireOptionDifficulte());

    // Ouverture du dictionnaire en lecture seule
    dico = fopen(nomFichier, "r");

    // Si le fichier dictionnaire n'a pas pu etre ouvert
    if (dico == NULL)
    {
        afficherMessageErreurDico();
        // Retour de 0 pour indiquer que la fonction a echoue
        return 0;
        // A la lecture du return, la fonction s'arrete imm�eiatement.
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
    fgets(motPioche, 100, dico);

    // Modification du '\n' en '\0' en fin de ligne
    motPioche[strlen(motPioche) - 1] = '\0';

    // Fermeture du fichier dico
    fclose(dico);

    // La fonction s'est deroulee normalement
    return 1;
}

// Fonction pour generer un nombre aleatoire utile a la fonction piocherMot
int genererNombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}
