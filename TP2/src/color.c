#include <stdio.h>
#include <stdbool.h>

#define MAX_COLORS 100
#define MAX_DISTINCT_COLORS 100

// Structure pour représenter une couleur
typedef struct {
    unsigned char R; // Composant rouge
    unsigned char G; // Composant vert
    unsigned char B; // Composant bleu
    unsigned char A; // Composant alpha
} Color;

// Structure pour représenter une couleur distincte et son compteur
typedef struct {
    Color color;    // Couleur distincte
    int count;      // Nombre d'occurrences
} DistinctColor;

// Fonction pour comparer deux couleurs
bool colors_equal(Color a, Color b) {
    return (a.R == b.R && a.G == b.G && a.B == b.B && a.A == b.A);
}

int main() {
    // Déclaration du tableau de couleurs
    Color colors[MAX_COLORS];

    // Remplir le tableau avec des couleurs aléatoires (exemple)
    for (int i = 0; i < MAX_COLORS; i++) {
        colors[i].R = rand() % 256;
        colors[i].G = rand() % 256;
        colors[i].B = rand() % 256;
        colors[i].A = 255; // Alpha fixe
    }

    // Tableau pour stocker les couleurs distinctes
    DistinctColor distinctColors[MAX_DISTINCT_COLORS];
    int distinctCount = 0;

    // Compter les occurrences
    for (int i = 0; i < MAX_COLORS; i++) {
        bool found = false;
        // Vérifier si la couleur existe déjà dans distinctColors
        for (int j = 0; j < distinctCount; j++) {
            if (colors_equal(colors[i], distinctColors[j].color)) {
                distinctColors[j].count++;
                found = true;
                break;
            }
        }
        // Si la couleur n'est pas trouvée, l'ajouter au tableau
        if (!found && distinctCount < MAX_DISTINCT_COLORS) {
            distinctColors[distinctCount].color = colors[i];
            distinctColors[distinctCount].count = 1;
            distinctCount++;
        }
    }

    // Afficher les résultats
    printf("Couleurs distinctes et leur nombre d'occurrences:\n");
    for (int i = 0; i < distinctCount; i++) {
        printf("Couleur %d: R=%d, G=%d, B=%d, A=%d - Occurrences: %d\n",
               i + 1, distinctColors[i].color.R, distinctColors[i].color.G,
               distinctColors[i].color.B, distinctColors[i].color.A,
               distinctColors[i].count);
    }

    return 0;
}
