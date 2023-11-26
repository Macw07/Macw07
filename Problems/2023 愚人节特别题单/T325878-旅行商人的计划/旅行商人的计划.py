import random
l, n, m, k = map(int, input().split())
print(l, n, m, k)
stations = []
while len(stations) < n:
    temp = random.randint(1, l)
    if temp not in stations:
        stations.append(temp)
        print(temp, end=" ")
print()
for i in range(1, m+1):
    print(random.randint(1, l), end=" ")