line = input()
chars = 0

while len(line) != 0:
    chars += line.count(line[0]) - 1
    line = line.replace(str(line[0]), "")

print(chars)
