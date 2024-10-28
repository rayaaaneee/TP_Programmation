#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <tgmath.h>

// Définition de la structure pour représenter une commande
typedef struct {
    const char *nom;
    int (*fonction)(char *commande);
} Commande;

// Fonctions pour les différentes commandes
int afficher_version(char *commande) {
    printf("Version 1.0\n");
    return 0;
}

int afficher_aide(char *commande) {
    printf("Commandes disponibles :\n");
    printf("  echo <text> : Affiche le texte spécifié\n");
    printf("  date : Affiche la date actuelle\n");
    printf("  version : Affiche la version du programme\n");
    printf("  quit/quitter : Quitte le programme\n");
    printf("  help/aide : Affiche cette aide\n");
    return 0;
}

int traiter_echo(char *commande) {
    printf("Echo: ");
    for (int i = 5; commande[i] != '\0'; i++) {
        printf("%c", commande[i]);
    }
    printf("\n");
    return 0;
}

int traiter_quit(char *commande) {
    printf("Arrêt...\n");
    return 1;
}

int afficher_date(char *commande) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Date actuelle : %02d-%02d-%04d %02d:%02d:%02d\n",
           tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
           tm.tm_hour, tm.tm_min, tm.tm_sec);
    return 0;
}

// Tableau de commandes
Commande commandes[] = {
    {"version", afficher_version},
    {"help", afficher_aide},
    {"aide", afficher_aide},
    {"echo", traiter_echo},
    {"quit", traiter_quit},
    {"quitter", traiter_quit},
    {"date", afficher_date},
    {NULL, NULL} // Marqueur de fin de tableau
};

// Fonction pour convertir une chaîne en minuscules
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Fonction pour calculer la distance de Levenshtein entre deux chaînes
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) matrix[i][0] = i;
    for (int j = 0; j <= len2; j++) matrix[0][j] = j;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }
    return matrix[len1][len2];
}

// Fonction pour trouver la commande la plus proche
const char* trouver_commande_proche(const char *commande) {
    int min_distance = INT_MAX;
    const char *meilleure_commande = NULL;
    for (int i = 0; commandes[i].nom != NULL; i++) {
        int distance = levenshtein(commande, commandes[i].nom);
        if (distance < min_distance) {
            min_distance = distance;
            meilleure_commande = commandes[i].nom;
        }
    }
    return meilleure_commande;
}

int main() {
    int continuer = 1;
    char commande[1024];

    while (continuer) {
        printf("> ");
        fgets(commande, sizeof(commande), stdin);
        commande[strcspn(commande, "\n")] = 0;

        // Convertir la commande en minuscules pour ignorer la casse
        to_lowercase(commande);

        int i;
        for (i = 0; commandes[i].nom != NULL; i++) {
            if (strncmp(commande, commandes[i].nom, strlen(commandes[i].nom)) == 0) {
                continuer = !commandes[i].fonction(commande);
                break;
            }
        }

        if (commandes[i].nom == NULL) {
            const char *suggestion = trouver_commande_proche(commande);
            if (suggestion) {
                printf("Commande non reconnue. Vouliez-vous dire '%s' ?\n", suggestion);
            } else {
                printf("Commande non reconnue. Essayez 'echo <text>' pour afficher du texte, 'date' pour afficher la date actuelle, ou tapez 'quit'/'quitter' pour quitter.\n");
            }
        }

        printf("\n");
    }

    return 0;
}