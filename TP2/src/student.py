class Student :
    
    def __init__(self, nom: str, prenom: str, adresse: str, age: int, notes: list[float] = []) -> None:
        self.nom: str = nom
        self.prenom: str = prenom
        self.adresse: str = adresse
        self.age: int = age
        self.notes: list[float] = notes
        
    def __str__(self) -> str:
        return f"\nNom : {self.nom}\nPrenom : {self.prenom}\n Adresse : {self.adresse}\n Age : {self.age} ans\n Notes : {self.notes}"
  
def add_student() -> Student :
    print("\n\nEnter his lastname : ")
    lastname: str = input()
    print("\n\nEnter his firstname : ")
    firstname: str = input()
    print("\n\nEnter his adress : ")
    adress: str = input()
    print("\n\nEnter his age : ")
    age: int = int(input())
    print("\n\nEnter his notes (separated by ',') :")
    notes: list[float] = [float(note) for note in input().split(",")]
    return Student(lastname, firstname, adress, age, notes)

if __name__ == "__main__":
    students: list[Student] = []
    while True :
        print("Enter A to add a new student, else enter another key : ")
        choice: str = input()
        match choice.lower() :
            case 'a':
                students.append(add_student())
            case _:
                break
            
    print("\n\n\nHere's students you added :\n")
    for i in range(len(students)) :
        print("\n", f"Student no {i + 1} :", students[i])
    
    