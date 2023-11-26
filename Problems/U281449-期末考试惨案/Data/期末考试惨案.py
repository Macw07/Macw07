import random
import math

n, m = map(int, input().split())
print(n, m)

arr = [[' ' for i in range(1005)] for j in range(1005)]
for i in range(n):
    for j in range(m):
        k = random.randint(1, 100)
        if k < 25:
            arr[i][j] = '#'
        else:
            arr[i][j] = '-'

sx = random.randint(1, n//2)
sy = random.randint(1, m//2)
arr[sx][sy] = '&'
for i in range(random.randint(1, 10)):
    ex = random.randint(max(n-5, n//2-1), n)
    ey = random.randint(max(m-5, m//2-1), m)
    arr[ex][ey] = '@'

for i in range(n):
    for j in range(m):
        print(arr[i][j], end="")
    print()

k = random.randint(1, min(n, m)-5)
print(k)
while k != 0:
    x = random.randint(1, n)
    y = random.randint(1, m)
    t = random.randint(1, min(n, m)//10)
    if arr[x][y] != '&' and arr[x][y] != '@':
        print(x, y, t)
        k -= 1