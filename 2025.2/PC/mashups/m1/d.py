# Homework
# https://codeforces.com/group/YPSel1QSwP/contest/634981/problem/D
t = int(input())

for i in range(t):
    input()
    a = input()
    input()
    b = input()
    c = input()

    for idx, j in enumerate(b):
        if c[idx] == "D":
            a += j
        else:
            a = j + a

    print(a)
