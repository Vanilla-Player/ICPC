import random

def generar_test_case(n, min_val, max_val, filename="test_case.txt"):
    # Genera una lista aleatoria de tamaño n con valores entre min_val y max_val
    arr = [random.randint(min_val, max_val) for _ in range(n)]
    
    # Escribe el test case en el archivo
    with open(filename, "w") as file:
        file.write(f"{n}\n")
        file.write(" ".join(map(str, arr)) + "\n")
    
    print(f"Test case generado con éxito en {filename}")

# Parámetros para generar el test case
n = 200000  # Tamaño del array
min_val = -291312  # Valor mínimo
max_val = 132141  # Valor máximo

generar_test_case(n, min_val, max_val)
