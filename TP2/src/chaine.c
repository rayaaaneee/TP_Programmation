#include <stdio.h>

int lenChaine(char* chaine)
{
    int i, longueur = 0;
    for(i=0; chaine[i] != '\0'; i++)
    {
        longueur++;
    }
    return longueur;
}

char* copie(char* chaine1,char* chaine2)
{
    int i=0;
    while(chaine1[i] != '\0')
    {
        chaine2[i] = chaine1[i];
        i++;
    }
    chaine2[i] = '\0';
    return chaine2;
}

char* concat(char* chaine1, char* chaine2, char* resultat)
{
    int j, i=0;

    while (chaine1[i] != '\0')
    {
        resultat[i] = chaine1[i];
        i++;
    }
    j=i;
    i=0;
    while (chaine2[i] != '\0')
    {
        resultat[j+i] = chaine2[i];
        i++;
    }
    resultat[j+i] = '\0';
    return resultat;
}

int main()
{
    /*
    char chaine[100];
    printf("Saisir une chaine de caracteres\n");
    scanf("%99s", chaine);
    printf("%d\n",lenChaine(chaine));
    printf("#################\n");
    char copier[100];
    printf("%s\n", copier);
    printf("%s\n",copie(chaine,copier));
    printf("#################\n");
    */
    char chaine1[100],chaine2[100],resultat[200];
    printf("Saisir la premiere chaine\n");
    scanf("%s",chaine1);
    printf("Saisir la deuxieme chaine\n");
    scanf("%s",chaine2);
    printf("%s",concat(chaine1,chaine2,resultat));

    return 0;
}

