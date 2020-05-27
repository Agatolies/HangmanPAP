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

char optionDifficulte = OPTION_DIFFICULTE_DEFAUT;
char optionMode = OPTION_MODE_DEFAUT;
const char* patternFichier = "difficulte=%c,mode=%c";
const char* nomFichier = "options.txt";


/*= FONCTIONS =======================================================*/

char lireOptionDifficulte()
{
    lireFichierOptions();
    return optionDifficulte;
}

void ecrireOptionDifficulte(const char difficulte)
{
    optionDifficulte = difficulte;
    ecrireFichierOptions();
}

const char* lireOptionDifficulteString()
{
    return convertirOptionDifficulteString(lireOptionDifficulte());
}

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

char lireOptionMode()
{
    lireFichierOptions();

    return optionMode;
}

void ecrireOptionMode(const char mode)
{
    optionMode = mode;
    ecrireFichierOptions();
}

const char* lireOptionModeString()
{
   return convertirOptionModeString(lireOptionMode());
}

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

void retablirOptions()
{
    optionDifficulte = OPTION_DIFFICULTE_DEFAUT;
    optionMode = OPTION_MODE_DEFAUT;
    ecrireFichierOptions();
}
