def count_occurrences(line, phrase):
    count = 0
    start = 0
    while (start := line.find(phrase, start)) != -1:
        count += 1
        start += len(phrase)  # avancer après la phrase trouvée
    return count

def main():
    filename = input("Entrez le nom du fichier : ")
    phrase = input("Entrez la phrase que vous souhaitez rechercher : ")

    try:
        with open(filename, 'r', encoding='utf-8') as file:
            line_number = 0
            for line in file:
                line_number += 1
                occurrences = count_occurrences(line, phrase)
                if occurrences > 0:
                    print(f"Ligne {line_number}, {occurrences} fois")
    except FileNotFoundError:
        print(f"Erreur : impossible d'ouvrir le fichier {filename}")

if __name__ == "__main__":
    main()