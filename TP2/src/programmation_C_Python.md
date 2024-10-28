# Synthèse des approches en langage C et Python

## Débogage

### C (avec gdb)
- **Outils** : gdb (GNU Debugger)
- **Techniques** :
  - Lancer gdb avec l'exécutable : `gdb ./programme`
  - Définir des points d'arrêt : `break main`
  - Exécuter le programme : `run`
  - Inspecter les variables : `print variable`
  - Avancer pas à pas : `step` ou `next`
- **Différences** :
  - Nécessite la compilation avec l'option `-g` pour inclure les informations de débogage.
  - Approche plus bas niveau, accès direct à la mémoire et aux registres.

### Python (avec pdb)
- **Outils** : pdb (Python Debugger)
- **Techniques** :
  - Importer pdb dans le script : `import pdb; pdb.set_trace()`
  - Lancer le script : `python script.py`
  - Définir des points d'arrêt : `break ligne`
  - Exécuter le programme : `continue`
  - Inspecter les variables : `print(variable)`
  - Avancer pas à pas : `step` ou `next`
- **Différences** :
  - Intégré directement dans l'interpréteur Python.
  - Approche plus haut niveau, manipulation directe des objets Python.

## Chaîne de Compilation

### C (avec gcc)
- **Étapes** :
  - **Prétraitement** : `gcc -E fichier.c -o fichier.i`
  - **Compilation** : `gcc -S fichier.i -o fichier.s`
  - **Assemblage** : `gcc -c fichier.s -o fichier.o`
  - **Édition des liens** : `gcc fichier.o -o programme`
- **Différences** :
  - Processus en plusieurs étapes, chaque étape produit un fichier intermédiaire.
  - Nécessite une gestion explicite des dépendances et des bibliothèques.

### Python
- **Gestion des modules** :
  - Les scripts Python sont interprétés directement.
  - Les modules sont importés dynamiquement avec `import module`.
  - Pas de compilation explicite, mais possibilité de compiler en bytecode avec `py_compile`.
- **Différences** :
  - Pas de chaîne de compilation complexe.
  - Gestion des dépendances simplifiée grâce à des outils comme `pip`.

## Inspection de Code

### C
- **Outils** : objdump, nm, readelf
- **Techniques** :
  - Examiner le code machine : `objdump -d programme`
  - Lister les symboles : `nm programme`
  - Inspecter les sections ELF : `readelf -a programme`
- **Différences** :
  - Nécessite des outils externes pour examiner le code compilé.
  - Accès direct au code machine et aux symboles.

### Python
- **Outils** : dis
- **Techniques** :
  - Examiner le bytecode : `import dis; dis.dis(function)`
- **Différences** :
  - Intégré directement dans l'interpréteur Python.
  - Permet d'examiner le bytecode Python de manière simple et rapide.

## Manipulation de Chaînes de Caractères

### C
- **Techniques** :
  - Utilisation des fonctions de la bibliothèque standard : `strcpy`, `strcat`, `strlen`, etc.
  - Manipulation directe des pointeurs et des tableaux de caractères.
- **Avantages** :
  - Contrôle fin sur la mémoire et les performances.
- **Inconvénients** :
  - Gestion manuelle de la mémoire, risque de débordement de tampon.

### Python
- **Techniques** :
  - Utilisation des méthodes de chaîne : `str.upper()`, `str.lower()`, `str.replace()`, etc.
  - Utilisation des f-strings pour l'interpolation : `f"{variable}"`
- **Avantages** :
  - Syntaxe simple et expressive.
  - Gestion automatique de la mémoire.
- **Inconvénients** :
  - Moins de contrôle sur les performances.

## Gestion des Données et Recherche dans les Fichiers

### C
- **Structures de données** :
  - Utilisation des structures (`struct`) pour représenter les données.
  - Exemple :
    ```c
    struct Etudiant {
        char nom[50];
        int age;
        float moyenne;
    };
    ```
- **Recherche dans les fichiers** :
  - Utilisation des fonctions de la bibliothèque standard : `fopen`, `fgets`, `strstr`, etc.
  - Exemple :
    ```c
    FILE *fichier = fopen("etudiants.txt", "r");
    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (strstr(ligne, "recherche")) {
            printf("Trouvé : %s", ligne);
        }
    }
    fclose(fichier);
    ```

### Python
- **Structures de données** :
  - Utilisation des classes pour représenter les données.
  - Exemple :
    ```python
    class Etudiant:
        def __init__(self, nom, age, moyenne):
            self.nom = nom
            self.age = age
            self.moyenne = moyenne
    ```
- **Recherche dans les fichiers** :
  - Utilisation des méthodes de fichier et des expressions régulières.
  - Exemple :
    ```python
    with open("etudiants.txt", "r") as fichier:
        for ligne in fichier:
            if "recherche" in ligne:
                print(f"Trouvé : {ligne.strip()}")
    ```
- **Différences** :
  - C utilise des structures pour les données, Python utilise des classes.
  - La recherche dans les fichiers est plus simple et expressive en Python.
