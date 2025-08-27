import math

n, m = map(int, input().split())

verdes = math.ceil(n / 2) * math.ceil(m / 2) \
       + math.floor(n / 2) * math.floor(m / 2)

print(verdes)
