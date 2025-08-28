# Prefix-Suffix Palindrome (Easy version)
# https://codeforces.com/group/YPSel1QSwP/contest/630230/problem/F
def palin(word):
    n = len(word) - 1
    for i, c in enumerate(word):
        if c != word[n-i]:
            return False
    return True


n = int(input())
for i in range(n):
    word = input()

    out = ""
    size = len(word)
    for i, c in enumerate(word):
        if word[size - 1 - i] == c:
            out += c
        else:
            break

    if i == size - 1:
        print(out)
        continue

    sub_right = f"{word[i]}"
    for j in range(i + 1, size - len(out)):
        if palin(word[i:j]):
            sub_right = word[i:j]
        else:
            continue

    k = size - len(out) - 1
    sub_left = f"{word[k]}"
    for j in range(k, i, -1):
        if palin(word[j:k + 1]):
            sub_left = word[j:k + 1]
        else:
            continue

    if len(sub_right) >= len(sub_left):
        print(out + sub_right + out[::-1])
    else:
        print(out + sub_left + out[::-1])
