#include <stdio.h>
#include <string.h>

#define MAX_NOTES 3
#define MAX_ETUDIANTS 5  // Nombre d'étudiants

// Définition de la structure pour représenter un étudiant
struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float notes[MAX_NOTES];
};

int main() {
    struct Etudiant etudiants[MAX_ETUDIANTS];

    // Saisie des informations pour chaque étudiant
    for (int i = 0; i < MAX_ETUDIANTS; i++) {
        printf("\nSaisie des informations pour l'étudiant %d:\n", i + 1);

        // Saisie du nom
        printf("Nom : ");
        fgets(etudiants[i].nom, 50, stdin);
        etudiants[i].nom[strcspn(etudiants[i].nom, "\n")] = '\0';  // Retirer le '\n' à la fin

        // Saisie du prénom
        printf("Prénom : ");
        fgets(etudiants[i].prenom, 50, stdin);
        etudiants[i].prenom[strcspn(etudiants[i].prenom, "\n")] = '\0';

        // Saisie de l'adresse
        printf("Adresse : ");
        fgets(etudiants[i].adresse, 100, stdin);
        etudiants[i].adresse[strcspn(etudiants[i].adresse, "\n")] = '\0';

        // Saisie des notes
        for (int j = 0; j < MAX_NOTES; j++) {
            printf("Note %d : ", j + 1);
            scanf("%f", &etudiants[i].notes[j]);
        }

        // Vider le tampon d'entrée après l'utilisation de scanf()
        getchar();
    }

    // Affichage des informations des étudiants
    printf("\nInformations des étudiants :\n");
    for (int i = 0; i < MAX_ETUDIANTS; i++) {
        printf("\nÉtudiant %d :\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prénom : %s\n", etudiants[i].prenom);
        printf("Adresse : %s\n", etudiants[i].adresse);

        // Afficher les notes
        printf("Notes : ");
        for (int j = 0; j < MAX_NOTES; j++) {
            printf("%.2f ", etudiants[i].notes[j]);
        }
        printf("\n");
    }

    return 0;
}
