l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))

ans = 0
current = 0

for i in range(0, len(l1)):
    current -= l1[i]
    current += l2[i]
    ans = max(ans, current)

print(ans)