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

    // Si le fichier dictionnaire n'a pas pu être ouvert, on tente de le creer
    if (dico == NULL)
    {
        ecrireFichierDictionnaireCourant();
        dico = fopen(nomFichier, "r");
    }

    // Si après avoir ete cree, on a toujours une erreur, alors on l'affiche
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
 * Fonction:   genererNombreAleatoire
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


/*
 * Fonction:   ecrireFichierDictionnaireCourant
 * --------------------
 * Cree le fichier dictionnaire correspondant
 * au niveau de difficulte selectionne par l'utilisateur
 */

void ecrireFichierDictionnaireCourant()
{
    switch (lireOptionDifficulte())
    {
        case '1':
            ecrireFichierDictionnaireFacile();
            break;
        case '2':
            ecrireFichierDictionnaireNormal();
            break;
        case '3':
            ecrireFichierDictionnaireDifficile();
            break;
        case '4':
            ecrireFichierDictionnaireTresDifficile();
            break;
        case '5':
            ecrireFichierDictionnaireDiabolique();
            break;
    }
}


/*
 * Fonction:   ecrireFichierDictionnaireFacile
 * --------------------
 * Cree le fichier dictionnaire prerempli avec des mots faciles
 */

void ecrireFichierDictionnaireFacile()
{
    FILE* fichier = NULL;

    fichier = fopen("dico1.txt", "w+");

    if (fichier != NULL)
    {
        fprintf(fichier, "MAISON\n");
        fprintf(fichier, "BLEU\n");
        fprintf(fichier, "AVION\n");
        fprintf(fichier, "NEIGE\n");
        fprintf(fichier, "ZERO\n");
        fprintf(fichier, "PAPA\n");
        fprintf(fichier, "POMME\n");
        fprintf(fichier, "SOURIS\n");
        fprintf(fichier, "ZEBRE\n");
        fprintf(fichier, "FILLE\n");

        fclose(fichier);
    }
}


/*
 * Fonction:   ecrireFichierDictionnaireNormal
 * --------------------
 * Cree le fichier dictionnaire prerempli avec des mots normaux
 */

void ecrireFichierDictionnaireNormal()
{
    FILE* fichier = NULL;

    fichier = fopen("dico2.txt", "w+");

    if (fichier != NULL)
    {
        fprintf(fichier, "ABEILLE\n");
        fprintf(fichier, "IMMEUBLE\n");
        fprintf(fichier, "GOURDIN\n");
        fprintf(fichier, "CHOCOLAT\n");
        fprintf(fichier, "VILLAGE\n");
        fprintf(fichier, "TROTTOIR\n");
        fprintf(fichier, "VOITURE\n");
        fprintf(fichier, "OISEAUX\n");
        fprintf(fichier, "DICTIONNAIRE\n");
        fprintf(fichier, "HORLOGE\n");

        fclose(fichier);
    }
}


/*
 * Fonction:   ecrireFichierDictionnaireDifficile
 * --------------------
 * Cree le fichier dictionnaire prerempli avec des mots difficiles
 */

void ecrireFichierDictionnaireDifficile()
{
    FILE* fichier = NULL;

    fichier = fopen("dico3.txt", "w+");

    if (fichier != NULL)
    {
        fprintf(fichier, "HEDONISME\n");
        fprintf(fichier, "OSTRACISME\n");
        fprintf(fichier, "PROTEIFORME\n");
        fprintf(fichier, "NONOBSTANT\n");
        fprintf(fichier, "MUTAGENE\n");
        fprintf(fichier, "OBEDIENCE\n");
        fprintf(fichier, "PRIMESAUTIER\n");
        fprintf(fichier, "SARDONIQUE\n");
        fprintf(fichier, "ZELATEUR\n");
        fprintf(fichier, "METROMANE\n");

        fclose(fichier);
    }
}


/*
 * Fonction:   ecrireFichierDictionnaireTresDifficile
 * --------------------
 * Cree le fichier dictionnaire prerempli avec des mots tres difficiles
 */

void ecrireFichierDictionnaireTresDifficile()
{
    FILE* fichier = NULL;

    fichier = fopen("dico4.txt", "w+");

    if (fichier != NULL)
    {
        fprintf(fichier, "IDEOGRAMME\n");
        fprintf(fichier, "SCEPTIQUE\n");
        fprintf(fichier, "XYLOPHONE\n");
        fprintf(fichier, "SCRIPTEUR\n");
        fprintf(fichier, "ALAMBIQUE\n");
        fprintf(fichier, "PITCH\n");
        fprintf(fichier, "OXYMORE\n");
        fprintf(fichier, "MUTIQUE\n");
        fprintf(fichier, "COQUECIGRUE\n");
        fprintf(fichier, "DIPSOMANE\n");

        fclose(fichier);
    }
}


/*
 * Fonction:   ecrireFichierDictionnaireDiabolique
 * --------------------
 * Cree le fichier dictionnaire prerempli avec des mots diaboliques
 */

void ecrireFichierDictionnaireDiabolique()
{
    FILE* fichier = NULL;

    fichier = fopen("dico5.txt", "w+");

    if (fichier != NULL)
    {
        fprintf(fichier, "CACOCHYME\n");
        fprintf(fichier, "ABUTYROTOMOFILOGENE\n");
        fprintf(fichier, "EPISTAXIS\n");
        fprintf(fichier, "OBCORDE\n");
        fprintf(fichier, "CAMERLINGUE\n");
        fprintf(fichier, "JOCRISSE\n");
        fprintf(fichier, "MESOMORPHE\n");
        fprintf(fichier, "PANGRAMME\n");
        fprintf(fichier, "SYNEISAKTISME\n");
        fprintf(fichier, "ZINZIBERIN\n");

        fclose(fichier);
    }
}
