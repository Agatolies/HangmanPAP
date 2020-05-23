/*********************************************************************/
/* Principes algorithmique et programmation - Examen final           */
/*===================================================================*/
/* Auteur   : Laure D'Este                                           */
/* Date     : 2020-05-22                                             */
/*********************************************************************/

/* display.c
   ------
Ces fonctions gèrent les entrées et les sorties depuis et vers
la console                                                           */

void afficherMessageIntroduction()
{
    printf("Bienvenue dans le Pendu !\n\n");
}

void afficherMessageCoupsRestants(int coupsRestants)
{
    printf("\n\nIl vous reste %d coups a jouer", coupsRestants);
}

void afficherMessageMotSecret()
{
    printf("\nQuel est le mot secret ? ");
}

void afficherLettreTrouvee(char* motSecret, int cptr)
{
    printf("%c", motSecret[cptr]);
}

void afficherLettreNonTrouvee()
{
    printf("*");
}

void afficherMessageProposerLettre()
{
    printf("\nProposez une lettre : ");
}

// Fonction qui lit le 1er caractère proposé
char lireCaractere()
{
    /*= Déclarations ================================================*/
    char caractere = 0;

    /*= Traitements ================================================*/
    // Le premier caractère est lu
    caractere = getchar();
    // Si le caractère est en minuscule, il est passé en majuscule
    caractere = toupper(caractere);

    // Les autres caractères mémorisés sont lus un à un jusqu'à l'\n
    // Sinon, chaque caractère supplémentaire crée une nouvelle tentative
    while (getchar() != '\n') ;

    // Retour du premier caractère lu
    return caractere;
}

void afficherMessageGagnant(char* motSecret)
{
    printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
}

void afficherMessagePerdant(char* motSecret)
{
    printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);
}
void afficherMessageErreurDico()
{
    printf("\nImpossible de charger le dictionnaire de mots");
}
