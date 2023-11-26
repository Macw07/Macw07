import random
k = int(input())
n = random.randint(1, k)
m = random.randint(1, int(k/10))
print(n, m)

for i in range(n):
    print(random.randint(k, k*10), end=" ")
print()

for i in range(m):
    print(random.randint(k, k*10), end=" ")
print()