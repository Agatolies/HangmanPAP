/*********************************************************************/
/* Principes algorithmique et programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-22                                             */
/*********************************************************************/

/* game.c
   ------
Ces fonctions servent � g�rer la partie jeu du programme              */

/*= Constantes symboliques ==========================================*/
#define TRUE  1
#define FALSE 0

// Fonction pour piocher le mot et effectuer les v�rifications n�cessaires au d�but du jeu
void debutJeu(char* motSecret, int tailleMot, int* lettreTrouvee)
{
    /*- D�clarations ================================================*/
    int cptr = 0;

    /*- Traitements =================================================*/
     // V�rification que la fonction piocherMot retourne bien un motSecret existant
    if (piocherMot(motSecret) == FALSE)
        exit(0);

    // Calculer la taille du tableau contenant le mot � trouver.
    tailleMot = strlen(motSecret);

    // Allocation de m�moire pour le tableau lettreTrouvee
    lettreTrouvee = malloc(tailleMot * sizeof(int));

    // V�rification de la fonction malloc pour lettreTrouvee
    if (lettreTrouvee == NULL)
        exit(0);

    // Initialisation de toutes les cellules lettreTrouvee � 0
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        lettreTrouvee[cptr] = 0;
}



//Fonction qui sert � lancer le jeu et les essais suivants
void essaisJeu(int coupsRestants, int tailleMot, int* lettreTrouvee, char lettreProposee, char* motSecret)
{
    /*- D�clarations ================================================*/
    int cptr = 0;

    /*- Traitements =================================================*/
    // Tant qu'il reste au moins un coup � jouer ou que la partie n'est pas gagn�e
    while (coupsRestants > 0 && verifierVictoire(lettreTrouvee, tailleMot) == FALSE)
    {
        afficherMessageCoupsRestants(coupsRestants);
        afficherMessageMotSecret();

        // Affichage du mot secret en masquant les lettres non trouv�es - Exemple : *A**ON
        for (cptr = 0 ; cptr < tailleMot ; cptr++)
            // Affichage des lettres si trouv�es
            if (lettreTrouvee[cptr])
                afficherLettreTrouvee(motSecret, cptr);
            // Sinon, affichage d'�toiles pour les lettres manquantes
            else
                afficherLettreNonTrouvee();

        afficherMessageProposerLettre();
        lettreProposee = lireCaractere();

        // Si lettrePorposee n'apparait pas dans motSecret, le joueur a un coup en moins
        if (rechercherLettre(lettreProposee, motSecret, lettreTrouvee) == FALSE)
            coupsRestants--;
    }
}
