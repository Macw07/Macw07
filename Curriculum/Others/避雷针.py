import sys
input = lambda: sys.stdin.readline().strip()
n, m = map(int, input().strip().split())

arr = set(list(map(lambda x: int(x) + 2, input().strip().split())))

cntlist = [0 for i in range(n + 6)]

for i in arr:
    for j in range(i-2, i+3):
        cntlist[j] = 1

print(cntlist[3:n+3].count(1))


