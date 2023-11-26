n, m = map(int, input().split())
arr = []
ans = 0
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def dfs(x, y):  # (x, y) coordinate
    global n, m, arr, dx, dy
    arr[x][y] = 0
    for direction in range(0, 4):
        new_x = x + dx[direction]
        new_y = y + dy[direction]
        if new_x < 0 or new_x >= n:
            continue
        if new_y < 0 or new_y >= m:
            continue
        if arr[new_x][new_y] == 0:
            continue
        dfs(new_x, new_y)


for i in range(n):
    temp = list(map(int, input().split()))
    arr.append(temp)

for i in range(0, n):
    for j in range(0, m):
        if arr[i][j] == 0:
            continue
        ans += 1
        dfs(i, j)

print(ans)
