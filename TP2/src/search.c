#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

int countOccurrences(char *line, char *phrase) {
    int count = 0;
    char *ptr = line;
    while ((ptr = strstr(ptr, phrase)) != NULL) {
        count++;
        ptr += strlen(phrase);  // avancer après la phrase trouvée
    }
    return count;
}

int main() {
    char filename[100];
    char phrase[100];
    char line[MAX_LINE];
    FILE *file;
    int lineNumber = 0;

    // Demander à l'utilisateur de saisir le nom du fichier et la phrase à rechercher
    printf("Entrez le nom du fichier : ");
    scanf("%s", filename);
    printf("Entrez la phrase que vous souhaitez rechercher : ");
    scanf(" %[^\n]", phrase);  // lire la phrase avec des espaces

    // Ouvrir le fichier
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", filename);
        return 1;
    }

    // Lire le fichier ligne par ligne
    while (fgets(line, MAX_LINE, file) != NULL) {
        lineNumber++;
        int occurrences = countOccurrences(line, phrase);
        if (occurrences > 0) {
            printf("Ligne %d, %d fois\n", lineNumber, occurrences);
        }
    }

    // Fermer le fichier
    fclose(file);

    return 0;
}
