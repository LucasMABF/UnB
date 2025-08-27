n, k = input().split()
k = int(k)
scores = input().split()
cut = int(scores[k - 1])

participants = 0
for i in scores:
    if int(i) >= cut and int(i) > 0:
        participants += 1

print(participants)
