import random

def create_random_input_file(filename):
    t = 10000  # Random value for t between 1 and 10
    lines = []
    
    for _ in range(t):
        l = 1  # Random value for l between 1 and 100
        r = 200000  # Random value for r between l and 100 to ensure l <= r
        lines.append(f"{l} {r}")
    
    # Create and write to the .txt file
    with open(filename, 'w') as file:
        file.write(f"{t}\n")
        file.write("\n".join(lines))
    
    print(f"File '{filename}' with random input created successfully!")

# Usage
create_random_input_file('random_input.txt')