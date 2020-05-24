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

#include "option.h"
#include "display.h"

/*= CONSTANTES SYMBOLIQUES ==========================================*/

/*= DECLARATIONS GLOBALES ===========================================*/

char optionMode = 'V';
char optionDifficulte = '2';

/*= FONCTIONS =======================================================*/

char lireOptionMode()
{
    return optionMode;
}

char* lireOptionModeString()
{
   return convertirOptionModeString(optionMode);
}

char* convertirOptionModeString(char mode)
{
    switch(mode)
    {
        case 'V' :
            return "Visible";
        case 'N' :
            return "Intermediaire";
        case 'I' :
            return "Invisible";
    }
}

void ecrireOptionMode(char mode)
{
    optionMode = mode;
}

char lireOptionDifficulte()
{
    return optionDifficulte;
}

char* lireOptionDifficulteString()
{
    return convertirOptionDifficulteString(optionDifficulte);
}

char* convertirOptionDifficulteString(char difficulte)
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
    }
}

void ecrireOptionDifficulte(char difficulte)
{
    optionDifficulte = difficulte;
}
