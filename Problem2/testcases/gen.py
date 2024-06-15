import random

for i in range(10):
    f = open(f"./Input/in{i + 1}.txt", "a")
    x = random.randint(1, 100000)
    f.write(f"{x}\n")
    for y in range(x):
        w = random.randint(1, 100000)
        f.write(f"{w} ")
    f.close()