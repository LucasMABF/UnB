# cAPS lOCK
# https://codeforces.com/group/YPSel1QSwP/contest/630230/problem/C
word = input()

if len(word) == 1 or word.isupper() or \
        (word[0].islower() and word[1:].isupper()):
    print(word.swapcase())
else:
    print(word)
