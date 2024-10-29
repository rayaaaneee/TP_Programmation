import math
import dis

def calculer_aire(rayon: float) -> float:
    # Si on remplace par une constante : RETURN_CONST 1 (45.0 (valeur donnée))
    return math.pi * rayon * rayon

def main() -> None:
    rayon : float = 56.0
    aire : float = calculer_aire(rayon)
    print(f"L'aire du cercle de rayon {rayon:.2f} est {aire:.2f}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_aire)
    main()
