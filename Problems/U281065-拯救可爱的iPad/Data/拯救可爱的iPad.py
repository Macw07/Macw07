import random
r = int(input())
n = random.randint(int(r/2), r)
m = random.randint(int(r/2), r)
print(n, m)

arr = [['#' for i in range(205)] for i in range(205)]
value = random.randint(10, 30)
for i in range(n):
    for j in range(m):
        k = random.randint(1, 100)
        if k <= value:
            arr[i][j] = '#'
        else:
            arr[i][j] = '-'

sx = random.randint(1, int(n/2)) - 1
sy = random.randint(1, int(m-1)) - 1
arr[sx][sy] = 'S'
ex = random.randint(max(sx+1, n-5), n) - 1
ey = random.randint(max(sy+1, m-5), m) - 1
arr[ex][ey] = 'O'

doors = random.randint(1, int(n*m/(random.randint(15, 20))))
for i in range(doors):
    dx = random.randint(1, n) - 1
    dy = random.randint(1, m) - 1
    if arr[dx][dy] == '-' or arr[dx][dy] == '#':
        arr[dx][dy] = 'D'

teachers = random.randint(1, int(n*m/(random.randint(25, 30))))
for i in range(doors):
    dx = random.randint(1, n) - 1
    dy = random.randint(1, m) - 1
    if arr[dx][dy] == '-' or arr[dx][dy] == '#' or arr[dx][dy] == 'D':
        arr[dx][dy] = 'T'

for i in range(n):
    for j in range(m):
        print(arr[i][j], end='')
    print()