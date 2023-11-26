num = list(map(int, input().split()))
n = num[0]
c = [0] * 1000
d = []

for i in range(1, n):
    c[i] = abs(num[i] - num[i + 1])
    d.append(c[i])

d.sort()

for i in range(n - 1):
    if d[i] != i + 1:
        print("Not jolly")
        break
else:
    print("Jolly")
