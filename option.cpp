/*********************************************************************/
/* Principes Algorithmique et Programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-23                                             */
/*********************************************************************/
/*                                                                   */
/* option.cpp                                                        */
/* ------                                                            */
/* Ces fonctions servent a gerer les differents options du programme */
/*                                                                   */
/*= DIRECTIVES DE PRECOMPILATION ====================================*/

#include <stdio.h>
#include <string.h>

#include "option.h"
#include "display.h"

/*= CONSTANTES SYMBOLIQUES ==========================================*/

#define OPTION_DIFFICULTE_DEFAUT '2'
#define OPTION_MODE_DEFAUT 'V'

/*= DECLARATIONS GLOBALES ===========================================*/

// Caractere allant de '1' a '5' representant le niveau de difficulte
char optionDifficulte = OPTION_DIFFICULTE_DEFAUT;
// Caractere 'I' pour invisible, 'V' pour visible et 'N' pour intermediaire
char optionMode = OPTION_MODE_DEFAUT;
// Masque utilise par fprintf et fscanf representant le contenu du fichier d'option
const char* patternFichier = "difficulte=%c,mode=%c";
// Chaine de caracteres representant le nom du fichier
const char* nomFichier = "options.txt";


/*= FONCTIONS =======================================================*/

/*
 * Fonction:  lireOptionDifficulte
 * --------------------
 * Lit le caractere choisi pour le niveau de difficulte
 *
 *  retourne: caractere de '1' a '5' representant le niveau de difficulte
 */

char lireOptionDifficulte()
{
    lireFichierOptions();
    return optionDifficulte;
}


/*
 * Fonction:
 * --------------------
 * Inscrit la valeur de la difficulte choisie par l'utilisateur
 * dans le fichier d'options.
 *
 *  difficulte = caractere allant de '1' a '5' representant le niveau de difficulte
 */

void ecrireOptionDifficulte(const char difficulte)
{
    optionDifficulte = difficulte;
    ecrireFichierOptions();
}

/*
 * Fonction:  lireOptionModeString
 * --------------------
 * Retourne le niveau de difficulte choisie en toutes lettres ('Facile', 'Difficile', ...)
 *
 *  retourne: chaine de caractere representant le niveau de difficulte choisis en toutes lettres
 */

const char* lireOptionDifficulteString()
{
    return convertirOptionDifficulteString(lireOptionDifficulte());
}


/*
 * Fonction:  convertirOptionDifficulteString
 * --------------------
 * Converti le caractere de l'option de difficulte choisie (de '1' a '5' )
 * en un mot complet repris dans une chaine de caractere.
 *
 *  retourne: chaine de caractere de l'option choisie en toute lettre
 */

const char* convertirOptionDifficulteString(const char difficulte)
{
    switch(difficulte)
    {
        case '1' :
            return "Facile";
        case '2' :
            return "Normal";
        case '3' :
            return "Difficile";
        case '4' :
            return "Tres difficile";
        case '5' :
            return "Diabolique";
        default :
            return "";
    }
}

/*
 * Fonction:  lireOptionMode
 * --------------------
 * Lit le caractere choisi pour le mode
 *
 *  retourne: caractere  'I', 'V' ou 'N'  representant le mode choisi
 */

char lireOptionMode()
{
    lireFichierOptions();

    return optionMode;
}


/*
 * Fonction:  ecrireOptionMode
 * --------------------
 * Inscrit la valeur du mode choisi par l'utilisateur dans le fichier d'options
 *
 *  mode = caractere  'I', 'V' ou 'N'  representant le mode choisi
 */

void ecrireOptionMode(const char mode)
{
    optionMode = mode;
    ecrireFichierOptions();
}

/*
 * Fonction:  lireOptionModeString
 * --------------------
 * Retourne le mode choisi en toutes lettres ('Invisible', 'Intermediaire', 'Visible')
 *
 *  retourne: chaine de caractere representant le mode choisi en toutes lettres
 */

const char* lireOptionModeString()
{
   return convertirOptionModeString(lireOptionMode());
}


/*
 * Fonction:  convertirOptionModeString
 * --------------------
 * Converti le caractere du mode choisi ('V', 'N' ou 'I') en
 * un mot complet repris dans une chaine de caractere.
 *
 *  retourne: chaine de caractere du choisi en toute lettre
 */

const char* convertirOptionModeString(const char mode)
{
    switch(mode)
    {
        case 'V' :
            return "Visible";
        case 'N' :
            return "Intermediaire";
        case 'I' :
            return "Invisible";
        default :
            return "";
    }
}


/*
 * Fonction:  ecrireFichierOptions
 * --------------------
 * Ouvre le fichier d'options en mode ecriture.
 * Si le fichier n'existe pas, il est cree.
 * Et inscrit dedans la valeur courante des variables du module.
 */

void ecrireFichierOptions()
{
    FILE* fichier = NULL;

    fichier = fopen(nomFichier, "w+");

    if (fichier != NULL)
    {
        fprintf(fichier, patternFichier, optionDifficulte, optionMode);
        fclose(fichier);
    }
}


/*
 * Fonction:  lireFichierOptions
 * --------------------
 * Ouvre le fichier d'options en mode lecture et initialise
 * les variables du module avec le contenu de ce fichier.
 * Si le fichier n'existe pas, alors il est cree avec
 * les options par defaut.
 */

void lireFichierOptions()
{
    FILE* fichier = NULL;

    fichier = fopen(nomFichier, "r");

    if (fichier == NULL)
    {
        ecrireFichierOptions();
        fichier = fopen(nomFichier, "r");
    }

    fscanf(fichier, patternFichier, &optionDifficulte, &optionMode);
    fclose(fichier);
}


/*
 * Fonction:
 * --------------------
 * Retablit le fichier d'options avec les valeurs par defaut.
 */

void retablirOptions()
{
    optionDifficulte = OPTION_DIFFICULTE_DEFAUT;
    optionMode = OPTION_MODE_DEFAUT;
    ecrireFichierOptions();
}
