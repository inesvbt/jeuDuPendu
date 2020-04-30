#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Prototypes
int gagne(int lettreTrouvee[]);
int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[]);
char lireCaractere();

// Fonction main
int main(int argc, char* argv[])
{
    char lettre = 0;
    char motSecret[] = "MARRON";
    int lettreTrouvee[6] = {0};
    int coupsRestants = 10;
    int i = 0;

    printf("Bienvenue dans le Pendu !\n\n");
    printf("Un mot a trouver. Proposez une lettre.\n");
    printf("Si la lettre fait partie du mot, la partie continue.\n");
    printf("Mais si la lettre est fausse, vous perdez une vie. Vous avez 10 vies.\n");
    printf("C'est parti, a vous de jouer !! \n\n");


    while (coupsRestants > 0 && !gagne(lettreTrouvee))
    {
        printf("\n\nIl vous reste %d coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");


        for (i = 0 ; i < 6 ; i++)
        {
            if (lettreTrouvee[i])
                printf("%c", motSecret[i]);
            else
                printf("*");
        }

        printf("\nProposez une lettre : ");
        lettre = lireCaractere();


        if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
        {
            coupsRestants--;
        }
    }


    if (gagne(lettreTrouvee))
        printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);

        return 0;
}

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);


    while (getchar() != '\n') ;

    return caractere;
}

int gagne(int lettreTrouvee[])
{
    int i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < 6 ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
    int i = 0;
    int bonneLettre = 0;


    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }

    return bonneLettre;
}
