/*********************************************************************/
/* Principes algorithmique et programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-22                                             */
/*********************************************************************/

/* game.c
   ------
Ces fonctions servent à gérer la partie jeu du programme              */

/*= Constantes symboliques ==========================================*/
#define TRUE  1
#define FALSE 0

// Fonction pour piocher le mot et effectuer les vérifications nécessaires au début du jeu
void debutJeu(char* motSecret, int tailleMot, int* lettreTrouvee)
{
    /*- Déclarations ================================================*/
    int cptr = 0;

    /*- Traitements =================================================*/
     // Vérification que la fonction piocherMot retourne bien un motSecret existant
    if (piocherMot(motSecret) == FALSE)
        exit(0);

    // Calculer la taille du tableau contenant le mot à trouver.
    tailleMot = strlen(motSecret);

    // Allocation de mémoire pour le tableau lettreTrouvee
    lettreTrouvee = malloc(tailleMot * sizeof(int));

    // Vérification de la fonction malloc pour lettreTrouvee
    if (lettreTrouvee == NULL)
        exit(0);

    // Initialisation de toutes les cellules lettreTrouvee à 0
    for (cptr = 0 ; cptr < tailleMot ; cptr++)
        lettreTrouvee[cptr] = 0;
}



//Fonction qui sert à lancer le jeu et les essais suivants
void essaisJeu(int coupsRestants, int tailleMot, int* lettreTrouvee, char lettreProposee, char* motSecret)
{
    /*- Déclarations ================================================*/
    int cptr = 0;

    /*- Traitements =================================================*/
    // Tant qu'il reste au moins un coup à jouer ou que la partie n'est pas gagnée
    while (coupsRestants > 0 && verifierVictoire(lettreTrouvee, tailleMot) == FALSE)
    {
        afficherMessageCoupsRestants(coupsRestants);
        afficherMessageMotSecret();

        // Affichage du mot secret en masquant les lettres non trouvées - Exemple : *A**ON
        for (cptr = 0 ; cptr < tailleMot ; cptr++)
            // Affichage des lettres si trouvées
            if (lettreTrouvee[cptr])
                afficherLettreTrouvee(motSecret, cptr);
            // Sinon, affichage d'étoiles pour les lettres manquantes
            else
                afficherLettreNonTrouvee();

        afficherMessageProposerLettre();
        lettreProposee = lireCaractere();

        // Si lettrePorposee n'apparait pas dans motSecret, le joueur a un coup en moins
        if (rechercherLettre(lettreProposee, motSecret, lettreTrouvee) == FALSE)
            coupsRestants--;
    }
}
