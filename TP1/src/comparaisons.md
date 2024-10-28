# Comparaisons entre C et Python

## Bases de la programmation

### Affichage de données

- **C** : Utilise la fonction `printf` pour afficher des données. La syntaxe nécessite la spécification des formats pour chaque type de donnée, ce qui permet une gestion fine du formatage des sorties.

  ```c
  #include <stdio.h>

  int main() {
      int num = 42;
      printf("Le nombre est %d\n", num);
      return 0;
  }
- **Python** : Utilise la fonction `print` , qui est plus simple et flexible, permettant d'afficher des données sans spécifier le format de manière aussi détaillée.

```python
  num = 42
  print(f"Le nombre est {num}")
```
**Différences** : 
- `printf` en C nécessite des spécifications de format pour chaque type de donnée.
- `print` en Python est plus intuitif avec des f-strings pour l'insertion des variables directement dans les chaînes de caractères.

### Gestion de la mémoire

- **C** : La gestion de la mémoire est manuelle. Le programmeur doit allouer et libérer la mémoire explicitement à l'aide de `malloc`, `calloc`, `realloc`, et `free`.
```c
  int *arr = (int *)malloc(10 * sizeof(int));
  free(arr);
```
- **Python** : La gestion de la mémoire est automatique grâce au ramasse-miettes (garbage collector). Les allocations et désallocations de mémoire sont gérées automatiquement.
```python
  arr = [0] * 10
  del arr
```
**Différences** :
- C requiert une gestion manuelle de la mémoire.
- Python utilise la gestion automatique de la mémoire.

## Manipulation des variables

### Déclaration des types

- **C** : Le typage est statique et explicite. Les types doivent être déclarés lors de la définition des variables.
```c
  int num = 10;
  float pi = 3.14;
```
- **Python** : Le typage est dynamique. Les types des variables sont déterminés au moment de l'exécution et ne nécessitent pas de déclaration préalable.
```python
  num = 10
  pi = 3.14
```
**Différences** :
- C utilise des types statiques et exige une déclaration explicite.
- Python utilise un typage dynamique, facilitant la flexibilité mais pouvant mener à des erreurs de type à l'exécution.

## Opérateurs
### Arithmétiques, logiques et bit à bit

- **C** : Les opérateurs arithmétiques (`+`, `-`, `*`, `/`, `%`), logiques (`&&`, `||`, `!`), et bit à bit (`&`, `|`, `^`, `~`, `<<`, `>>`) sont disponibles.
```c
  int a = 5, b = 3;
  int sum = a + b;
  int bitwise_and = a & b;
```
- **Python** : Les opérateurs arithmétiques (`+`, `-`, `*`, `/`, `%`), logiques (`and`, `or`, `not`), et bit à bit (`&`, `|`, `^`, `~`, `<<`, `>>`) sont également disponibles.
```python
  a = 5
  b = 3
  sum = a + b
  bitwise_and = a & b
```

**Similarités** :
- Les opérateurs arithmétiques et logiques sont similaires.
- Les opérations bit à bit sont présentes dans les deux langages, mais le format de certains opérateurs logiques diffère (`&&` et `||` en C vs `and` et `or` en Python).

## Boucles et structures de contrôle
### Boucles et conditionnelles

- **C** : Utilisez des accolades pour délimiter les blocs de code. Les boucles `for`, `while`, et `do..while` ainsi que les structures conditionnelles `if`, `else` sont disponibles.
```c
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
        printf("%d est pair\n", i);
    } else {
        printf("%d est impair\n", i);
    }
  }
```
- **Python** : Utilisez l'indentation pour délimiter les blocs de code. Les boucles `for` et `while`, ainsi que les structures conditionnelles `if`, `elif`, `else` sont disponibles.
```python
  for i in range(10):
    if i % 2 == 0:
        print(f"{i} est pair")
    else:
        print(f"{i} est impair")
```
**Différences** :
- C utilise des accolades pour délimiter les blocs de code, alors que Python utilise l'indentation.
- Les structures conditionnelles sont similaires mais avec une syntaxe différente.

## Conversion et formatage
### Conversion en binaire

-**C** : Utilise des opérations de division et de reste pour obtenir la représentation binaire, souvent stockée dans un tableau ou une chaîne de caractères.
```c
  int num = 10;
  for (int i = 31; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
  }
```
-**Python** : Utilise des fonctions intégrées pour obtenir la représentation binaire sous forme de chaîne de caractères.
```python
  num = 10
  print(bin(num)[2:])
```
**Différences** :
- C nécessite des manipulations manuelles pour obtenir la représentation binaire.
- Python fournit des fonctions intégrées comme `bin()` pour une conversion facile.