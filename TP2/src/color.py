from random import randint

class Color:
    def __init__(self, R: int, G: int, B: int, alpha: float = None) -> None:
        self.R: int = R
        self.G: int = G
        self.B: int = B
        self.alpha: float = alpha
    
    def __str__(self) -> str:
        alpha_str = f"\n\tAlpha : {self.alpha}" if self.alpha is not None else ""
        return f"\nColor {{\
            \n\tRED : {self.R}\
            \n\tGREEN : {self.G}\
            \n\tBLUE : {self.B}\
            {alpha_str}\
        \n}}"

    def __hash__(self):
        return hash((self.R, self.G, self.B, self.alpha))
    
    def __eq__(self, other):
        return (self.R, self.G, self.B, self.alpha) == (other.R, other.G, other.B, other.alpha)

if __name__ == "__main__":
    # Step 2: Create a list of 100 Color instances
    hundred_colors: list[Color] = []
    for i in range(100):
        R: int = randint(0, 255)
        G: int = randint(0, 255)
        B: int = randint(0, 255)
        color: Color = Color(R, G, B)

        a = randint(1, 5)
        color: Color = Color(R, G, B, alpha=a if a >= 4 else None)
        hundred_colors.append(color)

    # Step 3: Count occurrences of each color
    color_count: dict[Color, int] = dict()
    
    for color in hundred_colors:
        if color in color_count:
            color_count[color] += 1
        else:
            color_count[color] = 1

    print("Occurrences of each color:")
    for color, count in color_count.items():
        print(f"{color} occurs {count} time{"(s)" if count > 1 else ""}")