# Missing Number
# https://cses.fi/problemset/task/1083
n = int(input())
nums = map(int, input().split())

total = n * (n + 1) / 2

print(int(total - sum(nums)))
