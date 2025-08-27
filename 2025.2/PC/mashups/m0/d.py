n, c = input().split()
c = int(c)

competidores = sum(map(int, input().split()))

if competidores > c:
    print(int(c / 3))
else:
    print(int(competidores / 3))
