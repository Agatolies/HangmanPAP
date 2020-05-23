/*********************************************************************/
/* Principes Algorithmique et Programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-23                                             */
/*********************************************************************/
/*                                                                   */
/* main.cpp                                                          */
/* ------                                                            */
/*                                                                   */
/*= DIRECTIVES DE PRECOMPILATION ====================================*/

#include "screen.h"

/*= Fonction principale =============================================*/
int main()
{
    char choixUtilisateur = ' ';

    do
    {
        rafraichirEcranMenu();
        choixUtilisateur = gererChoixMenu();
    }
    while (choixUtilisateur != 'Q');

    return 0;
}
